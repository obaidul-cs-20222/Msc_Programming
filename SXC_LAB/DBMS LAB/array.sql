-- array_2.sql : Write a program in PL/SQL to store
-- 10 arbitrary numbers in 1-dim array a(). Input
--a number say 'num' to be searched in that array.
--Apply linear search algorithm to search num in given
-- array . the program should display the position where 
-- the number found. If num not found then it will
-- display num not found


SET SERVEROUTPUT ON
SET VERIFY OFF

DECLARE
	TYPE aarray IS VARRAY(10) of INTEGER;
	num INTEGER :=&num; -- num=number to be searched
	cnt INTEGER :=0; --cnt=number of times num;
	i INTEGER;
	a aarray;
	n INTEGER;
BEGIN
	a:=aarray(10,20,10,30,10,20,10,40,10,20);
	n := a.count();
	FOR i IN 1..n
	LOOP
		IF (num=a(i))
		THEN
		cnt := cnt+1;
		dbms_output.put_line(num||' found at position= '||i);
		END IF;
	END LOOP;
	IF(cnt!=0)
	THEN
	  dbms_output.put_line(' Number of Times= '||num|| ' found = '||cnt);
	ELSE
		dbms_output.put_line(' Not Found ');
	
	END IF;
END;
/