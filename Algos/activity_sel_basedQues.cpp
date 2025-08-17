#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort activities by their ending times
bool compareByEndTime(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maxMovies(vector<pair<int, int>>& activities) {
    // Sort the activities by their ending times
    sort(activities.begin(), activities.end(), compareByEndTime);

    // Initialize the end time of the last selected activity
    int e1 = activities[0].second;
    int j = 1;
    int count = 1;

    // Iterate through the sorted list of activities
    while (j < activities.size()) {
        // If the start time of the current activity is greater than or equal to
        // the end time of the last selected activity, select it
        if (activities[j].first >= e1) {
            count++;
            e1 = activities[j].second;
        }
        j++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of movies: ";
    cin >> n;

    vector<pair<int, int>> activities(n);
    cout << "Enter the start and end times of each movie:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }

    int result = maxMovies(activities);
    cout << "The maximum number of movies you can watch entirely is: " << result << endl;

    return 0;
}
