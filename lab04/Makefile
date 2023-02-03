#
# CIS330: Lab 3
#
# Makefile to build libraries and test applications.
#

CC=gcc
AR=ar

CFLAGS=-g -O2 -I./include -L./lib -fPIC
LIBS=-llab4 -lm

all: lab4 lab4_dyn

obj:
	mkdir -p obj

lib:
	mkdir -p lib

obj/stats.o: src/stats.c include/stats.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/ohno.o: src/ohno.c include/ohno.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

lib/liblab4.a: obj/stats.o obj/ohno.o lib
	$(AR) rc lib/liblab4.a obj/stats.o obj/ohno.o

lib/liblab4_dyn.so: obj/stats.o obj/ohno.o lib
	$(CC) -shared $(CFLAGS) -o $@ obj/stats.o obj/ohno.o

lab4: src/lab4.c lib/liblab4.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

lab4_dyn: src/lab4.c lib/liblab4_dyn.so
	$(CC) $(CFLAGS) -o $@ $< -llab4_dyn $(LIBS)

# # DYNAMICALLY LINKED this was my attempt

# dyn_obj/stats.o : src/stats.c include/stats.h dyn_obj
# 	$(CC) $(CFLAGS) -c -FPIC -o $@ $<

# dyn_obj/ohno.o : src/ohno.c include/ohno.h dyn_obj
# 	$(CC) $(CFLAGS) -c -FPIC -o $@ $<

# dyn_lib/liblab4.so : obj/stats.o obj/ohno.o dyn_lib
# 	$(CC) -shared -o dyn_lib/liblab4.so dyn_obj/stats.o dyn_obj/ohno.o

# lib_path :
# 	LD_LIBRARY_PATH=$(pwd)/bin/shared bin/use-shared-library

# #----

clean:
	rm lab4 lab4_dyn lib/liblab4.a lib/liblab4_dyn.so obj/ohno.o obj/stats.o
	rmdir obj
	rmdir lib


