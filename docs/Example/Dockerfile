FROM ubuntu:latest

LABEL net.hase-zheng.program="crow_web"
LABEL net.hase-zheng.crow_web.version="0.3.1"
LABEL net.hase-zheng.maintainer="ZHENG Robert"

RUN mkdir -p /home/webapp/data

COPY ./crow_web-x86_64.AppImage /home/webapp
COPY ./static /home/webapp/static
COPY ./start_app.sh /home/webapp

# only for local SSL testing
# RUN apt-get update && apt-get upgrade -y && apt-get install apt-utils libssl-dev openssl -y
# RUN openssl req -x509 -newkey rsa:2048 \
#  -subj "/C=DE/CN=paas platform instance" \
#  -keyout "/home/webapp/data/key.pem" \
#  -out "/home/webapp/data/cert.pem" \
#  -days 365 -nodes -sha256

RUN chmod -R 775 /home/webapp && cd /home/webapp

WORKDIR /home/webapp
EXPOSE 8080

CMD ["/home/webapp/start_app.sh"]

