echo "[Build] building logger..."

BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
    rm -rf $BUILD_DIR
fi

mkdir -p $BUILD_DIR
cd $BUILD_DIR || exit

cmake ../src
cmake --build . --config Release

echo "[Build] Done."