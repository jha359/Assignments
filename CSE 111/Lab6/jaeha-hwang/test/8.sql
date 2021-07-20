SELECT COUNT(DISTINCT o_custkey) FROM orders
WHERE o_orderkey NOT IN (
SELECT o_orderkey FROM orders
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
WHERE n_regionkey != 2)