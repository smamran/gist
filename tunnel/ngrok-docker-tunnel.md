### Ngrok Docker Tunneling
```sh
docker run -d -it -e NGROK_AUTHTOKEN=<ngrok-token> ngrok/ngrok http http://host.docker.internal:80 --host-header="localhost:80"
```
### Tunneling through Cloudflared Docker
```sh
 docker run -d --rm cloudflare/cloudflared tunnel --url http://192.168.1.101:80
```
### See URL
```sh
docker logs <container_id>
```
