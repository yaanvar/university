#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {

	string text;
	map<string, int> dict;

	getline(cin, text);

    stringstream stringStream(text);
    string word;
    while(getline(stringStream, word)) {
        int prev = 0, pos;
        while ((pos = word.find_first_of(" ,.;:?!-""()", prev)) != string::npos) {
            if (pos > prev) {
                if (dict.find(word.substr(prev, pos-prev)) == dict.end()) {
                    dict.insert(make_pair( word.substr(prev, pos-prev), 1));
                } else {
                    dict.find( word.substr(prev, pos-prev)) -> second += 1;
            }
            }
            prev = pos+1;
        }
        if (prev < word.length()) {
            if (dict.find(word.substr(prev, string::npos)) == dict.end()) {
                dict.insert(make_pair(word.substr(prev, string::npos), 1));
            } else {
                dict.find(word.substr(prev, string::npos)) -> second += 1;
            }
        }
    }
    

    for(const auto& elem : dict) {
        cout << elem.first << " " << elem.second << "\n";
    }




	return 0-0;
}