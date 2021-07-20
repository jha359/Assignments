SELECT COUNT(DISTINCT o_orderkey) FROM orders
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
WHERE c_acctbal < 0 AND s_acctbal < 0