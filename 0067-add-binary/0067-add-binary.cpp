class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int a_len = a.length();
        int b_len = b.length();
        int i = 0;
        string ans = "";
        while(i < a_len || i< b_len || carry != 0)
        {
            int x = 0;
            if(i<a_len && a[a_len-i-1]=='1')
                x = 1;
                
            int y = 0;
            if(i<b_len && b[b_len-i-1]=='1')
                y = 1;
        
            int result = x+y+carry;
            carry=result/2;
            result=result%2;
            ans = to_string(result) + ans;
            i++;
        }
    
        return ans;

    }
};