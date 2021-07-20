CREATE TRIGGER t2 AFTER UPDATE ON customer
FOR EACH ROW
BEGIN
    UPDATE customer
    SET c_comment = 'Negative balance!!!'
        WHERE c_custkey = NEW.c_custkey;
END;

UPDATE customer
    SET c_acctbal = -100
        WHERE c_nationkey IN (6, 7, 19, 22, 23);

SELECT COUNT(c_custkey) FROM customer
WHERE c_nationkey = 6;