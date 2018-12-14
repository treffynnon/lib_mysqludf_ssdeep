#!/bin/bash
SRC_DIR="src"
BUILD_DIR="build"
DATE_DIR=`date +%s`
FULL_BUILD_PATH="$BUILD_DIR/$DATE_DIR"
mkdir -p $FULL_BUILD_PATH
cp $SRC_DIR/* $FULL_BUILD_PATH -r
cd $FULL_BUILD_PATH
autoreconf --force --install --symlink
./configure --with-ssdeep
make
cd ../../
cp $FULL_BUILD_PATH/.libs/lib_mysqludf_ssdeep.so ./lib_mysqludf_ssdeep.so
if [ ! -z "$1" ] &&  [ "$1" = "debian" ]; then
	cp $FULL_BUILD_PATH/.libs/lib_mysqludf_ssdeep.so ./lib_mysqludf_ssdeep.so
	rm -rf build/
else
	cp $FULL_BUILD_PATH/.libs/lib_mysqludf_ssdeep.so ./lib_mysqludf_ssdeep.so
fi
