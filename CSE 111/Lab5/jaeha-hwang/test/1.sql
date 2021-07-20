SELECT COUNT(c_custkey) FROM customer
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
WHERE NOT (n_regionkey = 3 OR n_regionkey = 0)