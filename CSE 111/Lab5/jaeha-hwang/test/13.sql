SELECT o_orderpriority, COUNT(DISTINCT l_orderkey) FROM orders, lineitem
WHERE o_orderkey = l_orderkey AND 
strftime('%Y', o_orderdate) = '1996' AND
strftime('%m', o_orderdate) IN ('10','11','12') AND
julianday(l_receiptdate) > julianday(l_commitdate)
GROUP BY o_orderpriority