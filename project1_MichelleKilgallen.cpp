/************************************************************/
/* Author: Michelle Kilgallen */
/* Major: non-degree */
/* Creation Date: February 6, 2025 */
/* Due Date: February 6, 2025 */
/* Course: CSC 402 */
/* Professor Name: Dr. Zhang */
/* Assignment: Project 1 */
/* Filename: project1_MichelleKilgallen.cpp */
/* Purpose: This program will read from the input file and recognize whether each string in p1input.dat is a palindrome. */
/************************************************************/
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

/*************************************************************************/
/* */
/* Function name: pal */
/* Description: determines whether or not a string from the input file is a palindrome using a stack and a queue*/
/* Parameters: string str: string from main function - input */
/* Return Value: bool - confirms whether or not string is a palindrome (true if yes; false if no) */
/* */
/*************************************************************************/
bool pal(string str)//is input a palindrome? returns true if yes, false if no
{
    stack<char> stack;
    queue<char> queue;
    for(char letter:str)
    {
        stack.push(letter);
        queue.push(letter);
    }
    while (!stack.empty()) //while stack is not empty
    {
        if (stack.top()!=queue.front()) // if top of stack and front of queue are not equal, then str is not palindrome
        {
            return false;
        }
        else
        {
            stack.pop();
            queue.pop();
        }
    }
    //if we get to this point then we know that the str is a palindrome because the letters have all matched up so far...
    return true;
}

/*************************************************************************/
/* */
/* Function name: main */
/* Description: reads input file & sends the strings to function called pal which determines whether or not the strings are palindromes.*/
/* It also receives the answer from pal (true if palindrome; false if not) and prints out the string that was analyzed and if it is a palindrome or not*/
/* Parameters: none
/* Return Value: int because it's main in c++ */
/* */
/*************************************************************************/
int main()
{
    ifstream inputFile("p1input.dat");
    string str;
    if (inputFile.is_open())
    {
        while(getline(inputFile, str))//while there are strings in file
        {
            if (pal(str))//is string from file a palindrome? if yes print this...
            {
                cout << str << " is a palindrome.\n";
            }
            else//AKA if string from file is NOT a palindrome print this...
            {
                cout << str << " is not a palindrome.\n";
            }
        }
        inputFile.close();//close file
    }
    return 0;
}