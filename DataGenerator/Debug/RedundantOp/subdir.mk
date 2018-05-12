################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RedundantOp/RedundantOp.cpp 

O_SRCS += \
../RedundantOp/RedundantOp.o 

OBJS += \
./RedundantOp/RedundantOp.o 

CPP_DEPS += \
./RedundantOp/RedundantOp.d 


# Each subdirectory must supply rules for building sources it contributes
RedundantOp/%.o: ../RedundantOp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -pthread -D__GXX_EXPERIMENTAL_CXX0X__ -Ipthread -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


