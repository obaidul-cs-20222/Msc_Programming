--plsql5.sql : Write PL/SQL code to input 5-10 records
--in table6

DECLARE
ncnt INTEGER :=0; --ncnt=number of records added to table 3

BEGIN 
	INSERT INTO table6(name,email,mobile)
	VALUES('D.K.Sinha','dks@gmail.com','9831012345');
	ncnt := ncnt+1;
	
	INSERT INTO table6(name,email,mobile)
	VALUES('S.K.Basu','skb@gmail.com','8777741324');
	ncnt := ncnt+1;
	
	INSERT INTO table6(name,email,mobile)
	VALUES('P.K.Mehta','pkm@gmail.com','9431282345');
	ncnt := ncnt+1;
	
	INSERT INTO table6(name,email,mobile)
	VALUES('S.K.Das','skd@gmail.com','8985910324');
	ncnt := ncnt+1;
	
	INSERT INTO table6(name,email,mobile)
	VALUES('B.K.Mathur','bkm@gmail.com','9831681450');
	ncnt := ncnt+1;
	commit;
	dbms_output.put_line('Number of records added= '||ncnt);
END;
/