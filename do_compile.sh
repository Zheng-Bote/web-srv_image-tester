#!/usr/bin/bash

#TARGET="Debug"
TARGET="Release"

cd build

if [[ $TARGET == "Release" ]]; then
    echo "compile Release mode"
    cmake -B . -S ../src -DCMAKE_BUILD_TYPE=Release
    
    echo "create AppImage"
    cp crow_web ./AppDir/usr/bin/.
    ./linuxdeploy-plugin-appimage-x86_64.appimage --appdir ./AppDir
    sha256sum crow_web-x86_64.AppImage > crow_web-x86_64.AppImage.sha256sum

    echo "create deb package"
    cp crow_web ./crow-web/crow-web/usr/bin/.
    dpkg-deb --build crow-web
    mv crow_web.deb crow-web-x86_64.deb
    sha256sum crow-web-x86_64.deb > crow-web-x86_64.deb.sha256sum
else
    echo "compile Debug mode"
    cmake -B . -S ../src -DCMAKE_BUILD_TYPE=Debug     
fi
cmake --build . --parallel 6

echo "Done $TARGET"

./crow_web static/crow_web.ini


#clear
