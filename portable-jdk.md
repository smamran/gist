### [How to Create Portable JDK](https://stackoverflow.com/questions/1619662/how-can-i-get-the-latest-jre-jdk-as-a-zip-file-rather-than-exe-or-msi-installe)
```sh
For JDK 8u102 things have changed, this worked for me:
Download windows JDK exe
Open with 7-Zip
Dump contents into a directory %JDK-EXE%
cmd: cd %JDK-EXE%.rsrc\1033\JAVA_CAB10
cmd: extrac32 111
Now have a tools.zip in directory, open it in 7-Zip
Extract contents into a new directory %JDK-VERSION%
cmd: cd %JDK-VERSION%
cmd: for /r %x in (*.pack) do .\bin\unpack200 -r "%x" "%~dx%~px%~nx.jar"
src.zip is in %JDK-EXE%.rsrc\1033\JAVA_CAB9\110\ - put a copy into %JDK-VERSION%
Now you are ready to go. You might want to setup JAVA_HOME and PATH to point to 
your %JDK-VERSION% dir and its BIN subdir.
```
