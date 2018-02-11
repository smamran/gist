```sql
DELIMITER $$

USE `cms_4_0`$$

DROP FUNCTION IF EXISTS `fn_isAlreadyRegisteredCheck`$$

CREATE DEFINER=`root`@`localhost` FUNCTION `fn_isAlreadyRegisteredCheck`(p_msisdn VARCHAR (15), p_url VARCHAR (1000) ) RETURNS VARCHAR(120) CHARSET latin1
BEGIN
    DECLARE p_isAlreadyRegistered VARCHAR(120);
    
	IF ( (SELECT  COUNT(*)  FROM    subscriberservices   WHERE MSISDN = p_msisdn  AND STATUS = 'Registered') >0 ) THEN 
	INSERT INTO logforunregisteredrenewtry  VALUES ( DEFAULT, p_msisdn,  p_url, DEFAULT, DEFAULT );
	SET p_isAlreadyRegistered = 'YES';
  ELSE 
	SET p_isAlreadyRegistered = 'NO';
  END IF;
	
	RETURN p_isAlreadyRegistered;
    END$$

DELIMITER ;
```
