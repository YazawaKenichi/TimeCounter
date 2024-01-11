#include "TimeCounter.h"
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

const char* int_to_string(int value)
{
    char* buffer;
    int size = snprintf(NULL, 0, "%d", value);  // 必要なバッファのサイズを取得
    buffer = (char*)malloc(size + 1);  // メモリを動的に確保
    snprintf(buffer, size + 1, "%d", value);  // 整数を文字列に変換
    return buffer;
}

unsigned long long int  getTime()
{
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    unsigned long long int now = t.tv_sec * 1000 + t.tv_nsec / 1000000;
    // time_t now;
    // now = time(NULL);
    return now;
}

void printf_message(const char* msg)
{
    printf("%s\r\n", msg);
}

void write_file(TimeCounter* counter, const char* text)
{
    FILE *fp;
    fp = fopen(counter->path, "a");
    if(fp == NULL)
    {
        return;
    }

    printf_message(text);

    fprintf(fp, "%s\r\n", text);
}

TimeCounter* create_time_counter(const char* path)
{
    //! TimeCounter 構造体のポインタを作成
    TimeCounter* counter;
    //! 構造体ポインタに path を作成
    counter->path = path;
    //! 構造体ポインタを返す
    return counter;
}

void start_counter(TimeCounter* counter)
{
    counter->start = getTime();
}

void stop_counter(TimeCounter* counter)
{
    counter->stop = getTime();
    time_t dur = counter->stop - counter->start;
    const char* text = int_to_string(dur);
    write_file(counter, text);
}

