SELECT AVG(c_acctbal) FROM customer
WHERE c_nationkey IN (
SELECT n_nationkey FROM nation
WHERE n_regionkey == 0)
AND c_mktsegment == 'MACHINERY'