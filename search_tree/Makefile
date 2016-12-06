TARGET=search_tree_test
OBJ=search_tree_test.o search_tree.o

%.o:%.c
	gcc -g -c -o $@ $<
$(TARGET):$(OBJ)
	gcc -o $@ $^

.PHONY:clean 
clean:
	rm $(TARGET) $(OBJ)
