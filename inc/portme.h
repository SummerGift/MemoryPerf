/*
 * Copyright (c) 2020 SummerGift (summergift2019@gmail.com)
 *
 * MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-11-27     SummerGift   first version
 */

#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>

#define NSECS_PER_SEC          RT_TICK_PER_SECOND
#define CORETIMETYPE           rt_tick_t
#define MYTIMEDIFF(fin,ini)    ((fin)-(ini))
#define GETMYTIME(_t)          (*_t=rt_tick_get())

void start_time_mp(void);
void stop_time_mp(void);
CORETIMETYPE get_time_mp(void);
