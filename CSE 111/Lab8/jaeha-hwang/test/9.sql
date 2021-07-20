.eqp on
.expert

CREATE INDEX nation_idx_n_name ON nation(n_name);
select n_name, min(s_acctbal)
from supplier, nation
where s_nationkey = n_nationkey
group by n_name
having count(*) < 3;
