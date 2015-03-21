#!/bin/bash
stepLineNumber=0
arguments="$@"
function exitError
{
  echo "Exiting ${0} ${arguments}: error at or near line ${stepLineNumber}"
}
trap exitError EXIT 
trap 'stepLineNumber=${LINENO}' DEBUG

function default_config()
{
	CONFIG=${TYPHOON_DEFAULT_CONFIG}
	if [ -z "${CONFIG}" ]
	then
		CONFIG=Debug
	fi
	echo ${CONFIG}
}

CONFIG=$1
if [ -z "${CONFIG}" ]
then
	CONFIG=$(default_config)
fi

echo "Building sdks for ${CONFIG}"

make -C ../.. -f Makefile BUILD_TYPE_LIST=${CONFIG} buildSdks || trap DEBUG; exit $?

trap EXIT 
