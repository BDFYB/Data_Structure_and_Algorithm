#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void quick_sort(vector<int> &inputs, int low, int high) {
    if (low >= high) {
        return;
    }
    int flag_val = inputs[low];
    int pos = low;
    for (int i = low; i < high; i++) {
        if (inputs[i] < flag_val) {
            inputs[pos] = inputs[i];
            pos++;
            inputs[i] = inputs[pos];
        }
    }
    inputs[pos] = flag_val;
    quick_sort(inputs, low, pos);
    quick_sort(inputs, pos + 1, high);
};

void print_vector(vector<int> &inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << inputs[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char * argc[]) {
    int data[] = {22, 11, 88, 77, 34, 8, 9, 8, 98};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    quick_sort(inputs, 0,inputs.size());
    print_vector(inputs);
    
}
