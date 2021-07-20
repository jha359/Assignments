SELECT COUNT(o_orderpriority) FROM orders
WHERE strftime('%Y', o_orderdate) IN ('1994','1995','1996') AND o_custkey IN (
SELECT c_custkey FROM customer
WHERE c_nationkey == 6)
AND o_orderpriority == '1-URGENT'