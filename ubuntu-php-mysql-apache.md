# Install PHP 7
First install python-software-properties package on your system which provides add-apt-repository command then use the following set of commands to add PPA for PHP 7 in your Ubuntu system and install it.
```sh
sudo apt-get install python-software-properties
sudo add-apt-repository ppa:ondrej/php-7.0
sudo apt-get update
sudo apt-get install -y php7.0
```

# Install Apache 2.4
After successfully installation, lets begin installing Apache 2.4. Use the following set of commands to install Apache2 on your Ubuntu system available in default apt repositories.
```sh
sudo add-apt-repository ppa:ondrej/apache2
sudo apt-get update
sudo apt-get install apache2
```

# Install MySQL 5.6
Use the following commands to install or upgrade MySQL 5.6 on your Ubuntu systems. At the last update of this tutorial MySQL 5.6.27 is latest available MySQL version in series of MySQL 5.6.X.

```sh
sudo add-apt-repository -y ppa:ondrej/mysql-5.6
sudo apt-get update
sudo apt-get install mysql-server-5.6
```

# Install Other Requirements
You may also need to install modules like PHP7-MySQL, libapache2-mod-php7.0 etc based on your application requirements. Use the following command to find our available php 7 modules.

```sh
sudo apt-cache search php7-* 
```

Above command will list all available PHP7 modules for installation, Let’s begin installation of modules.
```sh
sudo apt-get install libapache2-mod-php7.0 php7.0-mysql php7.0-curl php7.0-json
```

# Verify Setup

Finally verify installation of PHP7 with Apache2. Let’s create a file info.php on website document root using following content.

```php
<?php
    phpinfo();
?>
```

Now browse this file in web browser. It will so all the details about version’s and installation.
