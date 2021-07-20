SELECT COUNT(DISTINCT s_suppkey) FROM supplier
INNER JOIN partsupp ON partsupp.ps_suppkey = supplier.s_suppkey
INNER JOIN part ON part.p_partkey = partsupp.ps_partkey
WHERE substr(p_type, 1, 15) = 'MEDIUM POLISHED' and p_size IN (3, 23, 36, 49)