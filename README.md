frdm-kl25z-blink3
=================

FRDM KL25Z Multicolor LED Blink Sample Application

This is another blinking led sample application for the Freescale FRDM-KL25Z board.

Original code was developed using CodeWarrior MCU v10.4 with Processor Expert for Windows, and then 'autotooled' for cross-building in a Gentoo Linux OS.

For building this application you'll need to grab the contents of two directories from CodeWarrior installation and have them available in your Linux filesystem:

  - MCU/ARM_GCC_Support/ewl (Freescale Embedded Warrior Libraries)
  - MCU/ProcessorExpert/lib/Kinetis/pdd/inc (Kinetis PDD headers)

Moreover for cross-compilation an arm-none-eabi crosstoolchain is also a must.

Flashing through USB in Linux was successfully tested with CMSIS-DAP enabled openocd AND board firmware; debugging using gdb worked fine as well using openocd as a remote backend for gdb.

Rafael Lorandi
www.coolparadox.com

