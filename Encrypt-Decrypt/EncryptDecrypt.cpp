#include <iostream>
#include <vector>
#include "EncryptDecrypt.h"

const int range_of_random_generation = 3;
const int num_of_tops = 8;

int generate_random_rotate()
{
    return rand() % range_of_random_generation;
}

char generate_random_direction()
{
    char dir[] = {'U', 'R', 'L', 'D'};
    return dir[rand() % range_of_random_generation];
}

Cube rotate_right(Cube &cube)
{
    std::swap(cube.cube_tops[5], cube.cube_tops[1]);
    std::swap(cube.cube_tops[5], cube.cube_tops[0]);
    std::swap(cube.cube_tops[4], cube.cube_tops[5]);
    std::swap(cube.cube_tops[7], cube.cube_tops[3]);
    std::swap(cube.cube_tops[7], cube.cube_tops[2]);
    std::swap(cube.cube_tops[6], cube.cube_tops[7]);
    return cube;
}

Cube rotate_left(Cube &cube)
{
    std::swap(cube.cube_tops[4], cube.cube_tops[5]);
    std::swap(cube.cube_tops[5], cube.cube_tops[1]);
    std::swap(cube.cube_tops[1], cube.cube_tops[0]);
    std::swap(cube.cube_tops[6], cube.cube_tops[7]);
    std::swap(cube.cube_tops[7], cube.cube_tops[3]);
    std::swap(cube.cube_tops[3], cube.cube_tops[2]);
    return cube;
}

Cube rotate_up(Cube &cube)
{
    std::swap(cube.cube_tops[2], cube.cube_tops[3]);
    std::swap(cube.cube_tops[3], cube.cube_tops[0]);
    std::swap(cube.cube_tops[0], cube.cube_tops[1]);
    std::swap(cube.cube_tops[6], cube.cube_tops[7]);
    std::swap(cube.cube_tops[6], cube.cube_tops[4]);
    std::swap(cube.cube_tops[4], cube.cube_tops[5]);
    return cube;
}

Cube rotate_down(Cube &cube)
{
    std::swap(cube.cube_tops[1], cube.cube_tops[3]);
    std::swap(cube.cube_tops[1], cube.cube_tops[2]);
    std::swap(cube.cube_tops[0], cube.cube_tops[1]);
    std::swap(cube.cube_tops[5], cube.cube_tops[7]);
    std::swap(cube.cube_tops[5], cube.cube_tops[6]);
    std::swap(cube.cube_tops[4], cube.cube_tops[5]);
    return cube;
}

Cube rotate_cube(std::vector<char> encrypt_string, Cube &cube)
{
    int i = 0;
    while (i < encrypt_string.size())
    {
        if (encrypt_string[i] == 'U')
        {
            rotate_up(cube);
        }
        else if (encrypt_string[i] == 'D')
        {
            rotate_down(cube);
        }
        else if (encrypt_string[i] == 'R')
        {
            rotate_right(cube);
        }
        else
        {
            rotate_left(cube);
        }
        ++i;
    }
    return cube;
}

Cube rotate_cube_for_decrypt(std::vector<char> encrypt_string, Cube &cube)
{
    int i = 0;
    while (i < encrypt_string.size())
    {
        if (encrypt_string[i] == 'U')
        {
            rotate_down(cube);
        }

        if (encrypt_string[i] == 'D')
        {
            rotate_up(cube);
        }

        if (encrypt_string[i] == 'R')
        {
            rotate_left(cube);
        }

        if (encrypt_string[i] == 'L')
        {
            rotate_right(cube);
        }
        ++i;
    }
    return cube;
}

std::string Encrypt(std::string& message)
{
    int num_of_cubes = (message.size() / num_of_tops);
    if (num_of_cubes * num_of_tops < message.size())
    {
        ++num_of_cubes;
    }
    int i = num_of_cubes;
    std::vector<Cube> cubs;
    while (i != 0)
    {
        cubs.push_back(Cube());
        --i;
    }
    int m = 0;
    for (int j = 0; j < num_of_cubes; ++j)
    {
        i = 0;
        cubs[j].cube_tops.resize(message.size() - m);
        while (i < cubs[j].cube_tops.size())
        {
            cubs[j].cube_tops[i] = message[m];
            ++i;
            ++m;
        }
    }
    std::string encryption_key;
    std::string rotation_result;
    for (int i = 0; i < num_of_cubes; ++i)
    {
        int k = 0;
        int r = generate_random_rotate();
        std::vector<char> encrypt_string;
        while (k < r)
        {
            char rand = generate_random_direction();
            encrypt_string.push_back(rand);
            ++k;
        }
        rotate_cube(encrypt_string, cubs[i]);
        k = 0;
        while (k < cubs[i].cube_tops.size())
        {
            rotation_result.push_back(cubs[i].cube_tops[k]);
            ++k;
        }
        k = 0;
        encryption_key += std::to_string(i);
        while (k < encrypt_string.size())
        {
            encryption_key.push_back(':');
            encryption_key.push_back(encrypt_string[k]);
            ++k;
        }
        encryption_key.push_back(',');
        encryption_key.push_back(' ');
    }
    encryption_key.push_back(' ');
    encryption_key += rotation_result;
    return encryption_key;
}

std::string Decrypt(std::vector<std::string>& message)
{
    std::string decryption_result;
    int ind = 0;
    std::string word;
    while (message[ind] != "rotations")
    {
        word += message[ind];
        ++ind;
    }
    ++ind;
    int num_of_cubes = (word.size() / num_of_tops);
    if (num_of_cubes * num_of_tops < word.size())
    {
        ++num_of_cubes;
    }
    int i = num_of_cubes;
    std::vector<Cube> cubs;
    while (i != 0)
    {
        cubs.push_back(Cube());
        --i;
    }
    int l = 0;
    for (int j = 0; j < num_of_cubes; ++j)
    {
        i = 0;
        while (i < cubs[j].cube_tops.size())
        {
            cubs[j].cube_tops[i] = word[l];
            ++i;
            ++l;
        }
    }
    for (int j = ind; j < message.size(); ++j)
    {
        int cub_number = int(message[j][0]) - 48;
        int m = 0;
        while (m < message[j].size())
        {
            if (message[j][m] == ':')
            {
                message[j].erase(message[j].begin() + m);
            }
            ++m;
        }
        std::vector<char> encrypt_string;
        message[j].erase(message[j].begin() + 0);
        m = 0;
        while (m < message[j].size())
        {
            encrypt_string.push_back(message[j][m]);
            ++m;
        }
        rotate_cube_for_decrypt(encrypt_string, cubs[cub_number]);
        int k = 0;
        while (k < cubs[cub_number].cube_tops.size())
        {
            decryption_result.push_back(cubs[cub_number].cube_tops[k]);
            ++k;
        }
    }
    return decryption_result;
}

int main()
{
    char option;
    std::string str;
    std::cout << "1.encrypt\n2.decrypt\n";
    std::cin >> option;
    if (option == '1')
    {
        std::cout << "enter the message " << std::endl;
        std::string message;
        std::cin >> str;
        std::cout << str;
        std::cout << message << std::endl;
        srand(time(0));
        std::cout << Encrypt(message);
    }
    if (option == '2')
    {
        std::vector<std::string> message;
        std::cout << "enter the message " << std::endl;

        while (std::cin)
        {
            std::string line;
            std::cin >> line;
            message.push_back(line);
            if (std::cin.get() == '\n')
            {
                srand(time(0));
                std::cout << Decrypt(message);
                break;
            }
        }
    }
    return 0;
}