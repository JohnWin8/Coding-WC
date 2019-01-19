#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void ireset(ifstream &ifile, const string filename) {
	  ifile.close();
	  ifile.clear();
	  ifile.open(filename);
}

int charCount(ifstream &file) {
	 string s;
	 int counter = 0;
	 while (getline(file, s)) {
		  counter += s.length() +1; 
	 }
 return counter;
}

int wordCount(ifstream &file) {
	 string s;
	 int counter = 0;
	 while (file >> s) {
		  counter++;
	 }
 return counter;
}

int wordCount(istringstream &file) {
	 string s;
	 int counter = 0;
	 while (file >> s) {
		  counter++;
	 }
 return counter;
}

int lineCount(ifstream &file) {
	 string s;
	 int counter = 0;
	 while (getline(file, s)) {
	  counter++; 
	 }
 return counter;
}
 
int main(int argc, char *argv[]) {
 bool cbool{false};
 bool lbool{false};
 bool wbool{false};
 bool needfile = true;
 string filename = "";

 for (int i = 1; i < argc; i++) {
	  string s = argv[i];
	  if (s == "-c") {cbool = true;
	  } else if (s == "-l") {lbool = true;
	  } else if (s == "-w") {wbool = true;
	  } else {
		   filename = s;
		   needfile = false;
	  }
 }
 if (!wbool && !lbool && !cbool) {
  wbool = true;
  cbool = true;
  lbool = true;
 }

 
int c{0},w{0},l{0};
 if (!needfile){
	 ifstream ifile{filename}; 
	 if (cbool){
		  c = charCount(ifile);
		  ireset(ifile, filename);
	 }
	 if (wbool){
		  w = wordCount(ifile);
		  ireset(ifile, filename);
	 }
	 if (lbool){
		  l = lineCount(ifile);
		  ireset(ifile, filename);
	 }
 } else {
	 string strfile = "";
	 string tmp;
	 while (getline(cin, tmp)) {
		  strfile += tmp;
		  l += 1;
		  c += tmp.length() + 1;
		  strfile += " ";
	 }
 	istringstream iss{strfile};
 	 w = wordCount(iss);
 }

 if (lbool) cout << l;
 if (wbool) {
	 if (lbool) cout << " ";
	 cout << w;
	}
 if (cbool) {
 	if (lbool || wbool) cout << " ";
 	cout << c;
 } 
if (!needfile)cout << " " << filename;

cout << endl;
}
