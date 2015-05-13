#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

class milking
{
public:
	int start,end;
	milking(){}
};

bool compare(milking m1,milking m2)
{
	return m1.start<m2.start;
}

int main()
{
	ifstream in;
	ofstream out;
	int N;
	milking milkings[5001];
	in.open("milk2.in");
	in >> N;
	for(int n=0;n<N;n++)
	{
		in >> milkings[n].start >> milkings[n].end;
	}
	sort(milkings,milkings+N,compare);
}
