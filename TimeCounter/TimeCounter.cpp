#include "TimeCounter.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addString(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1);

    if(result == NULL)
    {
        fprintf(stderr, "メモリの確保に失敗しました\n");
        exit(EXIT_FAILURE);
    }

    // str1 をコピー
    strcpy(result, str1);
    // str2 を結合
    strcat(result, str2);

    return result;
}

TimeCounter* create_time_counter(const char* path)
{
    TimeCounter* counter = new TimeCounter;
    counter->path = path;
    return counter;
}

void start_counter(TimeCounter* counter)
{
    counter->start = std::chrono::system_clock::now();
}

void stop_counter(TimeCounter* counter)
{
    counter->stop = std::chrono::system_clock::now();
    auto dur = counter->stop - counter->start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::string text = std::to_string(ms);
    write_file(counter, text.c_str());
}

void printf_message(const char* msg)
{
    std::cout << msg << std::endl;
}

void write_file(TimeCounter* counter, const char* text)
{
    std::fstream file;
    file.open(counter->path, std::ios_base::app);
    if (file.is_open())
    {
        std::string message = addString(text, "\r\n");
        printf_message(message.c_str());
        file.write(message.data(), message.size());
    }
}

void delete_time_counter(TimeCounter* counter)
{
    delete counter;
}

