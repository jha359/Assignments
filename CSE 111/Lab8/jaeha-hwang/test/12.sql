.eqp on
.expert

CREATE INDEX region_idx_r_regionkey_r_name ON region(r_regionkey, r_name);
CREATE INDEX orders_idx_o_orderstatus ON orders(o_orderstatus);
select r_name, count(*) as cnt
from orders, customer, nation, region
where o_custkey = c_custkey AND
  c_nationkey = n_nationkey AND
  n_regionkey = r_regionkey AND
  o_orderstatus = 'F'
group by r_name
order by cnt desc;
