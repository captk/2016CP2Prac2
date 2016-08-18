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
int search(string &in, string sArr[], int length);

//Function to check if the next character is appropriate
//deletes the rest of the string otherwise
bool appropriate(string &in);

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

int search(string &in, string sArr[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        //find a digit
        size_t index = in.find(sArr[i]);
        if (index != string::npos && index == 0) {

            //Need to look for one more in case it's the 4th element
            if (i == 4) {
                if (in.find(sArr[i - 1]) != string::npos) {
                    in.erase(index, sArr[i - 1].size());
                    return i;
                }
            }
            //remove the portion that is found
            //cout << "erasing index: " << index << " size: " << sArr[i].size() << endl;
            in.erase(index, sArr[i].size());

            return i + 1;
        }
    }

    return 0;
}

bool appropriate(string &in) {
    //cout << "checking appropriatness for: " << in << endl;
    switch (in[0]) {
        case 'M':
        case 'D':
        case 'C':
        case 'L':
        case 'X':
        case 'V':
        case 'I':
            return true;
            break;
        default:
            in.erase(0, in.size());
            //cout << "new string: " << in << endl;
            return false;

    }
}
//Converts a roman numeral string and returns an equivalent arabic string

string romanToArabic(string in) {

    //search for digits
    //if string is non-empty, remember to concatenate a zero
    int total = 0;
    stringstream totalString;
    int digit;
    if (appropriate(in) && (digit = search(in, thousands, 3))) {
        //cout << digit << "000" << endl;
        total += 1000 * digit;
    }
    if (appropriate(in) && (digit = search(in, hundreds, 9))) {
        //cout << digit << "00" << endl;
        total += digit * 100;
    }
    if (appropriate(in) && (digit = search(in, tens, 9))) {
        //cout << digit << "0" << endl;
        total += digit * 10;
    }


    if (appropriate(in) && (digit = search(in, units, 9))) {
        //cout << digit << endl;
        total += digit;
    }



    //cout << total << endl;
    totalString << total;
    return totalString.str();
}

//Converts an arabic numeral string and returns an equivalent roman string

string arabicToRoman(string in) {
    //search for digits
    //using stringstream to grab digits
    //not very elegant... oh well
    stringstream romanNumber, inStream, arabicNumber;
    int temp, remainder;
    inStream << in;

    //get all the numbers and put them together
    //we should now have an int
    while (inStream >> temp) {
        arabicNumber << temp;
    }

    //remainder is now an integer
    arabicNumber >> remainder;
    temp = remainder / 1000;

    for (int i = 0; i < temp; i++) {
        romanNumber << "M";
    }

    remainder %= 1000;
    temp = remainder / 100;
    if (temp != 0) {
        romanNumber << hundreds[temp - 1];
    }
    remainder %= 100;
    temp = remainder / 10;
    if (temp != 0) {
        romanNumber << tens[temp - 1];
    }
    remainder %= 10;
    if (remainder != 0) {
        romanNumber << units[remainder - 1];
    }
    return romanNumber.str();
}