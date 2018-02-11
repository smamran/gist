Hello friends, I am back with new video, but this time I am gonna show to something about a server.

Yeah, it's not an Apache, IIS, Zeus web server, Oracle Web Tier, lighttpd, Apache Tomcat etc..

But it's all about Nginx web server.



	- It's free open source popular web server including IMAP/POP3 proxy server.

	- Hosting about 7.5% of all domains worldwide, Nginx is known for its high performance, 
	  stability, simple configuration and low resource usage.

	- This web server doesn't use threads to handle requests rather a much more scalable
	  event-driven architecture which uses small and predictable amounts of memory under load.


For more information about Nginx search in Google :D


Today I'll show you that how to configure Nginx web server with PHP in windows 7.

For that we need to download Nginx server's setup files and PHP's setup files as well.


Go to Nginx main website: http://nginx.org/ and download nginx latest release.




For PHP got to this site http://windows.php.net/download/ and download latest relaese.

I am not gonna download both of them because I have already downloaded them.










After downloading both setups extract them into C:// drive.


put extract php folder in nginx folder.

Now follow steps as I am doing in this video.


To configure PHP in nginx we need to make some changes in nginx.conf file.

Remove old code in nginx.conf file paste below code in nginx.conf.

here is code :


	location ~ .php$ {
	root           html;
	fastcgi_pass   127.0.0.1:9000;
	fastcgi_index  index.php;
	fastcgi_param  SCRIPT_FILENAME  C:/nginx/html/$fastcgi_script_name;
	include        fastcgi_params;
	}







To start nginx and php use below batch code:

@ECHO OFF
start C:\nginx\nginx.exe
start C:\nginx\php\php-cgi.exe -b 127.0.0.1:9000 -c C:\nginx\php\php.ini
ping 127.0.0.1 -n 1>NUL
echo Starting nginx
echo .
echo ..
echo ...
ping 127.0.0.1 >NUL
EXIT


To stop nginx and php use below batch code.




@ECHO OFF
taskkill /f /IM nginx.exe
taskkill /f /IM php-cgi.exe
Exit



as we can see on my local ip 127.0.0.1 there is nothing to load.


let us start nginx server.



our server has been started :-)


now let us upload php file.



our nginx server started with php :-)

enjoy :-)


nginx to too faster than apache, once try nginx you will love it :-)


thank you :D




