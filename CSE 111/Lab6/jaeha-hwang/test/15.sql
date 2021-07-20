SELECT nationname, (export95 - import95) - (export94 - import94), (export96 - import96) - (export95 - import95) FROM (
SELECT n1.n_name AS nationname, COUNT(o1.o_orderkey) AS export96 FROM nation n1, orders o1
INNER JOIN supplier s1 ON s1.s_nationkey = n1.n_nationkey
INNER JOIN lineitem l1 ON l1.l_suppkey = s1.s_suppkey
INNER JOIN customer c1 ON c1.c_custkey = o1.o_custkey
INNER JOIN nation cn1  ON cn1.n_nationkey = c1.c_nationkey
WHERE o1.o_orderkey = l1.l_orderkey AND strftime('%Y', l1.l_shipdate) = '1996' AND n1.n_nationkey NOT IN (cn1.n_nationkey)
GROUP BY n1.n_name), (
SELECT n2.n_name AS importname, COUNT(o2.o_orderkey) AS import96 FROM nation n2, orders o2
INNER JOIN customer c2 ON c2.c_nationkey = n2.n_nationkey
INNER JOIN lineitem l2 ON l2.l_orderkey = o2.o_orderkey
INNER JOIN supplier s2 ON s2.s_suppkey = l2.l_suppkey
INNER JOIN nation sn2 ON sn2.n_nationkey = s2.s_nationkey
WHERE c2.c_custkey = o2.o_custkey AND strftime('%Y', l2.l_shipdate) = '1996' AND n2.n_nationkey NOT IN (sn2.n_nationkey)
GROUP BY n2.n_name), (
SELECT n3.n_name AS nationname2, COUNT(o3.o_orderkey) AS export95 FROM nation n3, orders o3
INNER JOIN supplier s3 ON s3.s_nationkey = n3.n_nationkey
INNER JOIN lineitem l3 ON l3.l_suppkey = s3.s_suppkey
INNER JOIN customer c3 ON c3.c_custkey = o3.o_custkey
INNER JOIN nation cn3  ON cn3.n_nationkey = c3.c_nationkey
WHERE o3.o_orderkey = l3.l_orderkey AND strftime('%Y', l3.l_shipdate) = '1995' AND n3.n_nationkey NOT IN (cn3.n_nationkey)
GROUP BY n3.n_name), (
SELECT n4.n_name AS importname2, COUNT(o4.o_orderkey) AS import95 FROM nation n4, orders o4
INNER JOIN customer c4 ON c4.c_nationkey = n4.n_nationkey
INNER JOIN lineitem l4 ON l4.l_orderkey = o4.o_orderkey
INNER JOIN supplier s4 ON s4.s_suppkey = l4.l_suppkey
INNER JOIN nation sn4 ON sn4.n_nationkey = s4.s_nationkey
WHERE c4.c_custkey = o4.o_custkey AND strftime('%Y', l4.l_shipdate) = '1995' AND n4.n_nationkey NOT IN (sn4.n_nationkey)
GROUP BY n4.n_name), (
SELECT n5.n_name AS nationname3, COUNT(o5.o_orderkey) AS export94 FROM nation n5, orders o5
INNER JOIN supplier s5 ON s5.s_nationkey = n5.n_nationkey
INNER JOIN lineitem l5 ON l5.l_suppkey = s5.s_suppkey
INNER JOIN customer c5 ON c5.c_custkey = o5.o_custkey
INNER JOIN nation cn5  ON cn5.n_nationkey = c5.c_nationkey
WHERE o5.o_orderkey = l5.l_orderkey AND strftime('%Y', l5.l_shipdate) = '1994' AND n5.n_nationkey NOT IN (cn5.n_nationkey)
GROUP BY n5.n_name), (
SELECT n6.n_name AS importname3, COUNT(o6.o_orderkey) AS import94 FROM nation n6, orders o6
INNER JOIN customer c6 ON c6.c_nationkey = n6.n_nationkey
INNER JOIN lineitem l6 ON l6.l_orderkey = o6.o_orderkey
INNER JOIN supplier s6 ON s6.s_suppkey = l6.l_suppkey
INNER JOIN nation sn6 ON sn6.n_nationkey = s6.s_nationkey
WHERE c6.c_custkey = o6.o_custkey AND strftime('%Y', l6.l_shipdate) = '1994' AND n6.n_nationkey NOT IN (sn6.n_nationkey)
GROUP BY n6.n_name)
WHERE nationname = importname AND nationname = nationname2 AND nationname = importname2 AND nationname = nationname3 AND nationname = importname3