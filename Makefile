CC = cc

HEADER = utils.h

FLAGS = -Wall -Wextra -Werror

SOURCE = parsing.c parsing2.c main.c

OBJECTS = $(SOURCE:.c=.o)

ARCHIVE = ./utils/utils.a

NAME = Soo_Looong

all: $(NAME) $(ARCHIVE)
 
$(NAME): $(OBJECTS) $(ARCHIVE)
	$(CC) $(FLAGS) $(OBJECTS) $(ARCHIVE) -o $@
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
$(ARCHIVE):
	$(MAKE) --no-print-directory -C utils all
clean:
	$(MAKE) --no-print-directory -C  utils clean
	rm -f $(OBJECTS) $(ARCHIVE)
fclean: clean
	$(MAKE) --no-print-directory -C utils fclean
	rm -f $(NAME)
re: fclean all

.PHONY: re clean fclean all