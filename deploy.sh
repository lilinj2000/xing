#! /bin/sh

home_app=~/app

home_xing=${home_app}/xing

./configure --prefix=${home_xing}

if test -d ${home_xing}; then
    rm -rf ${home_xing}
fi

make install

make distclean
