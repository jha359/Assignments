SELECT o_custkey, COUNT(l_discount) FROM orders, lineitem
WHERE o_orderkey == l_orderkey AND l_discount >= 0.05
GROUP BY o_custkey
HAVING COUNT(l_discount) >= 70