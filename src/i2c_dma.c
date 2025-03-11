#include "i2c_dma.h"
#include "board.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/dma.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(i2c_dma, LOG_LEVEL_DBG);

#define I2C_DEV DT_LABEL(DT_NODELABEL(i2c1))
#define DMA_DEV DT_LABEL(DT_NODELABEL(dma1))

static const struct device *i2c_dev;
static const struct device *dma_dev;

void i2c_dma_init(void) {
    i2c_dev = device_get_binding(I2C_DEV);
    dma_dev = device_get_binding(DMA_DEV);

    if (!i2c_dev || !dma_dev) {
        LOG_ERR("Failed to get I2C or DMA device");
        return;
    }

    LOG_INF("I2C and DMA initialized");
}

int i2c_dma_transfer(uint8_t *tx_buf, uint8_t *rx_buf, size_t len, uint16_t addr) {
    if (i2c_write(i2c_dev, tx_buf, len, addr) != 0) {
        LOG_ERR("I2C write failed");
        return -1;
    }

    if (i2c_read(i2c_dev, rx_buf, len, addr) != 0) {
        LOG_ERR("I2C read failed");
        return -1;
    }

    LOG_INF("I2C DMA Transfer Successful");
    return 0;
}

