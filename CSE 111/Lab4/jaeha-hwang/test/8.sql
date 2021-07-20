SELECT DISTINCT n_name, COUNT(DISTINCT l_orderkey) FROM nation, lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
WHERE s_nationkey = n_nationkey AND strftime('%Y', o_orderdate) = '1994' AND o_orderstatus = 'F'
GROUP BY n_name
HAVING COUNT(DISTINCT l_orderkey) > 300