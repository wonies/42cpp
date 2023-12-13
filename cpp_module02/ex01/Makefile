NAME	=	Fixed_Point
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
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
	@$(CXX) $(CXXFLAG) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CXX) $(CXXFLAG) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re