#include "kvs.h"
#include <iostream>
#include <fstream>

map< string, string > m;

int main(int argc, char* argv[]) {
	
	if (argc < 3) {
		cout << "Usage : ./a.out a.txt b.txt c.txt";
		return -1;
	}

	ifstream fp1;
	ifstream fp2;
	ofstream fp3 (argv[3]); // result.txt file pointer
	fp1.open(argv[1], ios::in); // put.txt file pointer
	fp2.open(argv[2], ios::in); // get.txt file pointer

	string k, v;

	if (!fp1.is_open()) {
		cout << "cannot open 'put.txt' file.";
		return 0;
	}

	if (!fp2.is_open()) {
		cout << "cannot open 'get.txt' file.";
		return 0;
	}
	
	open();

	while (!fp1.eof()) { // put.txt read
		fp1 >> k;
		if (k.length() == 0) break; // null check
		fp1 >> v;
		put(k, v);

		k.clear(); // string clear
		v.clear();
	}

	if (!fp3.is_open()) {
		cout << "cannot open 'result.txt' file.";
		return 0;
	}

	while (!fp2.eof()) { // get.txt read
		fp2 >> k;
		if (k.length() == 0) break; // null check
		fp3 << get(k) << "\n";

		k.clear(); // string clear
	}

	fp1.close();
	fp2.close();
	fp3.close();
	close();

	return 0;
}





