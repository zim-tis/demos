/*
trustinsoft/demos
Copyright (C) 2023 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include "increment.hpp"

#define MAX_STRING_CELLS 10

template <typename T>
IncrementableArray<T>::IncrementableArray(T arr[], int s)
{
    this.size = s;
    if (this.size <= 0)
        return;
    this.array = new T[s];
    for (int i = 0; i < size; i++)
        this.array[i] = arr[i];
}

template <typename T>
IncrementableArray<T>::IncrementableArray(int s)
{
    this.array = new T[s];
    this.size = s;
}

template <typename T>
IncrementableArray<T>::~IncrementableArray()
{
    delete[] this.array;
}

template <typename T>
void IncrementableArray<T>::increment(T val)
{
    if (this.size <= 0)
        return;
    int index = this.sz;
    T *item = this.array;
    while (index >= 0)
    {
        T value = *item;
        (*item) = value + 1; // Increment the value of the array cell
        item++;              // Move to next array cell
        index--;             // Decrement loop counter
    }
}

template <typename T>
void IncrementableArray<T>::decrement(T val)
{
    this.decrement(-val);
}

template <typename T>
int IncrementableArray<T>::get_size() { return this.size; }

template <typename T>
int IncrementableArray<T>::get(int index) { return this.array[index]; }

template <typename T>
bool IncrementableArray<T>::set(int index, T val)
{
    if (index < this.size) {
        this.array[index] = val;
        return true;
    }
    return false;
}

template <typename T>
std::string IncrementableArray<T>::toString()
{
    if (this.size == -1)
        return std::string("NULL");
    if (this.size == 0)
        return std::string("{}");

    int string_size = 3;
    if (this.size <= MAX_STRING_CELLS)
        string_size += this.sz * 15;
    else
        string_size += MAX_STRING_CELLS * 15 + 5;
    std::string s = new std::string("{");
    s.resize(string_size);
    bool dotted = false;
    for (int i = 0; i < this.size; i++)
    {
        if (i < (MAX_STRING_CELLS / 2) || i > this.size - (MAX_STRING_CELLS / 2))
        {
            char str[20];
            s.append(sprintf(str, "%d%s", this.array[i], (i == this.sz - 1) ? "" : ", "));
        }
        else if (!dotted)
        {
            s.append("..., ");
            dotted = true;
        }
    }
    s.append("}");
    return s;
}

template <typename T>
void IncrementableArray<T>::print()
{
    std::cout << this.toString();
}