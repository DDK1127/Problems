#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void organize_teams(const vector<int>& weights) {
    int n = weights.size();
    int totalWeight = 0;
    
    for (int i = 0; i < n; ++i) {
        totalWeight += weights[i];
    }

    int targetWeight = totalWeight / 2;

    vector<vector<int> > dp(n + 1, vector<int>(targetWeight + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= targetWeight; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], weights[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int team1Weight = totalWeight - dp[n][targetWeight];
    int team2Weight = dp[n][targetWeight];

    cout << min(team1Weight, team2Weight) << " " << max(team1Weight, team2Weight) << endl;
}

int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        if (i > 0) {
            cout << endl;  
        }

        int n;
        cin >> n;

        vector<int> weights(n);
        for (int j = 0; j < n; ++j) {
            cin >> weights[j];
        }

        organize_teams(weights);
    }

    return 0;
}
