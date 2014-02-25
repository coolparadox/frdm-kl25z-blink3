/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-02-18, 14:26, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LEDTimer_OnInterrupt (module Events)
**
**     Component   :  LEDTimer [TimerInt_LDD]
*/
/*!
**     @brief
**         Called if periodic event occur. Component and OnInterrupt
**         event must be enabled. See <SetEventMask> and <GetEventMask>
**         methods. This event is available only if a <Interrupt
**         service/event> is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
*/
/* ===================================================================*/
void LEDTimer_OnInterrupt(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	static int led_state = 0;
	switch (led_state++) {
	case 0:
		RedLED_SetVal(RedLED_DeviceData);
		GreenLED_SetVal(GreenLED_DeviceData);
		BlueLED_SetVal(BlueLED_DeviceData);
		break;
	case 1:
		RedLED_ClrVal(RedLED_DeviceData);
		break;
	case 2:
		RedLED_SetVal(RedLED_DeviceData);
		break;
	case 3:
		GreenLED_ClrVal(GreenLED_DeviceData);
		break;
	case 4:
		GreenLED_SetVal(GreenLED_DeviceData);
		break;
	case 5:
		BlueLED_ClrVal(BlueLED_DeviceData);
		break;
	default:
		BlueLED_SetVal(BlueLED_DeviceData);
		led_state = 1;
		break;
	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
