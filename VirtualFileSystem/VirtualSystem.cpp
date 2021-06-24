#include "VirtualSystem.h"
#include <iostream>

VirtualSystem::VirtualSystem()
{
    _root = new Node;
    _current = _root;
    _current->name = "root";
    _current->state = true;
    _current->parent = nullptr;
    _path += _root->name + '/';
}

VirtualSystem::~VirtualSystem()
{
    DeleteSystem(_root);
}

void VirtualSystem::DeleteSystem(Node *root)
{
    for (int i = 0; i < root->childeren.size(); ++i)
    {
        if (root->childeren.at(i) != nullptr)
        {
            DeleteSystem(root->childeren.at(i));
        }
        else
        {
            delete root->childeren.at(i);
            std::cout << root->childeren.at(i)->name;
        }
    }
}

void VirtualSystem::ListContent()
{
    if (_current->childeren.size() == 0)
    {
        std::cout << "is empty " << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < _current->childeren.size(); ++i)
        {
            std::cout << _current->childeren.at(i)->name << " ";
        }
        std::cout << std::endl;
    }
}

void VirtualSystem::TouchFile(const std::string &name)
{
    Node *file = new Node;
    file->state = false;
    file->name = name;
    _current->childeren.push_back(file);
    file->parent = _current;
}

void VirtualSystem::RemoveFile(const std::string &name)
{
    for (int i = 0; i < _current->childeren.size(); ++i)
    {
        if (_current->childeren.at(i)->name == name)
        {
            delete _root->childeren.at(i);
            _current->childeren.erase(_current->childeren.begin() + i);
        }
    }
}

void VirtualSystem::MkDir(const std::string &name)
{
    Node *dir = new Node;
    dir->state = true;
    dir->name = name;
    _current->childeren.push_back(dir);
    dir->parent = _current;
}

bool is_same(Node * _current,const std::string str){
    if(_current->name==str){
        return true;
    }
    return false;
}

void VirtualSystem::RemoveFolder(const std::string &name)
{
    for (int i = 0; i < _current->childeren.size(); ++i)
    {
        if (_current->childeren.at(i)->name == name)
        {
            if (_current->childeren.at(i)->childeren.empty())
            {
                delete _current->childeren.at(i);
                _current->childeren.erase(_current->childeren.begin() + i);
                if (_current->childeren.empty())
                {
                    _current = _current->parent;
                    RemoveFolder(_current->childeren[i]->name);
                }
            }
            else
            {
                _current = _current->childeren.at(i);
                RemoveFolder(_current->childeren[i]->name);
            }
        }
    }
}

void VirtualSystem::ChangeToChildDirectory(const std::string &name)
{
    for (int i = 0; i < _current->childeren.size(); ++i)
    {
        if (_current->childeren.at(i)->name == name)
        {
            _current = _current->childeren.at(i);
            _path += _current->name + '/';
        }
    }
}

void VirtualSystem::ChangeToParentDirectory()
{
    _current = _current->parent;
    int index = 0;
    while (index != _path.size())
    {
        ++index;
    }
    while (_path[index] != '/')
    {
        --index;
    }
    _path.resize(index);
    std::cout << _path << std::endl;
}

void VirtualSystem::ShowDirectoryPath()
{
    std::cout << _path << std::endl;
}

void VirtualSystem::ChangeDirectoryDoubly(const std::string &name1, const std::string &name2)
{
    for (int i = 0; i < _current->childeren.size(); ++i)
    {
        if (_current->childeren.at(i)->name == name1)
        {
            _current = _current->childeren.at(i);
            _path += _current->name + '/';
            if (!_current->childeren.empty())
            {
                for (int j = 0; j < _current->childeren.size(); ++j)
                {
                    if (_current->childeren.at(j)->name == name2)
                    {
                        _current = _current->childeren.at(j);
                        _path += _current->name + '/';
                    }
                }
            }
        }
    }
}