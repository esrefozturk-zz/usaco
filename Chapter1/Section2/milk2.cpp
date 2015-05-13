/********************************************************************************
Milking Cows

Three farmers rise at 5 am each morning and head for the barn to milk three cows. The first farmer begins milking his cow at time 300 (measured in seconds after 5 am) and ends at time 1000. The second farmer begins at time 700 and ends at time 1200. The third farmer begins at time 1500 and ends at time 2100. The longest continuous time during which at least one farmer was milking a cow was 900 seconds (from 300 to 1200). The longest time no milking was done, between the beginning and the ending of all milking, was 300 seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning and ending times for N (1 = N = 5000) farmers milking N cows and compute (in seconds)

     The longest time interval at least one cow was milked.
     The longest time interval (after milking starts) during which no cows were being milked. 

PROGRAM NAME milk2
INPUT FORMAT
Line 1  The single integer
Lines 2..N+1    Two non-negative integers less than 1000000, the starting and ending time in seconds after 0500
SAMPLE INPUT (file milk2.in)

3
300 1000
700 1200
1500 2100


OUTPUT FORMAT
A single line with two integers that represent the longest continuous time of milking and the longest idle time.
SAMPLE OUTPUT (file milk2.out)

900 300
********************************************************************************/
/*
ID: esrefoz1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct { int s,f; } milking;

bool compare( milking m1 , milking m2 )
{
    return ( m1.s<m2.s ) || ( m1.s==m2.s && m1.f<m2.f );
}

int main()
{
    ifstream in;
    ofstream out;
    in.open( "milk2.in" );
    out.open( "milk2.out" );
    
    int N,result1=0,result2=0,start,finish;
    milking times[5002];

    in >> N;
    for( int i=0 ; i<N ; i++ )
    {
        in >> times[i].s >> times[i].f;
    }

    sort( times , times+N , compare );
    
	start = times[0].s;
	finish = times[0].f;
	result1 = finish-start;

    for( int i=1 ; i<N ; i++ )
    {
		if( times[i].s > finish )
		{
			result2 = max(result2,times[i].s-finish);
			start = times[i].s;
			finish = times[i].f;
		}
		else
		{
			result1 = max(result1,times[i].f-start);
			finish = max(finish,times[i].f);
		}
    }
	out << result1 << " " << result2 << endl;

    in.close();
    out.close();
    return 0;
}
