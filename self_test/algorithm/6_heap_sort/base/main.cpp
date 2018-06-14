#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void print_array(vector<int> inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << inputs[i] << ' ' ;
    }
    std::cout << std::endl;
};

void _heap_sort(vector<int> &inputs, int start, int end) {
    int max_child = start;
    while (2 * start + 1 < end) {
        max_child = 2 * start + 1;
        if ((max_child + 1 < end) && (inputs[max_child + 1] > inputs[max_child])) {
            max_child ++;
        }
        if (inputs[start] < inputs[max_child]) {
            swap_int(inputs[start], inputs[max_child]);
        } else {
            break;
        }
        start = max_child;
    }
};

void heap_sort(vector<int> &inputs, int n) {
    int length = inputs.size();
    if (length <= 1) {
       return; 
    }

    //首次进行堆调整，调整出最大值
    for (int i = length/2 - 1; i >= 0; i--) {
        _heap_sort(inputs, i, length);
    }
    //print_array(inputs);

    //每次堆调整都能堆出一个最大值
    //for (int i = 0; i < length; i++) {
    for (int i = 0; i < n; i++) {
        swap_int(inputs[0], inputs[length - i - 1]);
        _heap_sort(inputs, 0, length -i - 1);
        //print_array(inputs);
    }
};

int main(int argv, char* argc[]) {
    int array[] = {2, 1, 4, 0, 12, 520, 2, 9, 5, 3, 13, 14};
    vector<int> inputs(array, array + sizeof(array)/sizeof(array[0]));
    print_array(inputs);
    heap_sort(inputs, 2);
    print_array(inputs);
}
