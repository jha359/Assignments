SELECT n_name FROM nation
WHERE n_nationkey IN (
SELECT c_nationkey FROM customer
WHERE c_custkey IN (
SELECT o_custkey FROM orders
WHERE o_orderdate IN ("1995-03-10", "1995-03-12", "1995-03-11")
));
