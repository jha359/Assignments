SELECT o_orderpriority, COUNT(l_orderkey) FROM orders, lineitem
WHERE strftime('%Y', o_orderdate) = '1996' AND julianday(l_receiptdate) > julianday(l_commitdate)
AND o_orderkey = l_orderkey
GROUP BY o_orderpriority
ORDER BY o_orderpriority DESC