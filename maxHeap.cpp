#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr, int &n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void deleteMid(vector<int> &arr, int &n) {
    int mid = n / 2;
    int i = (n % 2 == 0) ? mid - 1 : mid;
    int j = (n % 2 == 0) ? n - 1 : n;
    cout << arr[i] << " ";
    for (; i < j; i++) arr[i] = arr[i + 1];
    arr.pop_back();
    n--;
}

int main() {
    vector<int> arr;
    int temp, n = 0;
    while (true) {
        cin >> temp;
        if (temp == 0) break;
        else if (temp == -1) {
            sortArray(arr, n);
            deleteMid(arr, n);
        } else {
            arr.push_back(temp);
            n++;
        }
    }
    return 0;
}

//9 10 2 5 1 18 -1 -1 4 3 -1 8 7 -1 0