/********************************************************************************
Your Ride Is Here

It is a well-known fact that behind every good comet is a UFO. These UFOs often come to collect loyal supporters from here on Earth. Unfortunately, they only have room to pick up one group of followers on each trip. They do, however, let the groups know ahead of time which will be picked up for each comet by a clever scheme: they pick a name for the comet which, along with the name of the group, can be used to determine if it is a particular group's turn to go (who do you think names the comets?). The details of the matching scheme are given below; your job is to write a program which takes the names of a group and a comet and then determines whether the group should go with the UFO behind that comet.

Both the name of the group and the name of the comet are converted into a number in the following manner: the final number is just the product of all the letters in the name, where "A" is 1 and "Z" is 26. For instance, the group "USACO" would be 21 * 19 * 1 * 3 * 15 = 17955. If the group's number mod 47 is the same as the comet's number mod 47, then you need to tell the group to get ready! (Remember that "a mod b" is the remainder left over after dividing a by b; 34 mod 10 is 4.)

Write a program which reads in the name of the comet and the name of the group and figures out whether according to the above scheme the names are a match, printing "GO" if they match and "STAY" if not. The names of the groups and the comets will be a string of capital letters with no spaces or punctuation, up to 6 characters long.

Examples:

Input 	Output

COMETQ
HVNGAT

	GO

ABSTAR
USACO 

	STAY
PROGRAM NAME: ride
This means that you fill in your header with:
PROG: ride
INPUT FORMAT
Line 1: 	An upper case character string of length 1..6 that is the name of the comet.
Line 2: 	An upper case character string of length 1..6 that is the name of the group.

NOTE: The input file has a newline at the end of each line but does not have a "return". Sometimes, programmers code for the Windows paradigm of "return" followed by "newline"; don't do that! Use simple input routines like "readln" (for Pascal) and, for C/C++, "fscanf" and "fid>>string".
SAMPLE INPUT (file ride.in)

COMETQ
HVNGAT

OUTPUT FORMAT
A single line containing either the word "GO" or the word "STAY".
SAMPLE OUTPUT (file ride.out)

GO
********************************************************************************/
/*
ID: esrefoz1
LANG: C++
TASK: ride
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int calc( string str )
{
    int result = 1;
    for( int i=0 ; i<str.length() ; i++ )
    {
        result *= str[i] - 'A' + 1;
    }
    return result % 47;
}

int main()
{
    ifstream in;
    ofstream out;
    in.open( "ride.in" );
    out.open( "ride.out" );
    string str1,str2;
    in >> str1 >> str2;
    if( calc( str1 ) == calc( str2 ) )
        out << "GO" << endl;
    else
        out << "STAY" << endl;
    in.close();
    out.close();
    return 0;
}
