CXX		:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
RM		:=	rm -f

TARGET	:=	a.out
SRCS    :=	ScalarConverter.cpp \
			main.cpp
OBJS    :=	$(patsubst %.cpp, %.o, $(SRCS))

.PHONY: all clean flean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
