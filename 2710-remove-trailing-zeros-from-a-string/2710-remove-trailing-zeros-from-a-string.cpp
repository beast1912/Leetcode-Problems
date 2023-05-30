class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        string ans="";
        for(int i = n-1; i>=0; i--)
        {
            if(num[i] == '0')
                num.erase(num.begin()+i);
            else
                break;
            
        }
        return num;
    }
};