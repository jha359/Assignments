.eqp on
.expert

CREATE INDEX customer_idx_c_nationkey_c_custkey ON customer(c_nationkey, c_custkey);
CREATE INDEX nation_idx_n_name_n_nationkey ON nation(n_name, n_nationkey);
CREATE INDEX orders_idx_o_orderpriority_o_custkey ON orders(o_orderpriority, o_custkey);
select count(*)
from customer, nation, orders
where c_nationkey = n_nationkey AND
    c_custkey = o_custkey AND
    o_orderpriority = '1-URGENT' AND
    n_name = 'FRANCE' AND
    (o_orderdate like '1994-__-__' or
    o_orderdate like '1995-__-__' or
    o_orderdate like '1996-__-__');
