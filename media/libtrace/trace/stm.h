#ifndef __INC_STM_H
#define __INC_STM_H

#include <inc/type.h>

#define STM_NUM_CHANNEL 256

typedef struct {
    t_shared_reg osmo[2];
    t_shared_reg osmot[2];
} t_stm_msg_reg;

typedef struct
{
    t_stm_msg_reg channel[STM_NUM_CHANNEL];
} t_stm_channel;

#endif /* __INC_STM_H */
