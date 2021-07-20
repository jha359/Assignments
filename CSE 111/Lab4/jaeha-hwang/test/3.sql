SELECT n_name, COUNT(o_custkey) FROM nation, orders
INNER JOIN customer ON customer.c_custkey == orders.o_custkey AND customer.c_nationkey = nation.n_nationkey
WHERE n_regionkey = 2
GROUP BY n_name