class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_count = INT_MIN;
        int index = -1;
        for(int i = 0; i < mat.size() ; i++)
        {
            int count = 0;
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            if(count > max_count)
            {
                index = i;
                max_count = count;
            }
        }
        return {index, max_count};
    }
};