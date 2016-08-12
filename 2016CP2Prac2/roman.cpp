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

using namespace std;
//Function that returns a digit depending on input array
//returns -1 if not found.
int search(string in, string sArr[], int length);

int main(int argc, char** argv) {
    
    string units[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
    string tens[] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string hundreds[] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string thousands[] = {"M","MM","MMM"};
    string in;
    cin >> in;
    
    //make input uppercase
    for(int i = 0; i < in.length(); i++){
        in[i]=toupper(in[i]);
    }

    int digit = search(in, thousands, 3);
    if (digit){
        cout << digit << "000";
    }
    else if(digit = search(in, hundreds, 10)){
        cout << digit << "00";
    }
    else if(digit = search(in, tens, 10)){
        cout << digit << "0";
    }
    else if(digit = search(in, units, 10)){
        cout << digit;
    }
    
    cout << endl;
    return 0;
}

int search(string in, string sArr[], int length){
    for (int i = 0; i < length; i++){
        if (in == sArr[i]){
            return i+1;
        }
    }
    return 0;
}
