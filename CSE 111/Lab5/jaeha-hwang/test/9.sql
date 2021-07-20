SELECT COUNT(ps_partkey) FROM partsupp
INNER JOIN supplier ON supplier.s_suppkey = partsupp.ps_suppkey
WHERE s_nationkey = 3 AND
(ps_supplycost * ps_availqty) IN (
SELECT (ps_supplycost * ps_availqty) AS ps_totalval FROM partsupp
ORDER BY ps_totalval DESC
LIMIT (8000 * 0.03))