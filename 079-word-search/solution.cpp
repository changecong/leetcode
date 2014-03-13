/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Mar 11 14:17:38 2014
 * Modified at:   Thu Mar 13 12:49:48 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// define the node structure
struct Node{

    int x;
    int y;

    int mark;

    Node(int a, int b) {

        mark = -1;

        x = a;
        y = b;
    }
};

class Solution {

public:
    bool exist(vector<vector<char> > &board, string word) {
        
        if (board.empty()) {
            
            return false; 

        }

        int rows = board.size();
        int cols = board[0].size();
        
        // a copy
        vector<int> path(cols + 2);
        vector<vector<int> > paths(rows + 2, path);


        if (rows * cols < word.size()) return false;

        int x = 0;
        int y = 0;
        
        bool old = false;

        stack<Node*> nodes;

        Node *node;

        while(true) {

            if (x < 0 || y < 0 || (x >= rows) || (y >= cols)) {

                // go back
                node = nodes.top();
                x = nodes.top()->x;
                y = nodes.top()->y;
                old = true;
                nodes.pop();
                paths[x + 1][y + 1] = 0;
                continue;
            }

            char c = word[nodes.size()];
            
            // gen a node
            if (!old) {
                node = new Node(x, y);
            } else {
                
                old = false;
            }

            
            // cout << c << " >> " << board[x][y] << "(" << x << ", " << y << ") >> " << node->mark << " >> " << paths[x+1][y+1] << endl;

            if (c == board[x][y]) {  // match

                if (nodes.size() == word.size() - 1) return true;

                // find next;
                switch (node->mark) {
                case -1:  // null
                    paths[x + 1][y + 1] = 1;

                    x = x - 1;  // go up
                    node->mark = 0;
                    if (1 == paths[x + 1][y + 1]) {
                        // move to position 1
                        x = x + 1;
                        paths[x + 1][y + 1] = 0;
                    } else {
                    
                        nodes.push(node);
                        break;
                    }
                    
                case 0:  // up visited
                    paths[x + 1][y + 1] = 1;
                    
                    
                    y = y + 1; // go right;
                    node->mark = 1;
                    if (1 == paths[x + 1][y + 1]) {
                        // move to position 2
                        y = y - 1;
                        paths[x + 1][y + 1] = 0;
                    } else {

                        nodes.push(node);
                        break;
                    }

                case 1:  // right visited;
                    paths[x + 1][y + 1] = 1;
 
                    x = x + 1;  // go down
                    node->mark = 2;
                    if (1 == paths[x + 1][y + 1]) {
                        // move to position 3;
                        x = x - 1;
                        paths[x + 1][y + 1] = 0;
                
                    } else {

                        nodes.push(node);
                        break;
                    }

                case 2:  // bottom visited
                    paths[x + 1][y + 1] = 1;
                                        
                    y = y - 1;  // go left
                    node->mark = 3;

                    if (1 == paths[x + 1][y + 1]) {

                        // move to position 4
                        y = y + 1;
                        paths[x + 1][y + 1] = 0;
                     
                    } else {

                        nodes.push(node);
                        break;
                    }

                default:  // 3 or 4

                    paths[x + 1][y + 1] = 0;

                    // if no pre
                    if (nodes.empty()) {
                        // move to the next;
                        y++;
                        if (y == cols) {
                            y = 0;
                            x++;
                        }

                        if (x == rows) {
                            return false;
                        }
                        
                    } else {

                        // go back
                        node = nodes.top();
                        x = nodes.top()->x;
                        y = nodes.top()->y;
                        old = true;
                        nodes.pop();
                    }                    
                   
                    break;
                }                

            } else {

                paths[x + 1][y + 1] = 0;

                // if no pre
                if (nodes.empty()) {
                    // move to the next;
                    y++;
                    if (y == cols) {
                        y = 0;
                        x++;
                    }
                        
                    if (x == rows) {
                        return false;
                    } 
                        
                } else {
                    
                    // go back
                    node = nodes.top(); 
                    x = nodes.top()->x;
                    y = nodes.top()->y;
                    old = true;
                    nodes.pop();
                }

            }
          
        }

                
        delete node;
    }
};

int main() {

    Solution s;

    vector<vector<char> > S;

    vector<char> temp;
    // char A[5] = "AAAA";
    // for (int i = 0; i < 4; ++i) {
    //     temp.push_back(A[i]);
    // }

    // S.push_back(temp);
    // temp.clear();

    // char B[5] = "AAAA";
    // for (int i = 0; i < 4; ++i) {
    //     temp.push_back(B[i]);
    // }

    // S.push_back(temp);
    // temp.clear();

    // char C[5] = "ABAA";
    // for (int i = 0; i < 4; ++i) {
    //     temp.push_back(C[i]);
    // }

    // S.push_back(temp);
    // temp.clear();

    // string word = "BAAAAAAAAAAA";

    char A[4] = "aaa";
    char B[4] = "abb";
    char C[4] = "abb";
    char D[4] = "bbb";
    char E[4] = "bbb";
    char F[4] = "aaa";
    char G[4] = "bbb";
    char H[4] = "abb";
    char I[4] = "aab";
    char J[4] = "aba";

    for (int i = 0; i < 3; ++i) {
        temp.push_back(A[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(B[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(C[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(D[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(E[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(F[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(G[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(H[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(I[i]);
    }

    S.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; ++i) {
        temp.push_back(J[i]);
    }

    S.push_back(temp);
    temp.clear();

    /*
      "aaa",
      "abb",
      "abb",
      "bbb",
      "bbb",
      "aaa",
      "bbb",
      "abb",
      "aab",
      "aba"
     */

    string word = "aabaaaabbb";

    bool result = s.exist(S, word);

    cout << (result ? "true" : "false" ) << endl;
    

    return 0;
}
