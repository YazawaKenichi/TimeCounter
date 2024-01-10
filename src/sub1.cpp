#include "sub1.hpp"
#include <stdio.h>
#include <unistd.h>

namespace Sub1
{
    Class::Class(std::string _path)
    {
        this->path = _path;
    }

    void Class::execute()
    {
        auto tc = TimeCounter::TimeCounter(this->path);
        //! 開始時刻
        // auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        tc.startCounter();

        unsigned int count = COUNT;
        //! テキトーな処理
        for (int i = 0; i < count; i++)
        {
            sleep(1);
        }

        //! 終了時刻
        // auto   end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        tc.stopCounter();

        //! 処理時間の導出
        /*
        std::chrono::duration<double> rep = end - start;
        std::chrono::milliseconds::rep ms = rep.count();
        */
    }
}

