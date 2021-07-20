SELECT s_name, p_size, MIN(ps_supplycost) FROM supplier, part, partsupp
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
WHERE (substr(p_type, length(p_type) - 4, length(p_type)) = 'STEEL')
AND s_suppkey = ps_suppkey AND ps_partkey = p_partkey
AND n_regionkey = 1
GROUP BY p_size