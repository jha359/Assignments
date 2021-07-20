
SELECT s_name, COUNT(p_size) FROM supplier, part
INNER JOIN partsupp ON partsupp.ps_partkey = part.p_partkey 
AND partsupp.ps_suppkey = supplier.s_suppkey
WHERE p_size < 30 AND s_nationkey = 18
GROUP BY s_name