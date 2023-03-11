NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
AR = ar
ARFLAGS = -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = push_swap.c \
	   check_exception.c initialize_stack_a.c \
	   operations.c \
	   control_node.c \
	   get_string_array.c get_int_array.c ft_atoll.c \
	   push_swap_utils.c \
	   free_functions.c
		
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
	make bonus -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
