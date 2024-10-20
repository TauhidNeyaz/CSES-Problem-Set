#include <bits/stdc++.h>
using namespace std; 

bool fn(string str1, string str2)
{
    // Check if the lengths of the two strings are not
    // equal, return false if they are not.
    if (str1.length() != str2.length())
        return false;

    // If the length of the strings is less than or equal to
    // 2, simply check if they are equal.
    if (str1.length() <= 2 || str2.length() <= 2)
        return (str1 == str2);

    // Initialize strings to store the clockwise and
    // anti-clockwise rotations of str2.
    string clock_rot = "";
    string anticlock_rot = "";
    int len = str2.length();

    // Store the anti-clockwise rotation of str2 by
    // concatenating the last 2 characters to the beginning.
    anticlock_rot = anticlock_rot + str2.substr(len - 2, 2)
                    + str2.substr(0, len - 2);

    // Store the clockwise rotation of str2 by concatenating
    // the first 2 characters to the end.
    clock_rot
        = clock_rot + str2.substr(2) + str2.substr(0, 2);

    // Check if either the clockwise or anti-clockwise
    // rotation of str2 is equal to str1, and return the
    // result.
    return (str1.compare(clock_rot) == 0
            || str1.compare(anticlock_rot) == 0);
}

int main() {
    string s1 = "sample";
    string s2 = "plesam";

    cout << fn(s1, s2);
}