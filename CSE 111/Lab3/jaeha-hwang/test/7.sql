SELECT DISTINCT l_receiptdate, COUNT(l_receiptdate) FROM lineitem
WHERE l_orderkey IN (
SELECT o_orderkey FROM orders
WHERE o_custkey IN (
SELECT c_custkey FROM customer
WHERE c_name = "Customer#000000106"))
GROUP BY l_receiptdate;