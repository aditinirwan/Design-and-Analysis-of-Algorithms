/*Create a recursive function that takes the graph, current index, number of vertices, and output color array.
If the current index is equal to the number of vertices. Print the color configuration in output array.
Assign a color to a vertex (1 to m).
For every assigned color, check if the configuration is safe, 
(i.e. check if the adjacent vertices do not have the same color) 
recursively call the function with next index and number of vertices
If any recursive function returns true break the loop and return true.
If no recursive function returns true then return false.*/

#include<bits/stdc++.h>
using namespace std;
#define n 4

bool is_safe(int graph[n][n],int colour[],int v,int c) {
	for(int i=0;i<n;i++) {
		if(graph[v][i]==1 && colour[i]==c) {
			return false;
		}
	}
	return true;
}

bool rec_graph_colouring(int graph[n][n],int colour[],int m,int v) {
	if(v==n) {
		return true;
	}
	for(int c=1;c<=m;c++) {
		if(is_safe(graph,colour,v,c)) {
			colour[v]=c;
			
			if(rec_graph_colouring(graph,colour,m,v+1)==true) {
				return true;
			}
			colour[v]=0;
		}
	}
	return false;
}

bool backtrack_graph_colouring(int graph[n][n],int m) {
	int colour[n];
	for(int i=0;i<n;i++) {
		colour[i]=0;
	}
	if(rec_graph_colouring(graph,colour,m,0)==false) {
		cout<<"Solution does not exist.";
		return false; 
	}
	cout<<"solution found: "<<endl;
	for(int i=0;i<n;i++) {
		cout<<colour[i]<<",";
	}
	return true;
}

int main() {
	int graph[n][n]= { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 }, };
    int m = 3;
    backtrack_graph_colouring(graph, m);
    return 0;
}
