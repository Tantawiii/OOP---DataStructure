#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void InsertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

void PrintVector(const vector<int>& vec) {
    for (int value : vec)
        cout << value << " ";
    cout << endl;
}

void UnsortedData(vector<int>& vec) {
    vec = { 64, 34, 25, 12, 22, 11, 90 };
}

int main() {
    vector<int> data;

    UnsortedData(data);

    cout << "Unsorted Vector:" << endl;
    PrintVector(data);

    BubbleSort(data);

    cout << "Sorted Vector using Bubble Sort:" << endl;
    PrintVector(data);

    UnsortedData(data);

    cout << "Unsorted Vector:" << endl;
    PrintVector(data);

    InsertionSort(data);

    cout << "Sorted Vector using Bubble Sort:" << endl;
    PrintVector(data);

    return 0;
}
