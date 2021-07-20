.eqp on
.expert

CREATE INDEX supplier_idx_s_nationkey_s_acctbal ON supplier(s_nationkey, s_acctbal);
CREATE INDEX nation_idx_n_regionkey_n_nationkey ON nation(n_regionkey, n_nationkey);
CREATE INDEX region_idx_r_name_r_regionkey ON region(r_name, r_regionkey);
SELECT s_name
from supplier, nation, region
where s_acctbal < 1000 AND
    s_nationkey = n_nationkey AND
    n_regionkey = r_regionkey AND
    r_name = 'ASIA';
