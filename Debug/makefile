################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/c5500_4.4.1

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./aic_test_i2c.obj" \
"./cbrev.obj" \
"./cfft_scale.obj" \
"./dma_bypass1.obj" \
"./evm5515.obj" \
"./evm5515_gpio.obj" \
"./fir.obj" \
"./i2s_bypass1.obj" \
"./i2s_register.obj" \
"./iir.obj" \
"./iircas32.obj" \
"./iircas5.obj" \
"./led_test.obj" \
"./main.obj" \
"./maxval.obj" \
"./maxvec.obj" \
"./mmcsd_evm.obj" \
"./mmcsd_protocol.obj" \
"./nandflash_test.obj" \
"./power.obj" \
"./ref_data_bypass1.obj" \
"./rtc.obj" \
"./sar.obj" \
"./timer.obj" \
"./twiddle.obj" \
"./usbstk5515.obj" \
"./vector.obj" \
"../c5515.cmd" \
-l"C:\ti\ccsv6\tools\compiler\c5500_4.4.1\lib\rts55h.lib" \
-l"rts55h.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
VZV1-M4.out \

EXE_OUTPUTS__QUOTED += \
"VZV1-M4.out" \


# All Target
all: VZV1-M4.out

# Tool invocations
VZV1-M4.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" -z -m"VZV1-M4.map" --stack_size=1000 --heap_size=0x400 --warn_sections -i"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --reread_libs --xml_link_info="VZV1-M4_linkInfo.xml" --entry_point=reset_isr --rom_model --sys_stacksize=1000 -o "VZV1-M4.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "dma_bypass1.pp" "evm5515.pp" "evm5515_gpio.pp" "i2s_bypass1.pp" "iir.pp" "led_test.pp" "main.pp" "mmcsd_evm.pp" "mmcsd_protocol.pp" "nandflash_test.pp" "ref_data_bypass1.pp" "rtc.pp" "sar.pp" "timer.pp" "usbstk5515.pp" 
	-$(RM) "aic_test_i2c.obj" "cbrev.obj" "cfft_scale.obj" "dma_bypass1.obj" "evm5515.obj" "evm5515_gpio.obj" "fir.obj" "i2s_bypass1.obj" "i2s_register.obj" "iir.obj" "iircas32.obj" "iircas5.obj" "led_test.obj" "main.obj" "maxval.obj" "maxvec.obj" "mmcsd_evm.obj" "mmcsd_protocol.obj" "nandflash_test.obj" "power.obj" "ref_data_bypass1.obj" "rtc.obj" "sar.obj" "timer.obj" "twiddle.obj" "usbstk5515.obj" "vector.obj" 
	-$(RM) "aic_test_i2c.pp" "cbrev.pp" "cfft_scale.pp" "fir.pp" "i2s_register.pp" "iircas32.pp" "iircas5.pp" "maxval.pp" "maxvec.pp" "power.pp" "twiddle.pp" "vector.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

