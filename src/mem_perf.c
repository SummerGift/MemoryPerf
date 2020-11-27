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
#include "portme.h"

#define ITERATIONS     100
#define MEM_ADDR       (void *)0x10100000
#define MEM_LEN        0x100000

static uint32_t data_len = MEM_LEN * ITERATIONS;

static void memory_perf_8bit(void *addr, uint32_t len)
{
    volatile uint8_t *read_addr;
    float seconds, speed;


    printf("--------------------------------------\n");
    printf("8-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i++)
        {
            read_addr = (uint8_t *) (addr + i);
            *read_addr = 0x05;
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("8-bit write speed: %f M/s.\n", speed / 1000000);

    printf("8-bit read speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i++)
        {
            read_addr = (uint8_t *) (addr + i);
            asm volatile ("ldrb r0, [%0]\n"
                          ::"r"(read_addr): "r0");
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("8-bit Read speed: %f M/s.\n", speed / 1000000);
}

static void memory_perf_16bit(void *addr, uint32_t len)
{
    volatile uint16_t *read_addr;
    float seconds, speed;
    uint32_t data_len = 0x100000 * ITERATIONS;

    printf("--------------------------------------\n");
    printf("16-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 2)
        {
            read_addr = (uint16_t *) (addr + i);
            *read_addr = 0x05;
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("16-bit write speed: %f M/s.\n", speed / 1000000);

    printf("16-bit read speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 2)
        {
            read_addr = (uint16_t *) (addr + i);
            asm volatile ("ldrh r0, [%0]\n"
                          ::"r"(read_addr): "r0");
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("16-bit Read speed: %f M/s.\n", speed / 1000000);
}

static void memory_perf_32bit(void *addr, uint32_t len)
{
    volatile uint32_t *read_addr;
    float seconds, speed;
    uint32_t data_len = 0x100000 * ITERATIONS;

    printf("--------------------------------------\n");
    printf("32-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 4)
        {
            read_addr = (uint32_t *) (addr + i);
            *read_addr = 0x05;
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("32-bit Write speed: %f M/s.\n", speed / 1000000);

    printf("32-bit read speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 4)
        {
            read_addr = (uint32_t *) (addr + i);
            asm volatile ("ldr r0, [%0]\n"
                          ::"r"(read_addr): "r0");
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("32-bit Read speed: %f M/s.\n", speed / 1000000);
}

static int memory_perf(void)
{
    void *address = MEM_ADDR;
    uint32_t len = MEM_LEN;

    printf("Memory performance testing start...\n");
    printf("address: %p, length: 0x%lx\n", address, len);
    printf("Data length : %lu MB.\n", data_len / 1000000);

    memory_perf_8bit(address, len);
    memory_perf_16bit(address, len);
    memory_perf_32bit(address, len);

    printf("Memory performance completed.\n");
    return 0;
}
MSH_CMD_EXPORT(memory_perf, run memory performance test);
