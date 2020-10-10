#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "liblds_hal_video_encode_base.h"



static int lds_hal_video_encoder_open(char *dev_name)
{
    return 0;
}

static int lds_hal_video_encoder_close(int dev_fd)
{
    return 0;
}

static int lds_hal_video_encoder_start(void)
{
    return 0;
}

static int lds_hal_video_encoder_stop(void)
{
    return 0;
}

static int lds_hal_video_encoder_init(void)
{
    return 0;
}

static int lds_hal_video_encoder_deinit(void)
{
    return 0;
}

static int lds_hal_video_config_param(video_param * config_param)
{
    return 0;
}

static int lds_hal_video_frame_callback(video_capture_buffer capture_buffer)
{
    return 0;
}


struct LDS_VIDEO_ENCODE_OPERATION lds_hal_video_encoder = {
    .name                   = "lds_hal_video_encoder",
    .comm.lds_hal_open      = lds_hal_video_encoder_open,
    .comm.lds_hal_close     = lds_hal_video_encoder_close,
    .comm.lds_hal_start     = lds_hal_video_encoder_start,
    .comm.lds_hal_stop      = lds_hal_video_encoder_stop,
    .comm.lds_hal_init      = lds_hal_video_encoder_init,
    .comm.lds_hal_deinit    = lds_hal_video_encoder_deinit,
    .set_video_frame_callback = lds_hal_video_frame_callback,
    .set_capture_config_param = lds_hal_video_config_param,
};

