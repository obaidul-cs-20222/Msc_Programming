--plsql7.sql : write a program in PL/SQL to input --5 arbitrary numbers and store in 1-dim
--araay. find (i) average value,(ii) Standard deviation. display
--results on screen

DECLARE
	TYPE aarrays IS VARRAY(5) of INTEGER;
	s INTEGER:=0;
	av NUMBER(5,2);
	sdev NUMBER(5,2);
	i INTEGER;
	a aarrays;
	n INTEGER;
	sdev INTEGER;
BEGIN
	a:=aarrays(5,4,3,2,1);
	n:=a.count();
	FOR i IN 1..n 
	LOOP
	s:=s+a(i);
	END LOOP;
	av:=s/n;
	--to calculating Standard deviation
	sdev:= 0;
	FOR i IN 1..n 
	LOOP
	sdev:=sdev+(a(i)-av)**2;
	END LOOP;
	sdev=SQRT(sdev/n);
	dbms_output.put_line('Sum= '||s||'	Average= '||av);
	dbms_output.put_line('Standard deviation= '||sdev);	
END;
/