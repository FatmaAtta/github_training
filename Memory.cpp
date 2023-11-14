// File: Memory.cpp
// Purpose: Memory of machine
// Author: Fatma Mahmoud Atta, Iyad Mahdy Mahrous, Norhan Hossam
// Section: S9
// ID: 20220510 20220075 20221185
// TA: Samar Sabry
// Date: 10 Nov 2023

#include "Machine.h"

Memory::Memory()
{
    for (int i = 0; i < 256; i++)
    {
        this->memory[i] = "00";
    }
}

void Memory::get_status()
{

    cout << "\nMemory Status: " << endl;
    for (int i = 0; i < 256; i++)
    {
        if (i % 8 == 0 && i)
            cout << endl;
        cout << "|" << setw(2) << right << hex << uppercase << i << ": " << this->memory[i] << "\t";
    }
    cout << endl << endl;
}

void Memory::set_value(int index, string value)
{
    index = index % 256;
    this->memory[index] = value;
}

string Memory::get_value(int index)
{
    return this->memory[index];
}
