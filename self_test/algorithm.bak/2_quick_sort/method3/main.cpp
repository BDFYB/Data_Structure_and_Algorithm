#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void quick_sort(vector<int>& inputs, int low, int high) {
    if (low >= high) {
        return;
    }
    int pos = low;
    int flag = inputs[pos];
    for (int i = low; i < high; i++) {
        if (inputs[i] < flag) {
            inputs[pos] = inputs[i];
            pos++;
            inputs[i] = inputs[pos];
        }
    }
    inputs[pos] = flag;
    quick_sort(inputs, low, pos);
    quick_sort(inputs, pos + 1, high);
};

void print_vector(vector<int> data) {
    for (vector<int>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

int main(int argc, char* argv[]) {
    int data[] = {3, 5, 1, 4, 4, 7, 2, 6};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    quick_sort(inputs, 0, inputs.size());
    print_vector(inputs);
};
