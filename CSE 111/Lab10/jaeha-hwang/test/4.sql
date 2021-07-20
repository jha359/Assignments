CREATE TRIGGER t41 AFTER INSERT ON lineitem
FOR EACH ROW
BEGIN
    UPDATE orders
    SET o_orderpriority = 'HIGH'
        WHERE o_orderkey = NEW.l_orderkey;
END;

CREATE TRIGGER t42 AFTER DELETE ON lineitem
FOR EACH ROW
BEGIN
    UPDATE orders
    SET o_orderpriority = 'HIGH'
        WHERE o_orderkey = OLD.l_orderkey;
END;

DELETE FROM lineitem
WHERE l_orderkey IN (
    SELECT o_orderkey FROM orders
    WHERE o_orderdate LIKE '1996-11-__');

SELECT COUNT(o_orderkey) FROM orders
WHERE o_orderpriority = 'HIGH' AND strftime('%Y', o_orderdate) = '1996'
AND strftime('%m', o_orderdate) IN ('11');