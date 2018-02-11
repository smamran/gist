## Find String Pattern Recursively From Files
```powershell
Get-ChildItem -recurse | Select-String -pattern <pattern> | group path | select name
```
