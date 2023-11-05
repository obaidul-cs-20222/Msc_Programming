DECLARE 
	TYPE aarray IS VARRAY(10) of INTEGER;
	i INTEGER;
	t INTEGER;
	m INTEGER;
	flag INTEGER;
	a aarray;
	n INTEGER;
	counter INTEGER;
	comparison INTEGER;
BEGIN
	a:=aarray(100,90,80,70,60,50,40,30,20,10);
	n := a.count();
	dbms_output.put_line('Elements in Unsorted List--->');
	FOR i IN 1..n
	LOOP
		dbms_output.put_line(a(i));
	END LOOP;
	m:=n;
	flag:=0;
	counter:=1;
	comparison:=0;
		WHILE(flag=0)
		LOOP
		flag :=1;
			m :=m-1;
			FOR i IN 1..m
			LOOP
				IF(a(i)>a(i+1)) THEN
				comparison:=comparison+1;
				t :=a(i);
				a(i):=a(i+1);
				a(i+1):=t;
				flag :=0;
				END IF;
			END LOOP;
			dbms_output.put_line(' pass '||counter);
			counter:=counter+1;
			FOR i IN 1..n
			LOOP
			dbms_output.put_line(a(i));
		END LOOP;
		END LOOP;
		dbms_output.put_line('number of comparisons: '|| comparison);
END;
/