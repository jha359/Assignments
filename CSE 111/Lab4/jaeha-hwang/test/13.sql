SELECT COUNT(l_orderkey) FROM lineitem
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
WHERE c_nationkey = 1 AND n_regionkey = 2