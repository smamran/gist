## Parallel Build MSBuild Solution File
```sh
msbuild /p:Configuration=Release BigProj.sln /m
  [ /m = Parallel Build]
```

## Build Universal Window Program From Command Line
```sh
msbuild mysolution.sln  /p:Configuration=Release;AppxBundle=Always;AppxBundlePlatforms="x86|x64|ARM"
```
