OBJS=bin/objs/AssignmentGroup.o bin/objs/Class.o bin/objs/ClassManager.o bin/objs/GradeKeeper.o
 
CC=g++
 
DEBUG=-Wextra -g3 -Og -fno-optimize-sibling-calls -fno-ipa-icf -fno-omit-frame-pointer -fno-common -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=undefined -fsanitize=shift -fsanitize=shift-exponent -fsanitize=shift-base -fsanitize=integer-divide-by-zero -fsanitize=unreachable -fsanitize=vla-bound -fsanitize=null -fsanitize=return -fsanitize=signed-integer-overflow -fsanitize=bounds -fsanitize=bounds-strict -fsanitize=alignment -fsanitize=object-size -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fsanitize=bool -fsanitize=enum -fsanitize=vptr -fsanitize=pointer-overflow -fsanitize=builtin -fno-sanitize-recover=all -fsanitize-address-use-after-scope -fstack-protector-all

CFLAGS=-Wall -c ${DEBUG} 

LFLAGS=-Wall ${DEBUG}

grade_keeper: ${OBJS} 
	${CC} ${LFLAGS} ${OBJS} ./src/main.cpp -o ./bin/grade_keeper

bin/objs/AssignmentGroup.o: include/AssignmentGroup.h src/AssignmentGroup.cpp 
	${CC} ${CFLAGS} src/AssignmentGroup.cpp -o bin/objs/AssignmentGroup.o

bin/objs/Class.o: include/Class.h src/Class.cpp 
	${CC} ${CFLAGS} src/Class.cpp -o bin/objs/Class.o

bin/objs/ClassManager.o: include/Class.h src/Class.cpp 
	${CC} ${CFLAGS} src/ClassManager.cpp -o bin/objs/ClassManager.o

bin/objs/GradeKeeper.o: include/ClassManager.h src/ClassManager.cpp 
	${CC} ${CFLAGS} src/GradeKeeper.cpp -o bin/objs/GradeKeeper.o

clean:
	rm bin/grade_keeper bin/objs/*.o

remake:
	make clean; make

test:
	make clean; make; clear; ./bin/grade_keeper
