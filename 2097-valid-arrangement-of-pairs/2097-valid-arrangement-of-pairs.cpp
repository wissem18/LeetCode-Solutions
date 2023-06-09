class Solution {
public:
vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
map<int,vector<int>>adj;
map<int,int>in;
    for (auto p:pairs) {
      adj[p[0]].push_back(p[1]);
      in[p[1]]++;
    }
int startNode;
    for (auto x:adj) {
        startNode=x.first;
        if(x.second.size()-1==in[x.first])
            break;
    }
    vector<int>circuit;
    vector<int> curr_path;
    curr_path.push_back(startNode);
    while(!curr_path.empty()){
        int curr_v = curr_path.back();
        if (adj[curr_v].size() > 0) {
            // Find and remove the next vertex that is
            // adjacent to the current vertex
            int next_v = adj[curr_v].back();
            adj[curr_v].pop_back();

            // Push the new vertex to the stack
            curr_path.push_back(next_v);
        }
        else {
            // Remove the current vertex and
            // put it in the circuit
            circuit.push_back(curr_path.back());
            curr_path.pop_back();
        }
    }
    vector<vector<int>>ans(circuit.size()-1);
    vector<int>x={startNode};
    ans[0]=x;
    for (int i = circuit.size()-2; i >0 ; --i) {
        ans[circuit.size()-i-2].push_back(circuit[i]);
        ans[circuit.size()-i-1].push_back(circuit[i]);
    }
    ans[ans.size()-1].push_back(circuit[0]);
    return ans;
}
};