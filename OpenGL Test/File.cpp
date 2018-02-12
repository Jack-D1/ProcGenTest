#include "File.h"
using namespace std;

string readFile(string path) {
	ifstream f;
	string line;
	string content;
	f.open(path, ios::in);
	if (f.is_open()) {
		while (getline(f, line)) {
			content.append(line + '\n');
		}
		f.close();
	}
	//cout << content << endl;
	return content;
}
char* readFileC(string path) {
	ifstream f;
	string line;
	string content;
	f.open(path, ios::in);
	if (f.is_open()) {
		while (getline(f, line)) {
			content.append(line + '\n');
		}
		f.close();
	}
	//cout << content << endl;
	const char* a = content.c_str();
	cout << a << endl;
	return (char*) a;
}
