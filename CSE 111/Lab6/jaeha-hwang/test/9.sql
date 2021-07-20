SELECT DISTINCT p_name FROM part
INNER JOIN lineitem ON lineitem.l_partkey = part.p_partkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation n1 ON n1.n_nationkey = customer.c_nationkey
INNER JOIN partsupp ON partsupp.ps_partkey = part.p_partkey
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
INNER JOIN nation n2 ON n2.n_nationkey = supplier.s_nationkey
WHERE (n1.n_regionkey = 1) AND (n2.n_regionkey = 2)
GROUP BY p_name
HAVING COUNT(DISTINCT ps_suppkey) = 4