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

    //search for digits
    int total = 0;
    int digit; 
    if (digit = search(in, thousands, 3)){
        //cout << digit << "000";
        total += digit*1000;
    }
    if(digit = search(in, hundreds, 9)){
        //cout << digit << "00";
        total += digit*100;
    }
    if(digit = search(in, tens, 9)){
        //cout << digit << "0";
        total += digit*10;
    }
    if(digit = search(in, units, 9)){
        //cout << digit;
        total += digit;
    }
    
    //if total is 0, then maybe Arabic numbers are present
    if (total != 0){
        cout << total << endl;
    }
    return 0;
}

int search(string in, string sArr[], int length){
    for (int i = length-1; i >= 0; i--){
        //find a digit
        size_t index = in.find(sArr[i]);
        if(index != string::npos){
            
            //remove the portion that is found
            in.erase(index, sArr[i].size());
        
            return i+1;
        }
    }
    return 0;
}
