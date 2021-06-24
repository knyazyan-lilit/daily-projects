#include <iostream>
#include <vector>

class Cube
{
private:
    std::vector<char> cube_tops;

public:
    Cube()
    {
        cube_tops.resize(8);
    }
    friend std::string Encrypt(std::string& message);
    friend std::string Decrypt(std::vector<std::string>& message);
    friend Cube rotate_right(Cube &);
    friend Cube rotate_left(Cube &);
    friend Cube rotate_up(Cube &);
    friend Cube rotate_down(Cube &);
};
