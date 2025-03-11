#ifndef BOARD_H
#define BOARD_H

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>

// Define the I2C instance being used
#define I2C_DEV DT_LABEL(DT_NODELABEL(i2c1))

// Define the I2C slave device address (modify as needed)
#define I2C_SLAVE_ADDR 0x68  

// Define DMA channel (modify according to hardware setup)
#define DMA_CHANNEL 1

// Function to initialize board-specific peripherals
void board_init(void);

#endif // BOARD_H

