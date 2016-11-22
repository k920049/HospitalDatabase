typedef string str_t<256>;
typedef struct LIST list;
typedef struct ARG arg;
typedef struct FIELD field;

struct FIELD {
	str_t data;
};

struct LIST {
	field id;
	int age;
	bool gender;	/* Male : 0, Female : 1 */
	field cause;
	field unit;
	field admission;
	field discharge;
	field doctor;

	list *next;
};

struct ARG {
	field id;
	list *item;
};

program DATABASEPROG {
	version DATABASEVERS {
		int DBOPEN(field) = 1;
		bool DBINSERT(list) = 2;
		list DBQUERY(field) = 3;
		bool DBREMOVE(field) = 4;
		bool DBREPLACE(arg) = 5;
		bool DBCLOSE(field) = 6;
	} = 1;
} = 30000;

