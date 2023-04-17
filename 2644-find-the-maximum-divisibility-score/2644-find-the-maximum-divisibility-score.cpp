class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_count = INT_MIN;
        int ans;
        sort(divisors.begin(), divisors.end());
        for(int i = 0; i < divisors.size(); i++)
        {
            int count = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] % divisors[i] == 0)
                    count++;
            }
            if(count > max_count)
            {
                ans = divisors[i];
                max_count = count;
            }
        }
        return ans;
    }
};