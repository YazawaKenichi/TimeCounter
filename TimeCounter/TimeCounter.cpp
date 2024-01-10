#include "TimeCounter.hpp"

using namespace std;

namespace TimeCounter
{
    TimeCounter::TimeCounter(string _path) : start(chrono::system_clock::now()), stop(start)
    {
        this->path = _path;
    }

    //! 計測開始
    void TimeCounter::startCounter()
    {
        //! 開始時刻の取得
        this->start = chrono::system_clock::now();
    }

    //! 計測終了
    void TimeCounter::stopCounter()
    {
        //! 終了時刻の取得
        this->stop = chrono::system_clock::now();
        //! 差分の算出
        auto dur = this->stop - this->start;
        auto ms = chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        //! 処理時間 ms 変数を std::chrono::seconds::rep 型から std::string 型に変換
        std::string text = std::to_string(ms);
        this->writef(text);
    }

    void TimeCounter::printf(string msg)
    {
        cout << msg << endl;
    }

    void TimeCounter::writef(string _text)
    {
        fstream file;
        file.open(this->path, std::ios_base::app);
        if (file.is_open())
        {
            string text = _text + "\r\n";
            this->printf(text);
            file.write(text.data(), text.size());
        }
    }
}

