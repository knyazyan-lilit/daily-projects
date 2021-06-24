#include "VirtualSystem.h"
#include <iostream>

void Parse(std::vector<std::string> query, VirtualSystem &ob)
{
    if (query[0] == "ls")
    {
        ob.ListContent();
    }
    else if (query[0] == "mkdir")
    {
        ob.MkDir(query[1]);
    }
    else if (query[0] == "cd..")
    {
        ob.ChangeToParentDirectory();
    }
    else if (query[0] == "cd")
    {
        ob.ChangeToChildDirectory(query[1]);
    }
    else if (query[0] == "touch")
    {
        ob.TouchFile(query[1]);
    }
    else if (query[0] == "pwd")
    {
        ob.ShowDirectoryPath();
    }
    else if (query[0] == "rmdir")
    {
        ob.RemoveFolder(query[1]);
    }
    else if (query[0] == "rm")
    {
        ob.RemoveFile(query[1]);
    }
    else
    {
        std::cout << "wrong query" << std::endl;
    }
}

int main()
{
    VirtualSystem ob;
    while (true)
    {
        std::vector<std::string> query;
        while (std::cin)
        {
            std::string line;
            std::cin >> line;
            query.push_back(line);
            if (std::cin.get() == '\n')
            {
                Parse(query, ob);
                break;
            }
        }
    }
}