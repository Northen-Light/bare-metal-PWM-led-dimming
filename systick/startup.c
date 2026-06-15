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
void Systick_Handler(void);

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
  (char *)Systick_Handler
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

void Systick_Handler(void) {
  g_ms_ticks++;
}