// File: Machine.cpp
// Purpose: Machine Simulator
// Author: Fatma Mahmoud Atta, Iyad Mahdy Mahrous, Norhan Hossam
// Section: S9
// ID: 20220510 20220075 20221185
// TA: Samar Sabry
// Date: 10 Nov 2023

#include "Machine.h"
#include <fstream>
using namespace std;

void Machine::start()
{
    menu();
    status();
    initialize();
}

void Machine::menu()
{
    cout << "\t\tMachine Language Interpreter" << endl;
    cout << "\t--------------------------------------------" << endl;
}

void Machine::status()
{
    this->memory.get_status();
    get_register_status();
}

void Machine::get_register_status()
{
    cout << "Register Status:" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 8 == 0 && i)
            cout << endl;
        cout << "|" << setw(2) << right << hex << i << ": " << reg[i].get_content() << "\t";
    }
    cout << endl << endl;
}

void Machine::set_program_counter(string pc)
{
    this->program_counter = stoi(pc, 0, 16);
}

void Machine::get_instructions(string file_name){
    fstream file;
    int index = this->program_counter;
    string instruction;
    file.open(file_name+".txt",ios::in);
    if (file.is_open()){
        while(getline(file, instruction)){
            this->memory.set_value(index, instruction.substr(0, 2));
            this->memory.set_value(index+1, instruction.substr(2));
            index+=2;
        }
    }
    file.close();
}

void Machine::initialize()
{
    string start_address, file_name;
    int index;

    cout << "Enter .txt file name: ";
    cin >> file_name;
    cout << "Enter start address in a hexadecimal form: ";
    cin >> start_address;
    set_program_counter(start_address);
    get_instructions(file_name);
}

void Machine::increment_program_counter()
{
    this->program_counter += 2;
    this->program_counter %= 256;
}

void Machine::load_register_mem(string register_number, string address)
{
    int reg_index = stoi(register_number, 0, 16);
    int mem_index = stoi(address, 0, 16);
    string new_content = this->memory.get_value(mem_index);
    this->reg[reg_index].set_content(new_content);
}

void Machine::load_register_bit_pattern(string register_number, string bit_pattern)
{
    int reg_index = stoi(register_number, 0, 16);
    string new_content = bit_pattern;
    this->reg[reg_index].set_content(new_content);
}
void Machine::store_bit_pattern(string register_number, string address)
{
    int reg_index = stoi(register_number, 0, 16);
    string new_content = this->reg[reg_index].get_content();
    int mem_index = stoi(address, 0, 16);
    if (address == "00")
        cout << new_content << endl;
    this->memory.set_value(mem_index, new_content);
}

void Machine::move(string register1,string register2)
{
    int reg1_index = stoi(register1, 0, 16);
    int reg2_index = stoi(register2, 0, 16);
    string new_content = this->reg[reg1_index].get_content();

    this->reg[reg2_index].set_content(new_content);
    this->reg[reg1_index].set_content("00");
}
string Machine::get_register_value(int index)
{
    string value = this->reg[index].get_content();
}
void Machine::print(string register_number){
    string value= this->get_register_value(stoi(register_number, 0, 16));
    cout<<value<<"\n";
}
void Machine::jump(string register_number, string address)
{
    int reg_index = stoi(register_number, 0, 16);
    int num1 = stoi(this->reg[0].get_content(), 0, 16);
    int num2 = stoi(this->reg[reg_index].get_content(), 0, 16);
    if (num1 == num2)
        this->program_counter = stoi(address, 0, 16);
}
string hex_to_binary(char hexa){
    unordered_map<char,string> hex_binary;
    hex_binary['1']="0001";
    hex_binary['2']="0010";
    hex_binary['3']="0011";
    hex_binary['4']="0100";
    hex_binary['5']="0101";
    hex_binary['6']="0110";
    hex_binary['7']="0111";
    hex_binary['8']="1000";
    hex_binary['9']="1001";
    hex_binary['A']="1010";
    hex_binary['B']="1011";
    hex_binary['C']="1100";
    hex_binary['D']="1101";
    hex_binary['E']="1110";
    hex_binary['F']="1111";
    return hex_binary[hexa];
}
string ones_comp(string binary){
    for(int i=7;i>0;i--){
        if(binary[i]=='1'){
            binary[i]='0';
        }
        else{
            binary[i]='1';
        }
    }
}
string add(string num1,string num2){

}
void Machine::add_2s_complement(string register1,string register2,string register3){
    string num1 = hex_to_binary(register1[0])+hex_to_binary(register1[1]);
    string num2 = hex_to_binary(register2[0])+hex_to_binary(register2[1]);
    string num3 = hex_to_binary(register3[0])+hex_to_binary(register3[1]);
    twos_comp(num1);
    twos_comp(num2);
    twos_comp(num3);
    //add();
}
void Machine::halt()
{
    exit(0);
}
void Machine::execute() {
    bool isHalt=false;
    string instruction="";
    while(!isHalt){ //or while true
        string instruction=this->memory.get_value(program_counter)+this->memory.get_value(program_counter+1);
        switch (instruction[0]){
            case '1':
                load_register_mem(instruction.substr(1,1),instruction.substr(instruction.length()-2));
                break;
            case '2':
                load_register_bit_pattern(instruction.substr(1,1),instruction.substr(instruction.length()-2));
                break;
            case '3':
                if(instruction.substr(instruction.length()-2)=="00"){
                    print(instruction.substr(1,1));
                }
                else{
                    store_bit_pattern(instruction.substr(1,1), instruction.substr(instruction.length()-2));
                }
                break;
            case '4':
                move(instruction.substr(2,1),instruction.substr(3,1));
                break;
            case '5':
                add_2s_complement(instruction.substr(1,1),instruction.substr(2,1),instruction.substr(3,1));
                break;
            case 'B':
                jump(instruction.substr(1,1),instruction.substr(instruction.length()-2));
                break;
            case 'C':
                halt();
                isHalt=true;
                break;
        }
        increment_program_counter();
    }
}