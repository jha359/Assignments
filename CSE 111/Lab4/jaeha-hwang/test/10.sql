SELECT p_type, AVG(l_discount) FROM part, lineitem
WHERE p_partkey = l_partkey AND substr(p_type, 1, 5) = 'PROMO'
GROUP BY p_type
