.eqp on
.expert

CREATE INDEX lineitem_idx_l_orderkey_l_discount ON lineitem(l_orderkey, l_discount);
SELECT o_custkey, COUNT(*)
from lineitem, orders
where l_discount >= 0.05 AND
    l_orderkey = o_orderkey
group by o_custkey
having count(*) >= 70;
