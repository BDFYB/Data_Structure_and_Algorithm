#include <iostream>
#include <vector>

using std::vector;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
};

void shell_sort(vector<int>& inputs) {
    int length = inputs.size();
    for (int gap = length/2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            for (int j = i; j >=0; j -= gap ) {
                if (inputs[j] < inputs[j - gap]) {
                    swap(inputs[j], inputs[j - gap]);
                } else {
                    break;
                }
            }
        }
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
    shell_sort(inputs);
    print_vector(inputs);
};
