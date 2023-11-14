// File: Memory.cpp
// Purpose: Registers of machine
// Author: Fatma Mahmoud Atta, Iyad Mahdy Mahrous, Norhan Hossam
// Section: S9
// ID: 20220510 20220075 20221185
// TA: Samar Sabry
// Date: 10 Nov 2023

#include "Machine.h"

string Register::get_content()
{
    return this->content;
}

void Register::set_content(string new_content)
{
    this->content = new_content;
}

