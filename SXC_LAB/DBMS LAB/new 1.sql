SET SERVEROUTPUT ON;
SET VERIFY OFF;

DECLARE
emp_rec employee%rowtype;
CURSOR emp_cur IS
SELECT * FROM employee WHERE esal>30000;
BEGIN
OPEN emp_cur;
FETCH emp_cur INTO emp_rec;
dbms_output.put_line(emp_rec.ename||' '||emp_rec.esal);
CLOSE emp_cur;
END;
-- -------------------------------------------------------------------------------------

DECLARE
CURSOR emp_cur IS
SELECT ename,edept,esal FROM employee;
emp_rec emp_cur%rowtype;

BEGIN
IF NOT emp_cur%ISOPEN THEN
OPEN emp_cur;
END IF;
LOOP
FETCH emp_cur INTO emp_rec;
EXIT WHEN emp_cur%NOTFOUND;
dbms_output.put_line(emp_rec.ename||' '||emp_rec.esal);
END LOOP;
END;


-- (Q) increase the salary of employee by 15% if salary is less  than 40k else increase it
-- by 12% use a curor with a FOR UPDATE clause .
-- Update the salary with a WHERE CURRENT OF clause in a CURSOR FOR LOOP (cursor FOR loop problem)


DECLARE
CURSOR emp_cur IS
SELECT eid,ename,esal
FROM employee

FOR UPDATE;

incr NUMBER;
BEGIN

FOR emp_rec IN emp_cur LOOP 
	
		IF emp_rec.esal<40000 THEN
		INCR:=0.15;
		ELSE
			incr:= 0.12;
		END IF;
UPDATE employee
SET  esal=esal+esal*incr;
END LOOP;
END;