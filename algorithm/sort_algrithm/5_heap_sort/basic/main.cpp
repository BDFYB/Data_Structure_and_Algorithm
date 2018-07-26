#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void order_heap(vector<int>&inputs, int pos, int len) {
    while (pos * 2 + 1 < len) {
        int child = pos * 2 + 1;
        if (child + 1 < len && inputs[child] < inputs[child + 1]) {
            child ++;
        }
        if (inputs[pos] < inputs[child]) {
            swap(inputs[pos], inputs[child]);
        }
        pos = child;
    }
};

void heap_sort(vector<int>& inputs, int len){
    if (inputs.size() < 1) {
        return;
    }
    for (int i = len/2 - 1; i >= 0; i--) {
        order_heap(inputs, i, len);
    }

    for (int i = len - 1; i >= 0; i--) {
        swap(inputs[i], inputs[0]);
        order_heap(inputs, 0, i);
    }
};

void print_vector(vector<int>& inputs) {
    for (vector<int>::iterator it = inputs.begin(); it != inputs.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

int main(int argc, char* argv[]) {
    int data[] = {3, 2, 4, 9, 8, 6, 6, 4};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    heap_sort(inputs, inputs.size());
    print_vector(inputs);
};
