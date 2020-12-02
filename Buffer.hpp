// Rowan Simmons
// 11/29/2019
// Lab 9
// Buffer.hpp: header file for Buffer.cpp, which uses a queue to simulate a buffer from user input

#ifndef Buffer_hpp
#define Buffer_hpp

#include <iostream>
#include <string>
#include <queue>

void buffer(std::queue<int> &buff, int percentage_1, int percentage_2, int rounds);

#endif // !Buffer_hpp