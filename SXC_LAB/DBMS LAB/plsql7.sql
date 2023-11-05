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
BEGIN
	a:=aarrays(50,40,30,20,10);
	n:=a.count();
	FOR i IN 1..n 
	LOOP
	s:=s+a(i);
	END LOOP;
	av:=s/n;
	dbms_output.put_line('Sum= '||s||'	Average= '||av);
	
END;
/