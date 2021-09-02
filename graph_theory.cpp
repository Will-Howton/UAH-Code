#include <stdlib.h>
#include <vector>

using namespace std;

struct node {
    vector<tuple<node*,double>> nextNodes;
};

class graph {
    private:
        vector<node> nodes;
    
    public:
        graph(vector<node> nodes) {
            this->nodes = nodes;
        }

        vector<node> getnodes() {
            return this->nodes;
        }

        int getSize() {
            return this->nodes.size();
        }

        vector<vector<int>> getAdjMatrix() {
            vector<vector<int>> adjMatrix = vector<vector<int>>();
            adjMatrix.resize(this->nodes.size());
            for(int i = 0;i<this->nodes.size();i++) {
                node tempNode = this->nodes[i];

                for(int j = 0;j<tempNode.nextNodes.size();j++) {
                    node* currNode = get<0>(tempNode.nextNodes[j]);
                    vector<node>::iterator it = find(this->nodes.begin(),this->nodes.end(),currNode);
                    if (it != this->nodes.end()) {
                        adjMatrix[i][distance(this->nodes.begin(),)] = 1
                    }

                }
            }
        }
};