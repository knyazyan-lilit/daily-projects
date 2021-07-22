#include <vector>
#include <string>
struct Node
{
    bool state;
    std::string name;
    std::vector<Node *> childeren{};
    Node *parent;
};

class VirtualSystem
{
private:
    Node *_root;
    Node *_current;
    std::string _path;

public:
    VirtualSystem();
    void ListContent();
    void RemoveFolder(const std::string &name);
    void ChangeToChildDirectory(const std::string &name);
    void ChangeToParentDirectory();
    void TouchFile(const std::string &name);
    void RemoveFile(const std::string &name);
    void MkDir(const std::string &name);
    void ShowDirectoryPath();
    void ChangeDirectoryDoubly(const std::string &name1, const std::string &name2);
    void DeleteSystem(Node *root);
    ~VirtualSystem();
};
