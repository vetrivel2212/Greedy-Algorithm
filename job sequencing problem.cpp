#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

bool comp(Job a, Job b) {
    return a.profit > b.profit; // Sort by descending profit
}

vector<int> jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comp);  // Step 1: Sort by profit

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    vector<int> slot(maxDeadline + 1, -1);  // 1-based indexing
    int count = 0, countProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;  // Assign job
                count++;
                countProfit += arr[i].profit;
                break;
            }
        }
    }

    return {count, countProfit};
}

int main() {
    Job arr[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27},
                 {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = jobScheduling(arr, n);
    cout << "Maximum Jobs Done: " << result[0] << endl;
    cout << "Total Profit Earned: " << result[1] << endl;
    return 0;
}
