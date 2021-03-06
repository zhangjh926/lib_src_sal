#ifndef _LDS_FPGA_OPERATION_H
#define _LDS_FPGA_OPERATION_H

#include "lds_hal_common.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef enum   _LDS_FPGA_ErrorNo{
	LDS_FPGA_OPEN_ERROR,
	LDS_FPGA_INIT_ERROR,
	LDS_FPGA_START_ERROR,
}LDS_FPGA_ErrorNo;

typedef enum tagCTRL_FPGA
{
	LDS_CTRL_FPGA_END,
	LDS_CTRL_FPGA_SET_PARAM,
	LDS_CTRL_FPGA_SET_OUTPUT,
	LDS_CTRL_FPGA_MAX
}LDS_CTRL_FPGA;

typedef struct _LDS_FPGA_CTX{
	char dev_name[128];
	char dev_fd;
    LDS_FPGA_ErrorNo curr_err_state;
}LDS_FPGA_CTX;


struct LDS_FPGA_OPERATION
{
    struct  LDS_HAL_COMMON base;    
	const   char		  *name;

    int     (*ioctl)(LDS_FPGA_CTX *ctx, LDS_CTRL_FPGA type, ...);
};

extern struct LDS_FPGA_OPERATION lds_hal_fpga;


#ifdef __cplusplus
}
#endif

#endif