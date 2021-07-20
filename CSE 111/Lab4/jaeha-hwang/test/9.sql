SELECT COUNT(DISTINCT o_clerk) FROM orders
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
WHERE s_nationkey = 3