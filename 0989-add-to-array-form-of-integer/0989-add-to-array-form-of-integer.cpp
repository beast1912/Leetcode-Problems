class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>a;
        vector<int>ans;
        while(k!=0)
        {
            a.push_back(k%10);
            k=k/10;
        }
        reverse(a.begin(),a.end());
        int i=0;
        int carry=0;
        while(i<num.size() || i<a.size() || carry!=0)
        {
            int x=0;
            if(i<num.size() && num[num.size()-i-1]!=0)
                x = num[num.size()-i-1];
            int y=0;
            if(i<a.size() && a[a.size()-i-1]!=0)
                y = a[a.size()-i-1];
            int result = x+y+carry;
            ans.push_back(result%10);
            carry=result/10;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};