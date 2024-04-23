class Solution {
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        // making map to keep track of nodes appaer on particular number line
        // here in this case :  map<int, vector<int> > 
        // first "int," represents number line or horizontal distance hd
        // second "vector<int>" represents the set of numbers which appears on that hd
        map<int, map<int, vector<int> > > nodes;
        
        
        // queue contains pair of nodes and pair of horizontal distance(hd) and level(lvl)
        queue<pair<Node*, pair<int, int> > > q;
        
        // ans vector
        vector<int> ans;
        
        if (root == NULL) {
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0, 0)));       // intitailly hd : 0 and lvl : 0
        
        while (!q.empty()) {
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if (frontNode->left != NULL) {
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }
            
            if (frontNode->right != NULL) {
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }
        
        for (auto i : nodes) {      // it has <int, pair<int, vector<int> > >
            for (auto j : i.second) {       // it has pair<int, vector<int> >
                for (auto k : j.second) {       // it has vector<int>
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};