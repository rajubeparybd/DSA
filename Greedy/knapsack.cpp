#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int price, weight;
};

void sortItems(vector<Item> &arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            double ratioA = (double) arr[j].price / arr[j].weight;
            double ratioB = (double) arr[j + 1].price / arr[j + 1].weight;
            if (ratioA < ratioB) swap(arr[j], arr[j + 1]);
        }
    }
}

double knapsack(int w, vector<Item> &arr) {
    sortItems(arr, arr.size());
    double maxValue = 0.0;
    for (Item &item: arr) {
        if (w >= item.weight) {
            maxValue += item.price;
            w -= item.weight;
        } else {
            double fraction = (double) w / item.weight;
            maxValue += (fraction * item.price);
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<Item> arr;
    int w, price, weight, n;
    cout << "Enter capacity: ";
    cin >> w;
    cout << "Enter items number: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Item " << (i + 1) << " (price weight): ";
        cin >> price >> weight;
        arr.push_back({price, weight});
    }

    double result = knapsack(w, arr);
    cout << "Maximum possible value = " << result << endl;

    return 0;
}