NAME	=	megaphone
CC		=	clang++
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -rf
SRCS	=	megaphone.cpp
OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE) -j6 $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re