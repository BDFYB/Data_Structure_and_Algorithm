#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void bubble_sort(vector<int>& inputs) {
    int pos = 0;
    int loop_count = 0;
    for (int outer_c = 0; outer_c < inputs.size() - 1; outer_c++) {
        loop_count += 1;
        outer_c = pos > outer_c ? pos : outer_c;
        for (int inner_c = inputs.size() - 1; inner_c > outer_c; inner_c--) {
            if (inputs[inner_c] < inputs[inner_c - 1]) {
                swap(inputs[inner_c], inputs[inner_c - 1]);
                pos = inner_c;
            }
        }
    }
    std::cout << "loop time: " << loop_count << std::endl;
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
    bubble_sort(inputs);
    print_vector(inputs);
};
