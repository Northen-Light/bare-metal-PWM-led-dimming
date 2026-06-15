#define RCC_APB2ENR       *((volatile unsigned int *) 0x40021018)
#define RCC_APB1ENR       *((volatile unsigned int *) 0x4002101C)

#define AFIO_EXTICR2      *((volatile unsigned int *) 0x4001000C)

#define NVIC_ISER0        *((volatile unsigned int *) 0xE000E100)

#define TIM2_CR1          *((volatile unsigned int *) 0x40000000)
#define TIM2_CCMR1        *((volatile unsigned int *) 0x40000018)
#define TIM2_CCER         *((volatile unsigned int *) 0x40000020)
#define TIM2_PSC          *((volatile unsigned int *) 0x40000028)
#define TIM2_ARR          *((volatile unsigned int *) 0x4000002C)
#define TIM2_CCR1         *((volatile unsigned int *) 0x40000034)

#define GPIOA_CRL         *((volatile unsigned int *) 0x40010800)
#define GPIOA_IDR         *((volatile unsigned int *) 0x40010808)
#define GPIOA_ODR         *((volatile unsigned int *) 0x4001080C)

#define EXTI_IMR          *((volatile unsigned int *) 0x40010400)
#define EXTI_RTSR         *((volatile unsigned int *) 0x40010408)
#define EXTI_FTSR         *((volatile unsigned int *) 0x4001040C)
#define EXTI_PR           *((volatile unsigned int *) 0x40010414) 

#define SYST_CSR          *((volatile unsigned int *) 0xE000E010)
#define SYST_RVR          *((volatile unsigned int *) 0xE000E014)
#define SYST_CVR          *((volatile unsigned int *) 0xE000E018)