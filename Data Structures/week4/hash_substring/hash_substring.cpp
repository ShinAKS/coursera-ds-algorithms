#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

long long PolyHash(const string& s,int p,int x){
	ull hash=0;
	for (long long i=static_cast<long long>(s.size())-1;i>=0;i--){
		hash=(hash*x+s[i])%p;
	}
	return hash;
}

std::vector<long long> PrecomputeHashes(string T,int P,int p,int x){
	int len=T.size();
	std::vector<long long>H(len-P+1);
	string S=T.substr(len-P,P);
	H[len-P]=PolyHash(S,p,x);
	long long y=1;
	for (int i=1;i<=P;i++){
		y=y*x%p;
	}
	for (int i=len-P-1;i>=0;i--){
		H[i]=((x*H[i+1]+T[i]-y*T[i+P])%p+p)%p;
	}
	return H;
}
bool AreEqual(string s1,string s2){
	if (s1.size()!=s2.size())return false;
	for (int i=0;i<s1.size();i++){
		if (s1[i]!=s2[i])return false;
	}
	return true;
}
Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
	
    int p = 1000000007;
	int x = std::rand() % (p-1) + 1;
	const string& s = input.pattern, t = input.text;
	std::vector<int> ans;

	long long pHash = PolyHash(s, p, x);
//	std::cout<<pHash<<"\n";
	std::vector<long long> H = PrecomputeHashes(t, s.size(), p, x);
//	for (int i=0;i<H.size();i++)std::cout<<H[i]<<" ";
//  std::cout<<"\n";
	for (size_t i = 0; i + s.size() <= t.size(); ++i) {
		if (pHash != H[i])
			continue;
		if (AreEqual(t.substr(i, s.size()), s))
			ans.push_back(i);
	}
	return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
