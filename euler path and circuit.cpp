/*traverse(u, visited)
Input: The start node u and the visited node to mark which node is visited.
Output - Traverse all connected vertices.
Begin
   mark u as visited
   for all vertex v, if it is adjacent with u, do
      if v is not visited, then
         traverse(v, visited)
   done
End

isConnected(graph)
Input - The graph.
Output - True if the graph is connected.
Begin
   define visited array
   for all vertices u in the graph, do
      make all nodes unvisited
      traverse(u, visited)
      if any unvisited node is still remaining, then
         return false
   done
   return true
End

isEulerian(Graph)
Input - The given Graph.
Output - Returns 0, when not Eulerian, 1 when it has a Euler path, 2 when Euler circuit found
Begin
   if isConnected() is false, then
      return false
   define list of degree for each node
   oddDegree := 0

   for all vertex i in the graph, do
      for all vertex j which are connected with i, do
         increase degree
      done
      if degree of vertex i is odd, then
         increase dooDegree
   done

   if oddDegree > 2, then
      return 0
   if oddDegree = 0, then
      return 2
   else
      return 1
End*/

#include<bits/stdc++.h>
using namespace std; 
#define n 5

int graph[n][n] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {0, 0, 0, 1, 0}
};

void traverse(int u,bool visited[]) {
	visited[u]=true;
	for(int v=0;v<n;v++) {
		if(graph[u][v]) { //agar edge exist karta hai u se v 
			if(!visited[v]) { //agar vertex v visited nahi hai ab tak 
				traverse(v,visited);
			}
		}
	}	
}

bool isConnected() {
	bool visited[n];
	for(int u=0;u<n;u++) {
		for(int i=0;i<n;i++) {
			visited[i]=false;
		}
		traverse(u,visited);
	}
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			return false;
		}
	}
	return true;
}

int eulerian() {
	if(isConnected()==false) {
		return 0;
	}
	int degree[n];
	int odddegree=0; 
	for(int i=0;i<n;i++) {
		degree[i]=0;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(graph[i][j]) {
				degree[i]++;
			}
		}
		if(degree[i]%2!=0) {
			odddegree++;
		}
	}
	if(odddegree>2) return 0;
	return (odddegree)?1:2; 
}

int main() {
	int degree=eulerian();
	switch(degree) {
		case 0: cout<<"The graph has neither eulerian path nor circuit";break;
		case 1: cout<<"The graph has eulerian path";break;
		case 2: cout<<"The graph has eulerian circuit";break;
	}
}

