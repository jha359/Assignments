
SELECT s_name, o_orderpriority, COUNT(o_orderkey) FROM supplier, orders
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey AND nation.n_regionkey = 1
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey AND lineitem.l_suppkey = supplier.s_suppkey
GROUP BY s_name, o_orderpriority