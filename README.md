# Memory Performance Testing

## 1、介绍

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

## 2、如何打开 `MemoryPerf`

> 说明：描述该 package 位于 menuconfig 的位置，并对与其相关的配置进行介绍

使用 `MemoryPerf package` 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    tools packages --->
        [*] MemoryPerf: Memory Performance Testing for ARM CPU.
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 `MemoryPerf`

- 设置需要测试内存的地址和长度后重新编译
- 在 `msh` 中运行 `memory_perf` 命令
- 运行结果如下

```
msh />memory_perf
Memory performance testing start...
address: 0x10100000, length: 100000
--------------------------------------
8-bit write speed test begin.
Data length : 104 MB.
Spend time : 3.740000 s.
8-bit write speed: 28.036793 M/s.
8-bit read speed test begin.
Data length : 104 MB.
Spend time : 3.570000 s.
8-bit Read speed: 29.371878 M/s.
--------------------------------------
16-bit write speed test begin.
Data length : 104 MB.
Spend time : 1.870000 s.
16-bit write speed: 56.073586 M/s.
16-bit read speed test begin.
Data length : 104 MB.
Spend time : 1.790000 s.
16-bit Read speed: 58.579666 M/s.
--------------------------------------
32-bit write speed test begin.
Data length : 104 MB.
Spend time : 0.930000 s.
32-bit Write speed: 112.750107 M/s.
32-bit read speed test begin.
Data length : 104 MB.
Spend time : 0.890000 s.
32-bit Read speed: 117.817528 M/s.
Memory performance completed.
```

## 4、注意事项

- 无

## 5、联系方式 & 感谢

* 维护：我夏了夏天 （SummerGift）
* 主页：https://github.com/SummerLife
