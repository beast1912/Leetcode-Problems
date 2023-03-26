class Solution {
private:
    void sieve_of_eratosthenes(vector<bool> &isPrime, int n)
    {
        for(int i = 2; i*i<=n;i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j<n; j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        sieve_of_eratosthenes(isPrime, n);
        int count = 0;
        for(int i = 2; i<n; i++)
        {
            if(isPrime[i])
                count++;
        }
        return count;
    }
};