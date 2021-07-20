SELECT n_name, MIN(s_acctbal) FROM nation, supplier
WHERE n_nationkey == s_nationkey
GROUP BY s_nationkey
HAVING COUNT(s_nationkey) < 3;