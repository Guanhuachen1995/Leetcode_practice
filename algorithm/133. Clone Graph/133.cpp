/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return NULL;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*,  UndirectedGraphNode*> m;
        m[node] = p2;
        q.push(p1);
        while(!q.empty()) {
            p1 = q.front();
            p2 = m[p1];
            q.pop();
            for(auto n:p1->neighbors) {
                if(m.find(n) != m.end()) {
                    p2->neighbors.push_back(m[n]);
                } else {
                    UndirectedGraphNode *temp = new UndirectedGraphNode(n->label);
                    m[n] = temp;
                    p2->neighbors.push_back(temp);
                    q.push(n);
                }
            }
        }
        return m[node];
    }
};
