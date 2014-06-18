SUBDIRS = support/libaeabi-cortexm0

EXTRA_DIST = \
	README \
	build.sh \
	Project_Settings/Linker_Files/ProcessorExpert.ld \
	support/openocd \
	support/libaeabi-cortexm0

bin_PROGRAMS = frdm_kl25z_blink3

frdm_kl25z_blink3_SOURCES = \
	Generated_Code/BlueLED.c Generated_Code/BlueLED.h \
	Generated_Code/Cpu.c Generated_Code/Cpu.h \
	Generated_Code/GreenLED.c Generated_Code/GreenLED.h \
	Generated_Code/IO_Map.h \
	Generated_Code/LEDTimer.c Generated_Code/LEDTimer.h \
	Generated_Code/PE_Const.h \
	Generated_Code/PE_Error.h \
	Generated_Code/PE_LDD.c \
	Generated_Code/PE_LDD.h \
	Generated_Code/PE_Types.h \
	Generated_Code/RedLED.c Generated_Code/RedLED.h \
	Generated_Code/TU1.c Generated_Code/TU1.h \
	Generated_Code/Vectors.c \
	Project_Settings/Startup_Code/__arm_end.c \
	Project_Settings/Startup_Code/__arm_start.c \
	Project_Settings/Startup_Code/runtime_configuration.h \
	Sources/Events.c Sources/Events.h \
	Sources/ProcessorExpert.c \
	Sources/sa_mtb.c

frdm_kl25z_blink3_LDADD = support/libaeabi-cortexm0/libcortexm0.a

AM_CPPFLAGS = -I$(top_srcdir)/Sources -I$(top_builddir)/Generated_Code

clean-local:
	$(RM) debug.log

distclean-local:
	$(RM) -r autom4te.cache

maintainer-clean-local:
	$(RM) Makefile.in aclocal.m4 config.h.in configure depcomp install-sh missing
	$(RM) ar-lib

install-binPROGRAMS:
	@echo "ERROR: installation of this application is administratively disabled."
	@false

flash: frdm_kl25z_blink3
	openocd \
		-c 'interface cmsis-dap' \
		-f $(top_srcdir)/support/openocd/kl25_init.cfg \
		-f $(top_srcdir)/support/openocd/kl25_flash.cfg
.PHONY: flash

GDB = $(host_alias)-gdb \
	-ex "target remote | openocd -c \"gdb_port pipe; log_output debug.log; interface cmsis-dap\" -f $(top_srcdir)/support/openocd/kl25_init.cfg" \
	-ex "monitor reset init" \
	-ex "break main" \
	-ex "continue"

debug: frdm_kl25z_blink3
	$(GDB) frdm_kl25z_blink3
.PHONY: debug

ddd: frdm_kl25z_blink3
	ddd --debugger '$(GDB) frdm_kl25z_blink3'
.PHONY: ddd

