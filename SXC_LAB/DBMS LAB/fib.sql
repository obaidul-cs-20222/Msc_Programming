--plsql_2.sql : Input n(2-2000). Display all fibonaci numbers <=n

DECLARE 
	n1 INTEGER :=1;
	n2 INTEGER :=1;
	n  INTEGER :=&n;
	n3 INTEGER;
BEGIN
	dbms_output.put_line('Fibonacci Series<='||n||'==>');
	dbms_output.put_line(n1);
	dbms_output.put_line(n2);
	n3 :=n1+n2;
	WHILE(n3<=n)
	LOOP
	dbms_output.put_line(n3);
	n1 :=n2;
	n2 :=n3;
	n3 :=n1+n2;
	END LOOP;
END;
/	
