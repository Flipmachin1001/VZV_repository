################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic_test_i2c.obj: ../aic_test_i2c.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="aic_test_i2c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cbrev.obj: ../cbrev.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="cbrev.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cfft_scale.obj: ../cfft_scale.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="cfft_scale.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

dma_bypass1.obj: ../dma_bypass1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="dma_bypass1.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

evm5515.obj: ../evm5515.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="evm5515.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

evm5515_gpio.obj: ../evm5515_gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="evm5515_gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fir.obj: ../fir.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="fir.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

i2s_bypass1.obj: ../i2s_bypass1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="i2s_bypass1.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

i2s_register.obj: ../i2s_register.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="i2s_register.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

iir.obj: ../iir.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="iir.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

iircas32.obj: ../iircas32.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="iircas32.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

iircas5.obj: ../iircas5.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="iircas5.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

led_test.obj: ../led_test.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="led_test.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

maxval.obj: ../maxval.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="maxval.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

maxvec.obj: ../maxvec.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="maxvec.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mmcsd_evm.obj: ../mmcsd_evm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="mmcsd_evm.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mmcsd_protocol.obj: ../mmcsd_protocol.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="mmcsd_protocol.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

nandflash_test.obj: ../nandflash_test.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="nandflash_test.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

power.obj: ../power.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --memory_model=huge --asm_source=mnemonic --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="power.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ref_data_bypass1.obj: ../ref_data_bypass1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="ref_data_bypass1.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rtc.obj: ../rtc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="rtc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sar.obj: ../sar.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="sar.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: ../timer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="timer.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

twiddle.obj: ../twiddle.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="twiddle.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

usbstk5515.obj: ../usbstk5515.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="usbstk5515.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

vector.obj: ../vector.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"c:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -vcpu:3.3 -g --define="C55X" --define="_DEBUG" --include_path="c:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --diag_warning=225 --algebraic --memory_model=huge --obj_directory="D:/___/ VZV2/Debug" --preproc_with_compile --preproc_dependency="vector.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


