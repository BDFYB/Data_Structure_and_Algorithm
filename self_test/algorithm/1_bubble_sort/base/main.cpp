#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void bubble_sort(vector<int> &inputs) {
    int size = inputs.size();
    for (int i = 0; i < inputs.size(); i++) {
        int flag = size;
        for (int j = 1; j < flag; j++) {
            if (inputs[j] < inputs[j - 1] ) {
                swap_int(inputs[j], inputs[j - 1]);
                size = j;
            }
        }
    }
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
    bubble_sort(inputs);
    print_vector(inputs);
    
}
