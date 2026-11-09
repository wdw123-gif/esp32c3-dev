# esp32c3-dev

ESP32-C3 开发工程（基于 ESP-IDF v5.3.x）

## 功能

- 上电打印芯片信息与堆内存
- GPIO8 板载 LED 每秒闪烁一次
- 串口日志便于观察启动状态

## 环境要求

- ESP-IDF v5.3.5（或 v5.1 以上）
- 目标芯片：ESP32-C3

## 编译与烧录

```bash
# 1. 激活 ESP-IDF 环境（路径按你的实际安装位置调整）
. ~/esp/esp-idf/export.sh

# 2. 设置目标芯片（首次需要）
cd ~/esp32c3-dev
idf.py set-target esp32c3

# 3. 编译
idf.py build

# 4. 烧录并打开串口监视器（把 /dev/cu.usbmodem* 换成你的实际串口）
idf.py -p /dev/cu.usbmodem101 flash monitor
```

退出监视器：`Ctrl + ]`

## 引脚

| 用途 | GPIO |
|---|---|
| 板载 LED | 8（低电平点亮） |

如果板载 LED 不在 GPIO8，修改 `main/main.c` 中的 `LED_GPIO`。

## 目录结构

```
esp32c3-dev/
├── CMakeLists.txt        # 顶层构建入口
├── main/
│   ├── CMakeLists.txt    # 组件注册
│   └── main.c            # 应用逻辑
└── README.md
```

## 许可

MIT
