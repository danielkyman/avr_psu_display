#include <avr/io.h>

#define SCALE 1

struct ADCCh{
    uint8_t channel;
    uint16_t samples[16];
    uint8_t sample_count;
    uint16_t value;
    struct  ADCCh *next;
};

struct ADCList{
    uint16_t size;
    struct ADCCh *front;
    struct ADCCh *cur;
};

struct ADCList *_adc_lst_init();
void _add_adc(struct ADCList *lst, uint8_t num);

struct ADCList * adc_init();
void adc_convert(uint16_t reading, uint8_t *digits);
void next_adc(struct ADCList *lst);
void adc_add_reading(struct ADCCh *ch, uint16_t reading);
