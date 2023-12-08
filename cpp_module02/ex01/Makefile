NAME	=	Fixed_Point
CC		=	c++ 
CFLAG	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf
SRCS	=	srcs/main.cpp \
			srcs/Fixed.cpp
			

OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@echo "---------------------------"
	@echo "|                         |"
	@echo "|       Fixed_Point       |"
	@echo "|                         |"
	@echo "---------------------------"
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re