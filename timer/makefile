##########################Source Directory###################################
SRCS	= ./ros_event_handler.cpp ./ros_timer_custom.cpp ./test_timer.cpp
		
NAME	= Timer

CC2	= g++ -g -pthread -std=c++14
 
LIBS	= 

OBJS	= $(SRCS:.cpp=.o)

LIBPATH = -L -pthread

RM := rm -rf
#######################Include Paths###########################################

INCL	= -I./


# Add inputs and outputs from these tool invocations to the build variables 
# All Target
all: $(NAME)

# Tool invocations

$(NAME):$(OBJS) 
	       
	@$(CC2)  $(OBJS) $(INCL) $(LIBPATH) $(LIBS) -o $(NAME)
	@printf "\n \033[33m[Message]\033[39m Compilation under Linux done\n"	


.cpp.o:

	@$(CC2) $(INCL)  -c $< -o $@ $(LIBPATH)
	@printf " \033[34m[Compilation]\033[39m %s\n" $<


# Other Targets
clean:
	rm -rf *.o Timer*


