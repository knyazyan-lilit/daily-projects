#include <iostream>
#include <fstream>

std::string CompressWord(std::string &word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        int count_of_letter = 1;
        char current_word = word[i];
        int index = i + 1;
        while (current_word == word[index])
        {
            ++count_of_letter;
            ++index;
        }
        if (count_of_letter == 2 || count_of_letter == 1)
        {
            continue;
        }

        else
        {
            index = i + 1;
            while (current_word == word[index])
            {
                word.erase(word.begin() + index);
            }
            std::string c = std::to_string(count_of_letter);
            word.insert(i + 1, c);
        }
    }
    return word;
}

std::string DecompressWord(std::string &word)
{
    int index = 0;
    while (index < word.size())
    {
        if (isdigit(word[index]))
        {
            int current_letter = word[index - 1];
            int count = word[index] - '0';
            --count;
            std::string s(1, word[index - 1]);
            std::string new_word;
            for (int i = 0; i < word.size(); ++i)
            {
                if (i != index)
                {
                    new_word += word[i];
                }
                else
                {
                    while (count != 0)
                    {
                        new_word += word[index - 1];
                        --count;
                    }
                }
            }

            word = new_word;
        }
        ++index;
    }
   
    return word;
}

void Compress(std::string str)
{
    std::fstream file;
    std::string file_name = "./" + str;
    file.open(file_name);
    std::ofstream file1;
    file1.open("resfile.txt");
    while (!file.eof())
    {
        std::string word;
        file >> word;
        file1 << CompressWord(word);
        file1 << " ";
    }
}

void Decompress(std::string str)
{
    std::fstream file;
    std::string file_name = "./" + str;
    file.open(file_name);
    std::ofstream file1;
    file1.open("resfile.txt");
    while (!file.eof())
    {
        std::string word;
        file >> word;
        file1 << DecompressWord(word);
        file1 << " ";
    }
}

int main()
{
    std::cout << "1.compress" << std::endl;
    std::cout << "2.decompress" << std::endl;
    char option;
    std::cin >> option;
    std::string file_name;
    if (option == '1')
    {
        std::cout << "enter the file name" << std::endl;
        std::cin >> file_name;
        Compress(file_name);
    }

    if (option == '2')
    {
        std::cout << "enter the file name" << std::endl;
        std::cin >> file_name;
        Decompress(file_name);
    }
}
