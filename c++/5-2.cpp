
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string text;
    vector<string> numbers;
	getline(cin, text);
    stringstream stringStream(text);

    string temp;
	int found;
	while (!stringStream.eof()) {
		stringStream >> temp;

		if (stringstream(temp) >> found)
			cout << found << " ";

		temp = "";
	}
    

    string cur_num = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= '1' && text[i] <= '0') {
            cur_num += text[i];
            cout << cur_num;
        } else {
            numbers.push_back(cur_num);
            cur_num = "";
        }
    } 

    string biggest_num = "";

    if (numbers.size() == 0) {
        cout << "there is no numbers";
        return 0;
    }

    for (auto elem: numbers) {
        if (elem.length() > biggest_num.length()) {
            biggest_num = elem;
        }
    }

    cout << "the longest numbers is" << biggest_num;

    return 0;
}