class Solution
{
    private:
        void merge(vector<int> &nums, int start, int mid, int end)
        {
            if (start >= end) 
                return;
            int l = start, r = mid + 1, k = 0, size = end - start + 1;
            vector<int> sorted(size, 0);
            while (l <= mid and r <= end)
                sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
            while (l <= mid)
                sorted[k++] = nums[l++];
            while (r <= end)
                sorted[k++] = nums[r++];
            for (k = 0; k < size; k++)
                nums[k + start] = sorted[k];
        }
    void merge_sort(vector<int> &arr, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            merge_sort(arr, start, mid);
            merge_sort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    public:
        vector<int> sortArray(vector<int> &nums)
        {
            int start = 0;
            int end = nums.size() - 1;
            merge_sort(nums, start, end);
            return nums;
        }
};