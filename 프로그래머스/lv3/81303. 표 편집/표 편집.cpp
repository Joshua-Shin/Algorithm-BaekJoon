#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int val = -1;
    int prev = -1;
    int next = -1;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    struct Node node[n];
    stack<Node> deleted;
    
    for(int i = 0; i < n; i++){
        answer += "O";
        
        node[i].val = i;
        
        if(i > 0){
            node[i].prev = i - 1;
        }
        
        if(i < n - 1){
            node[i].next = i + 1;
        }
    }
    
    for(int i = 0; i < cmd.size(); i++){
        string command = cmd[i];
        
        switch(command[0]){
            case 'U':{
                int move = stoi(command.substr(2));
                
                while(move--){
                    k = node[k].prev;
                }
                
                break;
            }
                
            case 'D':{
                int move = stoi(command.substr(2));
                
                while(move--){
                    k = node[k].next;
                }
                
                break;
            }
                
            case 'C':{
                int next = node[k].next;
                int prev = node[k].prev;
                
                deleted.push(node[k]);
                
                if(prev > -1){
                    node[prev].next = next;
                }
                
                if(next > -1){
                    node[next].prev = prev;
                }
                
                k = next > -1 ? next : prev;
                
                break;
            }
                
            case 'Z':{
                Node restore = deleted.top();
                
                int val = restore.val;
                int next = restore.next;
                int prev = restore.prev;
                
                if(prev > -1){
                    node[prev].next = val;
                }
                
                if(next > -1){
                    node[next].prev = val;
                }
                
                deleted.pop();
                
                break;
            }
        }
    }
    
    while(!deleted.empty()){
        int top = deleted.top().val;
        
        deleted.pop();
        
        answer[top] = 'X';
    }
    
    return answer;
}