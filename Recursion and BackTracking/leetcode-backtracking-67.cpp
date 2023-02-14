// 67. Add Binary

class Solution {
public:
    string circulateBinary(string a, string b, int digit, int carry){
        if(digit < 0)
            if(carry == 1)
                return to_string(carry);
            else
                return "";

        string result;
        int carrybit = 0;
        int abit = 0;
        int bbit = 0;

        if(digit <= a.size())
            abit = a[digit] - '0';
        else
            abit = 0;
        
        if(digit <= b.size())
            bbit = b[digit] - '0';
        else
            bbit = 0;
        
        if(abit + bbit + carry == 3){
            result = "1";
            carrybit = 1;
        }else if(abit + bbit + carry == 2){
            result = "0";
            carrybit = 1;
        }else if(abit + bbit + carry == 1){
            result = "1";
            carrybit = 0;
        }else if(abit + bbit + carry == 0) {
            result = "0";
            carrybit = 0;
        }

        return circulateBinary(a, b, digit-1, carrybit)+result;
        
    }

    string addBinary(string a, string b) {
        int padding = 0;
        if(a.size() > b.size()){
            padding = a.size()-b.size();
            for(int i=0; i<padding;i++){
                b = "0"+b;
            }
        }else{
            padding = b.size()-a.size();
            for(int i=0; i<padding;i++){
                a = "0"+a;
            }
        }
        return circulateBinary(a, b, a.size()-1, 0);
    }
};