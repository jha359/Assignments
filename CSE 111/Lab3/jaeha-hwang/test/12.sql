SELECT r_name, COUNT(o_orderstatus) FROM region, orders
INNER JOIN nation ON nation.n_regionkey == region.r_regionkey
INNER JOIN customer ON customer.c_nationkey == nation.n_nationkey AND customer.c_custkey == orders.o_custkey
WHERE o_orderstatus == 'F'
GROUP BY r_name
ORDER BY COUNT(o_orderstatus) DESC