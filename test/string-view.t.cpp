// Copyright (C) 2017-2018 Martin Moene.
//
// https://github.com/martinmoene/string-view-lite
//
// This code is licensed under the MIT License (MIT).
//

#include "string-view-lite.t.h"

namespace {

using namespace nonstd;

CASE( "string_view: Allows to default construct an empty string_view" )
{
    string_view sv;

    // use parenthesis with data() to prevent lest from using sv.data() as C-string:

    EXPECT(  sv.size() == 0u );
    EXPECT( (sv.data() == nssv_nullptr) );
}

CASE( "string_view: Allows to construct from pointer and size" )
{
    string_view sv( "hello world", 5 );

    EXPECT(   sv.size()      == 5u  );
    EXPECT( *(sv.data() + 0) == 'h' );
    EXPECT( *(sv.data() + 4) == 'o' );
}

CASE( "string_view: Allows to construct from C-string" )
{
    string_view sv( "hello world" );

    EXPECT(   sv.size()       == 11u );
    EXPECT( *(sv.data() +  0) == 'h' );
    EXPECT( *(sv.data() + 10) == 'd' );
}

CASE( "string_view: Allows to copy-construct from empty string-view" )
{
    string_view sv1;

    string_view sv2( sv1 );

    // use parenthesis with data() to prevent lest from using sv.data() as C-string:

    EXPECT(  sv2.size() == 0u );
    EXPECT( (sv2.data() == nssv_nullptr) );
}

CASE( "string_view: Allows to copy-construct from non-empty string-view" )
{
    string_view sv1( "hello world", 5 );

    string_view sv2( sv1 );

    EXPECT(   sv2.size()      == sv1.size()  );
    EXPECT(  (sv2.data()      == sv1.data()) );
    EXPECT( *(sv2.data() + 0) == 'h'         );
    EXPECT( *(sv2.data() + 4) == 'o'         );
}

CASE( "string_view: Allows to copy-assign from empty string-view" )
{
    string_view sv1;
    string_view sv2;

    sv2 = sv1;

    // use parenthesis with data() to prevent lest from using sv.data() as C-string:

    EXPECT(  sv2.size() == 0u );
    EXPECT( (sv2.data() == nssv_nullptr) );
}

CASE( "string_view: Allows to copy-assign from non-empty string-view" )
{
    string_view sv1( "hello world", 5 );
    string_view sv2;

    sv2 = sv1;

    // use parenthesis with data() to prevent lest from using sv.data() as C-string:

    EXPECT(   sv2.size()      == sv1.size()  );
    EXPECT(  (sv2.data()      == sv1.data()) );
    EXPECT( *(sv2.data() + 0) == 'h'         );
    EXPECT( *(sv2.data() + 4) == 'o'         );
}

CASE( "string_view: Allows forward iteration" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( string_view::iterator pos = sv.begin(); pos != sv.end(); ++pos )
    {
        int i = std::distance( sv.begin(), pos );
        EXPECT( *pos == *(sv.data() + i) );
    }
}

CASE( "string_view: Allows const forward iteration" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( string_view::const_iterator pos = sv.begin(); pos != sv.end(); ++pos )
    {
        int i = std::distance( sv.cbegin(), pos );
        EXPECT( *pos == *(sv.data() + i) );
    }
}

CASE( "string_view: Allows reverse iteration" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( string_view::reverse_iterator pos = sv.rbegin(); pos != sv.rend(); ++pos )
    {
        int dist = std::distance( sv.rbegin(), pos );
        EXPECT( *pos == *(sv.data() + sv.size() - 1 - dist) );
    }
}

CASE( "string_view: Allows const reverse iteration" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( string_view::const_reverse_iterator pos = sv.crbegin(); pos != sv.crend(); ++pos )
    {
        int dist = std::distance( sv.crbegin(), pos );
        EXPECT( *pos == *(sv.data() + sv.size() - 1 - dist) );
    }
}

CASE( "string_view: Allows to observe an element via array indexing" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( unsigned int i = 0; i < sv.size(); ++i )
    {
        EXPECT( sv[i] == hello[i] );
    }
}

CASE( "string_view: Allows to observe an element via at()" )
{
    char hello[] = "hello";
    string_view sv( hello );

    for ( unsigned int i = 0; i < sv.size(); ++i )
    {
        EXPECT( sv.at(i) == hello[i] );
    }
}

CASE( "string_view: Allows to observe an element via data()" )
{
    char hello[] = "hello";
    string_view sv( hello );

    EXPECT( *sv.data() == *sv.begin() );

    for ( unsigned int i = 0; i < sv.size(); ++i )
    {
        EXPECT( sv.data()[i] == hello[i] );
    }
}

CASE( "string_view: . . .  and data() yields nullptr (or NULL) for an empty string_view" )
{
    string_view sv;

    // use parenthesis with data() to prevent lest from using sv.data() as C-string:

    EXPECT( (sv.data() == nssv_nullptr) );
}

} // anonymous namespace
