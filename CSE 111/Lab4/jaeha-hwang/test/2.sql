SELECT n_name, COUNT(s_nationkey) FROM nation, supplier
WHERE s_nationkey == n_nationkey
GROUP BY n_name