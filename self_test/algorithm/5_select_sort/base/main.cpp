#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void select_sort(vector<int> &inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        int min = inputs[i];
        int pos = i;
        for (int j = i; j < inputs.size(); j++) {
            if (inputs[j] < min) {
                min = inputs[j];
                pos = j;
            }
        }
        swap_int(inputs[pos], inputs[i]);
    }
};

void print_vector(vector<int> &inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << inputs[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char * argc[]) {
    int data[] = {22, 88, 77, 34, 8, 9, 38, 43, 23, 8, 98};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    select_sort(inputs);
    print_vector(inputs);
    
}
