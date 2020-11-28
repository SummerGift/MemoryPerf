# Memory Performance Testing

## 1. 介绍

这是一个运行在 RT-Thread 上的内存性能测试软件包，用于测试 ARM CPU 的 Memory 读写性能以及 Cache 性能。

### 1.1 目录结构

| 名称 | 说明 |
| ---- | ---- |
| inc  | 头文件目录 |
| src  | 源代码目录 |

### 1.2 许可证

`MemoryPerf` 软件包遵循 MIT 许可，详见 `LICENSE` 文件。

### 1.3 依赖

具有良好的移植性，无操作系统依赖。

## 2. 如何打开 `MemoryPerf`

> 说明：描述该 package 位于 menuconfig 的位置，并对与其相关的配置进行介绍

使用 `MemoryPerf package` 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    tools packages --->
        [*] MemoryPerf: Memory Performance Testing for ARM CPU.
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3. 使用 `MemoryPerf`

- 在 `msh` 中运行  `<memory_perf 0x10100000 0x100000>` 命令

### 3.1 测试示例一

测试环境 `zynq7045 Cortex-A9 800M uncached -O3` ：

```shell
msh />memory_perf 0x10100000 0x100000
Memory performance testing start...
address: 0x10100000, length: 0x100000
Data length : 209 MB.
--------------------------------------
8-bit write speed test begin.
Spend time : 7.480000 s.
8-bit write speed: 28.036793 M/s.
8-bit read speed test begin.
Spend time : 5.380000 s.
8-bit Read speed: 38.980518 M/s.
--------------------------------------
16-bit write speed test begin.
Spend time : 3.740000 s.
16-bit write speed: 56.073586 M/s.
16-bit read speed test begin.
Spend time : 2.690000 s.
16-bit Read speed: 77.961037 M/s.
--------------------------------------
32-bit write speed test begin.
Spend time : 1.870000 s.
32-bit Write speed: 112.147171 M/s.
32-bit read speed test begin.
Spend time : 1.350000 s.
32-bit Read speed: 155.344589 M/s.
Memory performance completed.
```

### 3.2 测试示例二

测试环境  `zynq7045 Cortex-A9 800M cached -O3` ：

```shell
msh />memory_perf 0x10100000 0x100000 # Testing with cache
Memory performance testing start...
address: 0x10100000, length: 0x100000
Data length : 209 MB.
--------------------------------------
8-bit write speed test begin.
Spend time : 0.290000 s.
8-bit write speed: 723.155884 M/s.    # Achieve the best write performance
8-bit read speed test begin.
Spend time : 0.490000 s.
8-bit Read speed: 427.990204 M/s.
--------------------------------------
16-bit write speed test begin.
Spend time : 0.290000 s.
16-bit write speed: 723.155884 M/s.   # Achieve the best write performance
16-bit read speed test begin.
Spend time : 0.410000 s.
16-bit Read speed: 511.500488 M/s.
--------------------------------------
32-bit write speed test begin.
Spend time : 0.290000 s.
32-bit Write speed: 723.155884 M/s.   # Achieve the best write performance
32-bit read speed test begin.
Spend time : 0.370000 s.
32-bit Read speed: 566.797852 M/s.
Memory performance completed.
```

### 3.3 测试示例三

测试环境  `stm32f407-atk-explorer Cortex-M4 168M SRAM uncached -O3` ：

```shell
msh >memory_perf 0x20010000 0x10000
Memory performance testing start...
address: 0x20010000, length: 0x10000, iterations: 200
Data length : 13 MB.
--------------------------------------
8-bit write speed test begin.
Spend time : 0.139000 s.
8-bit write speed: 94.296402 M/s.
8-bit read speed test begin.
Spend time : 0.361000 s.
8-bit Read speed: 36.308033 M/s.
--------------------------------------
16-bit write speed test begin.
Spend time : 0.070000 s.
16-bit write speed: 187.245712 M/s.
16-bit read speed test begin.
Spend time : 0.180000 s.
16-bit Read speed: 72.817780 M/s.
--------------------------------------
32-bit write speed test begin.
Spend time : 0.035000 s.
32-bit Write speed: 374.491425 M/s.
32-bit read speed test begin.
Spend time : 0.090000 s.
32-bit Read speed: 145.635559 M/s.
Memory performance completed.

```

## 4、注意事项

- 检查内存测试地址与长度是否设置正确
- 测试内存性能时推荐对比打开 cache 与 关闭 cache 的测试结果

## 5、联系方式

* 维护：我夏了夏天 （SummerGift）
* 主页：https://github.com/SummerLife
