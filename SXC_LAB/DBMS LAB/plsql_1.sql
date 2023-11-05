--plsql_1.sql: write a program in PL/SQL to calculate 
-- f from c/5=(f-32)/9. Print c,f. Choose value of c=0,100
--in step of 10

DECLARE 
	c INTEGER;
	f INTEGER;
BEGIN
	c :=0;
	dbms_output.put_line('C-F Conversation Table');
	WHILE(c<=100)
	LOOP
	f :=9*c/5+32;
	dbms_output.put_line('c='||c||' f='||f);
	c :=c+10;
	END LOOP;





END;
/
