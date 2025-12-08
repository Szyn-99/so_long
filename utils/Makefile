CC = cc
FLAGS = -Wall -Wextra -Werror 
HEADERRRRR = utils_helpers.h
NAME = utils.a

SRC = ft_lstadd_back.c \
    ft_lstclear.c \
    ft_lstdelone.c \
    ft_lstlast.c \
    ft_lstnew.c \
    get_next_line_utils.c \
    get_next_line.c \
    ft_strrchr.c \
    ft_strnstr.c \

OBJF = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	ar -rc $@ $^

%.o: %.c $(HEADERRRRR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)

re: fclean all
