# 🔫 🗡 Java Command Line ⚛ 💣 
### 🔪🔧 Compile Main Class in Different Directory 🗡🔨
```sh
>> javac main\Main.java
>> java main.Main.java
```

### 🔪🔧 Create Jar 🗡🔨
```sh
src >> jar cvfe Main.jar main.Main main\*.class
src >> jar cvfe Main.jar main.Main main\*.* [If contains FX CSS Windows PC]
src >> jar cvfe Main.jar main.Main main* [Linux n Windows Both]
```

### 🔪🔧 Java Compile & Run With External Jars 🗡🔨 
```sh
[Compiling]
>> javac -cp .:/path/external/libs.jar Main.java [For Linux]
>> javac -cp .;/path/external/libs.jar Main.java [For Windows]

[Running]
>> java -cp .:/path/external/libs.jar Main [For Linux]
>> java -cp .;/path/external/libs.jar Main [For Windows]

[Multiple Jars]
>> java -cp .:~app/java/apidemo/lib/* SyncApp [For Linux]

[Compile & Run a Project]
javac -d out/production/apidemo -cp .:./lib/* src/*.java
cd out/production/apidemo
java -cp .:../../../lib/* SyncApp
```


### 🔪🔧 Recursively Compile Java Files In Sub Folders 🗡🔨 
```sh
JBuild.bat >> for /r %%a in (*.java) do ( javac "%%a" )
JBuild.sh  >> javac $(find ./rootdir/* | grep .java)
```

### 🔪🔧 Java Compile By ant 🗡🔨
```sh
>> ant
```
### build.xml
```sh
<project default="compile">
    <target name="compile">
        <mkdir dir="bin"/>
        <javac srcdir="src" destdir="bin"/>
    </target>
</project>
```
