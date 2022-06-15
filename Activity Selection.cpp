/*1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do the following for the remaining activities in the sorted array. 
…….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and print it.
In the following C implementation, it is assumed that the activities are already sorted according to their finish time.*/


#include<bits/stdc++.h>
using namespace std;

int activity_selection(int s[],int f[],int n) 
{
	int i=0,j;
	cout<<i<<endl;
	for(j=1;j<n;j++) {
		if(s[j]>=f[i]) {
			cout<<j<<endl;
			i=j;
		}
	}
}

int main() 
{
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
	int n=sizeof(s)/sizeof(s[0]);
	activity_selection(s,f,n);
	return 0;
}
