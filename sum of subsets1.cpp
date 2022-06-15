#include<iostream>
#include<bits/stdc++.h>
int n=5;
int w[]={0,7,11,13,24};
int m=31;
int x[5];
using namespace std;
void sumofsub(int s,int k,int r)
{
	x[k]=1;
	if(s+w[k]==m)
	{
		for(int j=1;j<=n;j++)
		{
		
		cout<<x[j]<<" ";}
		cout<<endl;
	}
	else if(s+w[k]+w[k+1]<=m)
	{
		sumofsub(s+w[k],k+1,r-w[k]);
	}
	if(s+r-w[k]>=m && s+w[k+1]<=m)
	{
		x[k]=0;
		sumofsub(s,k+1,r-w[k]);
	}	
}
int main(){
	sumofsub(0,1,55);
}
