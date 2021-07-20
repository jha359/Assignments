SELECT r_name FROM region
INNER JOIN nation ON nation.n_regionkey = region.r_regionkey
INNER JOIN customer ON customer.c_nationkey = nation.n_nationkey
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_nationkey = nation.n_nationkey
GROUP BY r_name
HAVING SUM(l_extendedprice)
ORDER BY SUM(l_extendedprice) DESC
LIMIT 1