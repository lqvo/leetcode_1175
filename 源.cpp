#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int num_prime = 0;
        for (int i = 1; i <= n; i++)
            if (isPrime(i))num_prime++;
        long long unsigned int ans1 = jiechen(num_prime);
        long long unsigned int ans2=  jiechen(n - num_prime);
        int m = pow(10, 9) + 7;
        while (ans1 % 10 == 0)ans1 = ans1 / 10, ans2 = (ans2 * 10) % m;
        long long unsigned int ans = (ans1 *ans2)%m;
        return ans;
    }
    bool isPrime(int n) {
        if (n == 1)return false;
        if (n == 2)return true;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)return false;
        return true;
    }
    int jiechen(int n) {
        long long unsigned int ans = 1;
        int m = pow(10, 9) + 7;        
        for (int i = 1; i <= n; i++) {
            ans *= i;
            ans = ans % m;           
        }
        return ans;
    }
};
int main() {
    Solution sol;

   
    cout << sol.numPrimeArrangements(100);

    return 0;
}