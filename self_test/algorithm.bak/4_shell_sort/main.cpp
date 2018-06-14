#include <iostream>
#include <vector>

using std::vector;

void swap_int(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
};

void shell_sort(vector<int>& inputs) {
    for (int gap = 5; gap > 0; gap /= 2) {
        for (int i = gap; i < inputs.size(); i++) {
            int cur = inputs[i];
            int pos = i;
            for (int j = i - gap; j >= 0; j -= gap) {
                if (inputs[j] > cur) {
                    inputs[j + gap] = inputs[j];
                    pos = j;
                }
            }
            inputs[pos] = cur;
        }
    }
};


void print_vector(vector<int>& data) {
    for (int i = 0; i< data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char* argc[]) {
    //int data[] = {23, 85, 49, 98, 97, 76, 34};
    int data[] = {22, 88, 77, 34, 8, 9, 38, 43, 23, 8, 98};
    vector<int> inputs(data, data+sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    shell_sort(inputs);
    print_vector(inputs);
}
