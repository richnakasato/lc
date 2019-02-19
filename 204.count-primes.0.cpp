/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.52%)
 * Total Accepted:    195.3K
 * Total Submissions: 709.9K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 */
class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> primes(n+1,true);
        primes[0] = false;
        primes[1] = false;
        for (size_t i=2; i*i<primes.size(); ++i) {
            if (primes[i]) {
                for (size_t j=i*i; j<=n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        int count = 0;
        for (size_t i=0; i<primes.size(); ++i) {
            if (i < n && primes[i]) ++count;
        }
        return count;
    }
};
