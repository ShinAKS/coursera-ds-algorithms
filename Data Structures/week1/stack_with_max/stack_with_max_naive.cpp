#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    vector<int>auxstack;

  public:

    void Push(int value) {
        stack.push_back(value);
        if (auxstack.empty())auxstack.push_back(value);
        if (!auxstack.empty() && value>=auxstack[auxstack.size()-1])auxstack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        int t=stack[stack.size()-1];
        if (t==auxstack[auxstack.size()-1])auxstack.pop_back();
        stack.pop_back();
    }

    int Max() const {
        assert(auxstack.size());
        return auxstack[auxstack.size()-1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
        	int value;
            cin >> value;
            stack.Push((value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
