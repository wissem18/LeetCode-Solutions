class Solution {
public:
vector<string> findItinerary(vector<vector<string>>& tickets) {
    map<string,multiset<string>>adj;
    for (auto t:tickets) {
       adj[t[0]].insert(t[1]);
    }

    vector<string> curr_path;
    string startNode="JFK";//the starting node of the eulerian path
    curr_path.push_back(startNode);

    // list to store final circuit
    vector<string> circuit;

    while (curr_path.size() > 0) {
        string curr_v = curr_path[curr_path.size() - 1];

        // If there's remaining edge in adjacency list
        // of the current vertex
        if (adj[curr_v].size() > 0) {
            // Find and remove the next vertex that is
            // adjacent to the current vertex
            string next_v = *adj[curr_v].begin();
            adj[curr_v].erase(adj[curr_v].begin());

            // Push the new vertex to the stack
            curr_path.push_back(next_v);
        }

            // back-track to find remaining circuit
        else {
            // Remove the current vertex and
            // put it in the circuit
            circuit.push_back(curr_path.back());
            curr_path.pop_back();
        }
    }
    reverse(circuit.begin(),circuit.end());
return circuit;
}
};