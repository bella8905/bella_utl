/////////////////////////////////////////////////////////////////
//
//  Utilities - File related funcs
// 
//  
// 
//
//  Copyright (c) 2016 Bella Q
//  
/////////////////////////////////////////////////////////////////

#pragma once

#include <string>

namespace Utl
{
    /////////////////////////////////////////////////////////////////
    //
    //  if a file exist
    //  
    /////////////////////////////////////////////////////////////////
    bool DoesFileExist( std::string t_filespec );

    /////////////////////////////////////////////////////////////////
    //
    //  get file path from filespec
    //  eg., 
    //  "c:\\windows\\winhelp.exe" returns "c:\\windows"
    //  "/usr/bin/man" returns "/usr/bin"
    //  
    /////////////////////////////////////////////////////////////////
    void GetFilePath( std::string t_filespec, std::string& t_path );

    /////////////////////////////////////////////////////////////////
    //
    //  get file path with trailing slash from filespec
    //  eg., 
    //  "c:\\windows\\winhelp.exe" returns "c:\\windows\\"
    //  "/usr/bin/man" returns "/usr/bin/"
    //  
    /////////////////////////////////////////////////////////////////
    void GetFilePathWithSlash( std::string t_filespec, std::string& t_path );

    /////////////////////////////////////////////////////////////////
    //
    //  get file name with extension from filespec
    //  eg., 
    //  "c:\\windows\\winhelp.exe" returns "winhelp.exe"
    //  "/usr/bin/man" returns "man"
    //  
    /////////////////////////////////////////////////////////////////
    void GetFileName( std::string t_filespec, std::string& t_filename );



    /////////////////////////////////////////////////////////////////
    //
    //  get file base name without extension from filespec
    //  eg., 
    //  "c:\\windows\\winhelp.exe" returns "winhelp"
    //  "/usr/bin/man" returns "man"
    //  
    /////////////////////////////////////////////////////////////////
    void GetFileBaseName( std::string t_filespec, std::string& t_basename );


    /////////////////////////////////////////////////////////////////
    //
    //  get file extension with extension from filespec
    //  eg., 
    //  "c:\\windows\\winhelp.exe" returns "exe"
    //  
    /////////////////////////////////////////////////////////////////
    void GetFileExtension( std::string t_filespec, std::string& t_ext );
}