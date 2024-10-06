#include <bits/stdc++.h>
using namespace std;

struct info {
    int score, time;
    string description;
};

// Print function to display the selected evidence and totals
void Print(vector<info>& selected, int total_score, int total_time) {
    if (selected.empty()) {
        cout << "There is not enough time to present any evidence. Drop the charges." << endl;
        return;
    }

    cout << "Score  Time  Description" << endl;
    cout << "-----  ----  -----------" << endl;
    
    for (int i = 0; i < selected.size(); ++i)
        cout << std::setw(3) << selected[i].score << "    " << setw(3) << selected[i].time << "   " << selected[i].description << std::endl;
    cout << "\nTotal score: " << total_score << " points" << endl;
    cout << "Total time: " << total_time << " hours" << endl;
}

// Main function that handles the dynamic programming solution
void SolveCase(int allowed_time, vector<info>& evidences) {
    int n = evidences.size();

    // DP array: dp[i] will store the maximum score achievable with i hours of time
    vector<int> dp(allowed_time + 1, 0);
    // trace[i][j] will track whether the jth item was selected when time was i
    vector<vector<bool>> trace(n, vector<bool>(allowed_time + 1, false));

    // Dynamic programming to solve the 0/1 knapsack problem
    for (int i = 0; i < n; ++i) {
        for (int t = allowed_time; t >= evidences[i].time; --t) {
            if (dp[t - evidences[i].time] + evidences[i].score > dp[t]) {
                dp[t] = dp[t - evidences[i].time] + evidences[i].score;
                trace[i][t] = true;
            }
        }
    }

    // Backtrack to find the selected evidences
    vector<info> selected;
    int total_score = dp[allowed_time];
    int total_time = 0;
    int remaining_time = allowed_time;

    for (int i = n - 1; i >= 0 && remaining_time > 0; --i) {
        if (trace[i][remaining_time]) {
            selected.push_back(evidences[i]);
            remaining_time -= evidences[i].time;
            total_time += evidences[i].time;
        }
    }

    // Print the result
    Print(selected, total_score, total_time);
}

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore newline after the number of test cases

    while (t--) {
        int allowed_time;
        cin >> allowed_time;
        cin.ignore(); // Ignore newline after the allowed time

        vector<info> evidences;
        string line;

        // Read evidence data
        while (getline(cin, line) && !line.empty()) {
            int score, time;
            size_t pos1 = line.find(' ');  // First space between score and time
            size_t pos2 = line.find(' ', pos1 + 1);  // Second space between time and description

            score = stoi(line.substr(0, pos1));
            time = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            string description = line.substr(pos2 + 1);

            evidences.push_back({score, time, description});
        }

        // Solve the case
        SolveCase(allowed_time, evidences);

        if (t > 0) {
            cout << endl;  // Blank line between test cases
        }
    }

    return 0;
}
