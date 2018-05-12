################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ActiveObject.cpp \
../Algorithm.cpp \
../BSTree.cpp \
../CrackCodeing.cpp \
../DQueue.cpp \
../DataStructure.cpp \
../Distinary.cpp \
../Effectivecpp.cpp \
../Factory.cpp \
../Fixed_Array.cpp \
../FrameWirk.cpp \
../GoW.cpp \
../HashTablesRansomNote.cpp \
../List.cpp \
../MergeSort.cpp \
../MoreEffectiveCpp.cpp \
../Move.cpp \
../MoveConstroctor.cpp \
../MyMap.cpp \
../Myset.cpp \
../ObserverPattern.cpp \
../Prepaire.cpp \
../PriorityQueue.cpp \
../Queue.cpp \
../Stack.cpp \
../StackProblems.cpp \
../ThreadPool.cpp \
../ThreadWrapper.cpp 

OBJS += \
./ActiveObject.o \
./Algorithm.o \
./BSTree.o \
./CrackCodeing.o \
./DQueue.o \
./DataStructure.o \
./Distinary.o \
./Effectivecpp.o \
./Factory.o \
./Fixed_Array.o \
./FrameWirk.o \
./GoW.o \
./HashTablesRansomNote.o \
./List.o \
./MergeSort.o \
./MoreEffectiveCpp.o \
./Move.o \
./MoveConstroctor.o \
./MyMap.o \
./Myset.o \
./ObserverPattern.o \
./Prepaire.o \
./PriorityQueue.o \
./Queue.o \
./Stack.o \
./StackProblems.o \
./ThreadPool.o \
./ThreadWrapper.o 

CPP_DEPS += \
./ActiveObject.d \
./Algorithm.d \
./BSTree.d \
./CrackCodeing.d \
./DQueue.d \
./DataStructure.d \
./Distinary.d \
./Effectivecpp.d \
./Factory.d \
./Fixed_Array.d \
./FrameWirk.d \
./GoW.d \
./HashTablesRansomNote.d \
./List.d \
./MergeSort.d \
./MoreEffectiveCpp.d \
./Move.d \
./MoveConstroctor.d \
./MyMap.d \
./Myset.d \
./ObserverPattern.d \
./Prepaire.d \
./PriorityQueue.d \
./Queue.d \
./Stack.d \
./StackProblems.d \
./ThreadPool.d \
./ThreadWrapper.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -pthread -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


