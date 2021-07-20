SELECT n_name, o_orderstatus, COUNT(o_orderkey) FROM nation, orders
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
AND customer.c_nationkey = nation.n_nationkey
WHERE n_regionkey = 3
GROUP BY n_name, o_orderstatus