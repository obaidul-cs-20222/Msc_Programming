-- array_2.sql : Write a program in PL/SQL to store
-- 10 arbitrary numbers in 1-dim array a(). Input
--a number say 'num' to be searched in that array.
-- Sort the array in ascending order.
-- display Unsorted list and also sorted list.

DECLARE 
	TYPE aarray IS VARRAY(10) of INTEGER;
	i INTEGER;
	t INTEGER;
	m INTEGER;
	flag INTEGER;
	a aarray;
	n INTEGER;
BEGIN
	a :=aarray(10,20,10,30,10,20,10,40,10,20);
	n :=a.count();
	dbms_output.put_line('Elements in Unsorted List-->');
	FOR i IN 1..n
	LOOP
		dbms_output.put_line(a(i)||' ');
	END LOOP;
	--Bubble Sort Routine starts
	m:=n;
	flag:=0;
		WHILE(flag=0)
		LOOP
			flag :=1;
			m :=m-1;
			FOR i IN 1..m
			LOOP
				IF(a(i)>a(i+1)) THEN
				t :=a(i);
				a(i):=a(i+1);
				a(i+1):=t;
				flag :=0;
				END IF;
			END LOOP;
		END LOOP;
	dbms_output.put_line('Elements in sorted order ');
	FOR i IN 1..n
	LOOP
	dbms_output.put_line(a(i));
	END LOOP;
END;
/