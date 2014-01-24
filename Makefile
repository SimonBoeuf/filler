CC			= gcc

NAME		= filler

<<<<<<< HEAD
INCLUDE		= ./includes/

SRCS		= 	main.c				\
			ft_get_next_line.c		\
			token.c				\
			misc.c				\
			map.c				\
			play.c				\
			check_cell.c			\
			island.c			\
			cell.c				\
			player.c

=======
SRCS		=	filler.c	\
			get_fct.c		\
			is_fct.c		\
			ft_gnl.c
 
>>>>>>> 832928d2ac5d0e6bb60cedad7cf8b0d6c513e551
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
