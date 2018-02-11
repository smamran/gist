## Linux Compile MySQL C Api Source Codes
```sh
>> gcc mysql_me.c  `mysql_config --cflags --libs`
```
## C (time_t) vs MySQL Date Format Interchange
```sql
$$ SELECT FROM_UNIXTIME(UNIX_TIMESTAMP(), '%a %b %d %H:%i:%s %x');
$$ Mon Feb 08 19:01:08 2016
```
