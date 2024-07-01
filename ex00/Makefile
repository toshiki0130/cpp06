NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR	= src
SRCS	= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	= $(wildcard $(SRCDIR)/*.hpp)
OBJDIR	= obj
OBJS	= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $^ $(CXXFLAGS) -c -o $@

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

# define colors for output
RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m

test: $(NAME)
	# test from subject
	@echo "$(GREEN)Tests from subject:$(RESET)"
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	#char
	@echo "$(GREEN)Tests of char:$(RESET)"
	./$(NAME) a
	./$(NAME) d
	./$(NAME) A
	#int
	@echo "$(GREEN)Tests of int:$(RESET)"
	./$(NAME) 0
	./$(NAME) -42
	./$(NAME) 42
	# float
	@echo "${GREEN}Tests for float:${RESET}"
	./$(NAME) 0.0f
	./$(NAME) 4.2f
	./$(NAME) -4.2f
	./$(NAME) 42f
	./$(NAME) -42f
	./$(NAME) .42f
	./$(NAME) -.42f
	./$(NAME) inff
	./$(NAME) -inff
	./$(NAME) +inff
	./$(NAME) nanf
	# double
	@echo "${GREEN}Tests for double:${RESET}"
	./$(NAME) 0.0
	./$(NAME) 4.2
	./$(NAME) -4.2
	./$(NAME) 42.
	./$(NAME) -42.
	./$(NAME) .42
	./$(NAME) -.42
	./$(NAME) inf
	./$(NAME) -inf
	./$(NAME) +inf
	./$(NAME) nan
	@echo "${GREEN}Tests for overflow: char${RESET}"
	./$(NAME) 128
	./$(NAME) -129
	@echo "${GREEN}Tests for overflow: int${RESET}"
	./$(NAME) 2147483648
	./$(NAME) -2147483649
	@echo "${GREEN}Tests for overflow: from float to int${RESET}"
	./$(NAME) 21474836450f
	./$(NAME) -21474836450f
	@echo "${GREEN}Tests for overflow: from double to float${RESET}"
	./$(NAME) 340282346638528859811704183484516925440.0 # FLT_MAX
	./$(NAME) 3402823466385288598117041834845169254400.0 # FLT_MAX * 10
	./$(NAME) 1000000000000000000000000000000000000000000000000000000000000.0
	@echo "${GREEN}Tests for invalid literals:${RESET}"
	./$(NAME) '' #empty string
	./$(NAME) 'abc' # string literals
	./$(NAME) 42.42.42f # float with 2 dots
	./$(NAME) 42.42.42 # double with 2 dots
	./$(NAME) ...42f # float with 3 dots
	./$(NAME) 42f.42f # float with f inside number
	./$(NAME) 42ff # float with two f



	
.PHONY: all clean fclean re 