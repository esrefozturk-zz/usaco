/********************************************************************************
Greedy Gift Givers

A group of NP (2 ≤ NP ≤ 10) uniquely named friends has decided to exchange gifts of money. Each of these friends might or might not give some money to any or all of the other friends. Likewise, each friend might or might not receive money from any or all of the other friends. Your goal in this problem is to deduce how much more money each person gives than they receive.

The rules for gift-giving are potentially different than you might expect. Each person sets aside a certain amount of money to give and divides this money evenly among all those to whom he or she is giving a gift. No fractional money is available, so dividing 3 among 2 friends would be 1 each for the friends with 1 left over -- that 1 left over stays in the giver's "account".

In any group of friends, some people are more giving than others (or at least may have more acquaintances) and some people have more money than others.

Given a group of friends, no one of whom has a name longer than 14 characters, the money each person in the group spends on gifts, and a (sub)list of friends to whom each person gives gifts, determine how much more (or less) each person in the group gives than they receive.
IMPORTANT NOTE

The grader machine is a Linux machine that uses standard Unix conventions: end of line is a single character often known as '\n'. This differs from Windows, which ends lines with two charcters, '\n' and '\r'. Do not let your program get trapped by this!
PROGRAM NAME: gift1
INPUT FORMAT
Line 1: 	The single integer, NP
Lines 2..NP+1: 	Each line contains the name of a group member
Lines NP+2..end: 	NP groups of lines organized like this:
The first line in the group tells the person's name who will be giving gifts.
The second line in the group contains two numbers: The initial amount of money (in the range 0..2000) to be divided up into gifts by the giver and then the number of people to whom the giver will give gifts, NGi (0 ≤ NGi ≤ NP-1).
If NGi is nonzero, each of the next NGi lines lists the the name of a recipient of a gift.

SAMPLE INPUT (file gift1.in)

5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0

OUTPUT FORMAT

The output is NP lines, each with the name of a person followed by a single blank followed by the net gain or loss (final_money_value - initial_money_value) for that person. The names should be printed in the same order they appear on line 2 of the input.

All gifts are integers. Each person gives the same integer amount of money to each friend to whom any money is given, and gives as much as possible that meets this constraint. Any money not given is kept by the giver.
SAMPLE OUTPUT (file gift1.out)

dave 302
laura 66
owen -359
vick 141
amr -150
********************************************************************************/
/*
ID: esrefoz1
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

typedef struct
{
    string name;
    int money;
} person;


int find_index( person list[] , int len , string who )
{
    for( int i=0 ; i<len ; i++ )
    {
        if( list[i].name == who )
        {   
            return i;
        }
    }
}

int main()
{
    ifstream in;
    ofstream out;
    in.open( "gift1.in" );
    out.open( "gift1.out" );
    int NP,current_money,current_giver_id,count;
    person givers[10]; 
    string current_giver,taker;
    in >> NP;
    for( int i=0 ; i<NP ; i++ )
    {
        in >> givers[i].name;
        givers[i].money = 0;
    }
    for( ; ( in >> current_giver ) ; )
    {
        in >> current_money >> count;
        current_giver_id = find_index( givers , NP , current_giver );
        for( int i=0 ; i<count ; i++ )
        {
            in >> taker;
            givers[ find_index( givers , NP , taker ) ].money += current_money / count;
            givers[ current_giver_id ].money -= current_money / count;
        }
    }
    for( int i=0 ; i<NP ; i++ )
    {
        out << givers[i].name << " " << givers[i].money << endl;
    }

    in.close();
    out.close();
    return 0;
}
