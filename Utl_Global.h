/////////////////////////////////////////////////////////////////
//
//  Utilities - Global
//
//
//
//  Copyright (c) 2016 Bella Q
//
/////////////////////////////////////////////////////////////////

#pragma once

typedef unsigned short us;
typedef unsigned long ul;
typedef unsigned int uint;

// number of elements in array
#define array_size_of( a ) sizeof( a ) / sizeof( a[0] )

namespace Utl
{
    // 	template<typename T>
    // 	bool Equals( const T& t_x, const T& t_y ) { return std::abs( t_x - t_y ) < std::numeric_limits<T>::epsilon(); }
    //
    // 	template bool Equals( const float& t_x, const float& t_y );
    // 	template bool Equals( const double& t_x, const double& t_y );
}
