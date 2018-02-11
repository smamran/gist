```sql
DELIMITER $$
USE `smdb`$$

DROP PROCEDURE IF EXISTS `p_procedure`$$

CREATE DEFINER = `root` @`localhost` PROCEDURE `p_procedure` (
  IN p_msisdn VARCHAR (15),
  IN p_url VARCHAR (1000),
  OUT p_return VARCHAR (10)
) 
BEGIN
  IF ( (SELECT  COUNT(*)  FROM    subscriberservices   WHERE MSISDN = p_msisdn  AND STATUS = 'Registered') >0 ) THEN 
	INSERT INTO logforunregisteredrenewtry  VALUES ( DEFAULT, p_msisdn,  p_url, DEFAULT, DEFAULT );
	SET p_return = 'YES';
  ELSE 
	SET p_return = 'NO';
  END IF;
END $$

DELIMITER ;
```
