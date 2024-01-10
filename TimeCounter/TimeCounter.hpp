#ifndef __TIMECOUNTER_HPP__
#define __TIMECOUNTER_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

namespace TimeCounter
{
    class TimeCounter
    {
        public:
            TimeCounter(std::string);
            void startCounter();
            void stopCounter();
            void printf(std::string);
            void writef(std::string);
            std::string path;
            std::chrono::system_clock::time_point start;
            std::chrono::system_clock::time_point stop;
        private:
    };
}

#endif

