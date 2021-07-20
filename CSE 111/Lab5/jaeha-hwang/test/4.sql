SELECT n_name, COUNT(DISTINCT c_custkey), COUNT(DISTINCT s_suppkey) FROM nation, customer, supplier
WHERE (c_nationkey = n_nationkey AND n_regionkey = 3)
AND (s_nationkey = n_nationkey AND n_regionkey = 3)
GROUP BY n_name