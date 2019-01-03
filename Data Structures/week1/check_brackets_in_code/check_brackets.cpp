#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int ans=-1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()){
            	ans= (position+1);
            	break;
            }
            Bracket last_open=opening_brackets_stack.top();
            if (!last_open.Matchc(next)){
            	ans= position+1;
            	break;
            }
            else opening_brackets_stack.pop();
        }
    }
    // Printing answer, write your code here
    
    if (ans!=-1)std::cout<<ans<<std::endl;
	else if (opening_brackets_stack.size()==0)std::cout<<"Success"<<std::endl;
	else{
		while (opening_brackets_stack.size()!=1)opening_brackets_stack.pop();
		ans=opening_brackets_stack.top().position+1;
		std::cout<<ans<<std::endl;
	}
    

    return 0;
}
