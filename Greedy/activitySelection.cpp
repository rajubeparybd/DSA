#include <iostream>
#include <vector>
using namespace std;

struct Activity {
    int start, finish;
};

void sortItems(vector<Activity> &arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].finish > arr[j+1].finish)
                swap(arr[j], arr[j + 1]);
        }
    }
}

void scheduleActivities(vector<Activity>& arr) {
    sortItems(arr, arr.size());

    vector<Activity> schedule;
    schedule.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].start >= schedule.back().finish) {
            schedule.push_back(arr[i]);
        }
    }

    cout << endl;
    for (Activity& act : schedule) cout << "(" << act.start << "," << act.finish << ") ";
    cout << endl;
}

int main() {
    int n, start, finish;;
    cout << "Enter number of Activity: ";
    cin >> n;
    vector<Activity> arr;
    
    for (int i = 0; i < n; ++i) {
        cout << "A" << (i+1) << " (Start, Finish): ";
        cin >> start >> finish;
        arr.push_back({start, finish});
    }

    scheduleActivities(arr);

    return 0;
}
/*
 = {
            {5, 9},
            {1, 2},
            {3, 4},
            {0, 6},
            {5, 7},
            {8, 9}
    };
 */
