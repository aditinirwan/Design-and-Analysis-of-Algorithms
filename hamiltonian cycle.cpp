/*Create an empty path array and add vertex 0 to it. 
Add other vertices, starting from the vertex 1. 
Before adding a vertex, check for whether it is adjacent to the previously added vertex and not already added. 
If we find such a vertex, we add the vertex as part of the solution. 
If we do not find a vertex then we return false. */

#include<bits/stdc++.h>
using namespace std;
#define n 5

bool is_safe(int v,bool graph[n][n],int path[],int pos) {
	//whether it is adjacent to the previously added vertex
	if(graph[path[pos-1]][v]==0) {
		return false;
	}
	for(int i=0;i<pos;i++) {
		if(path[i]==v) {
			return false;
		}
	}
	return true;
}

//recursive function 
bool rec_ham_cycle(bool graph[n][n],int path[],int pos) {
	if(pos==n) {
		if(graph[path[pos-1]][path[0]]==1) {
			return true;
		}
		else return false; 
	}
	for (int v =1;v<n;v++)
    {
        if (is_safe(v, graph, path, pos))
        {
            path[pos] = v;
            if (rec_ham_cycle(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
	return false;
}

bool backtracing_ham_cycle(bool graph[n][n]) {
	int path[n];
	for(int i=0;i,n;i++) {
		path[i]=-1;
	}
	path[0]=0;
	if(rec_ham_cycle(graph,path,1)==false) {
		cout<<"Solution does not exist";
		return false;
	}
	cout<<"solution exists: "<<endl;
	for(int i=0;i<n;i++) {
		cout<<path[i]<<"-->";
	}
	cout<<path[0];
	return true;
}

int main() {
	bool graph[n][n]= {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    backtracing_ham_cycle(graph);
    return 0;
}
