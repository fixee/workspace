

CC=g++
CFLAG=-g -lcurl -I./include

TARGET=pick_svr
SUBDIR=./monitor ./httpclient1 ./jsoncpp ./Tools . 
OBJDIR=./obj

SRC=$(foreach DIR, $(SUBDIR), $(wildcard ${DIR}/*.cpp ))
OBJ=$(patsubst %.cpp, %.o, $(SRC))

BIN_TARGET: $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(TARGET)

$(OBJ): %.o:%.cpp
	$(CC) $(CFLAG) -c $^ -o $@
	
.PHONY:clean
clean:
	@for DIR in $(SUBDIR); do	\
		rm -rf  $$DIR/*.o; 		\
	done
