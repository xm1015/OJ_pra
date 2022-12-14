
AL_dir = algorepo

CC = g++

CPPFLAGS = -Wall -g

ALGO_obj = \
	$(AL_dir)/funcs.o \
	$(AL_dir)/sorting.o \
	$(AL_dir)/bitOperation.o \


all: main.o $(ALGO_obj)
	$(CC) -o main main.o $(ALGO_obj)

run: all
	@echo "============================================"
	@./main


install:
	@echo "this command should copy .a/.exe/.lib to target-dir, \n we do nothing here :)"

clean:
	rm -f \
	*.o \
	$(AL_dir)/*.o \
	main \