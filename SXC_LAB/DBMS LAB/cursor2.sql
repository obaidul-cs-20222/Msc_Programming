SET SERVEROUTPUT ON
SET VERIFY OFF
DECLARE
naam employee.ename%TYPE;
m_naam manager.mname%TYPE;
BEGIN
SELECT ename,mname
INTO naam, m_naam
FROM employee e,manager m
WHERE e.mid=m.mid
 AND e.eid='E03';
DBMS_OUTPUT.put_line(naam||' is assigned under '||m_naam);
END;
/