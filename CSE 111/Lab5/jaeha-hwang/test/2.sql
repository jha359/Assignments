SELECT r1.r_name, COUNT(s_acctbal) FROM region r1, supplier, nation
WHERE s_nationkey = n_nationkey AND n_regionkey = r1.r_regionkey AND s_acctbal > (
SELECT AVG(s_acctbal) FROM supplier, region r2, nation
WHERE s_nationkey = n_nationkey AND n_regionkey = r2.r_regionkey AND r2.r_name = r1.r_name)
GROUP BY r_name

