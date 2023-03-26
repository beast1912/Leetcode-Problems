class Solution
{
    public:
        int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
        {
            if (k <= numOnes)
                return k;
            if (k > numOnes && k - numOnes <= numZeros)
                return numOnes;
            if (k > numOnes + numZeros)
            {
                k = k - numOnes - numZeros;
                return (numOnes - k);
            }
            return 0;
        }
};