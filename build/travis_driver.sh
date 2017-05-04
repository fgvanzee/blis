#!/usr/bin/env bash

set -e
set -x

CC="$1"
THREADING="$2"
TARGET="$3"
RUN_TEST="$4"

export BLIS_IC_NT=2
export BLIS_JC_NT=1
export BLIS_IR_NT=1
export BLIS_JR_NT=1

HARDWARE=0
SDE_OPTIONS="false"
case "$TARGET" in
    knl)
        if $(grep avx512f -q /proc/cpuinfo) && $(grep avx512pf -q /proc/cpuinfo) ; then HARDWARE=1 ; fi
        SDE_OPTIONS="-knl"
        ;;
    skx)
        if $(grep avx512f -q /proc/cpuinfo) && $(grep avx512vl -q /proc/cpuinfo) && $(grep avx512dq -q /proc/cpuinfo) ; then HARDWARE=1 ; fi
        SDE_OPTIONS="-skx"
        ;;
    haswell)
        if $(grep avx2 -q /proc/cpuinfo) ; then HARDWARE=1 ; fi
        SDE_OPTIONS="-hsw"
        ;;
    sandybridge)
        if $(grep avx -q /proc/cpuinfo) ; then HARDWARE=1 ; fi
        SDE_OPTIONS="-snb"
        ;;
    dunnington)
        if $(grep ssse3 -q /proc/cpuinfo) && $(grep sse4_1 -q /proc/cpuinfo) ; then HARDWARE=1 ; fi
        SDE_OPTIONS="-pnr"
        ;;
    auto)
        HARDWARE=1
        ;;
    reference)
        HARDWARE=1
        ;;
    *)
        ;;
esac

# older binutils do not support AVX-512 (need at least 2.25)
if [ "x$TARGET" == "xknl" ] || [ "x$TARGET" == "xskx" ]; then
    pushd /tmp
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.bz2
    tar -xaf binutils-2.28.tar.bz2
    cd binutils-2.28
    export BINUTILS_PATH=/tmp/mybinutils
    ./configure --prefix=$BINUTILS_PATH
    make
    make install
    export PATH=$BINUTILS_PATH/bin:$PATH
    export LD_LIBRARY_PATH=$BINUTILS_PATH/lib:$LD_LIBRARY_PATH
    popd
    which ld
fi

# configure BLIS
if [ "x$TARGET" == "xknl" ] ; then
    ./configure -d sde -t $THREADING CC=$CC $TARGET
else
    ./configure        -t $THREADING CC=$CC $TARGET
fi

# compile BLIS library
make

# compile and run BLIS tests
if [ "x${RUN_TEST}" == "x1" ] ; then
    make testsuite-bin
    # We make no attempt to run SDE_OPTIONS on Mac.  It is supported but requires elevated permissions.
    if [ "x${HARDWARE}" != "x1" ] && [ "${TRAVIS_OS_NAME}" == "linux" ] ; then
        set +x
        echo wget -q SDE_LOCATION
        wget -q ${SDE_LOCATION}
        set -x
        tar -xaf sde-external-7.58.0-2017-01-23-lin.tar.bz2
        export PATH=${PWD}/sde-external-7.58.0-2017-01-23-lin:${PATH}
        if [ `uname -m` = x86_64 ] ; then SDE_BIN=sde64 ; else SDE_BIN=sde ; fi
        ${PWD}/sde-external-7.58.0-2017-01-23-lin/${SDE_BIN} ${SDE_OPTIONS} -- make BLIS_ENABLE_TEST_OUTPUT=yes testsuite-run
    else
        make BLIS_ENABLE_TEST_OUTPUT=yes testsuite-run
    fi
fi
