#include <iostream>
#include <vector>

using std::vector;

void swap_int(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
};

void insert_sort(vector<int>& inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        int pos = i;
        int current = inputs[i];
        for (int j = i; j > 0; j--) {
            if (current < inputs[j - 1]) {
                inputs[j] = inputs[j - 1];
                pos = j - 1;
            }
        }
        inputs[pos] = current;
    }
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
    insert_sort(inputs);
    print_vector(inputs);
}
