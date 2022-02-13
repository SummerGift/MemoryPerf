/*
 * Copyright (c) 2020 SummerGift (summergift2019@gmail.com)
 *
 * MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-11-27     SummerGift   first version
 * 2020-11-28     SummerGift   optimize cmd
 * 2022-01-27     geniusgogo   porting riscv
 */

#include <stdio.h>
#include "portme.h"

#define __version__ "1.0.0"

#define ITERATIONS     200

static mp_u32 data_len;

static void memory_perf_8bit(void *addr, mp_u32 len)
{
    volatile mp_u8 *read_addr;
    mp_f32 seconds, speed;


    printf("--------------------------------------\n");
    printf("8-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i+=8)
        {
            read_addr = (mp_u8 *) (addr + i);
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
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
        for(int i = 0; i < len; i+=8)
        {
            read_addr = (mp_u8 *) (addr + i);
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lb a6, (%0)\n"
                          ::"r"(read_addr): "a6");
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("8-bit Read speed: %f M/s.\n", speed / 1000000);
}

static void memory_perf_16bit(void *addr, mp_u32 len)
{
    volatile mp_u16 *read_addr;
    mp_f32 seconds, speed;

    printf("--------------------------------------\n");
    printf("16-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 16)
        {
            read_addr = (mp_u16 *) (addr + i);
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
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
        for(int i = 0; i < len; i += 16)
        {
            read_addr = (mp_u16 *) (addr + i);
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lh a6, (%0)\n"
                          ::"r"(read_addr): "a6");
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("16-bit Read speed: %f M/s.\n", speed / 1000000);
}

static void memory_perf_32bit(void *addr, mp_u32 len)
{
    volatile mp_u32 *read_addr;
    mp_f32 seconds, speed;

    printf("--------------------------------------\n");
    printf("32-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 32)
        {
            read_addr = (mp_u32 *) (addr + i);
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
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
        for(int i = 0; i < len; i += 32)
        {
            read_addr = (mp_u32 *) (addr + i);
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("lw a6, (%0)\n"
                          ::"r"(read_addr): "a6");
        }
    }
    stop_time_mp();

    seconds = (mp_u32) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("32-bit Read speed: %f M/s.\n", speed / 1000000);
}

#ifdef PKG_MEMORYPERF_ENABLE_64BIT
static void memory_perf_64bit(void *addr, mp_u32 len)
{
    volatile mp_u64 *read_addr;
    mp_f32 seconds, speed;

    printf("--------------------------------------\n");
    printf("64-bit write speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 64)
        {
            read_addr = (mp_u64 *) (addr + i);
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
            *read_addr++ = 0x55;
        }
    }
    stop_time_mp();

    seconds = (unsigned int) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("64-bit Write speed: %f M/s.\n", speed / 1000000);

    printf("64-bit read speed test begin.\n");

    start_time_mp();
    for(int i = 0; i < ITERATIONS; i++)
    {
        for(int i = 0; i < len; i += 64)
        {
            read_addr = (mp_u64 *) (addr + i);
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr++): "a6");
            asm volatile ("ld a6, (%0)\n"
                          ::"r"(read_addr): "a6");
        }
    }
    stop_time_mp();

    seconds = (mp_u32) get_time_mp() / (NSECS_PER_SEC * 1.0);
    speed = data_len / seconds;

    printf("Spend time : %f s.\n", seconds);
    printf("64-bit Read speed: %f M/s.\n", speed / 1000000);
}
#endif

static void memory_perf(int argc, char** argv)
{
    printf("\nMemoryPerf version " __version__ " \n");
    printf("Copyright (c) 2022 SummerGift (summergift2019@gmail.com)\n");
    printf("Licensed under the MIT License version.\n\n");
#ifdef PKG_MEMORYPERF_USING_HEAP
#if PKG_MEMORYPERF_ALLOC_SIZE <= 0
#error PKG_MEMORYPERF_ALLOC_SIZE must be > 0
#endif
    mp_u32 len = PKG_MEMORYPERF_ALLOC_SIZE;
    void *address = MEMPERF_MALLOC(len);

    if (!address)
    {
        printf("memperf malloc failure, alloc size:0x%x\n", len);
        return;
    }
#else
    if (argc != 3)
    {
        printf("Please set test address and length correctly.\n");
        printf("Example: <memory_perf 0x10100000 0x100000>\n");
        return;
    }

    void *address = (void *)strtoul(argv[1] + 2, NULL, 16);
    mp_u32 len = (mp_u32)strtoul(argv[2] + 2, NULL, 16);
#endif
    data_len = ITERATIONS * len;

    printf("Memory performance testing start...\n");
    printf("address: %p, length: 0x%x, iterations: %d\n", address, len, ITERATIONS);
    printf("Data length : %u MB.\n", data_len / 1000000);

    memory_perf_8bit(address, len);
    memory_perf_16bit(address, len);
    memory_perf_32bit(address, len);
#ifdef PKG_MEMORYPERF_ENABLE_64BIT
    memory_perf_64bit(address, len);
#endif
    printf("Memory performance completed.\n");
#ifdef PKG_MEMORYPERF_USING_HEAP
    if (address != NULL)
    {
        MEMPERF_FREE(address);
    }
#endif
}
MSH_CMD_EXPORT_ALIAS(memory_perf, memory_perf, run memory performance test);