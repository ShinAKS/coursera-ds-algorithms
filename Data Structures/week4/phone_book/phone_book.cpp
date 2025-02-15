#include <iostream>
#include <vector>
#include <string>
#define MAX 10000001


using std::string;
using std::vector;
using std::cin;


struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

/*
vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}
*/

vector<string>process_queries_faster(const vector<Query>&queries){
	vector<string>phone(MAX);
	vector<string>result;
	for (int i=0;i<MAX;i++)phone[i]="0";
	for (size_t i=0;i<queries.size();++i){
		if (queries[i].type=="add")phone[queries[i].number]=queries[i].name;
		if (queries[i].type=="del")phone[queries[i].number]="0";
		if (queries[i].type=="find"){
			if (phone[queries[i].number]=="0")result.push_back("not found");
			else result.push_back(phone[queries[i].number]);
		}
		
	}
	return result;
	
}

int main() {
    write_responses(process_queries_faster(read_queries()));
    return 0;
}
