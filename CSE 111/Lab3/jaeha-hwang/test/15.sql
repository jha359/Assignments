SELECT strftime('%Y', o_orderdate), r_name, COUNT(o_orderpriority) FROM orders, region
INNER JOIN nation ON region.r_regionkey == nation.n_regionkey
INNER JOIN supplier ON nation.n_nationkey == supplier.s_nationkey
INNER JOIN lineitem ON supplier.s_suppkey == lineitem.l_suppkey AND orders.o_orderkey == lineitem.l_orderkey
WHERE o_orderpriority == '1-URGENT'
GROUP BY strftime('%Y', o_orderdate), r_name
ORDER BY COUNT(o_orderpriority) ASC