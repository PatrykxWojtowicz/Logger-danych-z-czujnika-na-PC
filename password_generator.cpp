#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to get a random character from a given string
char getRandomChar(const string& chars) {
    return chars[rand() % chars.size()];
}

// Function to generate a random password
string generatePassword(int n) {
    if (n < 4) {
        throw invalid_argument("Password must be at least 4 characters long to meet complexity requirements.");
    }

    string vowels = "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    string digits = "0123456789";
    string specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    string allChars = vowels + consonants + digits + specialChars;

    string password;
    bool lastWasVowel = false;

    // Add at least one uppercase letter, digit, and special character
    password += toupper(getRandomChar(vowels + consonants));
    password += getRandomChar(digits);
    password += getRandomChar(specialChars);

    // Generate remaining characters
    for (int i = 3; i < n; i++) {
        char nextChar;
        if (lastWasVowel) {
            nextChar = getRandomChar(consonants + digits + specialChars);
        } else {
            nextChar = getRandomChar(vowels + digits + specialChars);
        }
        password += nextChar;
        lastWasVowel = isVowel(nextChar);
    }

    // Shuffle the password to ensure randomness
    random_shuffle(password.begin(), password.end());

    return password;
}

int main() {
    srand(time(0)); // Initialize random seed

    int n;
    cout << "Enter desired password length: ";
    cin >> n;

    try {
        string password = generatePassword(n);
        cout << "Generated password: " << password << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
