## MySQL DB Size in MB
```sql
SELECT * FROM (SELECT table_schema AS db_name,
	ROUND(SUM(data_length + index_length) / 1024/ 1024, 2) AS db_size_mb
FROM information_schema.`TABLES`
GROUP BY table_schema) a ORDER BY db_size_mb DESC;
```

## Measure Table size of Every Databases in Descending Order
```sql
SELECT 
     table_schema AS db_name, 
     table_name AS tbl_name, 
     ROUND(((data_length + index_length) / 1024 / 1024), 2) tbl_size_mb 
FROM information_schema.TABLES 
ORDER BY tbl_size_mb DESC;
```
## Measure Table size of Particular Database in Descending Order
```sql
SELECT * FROM (SELECT 
    table_name AS tbl_name, 
    ROUND(((data_length + index_length) / 1024 / 1024), 2) tbl_size_mb 
FROM information_schema.TABLES 
WHERE table_schema = 'smmydb') a 
ORDER BY tbl_size_mb DESC;
```
