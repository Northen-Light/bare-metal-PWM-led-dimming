#include "mmap-regs.h"

extern unsigned int g_ms_ticks;

char step = 100, dir = 1;
unsigned int last_update = 0;

void main(void) {
  RCC_APB2ENR |= (1 << 2);
  RCC_APB1ENR |= (1 << 0);

  GPIOA_CRL &= ~(0xF << 0);
  GPIOA_CRL |= (0xA << 0);

  TIM2_PSC = 7;
  TIM2_ARR = 999;
  TIM2_CCMR1 |= (0x6 << 4);
  TIM2_CCMR1 |= (1 << 3);
  TIM2_CCER |= (1 << 0);
  TIM2_CCR1 = 0;
  TIM2_CR1 |= (1 << 0);

  while(1) {
    if (g_ms_ticks - last_update >= 10) {
      last_update = g_ms_ticks;
      TIM2_CCR1 += (dir ? step : -step);
      if (TIM2_CCR1 >= 900) dir = 0;
      if (TIM2_CCR1 <= 100) dir = 1;
    }
  }
}