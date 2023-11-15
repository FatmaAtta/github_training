// File: main.cpp
// Purpose: Machine Simulator
// Author: Fatma Mahmoud Atta, Iyad Mahdy Mahrous, Norhan Hossam
// Section: S9
// ID: 20220510 20220075 20221185
// TA: Samar Sabry
// Date: 10 Nov 2023

#include "Machine.h"

using namespace std;
int main() {
//    Machine m;
//
//    m.start();
//
//    m.load_register_mem("5", "8");
//    m.load_register_bit_pattern("6", "D2");
//
//    m.status();
    string num1="01101111";
    string num2="10111001";
    string two1=twos_comp(num1);
    string two2=twos_comp(num2);
    cout<<two1<<" "<<two2;
    return 0;
}
