.eqp on
.expert

CREATE INDEX supplier_idx_s_acctbal ON supplier(s_acctbal DESC);
select max(s_acctbal)
from supplier;
