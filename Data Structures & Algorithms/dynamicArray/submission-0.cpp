#include<vector>
#include<iostream>

class DynamicArray {
    std::vector<int> arr;
public:

    DynamicArray(int capacity) {
        arr.reserve(capacity);
    }

    int get(int i) {
        return arr[i];

    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        arr.push_back(n);
    }

    int popback() {
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    void resize() {
        arr.resize(2 * (arr.size()));
    }

    int getSize() {
        return arr.size();
    }

    int getCapacity() {
        return arr.capacity();
    }
};
