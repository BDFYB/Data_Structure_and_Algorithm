#include <iostream>
#include <vector>

using std::vector;

void swap_int(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
};

void quick_sort(vector<int>& inputs, int low, int high) {
    if (low >= high) {
        return;
    }
    int flag = inputs[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (i < j) {
            if (inputs[j] < flag) {
                break;
            }
            j--;
        }
        if (i < j) {
            inputs[i] = inputs[j];
        }
        while (i < j) {
            if (inputs[i] > flag) {
                break;
            }
            i++;
        }
        if (i < j) {
            inputs[j] = inputs[i];
        }
    }
    inputs[i] = flag;
    quick_sort(inputs, low, i - 1);
    quick_sort(inputs, i + 1, high);
};


void print_vector(vector<int>& data) {
    for (int i = 0; i< data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char* argc[]) {
    int data[] = {23, 85, 49, 98, 97, 76, 34};
    vector<int> inputs(data, data+sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    quick_sort(inputs, 0, inputs.size() - 1);
    print_vector(inputs);
}
