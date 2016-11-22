# Hospital RPC Program
A hospital database management program
## HOWTO
Here is an simple example of how to use the program
### SERVER
```
$ ./hospital_svc
```
### CLIENT
```
$ ./hospital_clnt --host=${HOST_NAME} --${COMMANDS} --file==${STRING} --id=${STRING}
```

	List of __COMMANDS__
		* open : Opening the database on the server side
			--file parameter is required
		* close : Closing the database on the server side
			--file parameter is required
		* insert : Inserting an item read from a file on the database
			--file parameter is required
		* remove : Removing an item whose id is __STRING__
			--id parameter is required
		* replace : Replacing an item whose id is __STRING__ to an item read from a file
			both --id and --file parameter is required
		* query : Querying an item whose id is __STRING__
			--id parameter is required

#### An example of a database file
```
TO19238,18,0,Anotia,401,2013-03-27,2014-01-29,MD231-1
TO38291,27,1,Atherosclerosis,602,2011-02-08,2011-03-11,MD192-0
TO29991,60,0,Beriberi,203,2009-12-23,2010-09-03,MD102-1
TO04431,39,1,Calculi,203,2008-11-03,2010-01-11,MD902-3
TO13301,42,0,Botulism,409,2003-08-15,2003-09-21,MD102-3
TO90002,8,1,Chancroid,302,2013-09-23,2014-01-03,MD102-1
TO32951,71,0,Cowpox,102,2011-04-27,2011-09-25,MD301-0
TO59271,89,1,Chordoma,309,2007-03-27,2011-04-29,MD201-3
TO66912,42,0,Dengue,502,2010-06-04,2011-02-25,MD301-2
TO19923,62,0,Dysentery,212,2003-08-21,2003-09-04,301-0
TO59102,30,1,Ebola,610,2015-09-04,2015-12-25,MD201-1
TO90021,39,0,Encephalitis,302,2013-09-11,2014-01-03,MD192-0
TO06111,15,1,Flu,109,2016-05-27,2016-05-30,MD902-3
TO77142,51,0,Gangrene,410,2012-03-27,2012-04-19,MD231-1
TO83123,17,1,Goitre,105,2001-07-27,2010-03-17,MD701-0
TO72313,65,0,HeartAttack,510,2014-07-11,2014-07-13,MD201-1
TO23033,22,1,HIV,610,2013-09-23,2016-08-30,MD231-1
TO90231,90,0,Impetigo,201,2006-06-04,2006-08-30,MD401-2
TO49201,33,1,Keloids,210,2011-11-04,2012-02-03,MD301-0
TO61923,49,0,Laryngitis,301,2009-05-03,20110-01-25,MD402-0
TO41023,27,1,Leprosy,203,2007-10-03,2007-11-09,MD102-3
TO12390,50,0,Leukemia,610,2011-04-04,2011-11-03,MD201-1
TO29144,38,1,Migraine,401,2012-09-02,2013-02-23,MD102-3
TO49214,8,0,Myopia,401,2004-02-04,2005-01-17,MD902-3
TO23233,44,1,Neoplasm,401,2008-06-02,2009-01-17,MD201-3
TO98713,51,0,Obesity,102,2007-10-04,2008-07-14,MD204-1
TO51207,81,1,Plague,302,2002-07-29,2004-03-06,MD102-3
TO89123,67,0,Progeria,201,2005-08-27,2006-01-01,MD303-3
TO12340,23,1,PubicLice,303,2014-10-04,2014-11-03,MD301-2
TO88888,23,1,Nemasis,213,2009-12-02,2014-02-27,MD201-3
```


