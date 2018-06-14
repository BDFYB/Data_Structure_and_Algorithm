#include <iostream>
#include <vector>

using std::vector;

void swap_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void bubble_sort(vector<int> &inputs) {
    int low = 0;
    int high = inputs.size();
    while (low < high) {
        for (int i = low + 1; i < high; i++) {
            if (inputs[i - 1] > inputs[i]) {
                swap_int(inputs[i - 1], inputs[i]);
            }
        }
        high --;
        for (int j = high; j > low; j--) {
            if (inputs[j - 1] > inputs[j]) {
                swap_int(inputs[j - 1], inputs[j]);
            }
        }
        low ++;
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
