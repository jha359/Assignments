CREATE TRIGGER t1 AFTER INSERT ON orders
FOR EACH ROW
BEGIN
    UPDATE orders
    SET o_orderdate = '2020-12-01'
        WHERE o_orderkey = NEW.o_orderkey;
END;

INSERT INTO orders
    SELECT o_orderkey + 159973 AS o_orderkey, o_custkey, o_orderstatus,
    o_totalprice, o_orderdate, o_orderpriority, o_clerk, o_shippriority, o_comment FROM orders
    WHERE o_orderdate LIKE '1995-11-__';

SELECT COUNT(o_orderkey) FROM orders
WHERE o_orderdate LIKE '2020-__-__';
