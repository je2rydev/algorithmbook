/*
    107.
    failed
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty()) return res;
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        DFS(digits, 0, path, res, letter);
        return res;
    }
    
    void DFS(string digits, int pos, string& path, vector<string>& res, vector<string>& letter){
        if(pos == digits.size()){
            res.push_back(path);
            return;
        }
        for(auto c: letter[digits[pos] - '0']){
            path.push_back(c);
            DFS(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};

class Solution {
private:
    map<int, string> m;
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        string currString="";
        makeCombinations(digits, currString, 0);
        
        return ans;
            
    }
    
    void makeCombinations(string digits, string &currString, int i){
        if(i==digits.size()){
            ans.push_back(currString);
            return;
        }
        
        for(auto letter : m[digits[i]-'0']){
            currString.push_back(letter);
            makeCombinations(digits, currString, i+1);
            currString.pop_back();
        }
        return; 
    }  
};