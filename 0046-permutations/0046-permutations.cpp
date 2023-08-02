class Solution {
private:
    void helper(int index, vector<int>& nums, vector<vector<int>>&ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            helper(index+1, nums, ans);
            swap(nums[i], nums[index]);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(0, nums, ans);
        return ans;
    }
};