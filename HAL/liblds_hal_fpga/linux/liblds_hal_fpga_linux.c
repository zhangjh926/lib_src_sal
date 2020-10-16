#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "liblds_hal_fpga_base.h"

/* Define  -------------------------------------------------------------------*/
struct LDS_FPGA_CTX{
    LDS_FPGA_ErrorNo curr_err_state;
};

/* Define variable  ----------------------------------------------------------*/
static  struct LDS_FPGA_CTX ctx;
/* Define extern variable & function  ----------------------------------------*/



/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_fpga_open(char *dev_name)
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
static int lds_hal_fpga_close(int dev_fd)
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
static int lds_hal_fpga_init(void *param)
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
static int lds_hal_fpga_deinit(void)
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
static int lds_hal_fpga_start(void)
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
static int lds_hal_fpga_stop(void)
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
static int lds_hal_fpga_get_error(void)
{
    return ctx.curr_err_state;
}

/*******************************************************************************
*	Description		:
*	Argurments		:
*	Return value	:
*	Modify			:
*	warning			:
*******************************************************************************/
static int lds_hal_fpga_ioctl(LDS_CTRL_FPGA type, ...)
{
	switch(type)
	{
		default:
			break;
	}
	
	return 0;
}


struct LDS_FPGA_OPERATION lds_hal_fpga = {
    .name                   = "lds_hal_fpga",
    .comm.lds_hal_open      = lds_hal_fpga_open,
    .comm.lds_hal_close     = lds_hal_fpga_close,
    .comm.lds_hal_start     = lds_hal_fpga_start,
    .comm.lds_hal_stop      = lds_hal_fpga_stop,
    .comm.lds_hal_init      = lds_hal_fpga_init,
    .comm.lds_hal_deinit    = lds_hal_fpga_deinit,
    .comm.lds_hal_get_error = lds_hal_fpga_get_error,
    .ioctl                  = lds_hal_fpga_ioctl,
};