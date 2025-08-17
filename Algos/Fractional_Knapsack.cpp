#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double fractionalKnapsack(vector<pair<int,int>>& items, int n, int capacity) {
    // Creating a new vector to store items with their profit-to-weight ratios
    vector<pair<double,pair<int,int>>> new_items(n);
    
    // Calculating the profit-to-weight ratios for each item and storing them in new_items
    for(int i = 0; i < n; i++) {
        new_items[i].second.first = items[i].first;   // Weight of the item
        new_items[i].second.second = items[i].second; // Profit of the item
        new_items[i].first = (1.0 * items[i].second) / items[i].first; // Profit-to-weight ratio
    }

    // Sorting the items in non-increasing order of their profit-to-weight ratios
    sort(new_items.rbegin(), new_items.rend());

    double profit = 0.0;

    // Iterating through the sorted items and adding them to the knapsack
    for(int i = 0; i < n; i++) {
        int weight = new_items[i].second.first;   // Weight of the item
        int value = new_items[i].second.second;   // Profit of the item
        double ratio = new_items[i].first;        // Profit-to-weight ratio

        // If the weight of the item exceeds the remaining capacity, add a fraction of the item
        if(weight > capacity) {
            profit += capacity * ratio;
            capacity = 0;
            break;
        }
        // Otherwise, add the entire item
        else {
            profit += value;
            capacity -= weight;
        }
    }

    return profit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<pair<int,int>> items(n);
    cout << "Enter the weight and profit of each item: ";
    for(int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(items, n, capacity);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
