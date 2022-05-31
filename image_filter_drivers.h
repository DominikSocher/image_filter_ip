#ifndef IMAGE_FILTER_DRIVERS_H_INCLUDED
#define IMAGE_FILTER_DRIVERS_H_INCLUDED

#include "image_filter_csr.h"

// Read and write macros for the component
#define image_filter_read(offset)               IORD_32DIRECT  (FILTER_0_IMAGE_FILTER_INTERNAL_INST_AVS_CRA_BASE, offset)
#define image_filter_write(offset, data)        IOWR_32DIRECT  (FILTER_0_IMAGE_FILTER_INTERNAL_INST_AVS_CRA_BASE, offset, data)

// Read and write macros for the component memory (make sure correct bit-precision for macro is used)
#define image_filter_memory_read(offset)        IORD_32DIRECT  (FILTER_0_IMAGE_FILTER_INTERNAL_INST_AVS_PIXEL_DATA_BASE, offset)
#define image_filter_memory_write(offset, data) IOWR_32DIRECT  (FILTER_0_IMAGE_FILTER_INTERNAL_INST_AVS_PIXEL_DATA_BASE, offset, data)

// Component register macros
#define image_filter_enable_interrupt()         image_filter_write  (IMAGE_FILTER_CSR_INTERRUPT_ENABLE_REG, IMAGE_FILTER_CSR_INTERRUPT_ENABLE_MASK & 0x1)
#define image_filter_disable_interrupt()        image_filter_write  (IMAGE_FILTER_CSR_INTERRUPT_ENABLE_REG, IMAGE_FILTER_CSR_INTERRUPT_ENABLE_MASK & 0x0)
#define image_filter_clear_done_status()        image_filter_write  (IMAGE_FILTER_CSR_INTERRUPT_STATUS_REG, IMAGE_FILTER_CSR_INTERRUPT_STATUS_MASK & 0x1)
#define image_filter_start()                    image_filter_write  (IMAGE_FILTER_CSR_START_REG, IMAGE_FILTER_CSR_START_MASK & 0x1)
#define image_filter_busy()                     image_filter_read   (IMAGE_FILTER_CSR_BUSY_REG) & IMAGE_FILTER_CSR_BUSY_MASK
#define image_filter_done()                     image_filter_read   (IMAGE_FILTER_CSR_INTERRUPT_STATUS_REG) & IMAGE_FILTER_CSR_INTERRUPT_STATUS_MASK

#endif
