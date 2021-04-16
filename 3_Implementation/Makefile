#comments

#Target : dependency
#<TAB>Command

PROJECT_NAME = Snake.exe
SRC = Snake.c\
test_snake.c

INC = unity

TEST = unity/unity.c

#$(PROJECT_NAME): $(SRC) $(TEST)
all:
	gcc -I $(INC) $(SRC) $(TEST) -o $(PROJECT_NAME)
	
run: $(PROJECT_NAME)
	$(PROJECT_NAME)
	
clean:
	del /q *.exe
	
memory_map:
	nm Snake.exe