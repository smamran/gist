### Search Text in Directory Files
```sh
>> grep -r "Searching_Text" *
```

### Grep File Name Pattern Search Text
```sh
>> grep -r --include "*.txt" texthere .
>> grep -r ----exclude "*.txt" texthere .
```

### Search to Subfolder recursively Text in File
```sh
>> grep -R 'string' dir/
>> find dir/ -type f -exec grep -H 'string' {} +
```

### Check Library Architecture Linux
```sh
>> objdump -f libfoo.a | grep ^architecture
```

### c9.io Command
```sh
  sudo cp FileWalker.java /                                        ## copy FileWalker.java file to /(root) directory.
  (cd ..; cd .. ; cd .. ; javac FileWalker.java; java FileWalker)  ## it's a subshell , which executes a list of commands from current dir
  cp libc.h /home/ubuntu/workspace/                                ## compies libc.h file to c9.io workspace
  hostname -I                                                      ## get ip address of current machine
```
