#define RCC_APB2ENR       *((volatile unsigned int *) 0x40021018)
#define RCC_APB1ENR       *((volatile unsigned int *) 0x4002101C)

#define TIM2_CR1          *((volatile unsigned int *) 0x40000000)
#define TIM2_CCMR1        *((volatile unsigned int *) 0x40000018)
#define TIM2_CCER         *((volatile unsigned int *) 0x40000020)
#define TIM2_PSC          *((volatile unsigned int *) 0x40000028)
#define TIM2_ARR          *((volatile unsigned int *) 0x4000002C)
#define TIM2_CCR1         *((volatile unsigned int *) 0x40000034)

#define GPIOA_CRL         *((volatile unsigned int *) 0x40010800)

#define SYST_CSR          *((volatile unsigned int *) 0xE000E010)
#define SYST_RVR          *((volatile unsigned int *) 0xE000E014)
#define SYST_CVR          *((volatile unsigned int *) 0xE000E018)