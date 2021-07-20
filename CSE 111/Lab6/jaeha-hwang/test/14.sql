SELECT nationname, (export - import) AS ecoexchange FROM (
SELECT n1.n_name AS nationname, COUNT(o1.o_orderkey) AS export FROM nation n1, orders o1
INNER JOIN supplier s1 ON s1.s_nationkey = n1.n_nationkey
INNER JOIN lineitem l1 ON l1.l_suppkey = s1.s_suppkey
INNER JOIN customer c1 ON c1.c_custkey = o1.o_custkey
INNER JOIN nation cn1  ON cn1.n_nationkey = c1.c_nationkey
WHERE o1.o_orderkey = l1.l_orderkey AND strftime('%Y', l1.l_shipdate) = '1996' AND n1.n_nationkey NOT IN (cn1.n_nationkey)
GROUP BY n1.n_name), (
SELECT n2.n_name AS importname, COUNT(o2.o_orderkey) AS import FROM nation n2, orders o2
INNER JOIN customer c2 ON c2.c_nationkey = n2.n_nationkey
INNER JOIN lineitem l2 ON l2.l_orderkey = o2.o_orderkey
INNER JOIN supplier s2 ON s2.s_suppkey = l2.l_suppkey
INNER JOIN nation sn2 ON sn2.n_nationkey = s2.s_nationkey
WHERE c2.c_custkey = o2.o_custkey AND strftime('%Y', l2.l_shipdate) = '1996' AND n2.n_nationkey NOT IN (sn2.n_nationkey)
GROUP BY n2.n_name)
WHERE nationname = importname
ORDER BY ecoexchange DESC