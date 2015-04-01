#!/bin/bash
CONFIG=${1}
if [ -z "$CONFIG" ]
  then
  CONFIG=${MAKO_DEFAULT_CONFIG}
fi
if [ -z "$CONFIG" ]
  then
  CONFIG=Debug
fi

echo "Building sdks for $CONFIG"
CURRENT_DIR=$PWD
cd ../..
DEVROOT=$PWD
PROJECTROOT=${DEVROOT}/projects/sdks/$CONFIG


mkdir -p $PROJECTROOT
cd $PROJECTROOT

cmake $DEVROOT/src/sdks -DCMAKE_BUILD_TYPE=$CONFIG -DCMAKE_TOOLCHAIN_FILE=$CMAKE_TOOLCHAIN_FILE || exit 1
cmake --build . --target install || exit 1

cd $CURRENT_DIR
