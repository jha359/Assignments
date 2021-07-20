SELECT s_name FROM supplier
WHERE s_acctbal < 1000 AND s_nationkey IN (
SELECT n_nationkey FROM nation
WHERE n_regionkey = 2);