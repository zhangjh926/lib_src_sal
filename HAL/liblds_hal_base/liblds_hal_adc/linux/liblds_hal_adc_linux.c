#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "liblds_hal_adc_base.h"


/* Define  -------------------------------------------------------------------*/
/* Define variable  ----------------------------------------------------------*/

/* Define extern variable & function  ----------------------------------------*/

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_open(char *dev_name)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_close(int dev_fd)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_start(void)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_init(void)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_deinit(void)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_stop(void)
{
	return 0;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_adc_ioctl(LDS_CTRL_ADC type, ...)
{
	switch(type)
	{
		case LDS_CTRL_ADC_GET_VALUE:
			break;
		default:
			break;
	}
	
	return 0;
}

struct LDS_ADC_OPERATION  lds_hal_adc = {
	.name                       = "LDS_HAL_ADC",
	.comm.lds_hal_open          = lds_hal_adc_open,
	.comm.lds_hal_close         = lds_hal_adc_close,
	.comm.lds_hal_start         = lds_hal_adc_start,
	.comm.lds_hal_stop          = lds_hal_adc_stop,
	.comm.lds_hal_init          = lds_hal_adc_init,
	.comm.lds_hal_deinit        = lds_hal_adc_deinit,
	.ioctl                      = lds_hal_adc_ioctl, 
	
};