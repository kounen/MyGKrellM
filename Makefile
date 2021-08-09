##
## EPITECH PROJECT, 2020
## MyGKrellm
## File description:
## Makefile
##

SRC	=	src/GetInfoGraph.cpp	\
		src/LinuxCommands.cpp	\
		src/MonitorModuleMemory.cpp	\
		src/MonitorModuleSystem.cpp	\
		src/MonitorModuleCPU.cpp	\
		src/Core.cpp	\
		src/TestFunctionalSystem.cpp	\
		src/MonitorModuleDisk.cpp \
		src/MonitorModuleNetwork.cpp \
		src/TestFunctionalMemory.cpp	\
		src/TestFunctionalCPU.cpp \
		src/plot_sfml.cpp \
		src/main_sfml.cpp \
		src/UserSettings.cpp \
		src/ram_plot.cpp \
		src/cpu_plot.cpp \
		src/system_plot.cpp \
		main.cpp\
		plot/PieChart.cpp \
		ncurses/DisplayCPU.cpp \
		ncurses/DisplayMemory.cpp \
		ncurses/DisplayNetwork.cpp \
		ncurses/DisplaySystem.cpp \
		ncurses/Interface.cpp \
		ncurses/UpdateInfo.cpp

CXX	=	g++

CXXFLAGS = -Wall -Wextra -ggdb3 -O0



LDFLAGS 	= 	-lsfml-graphics -lsfml-window -lsfml-system -lncurses

OBJ			=	$(SRC:.cpp=.o)

NAME		=	MyGKrellm



all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
