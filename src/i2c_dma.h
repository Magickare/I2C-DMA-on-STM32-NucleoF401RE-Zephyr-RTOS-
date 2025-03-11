#ifndef I2C_DMA_H
#define I2C_DMA_H

#include <zephyr/types.h>

void i2c_dma_init(void);
int i2c_dma_transfer(uint8_t *tx_buf, uint8_t *rx_buf, size_t len, uint16_t addr);

#endif // I2C_DMA_H

