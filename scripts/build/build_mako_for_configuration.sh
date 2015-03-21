stepLineNumber=0
arguments="$@"
function exitError
{
  echo "Exiting ${0} ${arguments}: error at or near line ${stepLineNumber}"
}
trap exitError EXIT 
trap 'stepLineNumber=${LINENO}' DEBUG

CONFIG=${1}
if [ -z "${CONFIG}" ]
then
	CONFIG=${MAKO_DEFAULT_CONFIG}
fi
if [ -z "${CONFIG}" ]
then
	CONFIG=Debug
fi

echo Config: ${CONFIG}
CURRENT_DIR=${PWD}
cd ../.. || trap DEBUG; exit 1

DEVROOT=${PWD}
PROJECTROOT=${DEVROOT}/projects/mako/${CONFIG}

mkdir -p $PROJECTROOT
cd $PROJECTROOT


make -C ../.. -f Makefile BUILD_TYPE=${CONFIG} MAKE_FLAGS= buildMako || trap DEBUG; exit $?

cd ${CURRENT_DIR} || trap DEBUG; exit 1

trap EXIT 
