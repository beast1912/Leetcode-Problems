class Solution
{
    private:
        void merge(vector<int> &arr, int start, int mid, int end)
        {
            int i = start;
            int j = mid + 1;
            int k = 0;
            int n = end - start + 1;
            vector<int> brr(n, 0);
            while (i <= mid && j <= end)
            {
                if (arr[i] < arr[j])
                {
                    brr[k] = arr[i];
                    i++;
                }
                else
                {
                    brr[k] = arr[j];
                    j++;
                }
                k++;
            }

            while (i <= mid)
            {
                brr[k++] = arr[i++];
            }

            while (j <= end)
            {
                brr[k++] = arr[j++];
            }

            for (k = 0; k < n; k++)
            {
                arr[k + start] = brr[k];
            }
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