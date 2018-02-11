### Display Total Disk Size
```sh
fdisk -l | grep Disk
```

### Displays Size of Folder sorted according to size
```sh
sudo du -sh .[!.]* *| sort -nr   (Including Subdirectories)
sudo du -sh * | sort -nr         (Excluding Subdirectories)
```

### Displays the total size of the current directory including all the subdirectories
```sh
du -ch | grep total
```

### Sum of directories (-s) in kilobytes (-k)
```sh
du -sk *
152304  directoryOne
1856548 directoryTwo
```

### Sum of directories (-s) in human-readable format (-h : Byte, Kilobyte, Megabyte, Gigabyte, Terabyte and Petabyte)
```sh
du -sh *
149M directoryOne
1.8G directoryTwo
```

### Disk usage of all subdirectories and files including hidden files within the current directory (sorted by filesize)
```sh
du -sk .[!.]* *| sort -n
```

### Disk usage of all subdirectories and files including hidden files within the current directory (sorted by reverse filesize)
```sh
du -sk .[!.]* *| sort -nr
```
