BIN = hospital_clnt hospital_svc
GEN = hospital_clnt.c hospital_svc.c hospital_xdr.c hospital.h
RPCCOM = rpcgen
CC = gcc

all : $(BIN)

hospital_clnt : hospital_clnt.o hospital_xdr.o
	$(CC) -o $@ hospital_clnt.o hospital_xdr.o

hospital_clnt.o : hospital_clnt.c hospital.h
	$(CC) -g hospital_clnt.c -c

hospital_svc : hospital_svc.o hospital_xdr.o
	$(CC) -o $@ hospital_svc.o hospital_xdr.o

hospital_proc.o : hospital_proc.c hospital.h
