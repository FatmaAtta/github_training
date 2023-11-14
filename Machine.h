// File: Machine.h
// Purpose: Machine Simulator
// Author: Fatma Mahmoud Atta, Iyad Mahdy Mahrous, Norhan Hossam
// Section: S9
// ID: 20220510 20220075 20221185
// TA: Samar Sabry
// Date: 10 Nov 2023

#ifndef ASSIGNMENT2_TASK3_MACHINE_H
#define ASSIGNMENT2_TASK3_MACHINE_H

#include <bits/stdc++.h>

using namespace std;

int address_to_index(string address);
void display_menu();
vector<string> file_to_instructions(string file_name);

class Memory{
    string address;
    string value;
    string memory[256];

public:
    Memory();
    void get_status();
    void set_value(int index, string value);
    string get_value(int index);
};


class Register{
    string content = "00";

public:
    void set_content(string value);
    string get_content();

};

class Machine {
    int program_counter;
    Memory memory;
    Register reg[16];

public:
    void start();
    void menu();
    void status();
    void get_register_status();
    void set_program_counter(string pc);
    void get_instructions(string file_name);
    void initialize();
    void execute();
    void increment_program_counter();
    string get_register_value(int index);
    void load_register_mem(string register_number, string address);
    void load_register_bit_pattern(string register_number, string bit_pattern);
    void store_bit_pattern(string register_number, string address);
    void move(string register1,string register2);
    void print(string register_number);
    void jump(string register_number,string address);
    void halt();
    void add_2s_complement(string register1,string register2,string register3);
};

string hex_to_binary(string hexa);







#endif //ASSIGNMENT2_TASK3_MACHINE_H
