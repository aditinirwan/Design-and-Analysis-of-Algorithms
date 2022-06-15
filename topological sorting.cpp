#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> topoSort(int n,vector<int> adj[]) {
			queue<int> q;
			vector<int> indegree(n,0);
			for(int i=0;i<n;i++) {
				for(auto it: adj[i]) {
					indegree[it]++;
				}
			}
			for(int i=0;i<n;i++) {
				if(indegree[i]==0) {
					q.push(i);
				}
			}
			vector<int> topo;
			while(!q.empty()) {
				int node = q.front();
				q.pop();
				topo.push_back(node);
				for(auto it: adj[node]) {
					indegree[it]--;
					if(indegree[it]==0) {
						q.push(it);
					}
				}
			}
			return topo; 
		}
};

int main() {
	vector<int> adj[6][6];
	adj[6][6] = {
		{ 0,0,0,0,0,0},
		{ 0,0,0,0,0,0},
		{ 0,0,0,1,0,0},
		{ 0,1,0,0,0,0},
		{ 1,1,0,0,0,0},
		{ 1,0,1,0,0,0},
	};
	int n=sizeof(adj)/sizeof(adj[0]);
	cout<<topoSort(n,adj);
	return 0;
}
