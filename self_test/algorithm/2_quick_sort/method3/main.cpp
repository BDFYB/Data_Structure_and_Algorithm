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
    int start = low;
    int end = high;
    int flag_val = inputs[low];
    while (start < end) {
        for (; start < end; start++) {
            if (inputs[start] > flag_val) {
                break;
            }
        }
        for (; start < end; end--) {
            if (inputs[end] < flag_val) {
                break;
            }
        }
        if (start < end) {
            swap_int(inputs[start], inputs[end]);
        }
    }
    swap_int(inputs[low], inputs[end - 1]);
    quick_sort(inputs, low, end - 1);
    quick_sort(inputs, end + 1, high);
};

void print_vector(vector<int> &inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << inputs[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char * argc[]) {
    int data[] = {22, 88, 77, 34, 8, 9, 8, 98};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    quick_sort(inputs, 0,inputs.size() - 1);
    print_vector(inputs);
    
}
