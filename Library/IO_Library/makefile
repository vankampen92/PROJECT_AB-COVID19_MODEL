# =======================
#     LIBRARY make
# =======================

# Gnu C make cpgplot_GRID UTILS (libda_cpgplot_GRID.a)
LIB_DIR              = $(PROJECT_DIR)Library/IO_Library/
RANDOM_DIR           = $(PROJECT_DIR)Library/GSL_RANDOM/
LIB_OPT              = $(PROJECT_DIR)Library/Optimization_Library/
INCLUDE_R_DIR=/usr/share/R/include/
EXTRA_INCLUDE_PATH   = -I${LIB_DIR} -I${PROJECT_DIR} -I${PROJECT_DIR}Include/ -I${RANDOM_DIR} -I${INCLUDE_R_DIR} -I${LIB_OPT}

CFLAGS=-g -Wall -DHAVE_INLINE ${EXTRA_INCLUDE_PATH} 
###CFLAGS= -Wall -O21

COMPILER=gcc -fPIC -DSHARED_OBJECT

OBJECTS=IO_Procedures_Standard.o IO_Demographic_Parameters.o IO_Model_Parameters.o Uploading_Parameters_into_Parameter_Table.o IO_Observed_Data.o #Build_File_of_Time_Parameters_2000_2016.o

.SUFIXES:       .o .c

.c.o:
	${COMPILER} $(CFLAGS) -c $<

da_IO: ${OBJECTS}
	ar -q libda_IO.a ${OBJECTS}

da_IO_SO: ${OBJECTS}
	gcc -shared -o libda_IO.so ${OBJECTS}

all: da_IO 

clean:
	rm -f *.o *~
