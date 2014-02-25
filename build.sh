#!/bin/sh

set -e

# Change the following locations according to your filesystem
PDD_HEADERS_DIR=/opt/Freescale/MCU/ProcessorExpert/lib/Kinetis/pdd/inc
EWL_DIR=/opt/Freescale/MCU/ARM_GCC_Support/ewl

# Crossbuild frdm_kl25z_blink3 arm elf
test -x ./configure || autoreconf --verbose --install
test -r Makefile || ./configure \
	--host=arm-none-eabi \
	--with-pdd_headers_location=$PDD_HEADERS_DIR \
	--with-ewl_headers_location=$EWL_DIR \
	CFLAGS="-mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -O0 -ffunction-sections -fdata-sections -Wall -fmessage-length=0" \
	LDFLAGS="-Xlinker --gc-sections -n"
make
echo
file frdm_kl25z_blink3
exit 0

# For flashing using CMSIS-DAP protocol
make flash

# For debugging using gdb
make debug

# For debugging using ddd
make ddd

