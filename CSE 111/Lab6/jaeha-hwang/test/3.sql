SELECT COUNT(DISTINCT ps_partkey) FROM partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = 3 AND ps_partkey IN (
SELECT DISTINCT ps_partkey FROM partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = 3
GROUP BY ps_partkey
HAVING COUNT(ps_suppkey) > 1)