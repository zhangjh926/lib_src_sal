该目录主要实现HAL层功能模块不通用部分的代码实现

audio 	: 包含麦克风mic输入和speaker模块差异化的部分实现。默认采用的alsa框架，由于平台的不同，有些芯片可能并不支持alsa框架，只能直接控制驱动来实现。

video	: 由于不同芯片平台的视频操作接口不同，所以需要在此差异化对待实现.

base 	: 由于硬件设计导致的不同通用的模块的差异化代码实现.

platform: 平台相关的模块代码或者库文件. 接口按照HAL层定义的接口来封装实现.
