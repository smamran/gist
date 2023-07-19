## Docker Commands
```sh
docker pull nginx
docker image ls
docker container run --publish 8080:80 nginx
docker container ls
docker container ls -a
docker container run --publish 8080:80 --detach --name nodejs  nginx
docker container logs nodejs
docker container --help
docker container rm 1f0 b32
docker container ls
docker container rm -f 1f0
docker container ls -a
```

### Build a docker image with content -> Nginx Server

## Nginx Dockerfile ls -> adminlte  Dockerfile
```
FROM nginx
COPY adminlte /usr/share/nginx/html
```
## Build
```
docker build -t adminlte .
Sending build context to Docker daemon  86.85MB
Step 1/2 : FROM nginx
 ---> 602e111c06b6
Step 2/2 : COPY adminlte /usr/share/nginx/html
 ---> d6dc8504ba0c
Successfully built d6dc8504ba0c
Successfully tagged adminlte:latest

docker run --name adminlte -d -p 8080:80 adminlte
docker container ls -a
```

/////////////////// Build a docker image with nodejs -> Nodejs Server  ///////////////////


## Nginx Dockerfile ls -> app.js (runs on 8888 port)  node_modules views ... etc
```
FROM node
RUN mkdir -p /home/node/app/node_modules && chown -R node:node /home/node/app
WORKDIR /home/node/app
COPY package*.json ./
USER node
RUN npm install
COPY --chown=node:node . .
EXPOSE 8888
CMD [ "node", "app.js" ]
```
## .dockerignore
```
node_modules
npm-debug.log
Dockerfile
.dockerignore
.git
README.md
.gitignore
docker build -t todoapp .
docker run --name todoapp -p 8888:8888 -d todoapp
```

## Docker removing all images(stopped)
```
docker system prune
docker system prune -a
```
