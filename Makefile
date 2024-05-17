CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
FT_PRINTFDIR = ft_printf
LIBS = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf
NAME = client server
SRCS = $(NAME:=.c)
OBJS =$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $@.o $(LIBS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(LIBFTDIR) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all