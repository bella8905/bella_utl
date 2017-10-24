/////////////////////////////////////////////////////////////////
//
//  Utilities - File Browser
//
//
//
//  Cross platform( hopefully ) file browser,
//  open a file browser dialog and pass back the file name selected.
//
//
//
//  Copyright (c) 2016 Bella Q
//
/////////////////////////////////////////////////////////////////

#pragma once

#ifdef _WIN32
#include <windows.h>
#endif

namespace Utl
{
    class CFileBrowserDialog
    {
    public:
        CFileBrowserDialog();
        ~CFileBrowserDialog()
        {
        }

    public:
        TCHAR* _defaultExtension;
        TCHAR  _fileName[MAX_PATH];
        TCHAR* _filter;
        int    _filterIndex;
        int    _flags;
        TCHAR* _initialDir;
        HWND   _owner;
        TCHAR* _title;

    public:
        const TCHAR* ShowDialog();
    };
}