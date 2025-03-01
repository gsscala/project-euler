#include <vector>
#include <iostream>

using namespace std;

pair<vector<int>, vector<bool>> sieve(int MAXN) {
    vector<int> primes;
    vector<bool> isPrime(MAXN + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
        if (isPrime[i])
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;

    for (int i = 2; i <= MAXN; i++)
        if (isPrime[i])
            primes.push_back(i);

    return {primes, isPrime};
}

int main() {
    int MAXN;
    cin >> MAXN;
    auto [primes, isPrime] = sieve(MAXN);
    vector<int> prefixSum(primes.size() + 1, 0);

    for (int i = 0; i < primes.size(); i++)
        prefixSum[i + 1] = prefixSum[i] + primes[i];

    pair<int, int> resp = {0, 0};

    for (int i = 0; i < primes.size(); i++)
        for (int j = i + 1; j < primes.size(); j++) {
            int sum = prefixSum[j] - prefixSum[i];
            if (sum > MAXN)
                break;

            if (isPrime[sum])
                resp = max(resp, {j - i, sum});
        }

    
    cout << resp.second << endl;
}
