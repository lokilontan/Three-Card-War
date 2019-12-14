################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AIPlayer.cpp \
../src/Card.cpp \
../src/ComputerPlayer.cpp \
../src/Deck.cpp \
../src/TerminalPlayer.cpp \
../src/Test.cpp \
../src/ThreeWarGame.cpp 

OBJS += \
./src/AIPlayer.o \
./src/Card.o \
./src/ComputerPlayer.o \
./src/Deck.o \
./src/TerminalPlayer.o \
./src/Test.o \
./src/ThreeWarGame.o 

CPP_DEPS += \
./src/AIPlayer.d \
./src/Card.d \
./src/ComputerPlayer.d \
./src/Deck.d \
./src/TerminalPlayer.d \
./src/Test.d \
./src/ThreeWarGame.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


