########################################
##
## Makefile
## LINUX compilation
##
##############################################

# Flags
C++FLAG = -g -std=c++14 -Wall

# Math library

MATH_LIBS = -lm
EXEC_DIR=.

# Rule for .cpp files
# .SUFFIXES : .cc.o

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@

# Includes.
INCLUDES=  -I.
LIBS_ALL = -L/usr/lib -L/usr/local/lib $(MATH_LIBS)

# ZEROTH PROGRAM
ALL_OBJ0=main.o
PROGRAM_0=inheritance
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

# Compiling all

all:
		make $(PROGRAM_0)

# Clean obj files
clean:
	(rm -f *.o; rm -f inheritance)
