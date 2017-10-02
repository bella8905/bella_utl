/////////////////////////////////////////////////////////////////
//
//  Utilities - Time
//
//
//  Copyright (c) 2016 Bella Q
//
/////////////////////////////////////////////////////////////////
#pragma once

#include <time.h>
#include <string>
#include <iostream>

#include "Utl_LogMsg.h"

namespace Utl
{
    enum EQURY_TIME_TYPE
    {
        TIME_STAMP,  // %d-%m-%Y %H:%M:%S
        TIME_STAMP_FILE_NAME,  // %d_%m_%H_%M_%S, use it if we want a attach time to file name
    };

    inline std::string GetTime( EQURY_TIME_TYPE t_time = TIME_STAMP )
    {
        time_t rawTime = time( 0 );
        tm timeInfo;
        localtime_s( &timeInfo, &rawTime );
        char buffer[80];
        if( t_time == TIME_STAMP_FILE_NAME )
        {
            strftime( buffer, 80, "%d_%m_%I_%M_%S", &timeInfo );
        }
        else
        {
            strftime( buffer, 80, "%d-%m-%Y %I:%M:%S", &timeInfo );
        }

        return std::string( buffer );
    }

    struct STimer
    {
        clock_t _StartTime;

        void StartTimer( std::string t_Module )
        {
            LogError << t_Module << LogEndl;
            _StartTime = clock();
        }

        void EndTimer()
        {
            int elapsedTime = ( clock() - _StartTime ) / CLOCKS_PER_SEC;
            int hours = elapsedTime / 3600;
            int minutes = elapsedTime % 3600 / 60;
            int seconds = elapsedTime % 3600 % 60;

            std::cout << "Time Elapsed: " << hours << "h, " << minutes << "m, " << seconds << "s." << std::endl;
        }
    };
}
