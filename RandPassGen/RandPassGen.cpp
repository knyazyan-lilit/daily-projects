#include <iostream>
#include <string>

int random_index_generator()
{

    int r = rand() % 4;
    return r;
}

int alphabet_index_generator()
{

    int r = rand() % 26;
    return r;
}

std::string PasswordGenerator()
{

    int i = 0;
    std::string Uppercase;
    std::string Lowercase;
    std::string Numbers;
    std::string Symbols;

    while (i < 26)
    {
        Uppercase.push_back('A' + i);
        ++i;
    }

    i = 0;
    while (i < 26)
    {
        Lowercase.push_back('a' + i);
        ++i;
    }

    i = 0;
    while (i < 7)
    {
        Symbols.push_back('!' + i);
        ++i;
    }
    i = 0;
    Symbols.push_back(')');

    while (i < 5)
    {
        Symbols.push_back('+' + i);
        ++i;
    }
    i = 0;
    while (i < 5)
    {
        Symbols.push_back(':' + i);
        ++i;
    }
    i = 0;
    while (i < 4)
    {
        Symbols.push_back('{' + i);
        ++i;
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
        int ind = random_index_generator();
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

            int uppercase = alphabet_index_generator();
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
            int lowecase = alphabet_index_generator();
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