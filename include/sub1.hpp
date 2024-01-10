#ifndef __SUB1_HPP__
#define __SUB1_HPP__

#include "../TimeCounter/TimeCounter.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sys/time.h>
#include <time.h>

#define COUNT 1

namespace Sub1
{
    class Class
    {
        public:
            Class(std::string);
            void execute();
            std::string path;

        private:
    };
}

#endif

