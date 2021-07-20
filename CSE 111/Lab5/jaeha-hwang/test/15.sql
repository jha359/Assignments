SELECT(SELECT SUM(l_extendedprice*(1-l_discount)) FROM lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
WHERE n_regionkey = 3 AND strftime('%Y', l_shipdate) = '1996' AND s_nationkey = 24)/
(SELECT SUM(l_extendedprice*(1-l_discount)) FROM lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
WHERE n_regionkey = 3 AND strftime('%Y', l_shipdate) = '1996')