## Qmake Qt MinGW Compile Qt project via Command Line
```sh
>> qmake
>> mingw32-make -f Makefile.Debug
  [-f Makefile.Debug = Optional]
```

## [MinGW Error In Compilation](http://stackoverflow.com/questions/2033608/mingw-linker-error-winsock)
```sh
gcc hello.c -o hello.o -lws2_32
```
