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
    int flag = inputs[low];
    int start = low;
    int end = high - 1;
    while (start < end) {
        for (; start < end; end--) {
            if (inputs[end] < flag) {
                inputs[start] = inputs[end];
                start++;
                break;
            }
        }
        for (; start < end; start++) {
            if (inputs[start] > flag) {
                inputs[end] = inputs[start];
                end--;
                break;
            }
        }
    }
    inputs[end] = flag;
    quick_sort(inputs, low, end);
    quick_sort(inputs, end + 1, high);
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
