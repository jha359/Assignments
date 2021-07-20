SELECT COUNT(DISTINCT ps_suppkey) FROM partsupp
INNER JOIN part ON part.p_partkey = partsupp.ps_partkey
WHERE p_retailprice = (
SELECT DISTINCT MIN(p_retailprice) FROM part)