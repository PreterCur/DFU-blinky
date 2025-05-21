
#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <stdint.h>


#include "gd32f10x_libopt.h"
#include "systick.h"


void rcu_config (void);
void gpio_config(void);
void nvic_config(void);


#endif