

CC=g++
CFLAG=-g -lpthread

TARGET=exe
SUBDIR=./thpool .

SRC=$(foreach DIR, $(SUBDIR), $(wildcard ${DIR}/*.cpp ))
OBJ=$(patsubst %.cpp, %.o, $(SRC))

BIN_TARGET: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAG)

$(OBJ): %.o:%.cpp
	$(CC) $(CFLAG) -c $^ -o $@
	
.PHONY:clean
clean:
	@for DIR in $(SUBDIR); do	\
		rm -rf  $$DIR/*.o; 		\
	done;
	@rm -rf $(TARGET)
