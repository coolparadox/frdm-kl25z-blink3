#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(
	[FRDM KL25Z Multicolor LED Blink Sample Application],
	[1.1],
	[coolparadox@gmail.com],
	[frdm-kl25z-blink3],
	[http://github.com/coolparadox/frdm-kl25z-blink3])
AM_INIT_AUTOMAKE([1.13.4 foreign -Wall])
AC_CONFIG_SRCDIR([Sources/ProcessorExpert.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AM_PROG_AR
AM_PROG_AS
AC_PROG_CC
AC_PROG_RANLIB

# Check for Kinetis PDD headers
required_pdd_headers="GPIO_PDD.h LPTMR_PDD.h"
AC_MSG_CHECKING([if Generated_Code/IO_Map.h exists in sources])
if test -r "$srcdir/Generated_Code/IO_Map.h" ; then
	AC_MSG_RESULT([yes])
else
	AC_MSG_RESULT([no])
	AC_MSG_ERROR([missing peripheral memory map for MKL25Z4])
fi
AC_ARG_WITH(
	[pdd_headers_location],
	AS_HELP_STRING(
		[--with-pdd_headers_location=DIR],
		[location of Kinetis PDD header files]),
	[use_pdd_headers_location=$withval],
	[use_pdd_headers_location=''])
test x$use_pdd_headers_location = xyes && use_pdd_headers_location=''
AC_MSG_CHECKING([for Kinetis PDD headers location])
if test -n "$use_pdd_headers_location" ; then
	AC_MSG_RESULT([$use_pdd_headers_location])
else
	AC_MSG_RESULT([none])
fi
if test -n "$use_pdd_headers_location" ; then
	test -d "$use_pdd_headers_location" || AC_MSG_ERROR([$use_pdd_headers_location is not a directory])
	test -r "$use_pdd_headers_location/PDD_Types.h" || AC_MSG_WARN([missing PDD_Types.h in $use_pdd_headers_location, this is weird])
	CPPFLAGS="$CPPFLAGS -I$use_pdd_headers_location"
else
	AC_MSG_WARN([no location specified for Kinetis PDD headers, see --with-pdd_headers_location])
	AC_MSG_NOTICE([assuming Kinetis PDD headers location is informed through CPPFLAGS])
fi
AC_CHECK_HEADERS(
	[$required_pdd_headers],
	[],
	[AC_MSG_ERROR([missing Kinetis PDD headers])],
	[#include "$srcdir/Generated_Code/IO_Map.h"])

# Check for EWL headers and libraries
required_ewl_headers="ansi_parms.h CWCPlusLib.h runtime_configuration.h"
AC_ARG_WITH(
	[ewl_headers_location],
	AS_HELP_STRING(
		[--with-ewl_headers_location=DIR],
		[location of EWL header files]),
	[use_ewl_headers_location=$withval],
	[use_ewl_headers_location=''])
test x$use_ewl_headers_location = xyes && use_ewl_headers_location=''
AC_MSG_CHECKING([for EWL headers location])
if test -n "$use_ewl_headers_location" ; then
	AC_MSG_RESULT([$use_ewl_headers_location])
else
	AC_MSG_RESULT([none])
fi
if test -n "$use_ewl_headers_location" ; then
	test -d "$use_ewl_headers_location" || AC_MSG_ERROR([$use_ewl_headers_location is not a directory])
	test -r "$use_ewl_headers_location/EWL_C/include/ansi_parms.h" || AC_MSG_WARN([missing EWL_C/include/ansi_parms.h in $use_ewl_headers_location, this may cause missing headers])
	test -r "$use_ewl_headers_location/EWL_Runtime/include/CWCPlusLib.h" || AC_MSG_WARN([missing EWL_Runtime/include/CWCPlusLib.h in $use_ewl_headers_location, this may cause missing headers])
	test -r "$use_ewl_headers_location/EWL_Runtime/include/arm/runtime_configuration.h" || AC_MSG_WARN([missing EWL_Runtime/include/arm/runtime_configuration.h in $use_ewl_headers_location, this may cause missing headers])
	test -r "$use_ewl_headers_location/lib/armv6-m/librt.a" || AC_MSG_WARN([missing lib/armv6-m/librt.a in $use_ewl_headers_location, this may cause missing libraries])
	CPPFLAGS="$CPPFLAGS -I$use_ewl_headers_location/EWL_C/include -I$use_ewl_headers_location/EWL_Runtime/include -I$use_ewl_headers_location/EWL_Runtime/include/arm"
	LDFLAGS="$LDFLAGS -L$use_ewl_headers_location/lib/armv6-m"
else
	AC_MSG_WARN([no location specified for EWL headers, see --with-ewl_headers_location])
	AC_MSG_NOTICE([assuming EWL headers location is informed by CPPFLAGS])
	AC_MSG_NOTICE([assuming EWL armv6 libraries location is informed by LDFLAGS])
fi
AC_CHECK_HEADERS(
	[$required_ewl_headers],
	[],
	[AC_MSG_ERROR([missing EWL headers])])
pe_ld="Project_Settings/Linker_Files/ProcessorExpert.ld"
AC_MSG_CHECKING([if $pe_ld exists in sources])
if test -r "$srcdir/$pe_ld" ; then
	AC_MSG_RESULT([yes])
else
	AC_MSG_RESULT([no])
	AC_MSG_ERROR([missing processor expert linker component in sources])
fi
LDFLAGS="$LDFLAGS -T$srcdir/Project_Settings/Linker_Files/ProcessorExpert.ld"
AC_CHECK_LIB(
	rt,
	__init_registers,
	[],
	[AC_MSG_ERROR([missing EWL armv6-m libraries])])

# Generate Makefile
AC_CONFIG_FILES([Makefile support/libaeabi-cortexm0/Makefile])
AC_OUTPUT
