SELECT COUNT(o_orderkey) FROM orders
INNER JOIN customer ON orders.o_custkey = customer.c_custkey AND customer.c_nationkey = 17
WHERE strftime('%Y', o_orderdate) = '1996'