SET SERVEROUTPUT ON
SET VERIFY OFF
DECLARE
naam employee.ename%TYPE;
BEGIN
SELECT ename
INTO naam
FROM employee
WHERE eid='E04';
DBMS_OUTPUT.put_line(naam);
EXCEPTION
WHEN NO_DATA_FOUND THEN
DBMS_OUTPUT.put_line('Employee Not Found');
END;
/