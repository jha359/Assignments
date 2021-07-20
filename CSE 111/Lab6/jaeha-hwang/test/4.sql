SELECT COUNT(DISTINCT ps_suppkey) FROM partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = 3 AND ps_suppkey IN (
SELECT DISTINCT ps_suppkey FROM partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = 3
GROUP BY ps_suppkey
HAVING COUNT(ps_partkey) >= 4)