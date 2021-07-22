#include <iostream>
#include <vector>
#include <list>

struct AddressBook
{
    string name;
    string address;
    string phone;
};

int main()
{
    std::list<AddressBook> Book;
    int i = 0;
    std::vector<string> v;
    while (true)
    {
        while (std::cin)
        {
            std::string l;
            std::cin >> l;
            v.push_back(l);
            if (std::cin.get() == '\n')
            {
                v.clear();
                if (v[0] == "add")
                {
                    Book.push_back(AddressBook{v[1], v[2], v[3]});
                }
                v.clear();
                if (v[0] == "remove")
                {
                    list<AddressBook>::iterator itr;
                    for (itr = Book.begin(); itr != Book.end(); ++itr)
                    {
                        if (itr->name == v[1] && itr->address == v[2] && itr->phone == v[3])
                        {
                            Book.erase(itr);
                            break;
                        }
                    }
                }
                v.clear();
                if (v[0] == "ls")
                {
                    for (auto elem : Book)
                    {
                        std::cout << "name : " << elem.name << " ";
                        std::cout << "address : " << elem.address << " ";
                        sdt::cout << "phone : " << elem.phone << " ";
                        std::cout << endl;
                    }
                }
                if (v[0] == "help")
                {
                    std::cout << "add : adding element in AddressBook " << endl;
                    std::cout << "remove : remove element from AddressBook " << endl;
                    std::cout << "ls : lists elements of AddressBook " << endl;
                }
            }
        }
    }
    return 0;
}
