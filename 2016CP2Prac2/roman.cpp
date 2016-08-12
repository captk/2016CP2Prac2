mc/*
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

int main(int argc, char** argv) {
    
    string units[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
    string in;
    cin >> in;
    
    for (int i = 0; i < 10; i++){
        if (in == units[i]){
            cout << i;
        }
    }
    
    return 0;
}

