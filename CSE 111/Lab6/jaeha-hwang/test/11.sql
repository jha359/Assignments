SELECT n_name FROM nation
INNER JOIN customer ON customer.c_nationkey = nation.n_nationkey
GROUP BY n_name
HAVING COUNT(c_custkey) = (
SELECT MAX(custcount) FROM (
SELECT COUNT(c_custkey) as custcount FROM nation, customer
WHERE n_nationkey = c_nationkey
GROUP BY n_name
ORDER BY COUNT(c_custkey) DESC))