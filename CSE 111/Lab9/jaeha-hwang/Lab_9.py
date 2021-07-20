import sqlite3
from sqlite3 import Error


def openConnection(_dbFile):
    print("++++++++++++++++++++++++++++++++++")
    print("Open database: ", _dbFile)

    conn = None
    try:
        conn = sqlite3.connect(_dbFile)
        print("success")
    except Error as e:
        print(e)

    print("++++++++++++++++++++++++++++++++++")

    return conn

def closeConnection(_conn, _dbFile):
    print("++++++++++++++++++++++++++++++++++")
    print("Close database: ", _dbFile)

    try:
        _conn.close()
        print("success")
    except Error as e:
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View1(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V1")

    try:
        view = """
        CREATE VIEW V1 AS
        SELECT c_custkey, c_name, c_address, c_phone, c_acctbal, c_mktsegment, c_comment, n_name AS c_nation, r_name AS c_region FROM customer, nation, region
        WHERE c_nationkey = n_nationkey AND n_regionkey = r_regionkey;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View2(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V2")

    try:
        view = """
        CREATE VIEW V2 AS
        SELECT s_suppkey, s_name, s_address, s_phone, s_acctbal,
        s_comment, n_name AS s_nation, r_name AS s_region 
        FROM supplier, nation, region
        WHERE s_nationkey = n_nationkey AND n_regionkey = r_regionkey;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View5(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V5")

    try:
        view = """
        CREATE VIEW V5 AS
        SELECT o_orderkey, o_custkey, o_orderstatus, o_totalprice,
        strftime('%Y', o_orderdate) AS o_orderyear, o_orderpriority, 
        o_clerk, o_shippriority, o_comment FROM orders;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View10(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V10")

    try:
        view = """
        CREATE VIEW V10 AS
        SELECT p_type, AVG(l_discount) AS avg_discount FROM part, lineitem
        WHERE p_partkey = l_partkey
        GROUP BY p_type;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View151(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V151")

    try:
        view = """
        CREATE VIEW V151 AS
        SELECT c_custkey, c_name, c_nationkey, c_acctbal FROM customer
        WHERE c_acctbal < 0;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def create_View152(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Create V152")

    try:
        view = """
        CREATE VIEW V152 AS
        SELECT s_suppkey, s_name, s_nationkey, s_acctbal FROM supplier
        WHERE s_acctbal < 0;
        """

        cur = _conn.cursor()
        cur.execute(view)
        
        _conn.commit()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q1(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q1")

    try:
        sql = """
        SELECT c_name, ROUND(SUM(o_totalprice), 2) FROM V1, orders
        WHERE c_custkey = o_custkey AND c_nation = 'RUSSIA' AND strftime('%Y', o_orderdate) = '1996'
        GROUP BY c_name
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/1.out', 'w')

        for x in result:
            l = '{:<18}|{:<10}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q2(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q2")

    try:
        sql = """
        SELECT s_nation, COUNT(*) FROM V2
        GROUP BY s_nation
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/2.out', 'w')

        for x in result:
            l = '{:<1}|{:<10}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q3(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q3")

    try:
        sql = """
        SELECT c_nation, COUNT(o_custkey) FROM V1, orders
        WHERE c_custkey = o_custkey AND c_region = 'ASIA'
        GROUP BY c_nation
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/3.out', 'w')

        for x in result:
            l = '{:<1}|{:<10}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)
    print("++++++++++++++++++++++++++++++++++")


def Q4(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q4")

    try:
        sql = """
        SELECT s_name, COUNT(*) FROM V2, part, partsupp
        WHERE s_suppkey = ps_suppkey AND ps_partkey = p_partkey
        AND p_size < 30 AND s_nation = 'CHINA'
        GROUP BY s_name;
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/4.out', 'w')

        for x in result:
            l = '{:<1}|{:<10}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)
    print("++++++++++++++++++++++++++++++++++")


def Q5(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q5")

    try:
        sql = """
        SELECT COUNT(*) FROM V1, V5
        WHERE c_custkey = o_custkey AND c_nation = 'PERU' AND o_orderyear = '1996'
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/5.out', 'w')

        for x in result:
            l = '{:<1}'.format(x[0])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q6(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q6")

    try:
        sql = """
        SELECT s_name, o_orderpriority, COUNT(*) FROM supplier, V5, nation, lineitem
        WHERE n_nationkey = s_nationkey AND n_regionkey = 1 
        AND l_orderkey = o_orderkey AND l_suppkey = s_suppkey
        GROUP BY s_name, o_orderpriority
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/6.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}|{:<1}'.format(x[0],x[1],x[2])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q7(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q7")

    try:
        sql = """
        SELECT c_nation, o_orderstatus, COUNT(*) FROM V1, V5
        WHERE c_custkey = o_custkey AND c_region = 'EUROPE'
        GROUP BY c_nation, o_orderstatus
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/7.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}|{:<1}'.format(x[0],x[1],x[2])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)
    print("++++++++++++++++++++++++++++++++++")


def Q8(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q8")

    try:
        sql = """
        SELECT s_nation, COUNT(DISTINCT o_orderkey) FROM V2, V5, lineitem
        WHERE o_orderyear = '1994' AND o_orderstatus = 'F' AND o_orderkey = l_orderkey AND l_suppkey = s_suppkey
        GROUP BY s_nation
        HAVING COUNT(DISTINCT o_orderkey) > 300;
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/8.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q9(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q9")

    try:
        sql = """
        SELECT COUNT(DISTINCT o_clerk) FROM V2, V5, lineitem
        WHERE o_orderkey = l_orderkey AND l_suppkey = s_suppkey AND s_nation = 'CANADA';
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/9.out', 'w')

        for x in result:
            l = '{:<1}'.format(x[0])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)
    print("++++++++++++++++++++++++++++++++++")


def Q10(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q10")

    try:
        sql = """
        SELECT p_type, ROUND(avg_discount, 16) FROM V10
        WHERE substr(p_type, 1, 5) = 'PROMO'
        GROUP BY p_type
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/10.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q11(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q11")

    try:
        sql = """
        SELECT s_nation, s_name, MAX(s_acctbal) FROM V2
        GROUP BY s_nation
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/11.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}|{:<1}'.format(x[0],x[1],x[2])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q12(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q12")

    try:
        sql = """
        SELECT s_nation, ROUND(AVG(s_acctbal), 11) FROM V2
        GROUP BY s_nation
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/12.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}'.format(x[0],x[1])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q13(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q13")

    try:
        sql = """
        SELECT COUNT(*) FROM V1, lineitem, orders
        WHERE o_orderkey = l_orderkey AND o_custkey = c_custkey AND l_suppkey IN (
            SELECT s_suppkey FROM V2
            WHERE s_region = 'ASIA')
        AND c_custkey IN (
            SELECT c_custkey FROM V1
            WHERE c_nation = 'ARGENTINA')
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/13.out', 'w')

        for x in result:
            l = '{:<1}'.format(x[0])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q14(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q14")

    try:
        sql = """
        SELECT c_region, s_region, COUNT(o_orderkey) FROM V1, V2, orders, lineitem
        WHERE l_orderkey = o_orderkey AND l_suppkey = s_suppkey
        AND c_custkey = o_custkey
        GROUP BY c_region, s_region
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/14.out', 'w')

        for x in result:
            l = '{:<1}|{:<1}|{:<1}'.format(x[0],x[1],x[2])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def Q15(_conn):
    print("++++++++++++++++++++++++++++++++++")
    print("Q15")

    try:
        sql = """
        SELECT COUNT(DISTINCT o_orderkey) FROM orders, lineitem
        WHERE o_orderkey = l_orderkey
        AND o_custkey IN (
            SELECT c_custkey FROM V151)
        AND l_suppkey IN (
            SELECT s_suppkey FROM V152)
        """

        cur = _conn.cursor()
        cur.execute(sql)
        result = cur.fetchall()
        output = open('output/15.out', 'w')

        for x in result:
            l = '{:<1}'.format(x[0])
            print(l, file = output)
        output.close()
        print("success")
    except Error as e:
        _conn.rollback()
        print(e)

    print("++++++++++++++++++++++++++++++++++")


def main():
    database = r"data/tpch.sqlite"

    # create a database connection
    conn = openConnection(database)
    with conn:
        create_View1(conn)
        Q1(conn)

        create_View2(conn)
        Q2(conn)

        Q3(conn)
        Q4(conn)

        create_View5(conn)
        Q5(conn)

        Q6(conn)
        Q7(conn)
        Q8(conn)
        Q9(conn)

        create_View10(conn)
        Q10(conn)

        Q11(conn)
        Q12(conn)
        Q13(conn)
        Q14(conn)

        create_View151(conn)
        create_View152(conn)
        Q15(conn)

    closeConnection(conn, database)


if __name__ == '__main__':
    main()
