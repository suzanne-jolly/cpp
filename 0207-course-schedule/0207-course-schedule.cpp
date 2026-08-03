class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        int V=numCourses;
        vector<vector<int>>adj(V);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        int cnt=0;
        vector<int>indegree(V);
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
            
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    return cnt==V;
        
    }
};