#include<bits/stdc++.h>
using namespace std;

struct activity {
	int start,finish;
};

bool compare(activity a, activity b) {
	return a.finish<b.finish;
}

int activity_selection(struct activity arr[],int n) {
	sort(arr,arr+n,compare);
	int i=0,j;
	cout<<" "<<"Start Time"<<"\t"<<"Finish Time"<<endl;
	cout<<" "<<arr[i].start<<"\t\t"<<arr[i].finish<<endl;
	for(j=1;j<n;j++) {
		if(arr[j].start >= arr[i].finish) {
			cout<<" "<<arr[j].start<<"\t\t"<<arr[j].finish<<endl;
			i=j;
		}
	}
}

int main()
{
	activity arr[]={{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
	int n=sizeof(arr)/sizeof(arr[0]);
	activity_selection(arr,n);
	return 0;
}
