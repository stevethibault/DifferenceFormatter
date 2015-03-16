stepLineNumber=0
arguments="$@"
function exitError
{
  echo "Exiting ${0} ${arguments}: error at or near line ${stepLineNumber}"
}
trap exitError EXIT 
trap 'stepLineNumber=${LINENO}' DEBUG

./build_sdks_for_configuration.sh Debug || trap DEBUG; exit 1
./build_sdks_for_configuration.sh Release || trap DEBUG; exit 1
# ./set_sdks.sh || trap DEBUG; exit 1

trap EXIT 