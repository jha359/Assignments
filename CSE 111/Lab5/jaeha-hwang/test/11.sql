SELECT p_name FROM part
INNER JOIN lineitem ON lineitem.l_partkey = part.p_partkey
WHERE (l_extendedprice * (1-l_discount)) = (
SELECT (l_extendedprice * (1-l_discount)) AS highvalue FROM lineitem
WHERE julianday(l_shipdate) > julianday('1994-10-02')
ORDER BY highvalue DESC)