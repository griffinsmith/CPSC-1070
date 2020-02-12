CC = gcc
NAME = pipe
IDIR = ./
LDIR = ./
LIBS = -lezdraw -lm
CFLAGS = `sdl2-config --cflags` -g -W -Wall -Wextra -pedantic -O0 -I `sdl2-config --prefix`/include/
LDFLAGS = `sdl2-config --libs`
OBJS = $(NAME).o
%.o: %.c $(IDIR)ezdraw.h
	$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $@
$(NAME): $(OBJS) $(LDIR)libezdraw.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LDIR) $(LIBS) $(LDFLAGS)
clean:
	rm -f *.o
	rm -f *~
	rm -f $(NAME)
