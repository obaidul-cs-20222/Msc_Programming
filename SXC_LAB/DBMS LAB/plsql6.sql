--cursor1.sql: Write a program in PL/SQL to use Cursor
--which will read all data from a table. The program
--will display all records on screen

DECLARE
	name1 table6.name%type;
	email1 table6.email%type;
	mobile1 table6.mobile%type;
	CURSOR MYCURSOR IS SELECT name,email,mobile FROM table6;
	ncnt INTEGER :=0; --ncnt=number of records in table6
BEGIN
	open MYCURSOR;
	LOOP
	FETCH MYCURSOR INTO name1,email1,mobile1;
	ncnt :=ncnt+1;
	EXIT WHEN MYCURSOR%NOTFOUND;
	dbms_output.put_line(name1||' : '||email1 ||' : '||mobile1);
	END LOOP;
	dbms_output.put_line('Number of records availbale: '||ncnt);
	close MYCURSOR;
	
	
END;
/