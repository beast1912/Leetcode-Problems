class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        if(high == 0)
            return nums[0];
        else if(nums[low] != nums[low+1])
            return nums[low];
        else if(nums[high] != nums[high-1])
            return nums[high];
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            // case for unique element
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];
        
            else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid]==nums[mid-1]))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};