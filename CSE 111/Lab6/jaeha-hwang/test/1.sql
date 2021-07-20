SELECT strftime('%m', l_shipdate), SUM(l_quantity) FROM lineitem
WHERE strftime('%Y', l_shipdate) = '1997'
GROUP BY strftime('%m', l_shipdate)