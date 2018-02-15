# VC File Compile
* Run: Developer Command Prompt for VS2015
```sh
cl main.c
```

# VC++ File Compile
* Run: Developer Command Prompt for VS2015
```sh
cl main.cc /clr
```

# Add library to CC File
```c
#pragma comment (lib, "user32.lib")
```

# C# File Compile:

[C# Compile](https://msdn.microsoft.com/en-us/library/78f4aasd.aspx)
## Sample Command Lines for the C# Compiler
* Compiles main.cs producing main.exe
```sh
csc main.cs 
```
* Compiles main.cs producing main.dll
```sh
csc /target:library main.cs
```

* Compiles main.cs and creates main.exe
```sh
csc /out:main.exe main.cs
```

* Compiles all the C# files in the current directory, with optimizations on and defines the DEBUG symbol. The output is outfile.exe
```sh
csc /define:DEBUG /optimize /out:outfile.exe *.cs
```

* Compiles all the C# files in the current directory producing a debug version of outfile.dll
* No logo and no warnings are displayed
```sh
csc /target:library /out:outfile.dll /warn:0 /nologo /debug *.cs
```

* Compiles all the C# files in the current directory to outfile.xyz (a DLL)
```sh
csc /target:library /out:outfile.xyz *.cs
```
