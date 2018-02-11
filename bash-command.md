### Find Release Version of Linux Distros
```sh
cat /etc/*-release [CentOS release 6.6 (Final)]
```

### Mixed Commmands
```sh
ps aux | grep firefox
sudo killall cupsd
sudo apt-get install htop
sudo renice -5 2744         // Give Priority 2744  0 to -5
df -ah
ls -alh /proc               // List of all active processes 
ls -alh /proc/1 | less      

sudo -i                   // sudo interactive shell session
cat environ
cat statm
ls /

ls /etc                  // contains all apps configuration files
ls /etc/ssh/             // contains ssh configuration files
ls /sbin | less          // regular binaries need for sudo for execution
ls /bin | less           // any application installs and shipped binaries
ls -alh /bin | less
ls /bin | grep rmdir
ls /tmp
ls /home                 // home for users
sudo ls /root
ls /lib64
ls /lib                  // shared libraries
man hier  OR   man 7 hier
ls /boot
ls /dev
ls /dev | grep sd        // sda sda1 sda2 sda5  -> Disk and Partitions
ls /etc | less
/sbin /ifconfig
ls /usr/bin | less
ls /usr/bin | wc -l
rm -rf /home/newuser
```
