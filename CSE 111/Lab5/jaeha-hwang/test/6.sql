SELECT p_mfgr FROM part
INNER JOIN partsupp ON partsupp.ps_partkey = part.p_partkey
WHERE ps_suppkey = 53 AND ps_availqty = (
SELECT MIN(ps_availqty) FROM partsupp
WHERE ps_suppkey = 53)