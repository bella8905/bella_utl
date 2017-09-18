/////////////////////////////////////////////////////////////////
//
//  Utilities - Console Message
// 
//  
//
//  Copyright (c) 2016 Bella Q
//  
/////////////////////////////////////////////////////////////////


#include <assert.h>
#include <iostream>
#include <time.h>

#include "Utl_LogMsg.h"
#include "Utl_Time.h"


#if defined ( OS_WIN )
CONSOLE_SCREEN_BUFFER_INFO ColorReverter::_csbi;
#endif

ColorReverter* ColorReverter::_instance = 0;

std::ofstream outFile;

const std::string LOG_FILE = "GL_LOG.log";


ColorModifier ColorMod_Warning( COLOR_WARNING );
ColorModifier ColorMod_Error( COLOR_ERROR );
ColorModifier ColorMod_Pass( COLOR_PASS );
ColorReverter* ColorMod_Restore = ColorReverter::GetInstance();

ColorReverter* ColorEndl::_rvt = ColorMod_Restore;
ColorCout LogError( ColorMod_Error );
ColorCout LogWarning( ColorMod_Warning );
ColorCout LogPass( ColorMod_Pass );
ColorCout LogMsg;
ColorEndl LogEndl;

static void _initFileOutput();
// static string GetCurrentTime();

std::ostream& operator<<( std::ostream& os, const ColorModifier& mod )
{
#ifdef OS_WIN
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, mod.GetColorCode() );
#elif OS_APPLE
    // add something for osx

#endif
    return os;
}

std::ostream& operator<<( std::ostream& os, const ColorReverter* rev )
{
    if( rev == 0 )  return os;

#ifdef OS_WIN
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, rev->_csbi.wAttributes );

#elif OS_APPLE
    // add something for osx

#endif

    return os;
}




ColorCout& operator<<( ColorCout& t_os, const  ColorEndl& t_colorEndl )
{
    if( t_colorEndl._rvt == 0 ) return t_os;
#ifdef OS_WIN
    t_os.SetColorWritten( false );
#elif OS_APPLE
    // add something for osx

#endif

    std::cout << t_colorEndl._rvt << std::endl; // reset color and flush buffer

    if( LOGMSG_LOG_TO_FILE_ENABLED )
    {
        if( outFile.is_open() )
        {
            // don't use fflush to flush the buffer, it's very expensive
            // let the destructor do the work. RAII
            outFile << '\n';
        }
    }

    return t_os;
}


static void _initFileOutput()
{
    if( !outFile.is_open() )
    {
        outFile.open( LOG_FILE, std::fstream::out );
        if( !outFile )
        {
            std::cout << ColorMod_Warning << "can't open log file. log file not used" << std::endl;
            outFile.close();
            outFile.clear();
            return;
        }

        // write time info
        std::string time = Utl::GetTime();
        outFile << time << '\n';
    }
}

ColorCout::ColorCout( const ColorModifier& t_colorMod ) : _colorMod( t_colorMod ), _colorWritten( false )
{
    if( LOGMSG_LOG_TO_FILE_ENABLED )
    {
        _initFileOutput();
    }
}

ColorCout::ColorCout() : _colorWritten( false )
{
    if( LOGMSG_LOG_TO_FILE_ENABLED )
    {
        _initFileOutput();
    }
}

ColorEndl::ColorEndl()
{
    if( LOGMSG_LOG_TO_FILE_ENABLED )
    {
        _initFileOutput();
    }
}

std::string ConvertLPCWSTRToString( LPCWSTR t_in )
{
    std::wstring tempWstring( t_in );
    std::string tempString( tempWstring.begin(), tempWstring.end() );
    return tempString;
}