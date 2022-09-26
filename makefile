
AL_dir = algorepo

CC = g++

CPPFLAGS = -Wall -g

ALGO_obj = \
	$(AL_dir)/greedy.o \
	$(AL_dir)/dp.o \


all: main.o $(ALGO_obj)
	$(CC) -o main main.o $(ALGO_obj)

clean:
	rm -f \
	*.o \
	$(AL_dir)/*.o \