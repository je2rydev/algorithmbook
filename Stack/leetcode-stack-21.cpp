/*
    21
    2 hours.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        string dir = "";
        int dot = 0;
        for(int i=1; i<path.size(); i++){
            if(path[i] == '/'){
                if(dir == "."){
                    dir = "";
                    continue;
                }else if(dir == ".."){
                    if(!stack.empty()){
                        stack.pop();
                        
                    }
                    dir = "";
                    continue;
                }
                if(dir != "/" && dir != ""){
                    stack.push(dir);
                }
                dir = "";
            }else
                dir += path[i];
        }
        if(dir != ""){
            if(dir == ".."){
                if(!stack.empty())
                    stack.pop();
                dir = ".";
            }
            if(dir != "."){
                stack.push(dir);
            }
        }


        vector <string> resVec;
        while(!stack.empty()){
            resVec.push_back(stack.top());
            stack.pop();
        }
        string res;
        if(resVec.empty())
            res = "/";
        else
            res = "";
        for(int i=resVec.size()-1;i>=0; i--){
            res+="/";
            res+=resVec[i];
        }
        return res;
    }
};