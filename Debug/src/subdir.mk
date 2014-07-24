################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Facade.cpp \
../src/Macrochip.cpp \
../src/MicrocontrollerEmulator.cpp \
../src/Mops.cpp \
../src/Rotamola.cpp \
../src/Utils.cpp 

O_SRCS += \
../src/Facade.o \
../src/Macrochip.o \
../src/MicrocontrollerEmulator.o \
../src/Mops.o \
../src/Rotamola.o \
../src/Utils.o 

OBJS += \
./src/Facade.o \
./src/Macrochip.o \
./src/MicrocontrollerEmulator.o \
./src/Mops.o \
./src/Rotamola.o \
./src/Utils.o 

CPP_DEPS += \
./src/Facade.d \
./src/Macrochip.d \
./src/MicrocontrollerEmulator.d \
./src/Mops.d \
./src/Rotamola.d \
./src/Utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


