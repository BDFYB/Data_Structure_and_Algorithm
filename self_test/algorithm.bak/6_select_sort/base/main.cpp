#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void select_sort(vector<int>& inputs) {
    if (inputs.size() < 1) {
        return;
    }
    for (int i = 0; i < inputs.size(); i++) {
        int current = inputs[i];
        int pos = i;
        for (int j = i + 1; j < inputs.size(); j++) {
            if (inputs[j] < current) {
                current = inputs[j];
                pos = j;
            }
        }
        swap(inputs[i], inputs[pos]);
    }
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
    select_sort(inputs);
    print_vector(inputs);
};
