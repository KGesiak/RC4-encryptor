#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "string.h"

using namespace std;
void swap(int S[],int i,int j)
{
    int temp = S[i];
    S[i] = S[j];
    S[j] = temp;
}

int hextodec(char x)
{
    int temp;
    stringstream dec;
    dec << hex << x;
    dec >> temp;
    return temp;
}
string dectohex(int x)
{
    string temp;
    stringstream result;
    result << hex << x;
    result >>temp;
    return temp;
}
int main() {

    char K[6];
    cout << "Enter 5-character security key: ";
    cin >> K;


    int S[256];
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    //Shuffling values from S array with key
    int j = 0;
    int length= strlen(static_cast<const char*>(K));
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + K[i % length]) % 256;
        swap(S, i, j);
    }


    fstream input_file,output_file;
    input_file.open("input.txt", ios::in);
    output_file.open("output.txt", ios::out);
    if( input_file.bad() || output_file.bad() )
    {
        cout<< "\nProblem with input or output file";
        return -1;
    }


    string line_of_text;

    while(getline(input_file, line_of_text)) {

        int text_length = line_of_text.length();

        int i = 0;
        j = 0;
        for (int k = 1; k < text_length; k += 2) {
            i = (i + 1) % 256;
            j = (j + S[i]) % 256;
            swap(S, i, j);
            int W = S[(S[i] + S[j]) % 256];

            int dec = hextodec(line_of_text[k - 1]) * 16 + hextodec(line_of_text[k]);

            int output = dec^W; // XOR

            if (output < 16) output_file << '0';

            output_file << (char)wynik;
        }
        output_file << '\n';
    }
    cout<<"Input has been encrypted\n";
    input_file.close();
    output_file.close();
    return 0;

}
