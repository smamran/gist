# VC File Compile:
Run: Developer Command Prompt for VS2015
```sh
>> cd F:\GD\Microsoft\MSDN-CODES
>> F:
>> cl main.c
```

# VC++ File Compile:
Run: Developer Command Prompt for VS2015
```sh
>> cd F:\GD\Microsoft\MSDN-CODES
>> F:
>> cl FileSystemWatch.cc /clr
```

# Add library to CC File
```c
>> #pragma comment (lib, "user32.lib")
```

# C# File Compile:

[C# Compile](https://msdn.microsoft.com/en-us/library/78f4aasd.aspx)
## Sample Command Lines for the C# Compiler
Compiles File.cs producing File.exe:
> csc File.cs 

Compiles File.cs producing File.dll:
> csc /target:library File.cs

Compiles File.cs and creates My.exe:
> csc /out:My.exe File.cs

Compiles all the C# files in the current directory, with optimizations on and defines the DEBUG symbol. The output is File2.exe:
> csc /define:DEBUG /optimize /out:File2.exe *.cs

Compiles all the C# files in the current directory producing a debug version of File2.dll. No logo and no warnings are displayed:
> csc /target:library /out:File2.dll /warn:0 /nologo /debug *.cs

Compiles all the C# files in the current directory to Something.xyz (a DLL):
> csc /target:library /out:Something.xyz *.cs
