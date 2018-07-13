#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void insert_sort(vector<int>& inputs) {
    if (inputs.size() < 1) {
        return;
    }
    for (int i = 0; i < inputs.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (inputs[j] < inputs[j - 1]) {
                swap(inputs[j], inputs[j - 1]);
            } else {
                break;
            }
        }
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
    insert_sort(inputs);
    print_vector(inputs);
};
