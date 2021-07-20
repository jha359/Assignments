SELECT COUNT(DISTINCT l_suppkey) FROM lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
WHERE (c_nationkey = 6 OR c_nationkey = 7) AND l_suppkey IN (
SELECT l_suppkey FROM lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
WHERE (c_nationkey = 6 OR c_nationkey = 7)
GROUP BY l_suppkey
HAVING COUNT(DISTINCT l_orderkey) < 30)