SELECT r_name, COUNT(c_custkey) FROM region, customer
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
WHERE (NOT c_custkey IN (SELECT o_custkey FROM orders)) AND 
(c_acctbal > (SELECT AVG(c_acctbal) FROM customer)) AND 
r_regionkey = n_regionkey
GROUP BY r_name