#include "mmap-regs.h"

void main(void) {
  RCC_APB2ENR |= (1 << 2);
  RCC_APB2ENR |= (1 << 0);
  RCC_APB1ENR |= (1 << 0);

  GPIOA_CRL &= ~(0xF << 0);
  GPIOA_CRL |= (0xA << 0);

  GPIOA_CRL &= ~(0xF << 20);
  GPIOA_CRL |= (0x8 << 20);
  GPIOA_ODR |= (1 << 5);
  
  AFIO_EXTICR2 &= ~(0xF << 4);
  EXTI_IMR |= (1 << 5);
  EXTI_FTSR |= (1 << 5);
  EXTI_RTSR &= ~(1 << 5);
 
  NVIC_ISER0 |= (1 << 23);

  TIM2_PSC = 7;
  TIM2_ARR = 999;
  TIM2_CCMR1 |= (0x6 << 4);
  TIM2_CCMR1 |= (1 << 3);
  TIM2_CCER |= (1 << 0);
  TIM2_CCR1 = 0;
  TIM2_CR1 |= (1 << 0);
  while(1);
}