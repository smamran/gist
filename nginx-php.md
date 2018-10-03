## Nginx Configure for PHP

* First Install Nginx Server
```sh
sudo -s
nginx=stable # use nginx=development for latest development version
add-apt-repository ppa:nginx/$nginx
apt-get update
apt-get install nginx
```

* Check Ubuntu Firewall Allows Nginx
```sh
sudo ufw app list
```

* Install PHP-FPM Package 
* Works Like Node Server. Process php files, generates contents and serves back to Nginx
```sh
sudo apt install php7.2-fpm
```

* Configuration change ` php7.2-fpm `
```sh
sudo vim /etc/php/7.2/fpm/php.ini
```

* Search ` / ` for ` cgi.fix_pathinfo `
* Uncomment the line and set value ` 0 `
```sh
cgi.fix_pathinfo=0
```

* Nginx Configs folder ` /etc/nginx/sites-available ` contains available sites configurations for future use
* ` /etc/nginx/sites-enabled ` folder contains currently active configurations
* Normally a ` default ` file from ` sites-available ` is soft linked to ` etc/nginx/sites-enabled ` folder
* We can see what contains in ` sites-enabled ` folder using ` ll `
```sh
lrwxrwxrwx 1 root root   34 Oct  2 02:42 default -> /etc/nginx/sites-available/default
```
* So Editing ` sites-available/default ` file will efect ` sites-enabled/default ` file
```sh
sudo vim /etc/nginx/sites-available/default
```
* Only Change Configs like this
```sh
index index.php index.html index.htm index.nginx-debian.html;

server_name 192.168.5.128;

location ~ \.php$ {
                include snippets/fastcgi-php.conf;

        #       # With php-fpm (or other unix sockets):
                fastcgi_pass unix:/var/run/php/php7.2-fpm.sock;
        #       # With php-cgi (or other tcp sockets):
        #       fastcgi_pass 127.0.0.1:9000;
        }

 location ~ /\.ht {
                deny all;
        }
```

* Check Configuration & Restart
```sh
sudo nginx -t
sudo systemctl restart nginx
```

* Check ` php7.2-fpm ` is running
```sh
ps aux | grep php
/etc/init.d/php7.2-fpm start
```

* Check what error nginx generates after reloading browser url
```sh
tail /var/log/nginx/error.log
```

* Serve ` phpinfo() ` contents
```sh
curl localhost
```

## Troubleshoot
#### Bad Gateway Problem
* Check ` fastcgi_pass unix:/var/run/php/php7.2-fpm.sock; ` file location is ok configured in ` nginx `
