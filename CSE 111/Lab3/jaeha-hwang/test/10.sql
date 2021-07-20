SELECT SUM(o_totalprice) FROM orders
WHERE strftime('%Y', o_orderdate) == "1996" AND o_custkey IN (
SELECT c_custkey FROM customer
WHERE c_nationkey IN (
SELECT n_nationkey FROM nation
WHERE n_regionkey == 3))