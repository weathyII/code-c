#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < count.size(); i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    for (int i = 0; i < arr.size (); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


