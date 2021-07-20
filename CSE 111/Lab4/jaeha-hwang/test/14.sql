SELECT DISTINCT r2.r_name, r1.r_name, COUNT(o_orderkey) FROM region r1, region r2, orders
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation n1 ON n1.n_nationkey = supplier.s_nationkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation n2 ON n2.n_nationkey = customer.c_nationkey
WHERE n1.n_regionkey = r1.r_regionkey AND n2.n_regionkey = r2.r_regionkey
GROUP BY r2.r_name, r1.r_name