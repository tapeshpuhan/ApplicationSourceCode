##########################Source Directory###################################
SRCS	=	./BiologicalInfo.cpp ./FrameWorkComposit.hpp ./MyBiologyBook.cpp
		
NAME	= BioInfo

CC2	= g++ -g -pthread -std=c++11 
 
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
	rm -rf *.o BuildTheaterTicket*


