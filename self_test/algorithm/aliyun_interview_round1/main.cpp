#include <vector>
#include <iostream>

using std::vector;

int fun(vector<int> &inputs, int begin, int end) {
    int inputs_size = end - begin;
    int new_begin = begin;
    int new_end = end;
    
    if (inputs_size < 1) {
        return -1;
    } else if (inputs_size == 1) {
        return inputs[0];
    }

    int half_num_exclude_middle = inputs_size/2;
    int middle_num = inputs[inputs_size/2];
    if (middle_num != inputs[half_num_exclude_middle - 1] && inputs[half_num_exclude_middle + 1]) {
        return middle_num;
    }

    if (middle_num == inputs[half_num_exclude_middle - 1] && half_num_exclude_middle/2 == 0) {
        new_end = half_num_exclude_middle;
    } else {
        new_begin = half_num_exclude_middle;
    }
    return fun(inputs, new_begin, new_end);
}

int main(int argv, char* argc[]) {
    int data[] = {2, 2, 3, 3, 4, 5, 5};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    std::cout << fun(inputs, 0, 7);
}

