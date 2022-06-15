#include<bits/stdc++.h>
using namespace std;

struct Item {
	int profit,weight;
	
	Item(int profit,int weight) {
		this->profit=profit;
		this->weight=weight;
	}
};

bool compare(struct Item a,struct Item b) {
	double r1=(double)a.profit/(double)a.weight;
	double r2=(double)a.profit/(double)a.weight;
	return r1>r2; 
}

double frac_knapsack(int M,struct Item arr[],int n) {
	sort(arr,arr+n,compare);
	double final_P=0.0;
	for(int i=0;i<n;i++) {
		if(arr[i].weight < M) {
			M = M - arr[i].weight;
			final_P = final_P + arr[i].profit;
		}
		else {
			final_P = final_P + arr[i].profit * (double)M/(double)arr[i].weight;
			break; 
		}
	}
	return final_P;
}

int main() {
	int M=50;
	Item arr[]= { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int n= sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum value we can obtain = "<< frac_knapsack(M, arr, n);
    return 0;
}
