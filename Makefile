CC			= gcc

NAME		= filler

SRCS		=	filler.c	\
			get_fct.c		\
			is_fct.c		\
			ft_gnl.c
 
OBJS		= $(SRCS:.c=.o)

INCS		= -I ./includes/

CFLAGS		= -Wall -Werror -Wextra -g

CLFLAGS		+= -L libft -lft

LDFLAGS		= -I $(DIR_LIBFT)/includes

DIR_LIBFT	= ./libft

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCS) -c $^

$(NAME):	$(OBJS)
			make -C $(DIR_LIBFT)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CLFLAGS) $(LDFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
