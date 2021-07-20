SELECT r1.r_name, r2.r_name, strftime('%Y', l_shipdate), SUM(l_extendedprice*(1-l_discount))
FROM region r1, region r2, lineitem
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation n1 ON n1.n_nationkey = supplier.s_nationkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation n2 ON n2.n_nationkey = customer.c_nationkey
WHERE strftime('%Y', l_shipdate) IN ('1995','1996')
AND n1.n_regionkey = r1.r_regionkey
AND n2.n_regionkey = r2.r_regionkey
GROUP BY r1.r_name, r2.r_name, strftime('%Y', l_shipdate)