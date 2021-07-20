.eqp on
.expert

CREATE INDEX nation_idx_n_nationkey ON nation(n_nationkey);
CREATE INDEX customer_idx_c_custkey ON customer(c_custkey);
CREATE INDEX orders_idx_o_orderdate ON orders(o_orderdate);
select distinct n_name
from customer, nation, orders
where o_orderdate >= '1995-03-10' AND
	o_orderdate <= '1995-03-12' and
	o_custkey = c_custkey and
	c_nationkey = n_nationkey;
