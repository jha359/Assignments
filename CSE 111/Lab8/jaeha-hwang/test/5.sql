.eqp on
.expert

CREATE INDEX customer_idx_c_mktsegment ON customer(c_mktsegment);
SELECT
    c_mktsegment,
    min(c_acctbal),
    max(c_acctbal),
    avg(c_acctbal),
    sum(c_acctbal) as total
from customer
group by c_mktsegment
order by total desc;
