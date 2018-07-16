#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void adjest_heap(vector<int>& inputs, int start, int end) {
    int i = start;
    int child;
    while (2 * i + 1 < end) {
        child = 2 * i + 1;
        if (child + 1 < end && inputs[child] > inputs[child + 1]) {
            child += 1;
        }
        if (inputs[i] > inputs[child]) {
            swap(inputs[i], inputs[child]);
        }
        i = child;
    }
};

void heap_sort(vector<int>& inputs) {
    if (inputs.size() <= 1) {
        return;
    }
    //建堆
    for (int i = inputs.size() / 2 - 1; i >= 0; i--) {
        adjest_heap(inputs, i, inputs.size());
    }

    for (int i = inputs.size() - 1; i > 0; i--) {
        swap(inputs[i], inputs[0]);
        adjest_heap(inputs, 0, i);
    }

}

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
    heap_sort(inputs);
    print_vector(inputs);
};
