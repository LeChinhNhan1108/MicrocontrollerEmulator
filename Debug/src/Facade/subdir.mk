################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Facade/Facade.cpp 

OBJS += \
./src/Facade/Facade.o 

CPP_DEPS += \
./src/Facade/Facade.d 


# Each subdirectory must supply rules for building sources it contributes
src/Facade/%.o: ../src/Facade/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


