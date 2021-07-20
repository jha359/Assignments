SELECT COUNT(DISTINCT o_custkey) FROM orders
WHERE strftime('%m', o_orderdate) = '08' AND strftime('%Y', o_orderdate) = '1996'
AND o_custkey IN (
SELECT o_custkey FROM orders
WHERE strftime('%m', o_orderdate) = '08' AND strftime('%Y', o_orderdate) = '1996'
GROUP BY o_custkey
HAVING COUNT(o_orderkey) <= 2)