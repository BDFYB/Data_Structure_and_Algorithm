#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void insert_sort(vector<int> &inputs) {
    for (int i = 1; i < inputs.size(); i++) {
        int current = inputs[i];
        int j = i;
        for (; j > 0; j--) {
            if (inputs[j - 1] > current) {
                inputs[j] = inputs[j - 1];
            } else {
                break;
            }
        } 
        inputs[j] = current;
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
    insert_sort(inputs);
    print_vector(inputs);
    
}
