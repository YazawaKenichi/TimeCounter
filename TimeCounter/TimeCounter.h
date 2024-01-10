#ifndef __TIMECOUNTER_HPP__
#define __TIMECOUNTER_HPP__

#include <chrono>
#include <fstream>
#include <string>

struct TimeCounter
{
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point stop;
    std::string path;
};

TimeCounter* create_time_counter(const char* path);
void start_counter(TimeCounter* counter);
void stop_counter(TimeCounter* counter);
void printf_message(const char* msg);
void write_file(TimeCounter* counter, const char* text);
void delete_time_counter(TimeCounter* counter);

#endif

