/********************************************************************************
Broken Necklace

You have a necklace of N red, white, or blue beads (3<=N<=350) some of which are red, others blue, and others white, arranged at random. Here are two examples for n=29:

                1 2                               1 2
            r b b r                           b r r b
          r         b                       b         b
         r           r                     b           r
        r             r                   w             r
       b               r                 w               w
      b                 b               r                 r
      b                 b               b                 b
      b                 b               r                 b
       r               r                 b               r
        b             r                   r             r
         b           r                     r           r
           r       r                         r       b
             r b r                             r r w
            Figure A                         Figure B
                        r red bead
                        b blue bead
                        w white bead

The beads considered first and second in the text that follows have been marked in the picture.

The configuration in Figure A may be represented as a string of b's and r's, where b represents a blue bead and r represents a red one, as follows: brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight, and then collect beads of the same color from one end until you reach a bead of a different color, and do the same for the other end (which might not be of the same color as the beads collected before this).

Determine the point where the necklace should be broken so that the most number of beads can be collected.
Example

For example, for the necklace in Figure A, 8 beads can be collected, with the breaking point either between bead 9 and bead 10 or else between bead 24 and bead 25.

In some necklaces, white beads had been included as shown in Figure B above. When collecting beads, a white bead that is encountered may be treated as either red or blue and then painted with the desired color. The string that represents this configuration will include the three symbols r, b and w.

Write a program to determine the largest number of beads that can be collected from a supplied necklace.
PROGRAM NAME: beads
INPUT FORMAT
Line 1:     N, the number of beads
Line 2:     a string of N characters, each of which is r, b, or w
SAMPLE INPUT (file beads.in)

29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

OUTPUT FORMAT
A single line containing the maximum of number of beads that can be collected from the supplied necklace.
SAMPLE OUTPUT (file beads.out)

11

OUTPUT EXPLANATION
Consider two copies of the beads (kind of like being able to runaround the ends). The string of 11 is marked.

wwwbbrwrbrbrrbrbrwrwwrbwrwrrb wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
                       ****** *****
********************************************************************************/
/*
ID: esrefoz1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    in.open( "beads.in" );
    out.open( "beads.out" );
    
    int N,max=0,current,j;
    char pivot;
    string necklace,necklace_tmp;
    in >> N;
    in >> necklace;
    
    for( int i=0 ; i<N ; i++ )
    {
        
        current = 0;
        necklace_tmp = necklace;
        
        pivot = necklace_tmp[i];
        for( int j=i; necklace_tmp[j]!='x' && ( pivot=='w' || ( necklace_tmp[j]==pivot || necklace_tmp[j]=='w' ) ) ; j=(j+1)%N , current++ )
        {
            if( pivot=='w' )
                pivot = necklace_tmp[j];
            necklace_tmp[j]='x';
        }
        pivot = necklace_tmp[(i-1+N)%N];
        for( int j=(i-1+N)%N; necklace_tmp[j]!='x' && ( pivot=='w' || ( necklace_tmp[j]==pivot || necklace_tmp[j]=='w' ) ) ; j=(j-1+N)%N , current++ )
        {
            if( pivot=='w' )
                pivot = necklace_tmp[j];
            necklace_tmp[j]='x';
        }

        if( current > max )
            max = current;

    }
    out << max << endl;
    in.close();
    out.close();
    return 0;
}
