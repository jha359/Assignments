CREATE TRIGGER t3 AFTER UPDATE ON customer
FOR EACH ROW
WHEN OLD.c_acctbal < 0 AND NEW.c_acctbal > 0
BEGIN
    UPDATE customer
    SET c_comment = 'Positive balance'
        WHERE c_custkey = NEW.c_custkey;
END;

UPDATE customer
SET c_acctbal = 100
    WHERE c_nationkey = 19;

SELECT COUNT(c_custkey) FROM customer
INNER JOIN nation ON nation.n_nationkey = c_nationkey
WHERE c_acctbal < 0 AND n_regionkey = 3;