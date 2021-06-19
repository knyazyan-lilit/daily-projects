#include <iostream>
#include <string>

const int rand_range_for_string = 4;
const int rand_range_for_alphabet = 26;

int generate_random_index()
{
    int r = rand() % rand_range_for_string;
    return r;
}

int generate_alphabet_index()
{
    int r = rand() % rand_range_for_alphabet;
    return r;
}

std::string PasswordGenerator()
{
    int index = 0;
    std::string Uppercase;
    std::string Lowercase;
    std::string Numbers;
    std::string Symbols;
    while (index < 26)
    {
        Uppercase.push_back('A' + index);
        ++index;
    }
    index = 0;
    while (index < 26)
    {
        Lowercase.push_back('a' + index);
        ++index;
    }
    index = 0;
    while (index < 7)
    {
        Symbols.push_back('!' + index);
        ++index;
    }
    index = 0;
    Symbols.push_back(')');

    while (index < 5)
    {
        Symbols.push_back('+' + index);
        ++index;
    }
    index = 0;
    while (index < 5)
    {
        Symbols.push_back(':' + index);
        ++index;
    }
    index = 0;
    while (index < 4)
    {
        Symbols.push_back('{' + index);
        ++index;
    }
    std::string password;
    int length = 8 + (rand() % (24 - 8 + 1));
    int count_of_elems = 0;
    int count_of_uppercases = 0;
    int count_of_lowercases = 0;
    int count_of_symbols = 0;
    password.resize(length);
    while (count_of_elems < length)
    {
        int ind = generate_random_index();
        if (ind == 3 && count_of_symbols == 2)
        {
            continue;
        }
        if (count_of_elems == length - 1 && count_of_symbols == 1)
        {

            int symbols = rand() % Symbols.size();
            password = password + Symbols[symbols];
            count_of_symbols++;
            count_of_elems++;
            break;
        }
        if (count_of_elems == length - 2 && count_of_symbols == 0)
        {
            int symbols = rand() % Symbols.size();
            password = password + Symbols[symbols];
            count_of_symbols++;
            count_of_elems++;
            symbols = rand() % Symbols.size();
            password = password + Symbols[symbols];
            count_of_symbols++;
            count_of_elems++;
        }
        if (ind == 0)
        {
            if ((count_of_uppercases == 2) && (count_of_lowercases == 0 || count_of_lowercases == 1 || count_of_symbols == 0 || count_of_symbols == 1))
            {
                continue;
            }
            int uppercase = generate_alphabet_index();
            password = password + Uppercase[uppercase];
            count_of_uppercases++;
            count_of_elems++;
        }
        if (ind == 1)
        {
            if ((count_of_lowercases == 2) && (count_of_uppercases == 0 || count_of_uppercases == 1 || count_of_symbols == 0 || count_of_symbols == 1))
            {
                continue;
            }
            int lowecase = generate_alphabet_index();
            password = password + Lowercase[lowecase];
            count_of_lowercases++;
            count_of_elems++;
        }
        if (ind == 2)
        {
            int number = rand() % 10;
            password = password + std::to_string(number);
            count_of_elems++;
        }
        if (ind == 3)
        {
            int symbols = rand() % Symbols.size();
            password = password + Symbols[symbols];
            count_of_symbols++;
            count_of_elems++;
        }
    }
    return password;
}

int main()
{
    srand(time(0));
    std::string str = PasswordGenerator();
    std::cout << str;
    return 0;
}
