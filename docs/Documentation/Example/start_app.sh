#!/usr/bin/bash

echo "Starting the application..."

cd /home/webapp && ./crow_web-x86_64.AppImage --appimage-extract

squashfs-root/usr/bin/crow_web static/crow_web.ini

/bin/bash
