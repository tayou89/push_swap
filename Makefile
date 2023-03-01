NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
AR = ar
ARFLAGS = -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = main.c \
	   get_number_array.c \
	   ft_atoi_longlong.c ft_isspace.c free_array.c \
		
OBJS = $(SRCS:.c=.o)

all : $(NAME) 

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(LIBFT) : 
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
