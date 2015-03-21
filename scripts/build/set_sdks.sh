CONFIG=$1
if [ -z "$CONFIG" ]
then
	CONFIG=$MAKO_DEFAULT_CONFIG
fi
if [ -z "$CONFIG" ]
then
	CONFIG=Debug
fi

BUILD_SCRIPT_DIR=$PWD
cd ../..
DEVROOT=$PWD
cd $BUILD_SCRIPT_DIR
BUILDDIR=$DEVROOT/build/sdks/${CONFIG}

mkdir -p $DEVROOT/bin/
cp $BUILDDIR/bin/* $DEVROOT/bin/    
mkdir -p $DEVROOT/include/sdks
cp -r $BUILDDIR/include/* $DEVROOT/include/sdks
