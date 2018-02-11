### Check whether a directory exists
```c
#include <sys/stat.h>
struct stat st;
if(stat("/tmp",&st) == 0)
        printf(" /tmp is present\n");
```
