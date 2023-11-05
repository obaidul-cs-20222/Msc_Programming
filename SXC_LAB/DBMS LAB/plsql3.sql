--plsql_3.sql: Write a program in PL/SQL to input
--roll, total(0-100). Calculate grade as follows:
--total>=70 then grade='A', total>=60 and <70 grade='B'
--total>=50 and <60 grade='C', total>=40 and <50
--grade='D'. total<40 grade='F'.Print roll,total,grade.

DECLARE
roll INTEGER :=&roll;
total INTEGER :=&total;
grade varchar2(5);

BEGIN
--To calculate grade
	IF(total>=70)THEN
	grade :='A';
	ELSIF(total>=60)THEN
	grade :='B';
	ELSIF(total>=50)THEN
	grade :='C';
	ELSIF(total>=40)THEN
	grade :='D';
	ELSE
	grade :='F';
	END IF;
	dbms_output.put_line('Roll='||roll||' Total='||total||' Grade '||grade);
	
END;
/