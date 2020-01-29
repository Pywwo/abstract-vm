##
## EPITECH PROJECT, 2018
## AbstractVM
## File description:
## Makefile for the AbstractVM
##

SRC_DIR			=	$(realpath src)

SRC_MAIN_FILE		=	main.cpp

SRC_FILES		=		Float.cpp					\
					CPU.cpp						\
					InputOutputManager.cpp		\
					BigDecimal.cpp				\
					Double.cpp					\
					Factory.cpp					\
					Int8.cpp					\
					Int16.cpp					\
					Int32.cpp					\
					IOperand.cpp				\
					Memory.cpp					\
					Orchestrator.cpp			\
					VM.cpp						\
					Operation.cpp


SRC				= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_MAIN			= 	$(addprefix $(SRC_DIR)/, $(SRC_MAIN_FILE))

OBJ				=	$(SRC:%.cpp=%.o)

OBJ_MAIN			=	$(SRC_MAIN:%.cpp=%.o)

NAME			=   abstractVM

INCLUDE			=   -iquote src/ -iquote src/CLI -iquote include/

CXXFLAGS		=	-W -Wall -Wextra -Wno-unknown-pragmas -Wshadow
CXXFLAGS		+=	$(INCLUDE)

CXX				=	g++

NAME_UT			=	unit_tests

SRC_UT			=	tests/test_cpu.cpp	\

OBJ_UT			=	$(SRC_UT:%.cpp=%.o)

LDFLAGS         =       -lcriterion -lgcov

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			$(CXX) -o $(NAME) $(OBJ_MAIN) $(OBJ)

clean:
				@echo Cleaning $(OBJ)
				$(RM) $(OBJ_MAIN) $(OBJ) $(OBJ_UT)
				find . -type f -name '*.gcno' -delete
				find . -type f -name '*.gcda' -delete
				find . -type f -name 'vgcore.*' -delete
				@echo Cleaning done

tests_run:		CXXFLAGS += --coverage $(INCLUDE)
tests_run:		fclean $(OBJ_UT) $(OBJ)
			$(CXX) -o $(NAME_UT) $(OBJ) $(OBJ_UT) $(CXX_FLAGS) $(LDFLAGS)
			./$(NAME_UT)

fclean:			clean
				@echo Cleaning $(NAME)
				$(RM) $(NAME) $(NAME_UT)
				@echo Cleaning done

re:				fclean all

debug:			CXXFLAGS += -g
debug:			re

.DEFAULT_GOAL := all
