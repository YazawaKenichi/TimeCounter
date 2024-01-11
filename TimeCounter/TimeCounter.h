#ifndef __TIMECOUNTER_H__
#define __TIMECOUNTER_H__

#include <stdio.h>
#include <time.h>

typedef struct TimeCounter_
{
    time_t start;
    time_t stop;
    const char* path;
} TimeCounter;

char* addString(const char* str1, const char* str2);
const char* int_to_string(int value);
unsigned long long int  getTime();
void printf_message(const char* msg);
void write_file(TimeCounter* counter, const char* text);
TimeCounter* create_time_counter(const char* path);
void start_counter(TimeCounter* counter);
void stop_counter(TimeCounter* counter);

#endif

