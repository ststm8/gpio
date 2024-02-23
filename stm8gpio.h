#pragma once

#ifndef __ststm8_gpio__
#define __ststm8_gpio__

// DDR input(=0) or output(=1)
// CR1 input: 0=float, 1=pull-up; output: 0=open-drain, 1=push-pull
// CR2 input: 0=no exint, 1=exint; output: 0=2MHz slope, 1=10MHz slope

// in, pull_up, no_int
#define gpio_configure_pin_in(_PORT, _PIN) \
    {                                      \
        (_PORT).DDR.byte &= ~_PIN;         \
        (_PORT).CR1.byte |= _PIN;          \
        (_PORT).CR2.byte &= ~_PIN;         \
    }

// out, push_pull, fast
#define gpio_configure_pin_out(_PORT, _PIN) \
    {                                       \
        (_PORT).DDR.byte |= _PIN;             \
        (_PORT).CR1.byte |= _PIN;             \
        (_PORT).CR2.byte |= _PIN;             \
    }

#define gpio_set_pin(_PORT, _PIN) (_PORT).ODR.byte |= _PIN
#define gpio_res_pin(_PORT, _PIN) (_PORT).ODR.byte &= ~_PIN

#define gpio_get_pin(_PORT, _PIN) ((_PORT).ODR.byte &= _PIN)
#define gpio_toggle_pin(_PORT, _PIN) ((_PORT).ODR.byte ^= _PIN)

#endif