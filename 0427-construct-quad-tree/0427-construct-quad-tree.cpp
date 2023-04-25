/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
Node* rec(vector<vector<int>>&grid,int x,int y,int sz){
    if(sz==1)
        return new Node(grid[x][y],true);
Node* ans=new Node(0,false,rec(grid,x,y,sz/2),rec(grid,x,y+sz/2,sz/2),rec(grid,x+sz/2,y,sz/2),rec(grid,x+sz/2,y+sz/2,sz/2));
    if(ans->topLeft->val==ans->topRight->val&&ans->bottomLeft->val==ans->bottomRight->val&&ans->topLeft->val==ans->bottomLeft->val &&ans->topLeft->isLeaf&&ans->topRight->isLeaf&&ans->bottomLeft->isLeaf&&ans->bottomRight->isLeaf){
    return new Node(ans->topLeft->val,true);
    }
    return ans;
}
Node* construct(vector<vector<int>>&grid){
    int n=grid.size();
    return rec(grid,0,0,n);
}
};
