.eqp on
.expert

CREATE INDEX lineitem_idx_l_orderkey_l_receiptdate ON lineitem(l_orderkey, l_receiptdate);
CREATE INDEX orders_idx_o_custkey_o_orderkey ON orders(o_custkey, o_orderkey);
CREATE INDEX customer_idx_c_name_c_custkey ON customer(c_name, c_custkey);
SELECT l_receiptdate, count(*) as no_items
from orders, customer, lineitem
where o_custkey = c_custkey AND
	o_orderkey = l_orderkey AND
	c_name = 'Customer#000000106'
group by l_receiptdate;
