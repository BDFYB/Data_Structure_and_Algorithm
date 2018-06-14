#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void shell_sort(vector<int> &inputs) {
    for (int gap = inputs.size()/2; gap > 0; gap /= 2) {
        for (int i = gap; i < inputs.size(); i++) {
            int current = inputs[i];
            int pos = i;
            for (int j = i - gap; j >= 0; j -= gap) {
                if (inputs[j] > current) {
                    inputs[j + gap] = inputs[j];
                    pos = j;
                }
            }
            inputs[pos] = current;
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
    int data[] = {22, 88, 77, 34, 8, 9, 38, 43, 23, 8, 98};
    vector<int> inputs(data, data + sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    shell_sort(inputs);
    print_vector(inputs);
    
}
