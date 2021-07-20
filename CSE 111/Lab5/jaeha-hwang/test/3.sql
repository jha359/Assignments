SELECT MAX(l_discount) FROM lineitem
INNER JOIN orders ON lineitem.l_orderkey = orders.o_orderkey
WHERE strftime('%Y', o_orderdate) = '1995' AND strftime('%m', o_orderdate) = '05'
AND l_discount < (
SELECT AVG(l_discount) FROM lineitem)