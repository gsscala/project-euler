#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findNumWays(int goal, vector<int>& availableCoins){
    vector<int>numWays(goal + 1, 0);

    numWays[0] = 1;

    for (int coin : availableCoins)
        for (int sum = 1; sum <= goal; sum++)
            if (sum >= coin)
                numWays[sum] += numWays[sum - coin];

    return numWays[goal];
}

int main(){
    int numCoins, goal;

    cin >> numCoins;

    vector<int>availableCoins(numCoins);
    
    for (int & coin : availableCoins)
        cin >> coin;
    
    sort(availableCoins.begin(), availableCoins.end());
    
    cin >> goal;
    
    cout << findNumWays(goal, availableCoins) << endl;

    return 0;
}
