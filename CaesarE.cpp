#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string CI(const string& text, int shift, bool decrypt = false){
    string result = text;
    if(decrypt) shift = -shift;

    for(char& c : result){
        if(isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return result;
}

int main(){
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    int shift = 3;
    char mode;

    cout << "Select mode: (e)ncrypt or (d)ecrypt: ";
    cin >> mode;

    bool decrypt = (mode == 'd');

    ifstream in(inputFile);
    ofstream out(outputFile);

    if(!in ||  !out){
        cerr << "Error opening file (check file)\n";
        return 1;
    }

    string line;
    while(getline(in, line)){
        out << CI(line, shift, decrypt) << endl;

    }

    in.close();
    out.close();

    cout << "Encryption complete. Check output.txt\n";
    return 0;
}