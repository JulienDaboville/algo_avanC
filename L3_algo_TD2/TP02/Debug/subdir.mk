################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chemin.c \
../file.c \
../graphe.c \
../main.c \
../temps.c 

C_DEPS += \
./chemin.d \
./file.d \
./graphe.d \
./main.d \
./temps.d 

OBJS += \
./chemin.o \
./file.o \
./graphe.o \
./main.o \
./temps.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./chemin.d ./chemin.o ./file.d ./file.o ./graphe.d ./graphe.o ./main.d ./main.o ./temps.d ./temps.o

.PHONY: clean--2e-

