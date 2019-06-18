# 🔫 🗡Commands ⚛ 💣 

#### 🔪🔧 Download NginX Source & Unzip 🗡🔨
```sh
>> wget http://nginx.org/download/nginx-1.9.9.tar.gz  
>> tar xvfvz nginx-1.9.9.tar.gz
>> cd nginx-1.9.9/
```

### 🔪🔧 Install Dependencies 🗡🔨
```sh
sudo apt install libxslt-dev
sudo apt install libpcre3 libpcre3-dev
sudo apt install build-essential
sudo apt install openssl libssl-dev libperl-dev
sudo apt install libxslt-dev
sudo apt install libgd2-xpm libgd2-xpm-dev
sudo apt install libgeoip-dev
sudo apt install libpam-dev
```

#### 🔪🔧 Configure, Compile & Install 🗡🔨
```sh
>> ./configure  --prefix=/usr/local/nginx \
                --sbin-path=/usr/local/sbin/nginx \
                --conf-path=/etc/nginx/nginx.conf \
                --error-log-path=/var/log/nginx/error.log \
                --http-log-path=/var/log/nginx/access.log \
                --pid-path=/run/nginx.pid \
                --lock-path=/run/lock/subsys/nginx \
                --user=nginx \
                --group=nginx \
                --with-file-aio \
                --with-ipv6 \
                --with-http_ssl_module \
                --with-http_v2_module \
                --with-http_realip_module \
                --with-http_addition_module \
                --with-http_xslt_module \
                --with-http_image_filter_module \
                --with-http_geoip_module \
                --with-http_sub_module \
                --with-http_dav_module \
                --with-http_flv_module \
                --with-http_mp4_module \
                --with-http_gunzip_module \
                --with-http_gzip_static_module \
                --with-http_random_index_module \
                --with-http_secure_link_module \
                --with-http_degradation_module \
                --with-http_stub_status_module \
                --with-http_perl_module \
                --with-mail \
                --with-mail_ssl_module \
                --with-pcre \
                --with-google_perftools_module \
                --with-debug
>> ./configure [Default Configuration]
>> make
>> sudo make install
```
#### 🔪🔧 Start Stop 🗡🔨
```sh
>> sudo service nginx start
>> sudo service nginx stop

>> pgrep nginx
>> pkill pid

>> cd objs
>> sudo ./nginx
```
