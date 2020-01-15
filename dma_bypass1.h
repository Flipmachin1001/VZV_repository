


#ifndef _DMA_H_
#define _DMA_H_

Uint16 set_dma0_ch0_i2s0_Lout(void);
Uint16 set_dma0_ch1_i2s0_Rout(void);
Uint16 set_dma0_ch2_i2s0_Lin(void);
Uint16 set_dma0_ch3_i2s0_Rin(void);



Uint16 set_dma0_ch2_i2s0_Lin_non(void);




void set_dma0_ch0_stop(void);
void set_dma0_ch1_stop(void);
void set_dma0_ch2_stop(void);
void set_dma0_ch3_stop(void);

void enable_dma_int(void);
interrupt void DMA_Isr(void);
void setDMA_address(void);

#endif
