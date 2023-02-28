//20. Valid Parentheses
// 10mins

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> mystack;
        for(int i=0; i<s.size() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                mystack.push(s[i]);
            else{
                if(mystack.empty())
                    return false;
                char tmp = mystack.top();
                mystack.pop();
                if(tmp == '(' && s[i] ==')')
                    continue;
                if(tmp == '{' && s[i] =='}')
                    continue;
                if(tmp == '[' && s[i] ==']')
                    continue;
                return false; 
            }
        }
        if(mystack.empty())
            return true;
        else
            return false;
    }
};