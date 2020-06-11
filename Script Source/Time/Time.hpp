/*
   DISCORD: sector#7111
*/

#ifndef _TIME_HPP
#define _TIME_HPP

#include <chrono>
#include <thread>
#include <time.h>

namespace Time
{
    /*
   * Hot looping sleep function that uses timepoints to remain 'accurate'
   */
    void Sleep(int64_t sleep_ms, std::chrono::time_point<std::chrono::steady_clock> start); 
}

#endif // !_TIME_HPP
