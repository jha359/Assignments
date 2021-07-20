SELECT n_name FROM (
SELECT n_name, MAX(totalsell) FROM (
SELECT n_name, SUM(l_extendedprice) AS totalsell FROM nation, lineitem
INNER JOIN supplier ON supplier.s_nationkey = nation.n_nationkey
WHERE l_suppkey = s_suppkey AND strftime('%Y', l_shipdate) = '1996'
GROUP BY n_name))