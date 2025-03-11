# UART and I2C with DMA on STM32 Nucleo-F401RE using Zephyr RTOS

## Overview
This project demonstrates the implementation of **UART and I2C with DMA** on the STM32 Nucleo-F401RE development board using **Zephyr RTOS**. The project is structured to use Zephyr's device model, logging, and configuration framework efficiently.

## Features
- **UART Communication with DMA** for efficient data transfer.
- **I2C Communication with DMA** to interface with peripherals.
- Uses **Zephyr RTOS** for handling peripherals and task management.
- Configurable via **prj.conf** and **DTS overlays**.
- Organized modular structure for scalability.

---

## Project Structure
```
UART-I2C-DMA-Zephyr/
├── app/
│   ├── src/
│   │   ├── main.c            # Main application entry
│   │   ├── uart_dma.c        # UART DMA implementation
│   │   ├── i2c_dma.c         # I2C DMA implementation
│   ├── include/
│   │   ├── board.h           # Board configuration and macros
│   ├── prj.conf              # Zephyr project configurations
│   ├── CMakeLists.txt        # Build system config
│   ├── west.yml              # West manifest for dependencies
│   ├── dts/
│   │   ├── stm32f401re.overlay # Device tree overlay for peripheral configs
```

---

## Setup and Build Instructions

### **1. Install Zephyr SDK and West Tool**
Follow [Zephyr's Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html) to install required dependencies.

### **2. Clone the Repository**
```sh
git clone https://github.com/Magickare/UART-DMA-on-STM32-NucleoF401RE-Zephyr-RTOS-.git
cd UART-DMA-on-STM32-NucleoF401RE-Zephyr-RTOS-
```

### **3. Initialize and Update West Modules**
```sh
west init -l app
west update
west zephyr-export
```

### **4. Build the Project**
```sh
west build -b nucleo_f401re app
```

### **5. Flash to STM32 Board**
```sh
west flash
```

### **6. Monitor Serial Output (UART)**
```sh
minicom -D /dev/ttyUSB0 -b 115200
```

---

## Configuration Details

### **prj.conf (Zephyr Configuration File)**
```ini
CONFIG_UART_CONSOLE=n
CONFIG_SERIAL=y
CONFIG_UART_ASYNC_API=y
CONFIG_DMA=y
CONFIG_I2C=y
```

### **Device Tree Overlay (`dts/stm32f401re.overlay`)**
```dts
&usart2 {
    status = "okay";
    current-speed = <115200>;
    dma-channel = <1>;
};

&i2c1 {
    status = "okay";
    dma-channel = <1>;
};
```

---

## Code Implementation

### **`src/main.c` (Main Application Entry)**
```c
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "board.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

void main(void) {
    LOG_INF("Starting UART and I2C DMA Example");
    board_init();
}
```

### **`src/uart_dma.c` (UART DMA Implementation)**
```c
#include "board.h"
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(uart_dma, LOG_LEVEL_DBG);
void uart_dma_init(void) {
    LOG_INF("Initializing UART with DMA");
}
```

### **`src/i2c_dma.c` (I2C DMA Implementation)**
```c
#include "board.h"
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(i2c_dma, LOG_LEVEL_DBG);
void i2c_dma_init(void) {
    LOG_INF("Initializing I2C with DMA");
}
```

---

## Troubleshooting
### **Common Issues and Solutions**
- **Build Fails**: Ensure Zephyr dependencies are correctly set up using `west update`.
- **Flashing Error**: Check board connection and permissions for `/dev/ttyUSB0`.
- **No UART Output**: Ensure baud rate is set to `115200` and `CONFIG_UART_CONSOLE=n` in `prj.conf`.

---

## Contributing
Feel free to fork this repository and submit pull requests for improvements.

## License
This project is open-source and licensed under the MIT License.

---

### **Contact**
For queries or contributions, contact **MAGIC KARE - Embedded Cluster**.

---
🚀 **Happy Coding with Zephyr on STM32!** 🚀

