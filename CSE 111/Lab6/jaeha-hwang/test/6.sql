SELECT s_name, c_name FROM supplier, customer
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
WHERE c_custkey = o_custkey AND o_orderstatus = 'F' AND o_totalprice IN (
SELECT MAX(o_totalprice) FROM orders
WHERE o_orderstatus = 'F')