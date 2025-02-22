<div id="top" align="center">
<h1>Docker example</h1>

<p>Crow webserver to check docker image content</p>

</div>

<hr>

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<hr>

## Dockerfile

### File structure

```bash
myDir.
      ├── crow_web-x86_64.AppImage
      ├── Dockerfile
      ├── start_app.sh
      └── static
          ├── crow_web.ini
          ├── favicon.ico
          ├── favicon.svg
          ├── index.html
          ├── main.css
          └── main.js

1 directory, 9 files
```

### Dockerfile

> \[!NOTE]
> Alpine doesn't work

```Dockerfile
FROM ubuntu:latest

LABEL net.hase-zheng.program="crow_web"
LABEL net.hase-zheng.crow_web.version="0.3.1"
LABEL net.hase-zheng.maintainer="ZHENG Robert"

RUN mkdir -p /home/webapp/data

COPY ./crow_web-x86_64.AppImage /home/webapp
COPY ./static /home/webapp/static
COPY ./start_app.sh /home/webapp

RUN chmod -R 775 /home/webapp && cd /home/webapp

WORKDIR /home/webapp
EXPOSE 8080

CMD ["/home/webapp/start_app.sh"]
```

### start_app.sh

```bash
#!/usr/bin/bash

cd /home/webapp && ./crow_web-x86_64.AppImage --appimage-extract

echo "Starting the application..."
squashfs-root/usr/bin/crow_web static/crow_web.ini

/bin/bash
```

### create Docker image

```bash
docker build -t crow_web .
```

### create/run Docker container

```bash
docker run -it --name crow_web_checker --network=docker-net -p 8085:8080 crow_web
```

### run/check Docker container

```bash
docker start crow_web_checker
docker ps
```
