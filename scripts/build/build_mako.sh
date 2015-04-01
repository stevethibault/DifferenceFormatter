stepLineNumber=0
arguments="$@"
function exitError
{
  echo "Exiting ${0} ${arguments}: error at or near line ${stepLineNumber}"
}
trap exitError EXIT
trap 'stepLineNumber=${LINENO}' DEBUG

./build_mako_for_configuration.sh Debug || trap DEBUG; exit 1
./build_mako_for_configuration.sh Release || trap DEBUG; exit 1

trap EXIT

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

echo "Building mako for $CONFIG"
CURRENT_DIR=${PWD}
cd ../..
DEVROOT=${PWD}
PROJECTROOT=$DEVROOT/projects/mako/$CONFIG


mkdir -p $PROJECTROOT
cd $PROJECTROOT

cmake $DEVROOT/src -DCMAKE_BUILD_TYPE=$CONFIG -DCMAKE_TOOLCHAIN_FILE=$CMAKE_TOOLCHAIN_FILE -DALWAYS_RUN_UNIT_TESTS=On || exit 1
cmake --build . || exit 1

cd $CURRENT_DIR
