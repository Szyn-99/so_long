CC = cc
FLAGS = -Wall -Wextra -Werror 
HEADERRRRR = lists.h
NAME = lists.a

SRC = ft_lstadd_back.c \
    ft_lstclear.c \
    ft_lstdelone.c \
    ft_lstlast.c \
    ft_lstnew.c \

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
