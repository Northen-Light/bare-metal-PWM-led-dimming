#include "mmap-regs.h"

extern void main(void);
extern char _estack;
extern char _end_rodata_;
extern char _start_data_;
extern char _end_data_;
extern char _start_bss_;
extern char _end_bss_;

void Reset_Handler(void);
void HardFault_Handler(void);
void EXTI9_5_IRQHandler(void);
void Systick_Handler(void);

char step = 100, dir = 1;
unsigned int last_btn_press_time = 0, count = 0;
unsigned int g_ms_ticks = 0;

__attribute__((section(".isr_vector")))
char *vector_table[] = {
  &_estack,
  (char *)Reset_Handler,
  0,
  (char *)HardFault_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  (char *)Systick_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  (char *) EXTI9_5_IRQHandler
};

void Reset_Handler(void) {
  char *start_data_src = &_end_rodata_;
  char *start_data_dest = &_start_data_;
  char *end_data_dest = &_end_data_;

  while (start_data_dest != end_data_dest) {
    *start_data_dest++ = *start_data_src++;
  }

  char *start_bss = &_start_bss_;
  char *end_bss = &_end_bss_;

  while (start_bss != end_bss) {
    *start_bss = 0;
    start_bss++; 
  }

  SYST_RVR = 7999;
  SYST_CVR = 0;
  SYST_CSR = 7;

  main();
}

void HardFault_Handler(void) {
  while(1);
}

void EXTI9_5_IRQHandler(void) {
  EXTI_PR |= (1 << 5);
  if ((g_ms_ticks - last_btn_press_time) >= 200) {
    last_btn_press_time = g_ms_ticks;
    count++;
    TIM2_CCR1 += (dir ? step : -step);
    if (TIM2_CCR1 == 0) dir = 1;
    if (TIM2_CCR1 == TIM2_ARR + 1) dir = 0;
  }
}

void Systick_Handler(void) {
  g_ms_ticks++;
}