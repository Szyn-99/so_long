CC = cc
HEADER = utils.h
FLAGS = -Wall -Wextra -Werror
SOURCE = 
OBJECTS = $(HELPERS:.c=.o)
NAME = Soo_Looong

all: $(NAME)
 
$(NAME): $(OBJECTS)
	ar rcs $@ $^
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: re clean fclean all