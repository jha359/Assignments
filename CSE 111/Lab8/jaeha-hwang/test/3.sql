.eqp on
.expert

CREATE INDEX lineitem_idx_l_returnflag_l_receiptdate ON lineitem(l_returnflag, l_receiptdate);
select *
from lineitem
where l_returnflag = 'R' AND
    l_receiptdate = '1992-05-30';
