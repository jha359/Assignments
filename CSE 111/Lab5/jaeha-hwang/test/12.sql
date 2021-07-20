SELECT SUM(ps_supplycost) FROM partsupp
INNER JOIN part ON part.p_partkey = partsupp.ps_partkey
INNER JOIN lineitem ON lineitem.l_suppkey = partsupp.ps_suppkey AND lineitem.l_partkey = partsupp.ps_partkey
WHERE p_retailprice < 1000 AND strftime('%Y',l_shipdate) = '1996' AND 
l_suppkey NOT IN (SELECT DISTINCT l_suppkey FROM lineitem
WHERE l_extendedprice < 2000 AND strftime('%Y',l_shipdate) = '1995')