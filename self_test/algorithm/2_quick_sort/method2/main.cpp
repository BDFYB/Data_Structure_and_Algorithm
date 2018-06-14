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
    int start = low;
    int end = high - 1;
    while (start < end) {
        for (; start < end; end--) {
            if (inputs[end] < flag_val) {
                inputs[start] = inputs[end];
                start++;
                break;
            }
        }
        for (; start < end; start++) {
            if (inputs[start] > flag_val) {
                inputs[end] = inputs[start];
                end --;
                break;
            }
        }
    }
    inputs[end] = flag_val;
    quick_sort(inputs, low, end);
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
    quick_sort(inputs, 0,inputs.size());
    print_vector(inputs);
    
}
