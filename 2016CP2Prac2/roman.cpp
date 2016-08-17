/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   roman.cpp
 * Author: k
 *
 * Created on 11 August 2016, 3:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;
//Function that returns a digit depending on input array
//returns -1 if not found.
int search(string in, string sArr[], int length);

//converter functions
//returns converted string
string romanToArabic(string);
string arabicToRoman(string);

//Roman numeral arrays
string units[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string thousands[] = {"M", "MM", "MMM"};

int main(int argc, char** argv) {

    string in;

    while (cin >> in) {

        //make input uppercase
        for (int i = 0; i < in.length(); i++) {
            in[i] = toupper(in[i]);
        }

        switch (in[0]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                cout << arabicToRoman(in) << endl;
                break;
            case 'M':
            case 'D':
            case 'C':
            case 'L':
            case 'X':
            case 'V':
            case 'I':
                cout << romanToArabic(in) << endl;
                break;
            default:
                cout << "0" << endl;
        }
    }

    return 0;
}

//Looks for string 'in' inside of sArr[]
//returns index of array + 1

int search(string in, string sArr[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        //find a digit
        size_t index = in.find(sArr[i]);
        if (index != string::npos) {

            //Need to look for one more in case it's the 4th element
            if (i == 4) {
                if (in.find(sArr[i - 1]) != string::npos) {
                    in.erase(index, sArr[i - 1].size());
                    return i;
                }
            }
            //remove the portion that is found
            in.erase(index, sArr[i].size());

            return i + 1;
        }
    }
    return 0;
}

//Converts a roman numeral string and returns an equivalent arabic string

string romanToArabic(string in) {

    //search for digits
    //if string is non-empty, remember to concatenate a zero
    stringstream total;
    int digit;

    if (digit = search(in, thousands, 3)) {
        //cout << digit << "000";
        total << digit;
    }

    if (digit = search(in, hundreds, 9)) {
        //cout << digit << "00";
        total << digit;
    } else if (total.str().length() > 0) {
        total << digit;
    }

    if (digit = search(in, tens, 9)) {
        //cout << digit << "0";
        total << digit;
    } else if (total.str().length() > 0) {
        total << digit;
    }

    if (digit = search(in, units, 9)) {
        //cout << digit;
        total << digit;
    } else if (total.str().length() > 0) {
        total << digit;
    }

    return total.str();
}

//Converts an arabic numeral string and returns an equivalent roman string

string arabicToRoman(string in) {
    //search for digits
    //if string is non-empty, remember to concatenate a zero
    stringstream total;
    int digit;

    return "0000";
}