#include <bits/stdc++.h>
using namespace std;

struct item {
    int val;
    int weight;
};

bool comp(item a, item b) {
    double r1 = double(a.val) / a.weight;
    double r2 = double(b.val) / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, item arr[], int n) {
    sort(arr, arr + n, comp);
    int curr_weight = 0;
    double final_value = 0.0;

    for (int i = 0; i < n; i++) {
        if (curr_weight + arr[i].weight <= W) {
            curr_weight += arr[i].weight;
            final_value += arr[i].val;
        } else {
            int remain = W - curr_weight;
            final_value += (double(arr[i].val) / arr[i].weight) * double(remain);
            break; // very important to break here!
        }
    }

    return final_value;
}

int main() {
    int n = 3, weight = 50;
    item arr[n] = { {100, 20}, {60, 10}, {120, 30} };
    double ans = fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
}
