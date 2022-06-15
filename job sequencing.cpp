/*1) Sort all jobs in decreasing order of profit. 
2) Iterate on jobs in decreasing order of profit.For each job , do the following : 
a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in 
this slot and mark this slot filled. 
b)If no such i exists, then ignore the job. */

#include<bits/stdc++.h>
using namespace std;

struct job 
{
	char id;
	int deadline;
	int profit;
};

bool compare(struct job a,struct job b) {
	return a.profit>b.profit;
}

int job_sequencing(struct job arr[],int n) {
	sort(arr,arr+n,compare);
	int result[n];
	bool slot[n];
	for(int i=0;i<n;i++) 
	{
		slot[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		//finding a free slot for this job, we start from the last possible slot
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--) 
		{
			if(slot[j]==false) {
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(slot[i]) {
			cout<<arr[result[i]].id<<"\t";
		}
	}
}

int main() 
{
	job arr[]={ { 'a', 2, 100 },
                { 'b', 1, 19 },
                { 'c', 2, 27 },
                { 'd', 1, 25 },
                { 'e', 3, 15 } };;
	int n=sizeof(arr)/sizeof(arr[0]); 
	job_sequencing(arr,n);
	return 0;
}
