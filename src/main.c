#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log.h>
#include "board.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#define I2C_DEV DT_LABEL(DT_NODELABEL(i2c1))
#define I2C_SLAVE_ADDR 0x68  // Example slave address (modify accordingly)

static const struct device *i2c_dev;

void main(void) {
    LOG_INF("Initializing board...");
    board_init();

    LOG_INF("Starting I2C DMA Example");

    i2c_dev = device_get_binding(I2C_DEV);
    if (!i2c_dev) {
        LOG_ERR("Failed to get I2C device");
        return;
    }

    uint8_t data_write[2] = {0x00, 0xFF}; // Example data
    uint8_t data_read[2];

    // Write data
    if (i2c_write(i2c_dev, data_write, sizeof(data_write), I2C_SLAVE_ADDR) != 0) {
        LOG_ERR("I2C write failed");
    } else {
        LOG_INF("I2C write successful");
    }

    // Read data
    if (i2c_read(i2c_dev, data_read, sizeof(data_read), I2C_SLAVE_ADDR) != 0) {
        LOG_ERR("I2C read failed");
    } else {
        LOG_INF("I2C read successful: 0x%X, 0x%X", data_read[0], data_read[1]);
    }
}

