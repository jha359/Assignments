SELECT n_name FROM (
SELECT n_name, MAX(moneyspent) FROM (
SELECT n_name, SUM(o_totalprice) AS moneyspent FROM orders, nation
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
WHERE n_nationkey = c_nationkey
GROUP BY n_name
ORDER BY moneyspent DESC))