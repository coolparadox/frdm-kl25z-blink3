/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RedLED.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitIO_LDD
**     Version     : Component 01.033, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-02-18, 15:32, # CodeGen: 7
**     Abstract    :
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : RedLED
**          Pin for I/O                                    : TSI0_CH11/PTB18/TPM2_CH0
**          Pin signal                                     : 
**          Direction                                      : Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 0
**            Auto initialization                          : yes
**          Safe mode                                      : no
**     Contents    :
**         Init   - LDD_TDeviceData* RedLED_Init(LDD_TUserData *UserDataPtr);
**         Deinit - void RedLED_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         ClrVal - void RedLED_ClrVal(LDD_TDeviceData *DeviceDataPtr);
**         SetVal - void RedLED_SetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file RedLED.c
** @version 01.00
** @brief
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
*/         
/*!
**  @addtogroup RedLED_module RedLED module documentation
**  @{
*/         

/* MODULE RedLED. */

/* {Default RTOS Adapter} No RTOS includes */
#include "RedLED.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TUserData *UserDataPtr;          /* Pointer to user data */
} RedLED_TDeviceData;                  /* Device data structure type */

typedef RedLED_TDeviceData *RedLED_TDeviceDataPtr ; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static RedLED_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  RedLED_Init (component BitIO_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* RedLED_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  RedLED_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */

  /* Configure pin as output */
  /* GPIOB_PDDR: PDD|=0x00040000 */
  GPIOB_PDDR |= GPIO_PDDR_PDD(0x00040000);                                   

  /* Set initialization value */
  /* GPIOB_PDOR: PDO&=~0x00040000 */
  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(0x00040000));                                   

  /* Initialization of Port Control register */
  /* PORTB_PCR18: ISF=0,MUX=1 */
  PORTB_PCR18 = (uint32_t)((PORTB_PCR18 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                  
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_RedLED_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}
/*
** ===================================================================
**     Method      :  RedLED_Deinit (component BitIO_LDD)
*/
/*!
**     @brief
**          Deinitializes the device. Switches off the device, frees
**         the device data structure memory, interrupts vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void RedLED_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* GPIOB_PDDR: PDD&=~0x00040000 */
  GPIOB_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x00040000));                                   
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_RedLED_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  RedLED_ClrVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Clears (set to zero) the output value. It is equivalent to
**         the [PutVal(FALSE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void RedLED_ClrVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  GPIO_PDD_ClearPortDataOutputMask(RedLED_MODULE_BASE_ADDRESS, RedLED_PORT_MASK);
}

/*
** ===================================================================
**     Method      :  RedLED_SetVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Sets (to one) the output value. It is equivalent to the
**         [PutVal(TRUE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void RedLED_SetVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  GPIO_PDD_SetPortDataOutputMask(RedLED_MODULE_BASE_ADDRESS, RedLED_PORT_MASK);
}

/* END RedLED. */

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
