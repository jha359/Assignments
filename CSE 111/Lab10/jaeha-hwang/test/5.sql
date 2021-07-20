CREATE TRIGGER t5 AFTER DELETE ON part
FOR EACH ROW
BEGIN
    UPDATE partsupp
    DELETE FROM partsupp
    WHERE ps_partkey = OLD.p_partkey;
    UPDATE lineitem
    DELETE FROM lineitem
    WHERE l_partkey = OLD.p_partkey;
END;

DELETE FROM part
WHERE p_partkey IN (
    SELECT ps_partkey FROM partsupp
    INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
    WHERE s_nationkey IN (6, 7));

SELECT n_name, COUNT(ps_partkey) FROM nation, partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = n_nationkey AND n_regionkey = 3
GROUP BY n_name;