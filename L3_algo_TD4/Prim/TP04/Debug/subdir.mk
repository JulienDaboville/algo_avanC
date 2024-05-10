################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../graphe.c \
../main.c \
../prim.c \
../t_arete.c 

C_DEPS += \
./graphe.d \
./main.d \
./prim.d \
./t_arete.d 

OBJS += \
./graphe.o \
./main.o \
./prim.o \
./t_arete.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./graphe.d ./graphe.o ./main.d ./main.o ./prim.d ./prim.o ./t_arete.d ./t_arete.o

.PHONY: clean--2e-

