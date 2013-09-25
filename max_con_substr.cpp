#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

pair<int, string> fun(const string str) {
	vector<string> substrs;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		substrs.push_back(str.substr(i, len-i));
	}
	int count = 1;
	int maxcount = 1;
	string substr;
	for(int i = 0; i < len; i++) {
		for(int j = i+1; j < len; j++) {
			count = 1;
			if(substrs[i].substr(0,j-i) == substrs[j].substr(0, j-i)) {
				count++;
				for(int k = j+(j-i); k < len; k +=(j-i)) {
					if(substrs[i].substr(0, j-i) == substrs[k].substr(0, j-i)) {
						count++;
					} else {
						break;
					}
				}
				if(count > maxcount) {
					maxcount = count;
					substr = substrs[i].substr(0, j-i);
				}
			}
		}
	}
	return make_pair(maxcount, substr);
}


int main()
{
	pair<int, string> rs;
	string str="abababababaccccc";
	rs = fun(str);
	cout << rs.second<<':'<<rs.first<<'\n';
	system("pause");
	return 0;
} 
