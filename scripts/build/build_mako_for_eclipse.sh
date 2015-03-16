CONFIG=$1
if [ -z "$CONFIG" ]
then
	CONFIG=$MAKO_DEFAULT_CONFIG
fi
if [ -z "$CONFIG" ]
then
	CONFIG=Debug
fi

echo Config: $CONFIG
CURRENT_DIR=$PWD
cd ../..
DEVROOT=$PWD
PROJECTROOT=$DEVROOT/projects/typhoon/$CONFIG

mkdir -p $PROJECTROOT
cd $PROJECTROOT

if [ ! -d "$DEVROOT/config" ]; then
	ln -s "$DEVROOT/instruments/acquity_pump" "$DEVROOT/config"
fi

cmake -G"Eclipse CDT4 - Unix Makefiles" $DEVROOT/src -DCMAKE_BUILD_TYPE=$CONFIG

cd $CURRENT_DIR
