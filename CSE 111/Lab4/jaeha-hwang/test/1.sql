SELECT c_name, SUM(o_totalprice) FROM customer, orders
WHERE c_custkey = o_custkey
AND c_nationkey = 22 
AND strftime('%Y',o_orderdate) == '1996'
GROUP BY c_name