/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include <getopt.h> /* for getopt_long */
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "hospital.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

	int *
dbopen_1(field *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBOPEN,
				(xdrproc_t) xdr_field, (caddr_t) argp,
				(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

	bool_t *
dbinsert_1(list *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBINSERT,
				(xdrproc_t) xdr_list, (caddr_t) argp,
				(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

	list *
dbquery_1(field *argp, CLIENT *clnt)
{
	static list clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBQUERY,
				(xdrproc_t) xdr_field, (caddr_t) argp,
				(xdrproc_t) xdr_list, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

	bool_t *
dbremove_1(field *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBREMOVE,
				(xdrproc_t) xdr_field, (caddr_t) argp,
				(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

	bool_t *
dbreplace_1(arg *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBREPLACE,
				(xdrproc_t) xdr_arg, (caddr_t) argp,
				(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

	bool_t *
dbclose_1(field *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DBCLOSE,
				(xdrproc_t) xdr_field, (caddr_t) argp,
				(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
				TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

list *initialize(void) {
	list *record = (list *)malloc(sizeof(list));
	record->id.data = (char *)malloc(sizeof(char) * 256);
	record->cause.data = (char *)malloc(sizeof(char) * 256);
	record->unit.data = (char *)malloc(sizeof(char) * 256);
	record->admission.data = (char *)malloc(sizeof(char) * 256);
	record->discharge.data = (char *)malloc(sizeof(char) * 256);
	record->doctor.data = (char *)malloc(sizeof(char) * 256);
	record->next = NULL;
	return record;
}

void printList(const list *item) {
	if(item == NULL) {
		printf("The item is NULL\n");
	}

	printf("ID:					%s\n", item->id.data);
	printf("AGE:				%d\n", item->age);
	printf("GENDER:				%s\n", (item->gender == 0) ? "Male" : "Female");
	printf("CAUSE OF DISEASE:	%s\n", item->cause.data);
	printf("WHICH UNIT:			%s\n", item->unit.data);
	printf("ADMITTED SINCE:		%s\n", item->admission.data);
	printf("DATE OF DISCHARGE	%s\n", item->discharge.data);
	printf("DOCTOR'S ID			%s\n", item->doctor.data);
}

void RPCFucntion(const char *functionName,
		char *host,
		char fileName[256],
		char id[256],
		int argc,
		char *argv[]) {

	CLIENT *clnt;
	int filedes = 0,
		returned = 0, 
		index = 0,
		i = 0;

	char buffer[BUFSIZ];
	char *token;
	char line[128][256];

	memset(buffer, 0, BUFSIZ);

	clnt = clnt_create(host, DATABASEPROG, DATABASEVERS, "udp");
	if(clnt == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}

	if(strlen(fileName) != 0) {
		if(strcmp(functionName, "open") == 0) {
			int *result_1 = NULL;
			field *param = (field *)malloc(sizeof(field));
			param->data = (str_t)malloc(sizeof(char) * 256);
			strcpy(param->data, fileName);

			result_1 = dbopen_1(param, clnt);
			if(result_1 == NULL) {
				clnt_perror(clnt, "call failed");
			}
			if(*result_1 == true)
				printf("Succeed to open the DB\n");
			else
				printf("Failed to open the DB\n");
			free(param);
		}
		else if(strcmp(functionName, "close") == 0) {
			bool_t *result_1 = NULL;
			field *param = (field *)malloc(sizeof(field));
			param->data = (str_t)malloc(sizeof(char) * 256);
			strcpy(param->data, fileName);

			result_1 = dbclose_1(param, clnt);
			if(result_1 == NULL) {
				clnt_perror(clnt, "call failed");
			}
			if(*result_1 == true) 
				printf("Succeed to close the DB\n");
			else
				printf("Failed to close the DB\n");
			free(param);
		}
		else {
			if((filedes = open(fileName, O_RDONLY)) < 0) {
				perror("open");
				clnt_destroy(clnt);
				exit(1);
			}

			if((returned = read(filedes, (void *)buffer, BUFSIZ)) < 0) {
				perror("read");
				clnt_destroy(clnt);
				exit(1);
			}

			token = strtok(buffer, "\n");
			while(token != NULL) {
				strcpy(line[index], token);
				token = strtok(NULL, "\n");
				index++;
			}

			for(i = 0;i < index;i++) {
				list *record = initialize();
				record->next = NULL;

				token = strtok(line[i], ",");
				strcpy(record->id.data, token);				// id
				token = strtok(NULL, ",");
				record->age = atoi(token);				// age
				token = strtok(NULL, ",");
				record->gender = (bool_t)atoi(token);	// gender
				token = strtok(NULL, ",");
				strcpy(record->cause.data, token);			// cause
				token = strtok(NULL, ",");
				strcpy(record->unit.data, token);			// unit
				token = strtok(NULL, ",");
				strcpy(record->admission.data, token);		// admission
				token = strtok(NULL, ",");
				strcpy(record->discharge.data, token);		// discharge
				token = strtok(NULL, ", ");
				strcpy(record->doctor.data, token);			// doctor

				if(strlen(id) != 0 
						&&strcmp(functionName, "replace") == 0) {
					printf("Replacing item using primary key %s\n", id);
					printList(record);
					arg *argument = (arg*)malloc(sizeof(arg));
					argument->id.data = (str_t)malloc(sizeof(char) * 256);
					argument->item = initialize();
					bool_t *result_1;
					strcpy(argument->id.data, id);
					memcpy(argument->item, record, sizeof(list));

					result_1 = dbreplace_1(argument, clnt);
					if(result_1 == NULL) {
						clnt_perror(clnt, "call failed");
					}
					if(*result_1 == true)
						printf("Succeed to replace item in the DB\n");
					else
						printf("Failed to replace item in the DB\n");

					free(argument);
				}
				else {
					if(strcmp(functionName, "insert") == 0) {
						bool_t *result_1;
						printf("Inserting item\n");
						printList(record);
						result_1 = dbinsert_1(record, clnt);
						if(result_1 == NULL) {
							clnt_perror(clnt, "call failed");
						}
						if(*result_1 == true)
							printf("Succeed to insert item in the DB\n");
						else
							printf("Failed to insert item in the DB\n");
					}
				}
				free(record);
			}
			close(filedes);
		}
	}
	else{
		if(strlen(id) != 0) {
			if(strcmp(functionName, "query") == 0) {
				printf("Querying item using primary key %s\n", id);
				list *result_1;
				field *param = (field *)malloc(sizeof(field));
				param->data = (str_t)malloc(sizeof(char) * 256);
				strcpy(param->data, id);
				result_1 = dbquery_1(param, clnt);

				if(result_1 == NULL)
					clnt_perror(clnt, "call failed");

				if(strcmp(result_1->id.data, "NULL") == 0) {
					printf("No such item in the DB");	
				}else{
					printList(result_1);
				}
				free(param);
			}
			else if(strcmp(functionName, "remove") == 0) {
				bool_t *result_1;
				field *param = (field *)malloc(sizeof(field));
				param->data = (str_t)malloc(sizeof(char) * 256);
				strcpy(param->data, id);
				result_1 = dbremove_1(param, clnt);
				if(result_1 == NULL) {
					clnt_perror(clnt, "call failed");
				}
				if(*result_1 == true) 
					printf("Succeed to remove item in the DB\n");
				else
					printf("Failed to remove item in the DB\n");
				free(param);
			}
			else {
				printf("Wrong usage, please enter command again\n");
			}
		}
		else{
			printf("Wrong usage, please enter command again\n");
		}
	}
	clnt_destroy(clnt);
	printf("Done, goodbye");
}

void main(int argc, char *argv[]) {

	char host[256],
	fileName[256],
	id[256],
	functionName[16];
	int	option_index = 0,
		result = 0;

	static int isOpen = false,
			   isInsert = false,
			   isQuery = false,
			   isRemove = false,
			   isReplace = false,
			   isClose = false;

	static struct option long_options[] = {
		{"file", optional_argument, 0, 'f'},
		{"host", required_argument, 0, 'h'},
		{"id", optional_argument, 0, 'i'},
		{"open", no_argument, &isOpen, 1},
		{"insert", no_argument, &isInsert, 1},
		{"query", no_argument, &isQuery, 1},
		{"remove", no_argument, &isRemove, 1},
		{"replace", no_argument, &isReplace, 1},
		{"close", no_argument, &isClose, 1},
		{0, 0, 0, 0}
	};

	memset(host, 0, 256);
	memset(fileName, 0, 256);
	memset(id, 0, 256);

	if(argc < 4) {
		printf("usage : %s server_host command ...", argv[0]);
		exit(1);
	}

	while(true) {
		option_index = 0;

		if((result = getopt_long(argc, argv, "f:h:i:", long_options, &option_index)) == -1) {
			break;
		}

		switch(result) {
			case 0:
				if(long_options[option_index].flag != 0)
					break;
				printf ("option %s", long_options[option_index].name);
				if (optarg)
					printf (" with arg %s", optarg);
				printf ("\n");                 
				break;
			case 'f':
				strcpy(fileName, optarg);
				printf("Reading from file %s\n", fileName);
				break;
			case 'h':
				strcpy(host, optarg);
				printf("Host processing RPC is %s\n", host);
				break;
			case 'i':
				strcpy(id, optarg);
				printf("Primary key is %s\n", id);
				break;
			default:
				abort();
		}
	}

	if(isOpen)
		sprintf(functionName, "open");
	else if(isInsert)
		sprintf(functionName, "insert");
	else if(isQuery)
		sprintf(functionName, "query");
	else if(isRemove)
		sprintf(functionName, "remove");
	else if(isReplace)
		sprintf(functionName, "replace");
	else if(isClose)
		sprintf(functionName, "close");

	RPCFucntion(functionName,
			host,
			fileName,
			id,
			argc,
			argv);
}
