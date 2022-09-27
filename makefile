
AL_dir = algorepo

CC = g++

CPPFLAGS = -Wall -g

ALGO_obj = \
	$(AL_dir)/greedy.o \
	$(AL_dir)/dp.o \
	$(AL_dir)/funcs.o \


all: main.o $(ALGO_obj)
	$(CC) -o main main.o $(ALGO_obj)






install:
	@echo "this should copy .a/.exe/.lib to target-dir, \n we do nothing here :)"

clean:
	rm -f \
	*.o \
	$(AL_dir)/*.o \
	main \