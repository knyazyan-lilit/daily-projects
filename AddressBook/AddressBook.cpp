#include <iostream>
#include <vector>

struct AddressBook
{
    std::string name;
    std::string address;
    std::string phone;
};

int main()
{
    std::vector<AddressBook> Book;
    int i = 0;
    std::vector<std::string> v;
    while (true)
    {
        while (std::cin)
        {
            std::string l;
            std::cin >> l;
            v.push_back(l);
            if (std::cin.get() == '\n')
            {
                if (v[0] == "add")
                {
                    if (v.size() < 4) {
                        std::cout << "field is missing" << std::endl;
                        v.clear();
                        continue;
                    }
                    else if (v.size() > 4) {
                        std::cout << "unnecessary field" << std::endl;
                        v.clear();
                        continue;
                    }
                    else {
                        Book.push_back(AddressBook{ v[1], v[2], v[3] });
                        v.clear();
                    }
                }
                else if (v[0] == "remove")
                {
                    if (v.size() == 1) {
                        std::cout << "field is missing" << std::endl;
                        v.clear();
                        continue;
                    }
                    else if (v.size() == 2) {
                        std::vector<AddressBook>::iterator itr;
                        for (itr = Book.begin(); itr != Book.end(); ++itr)
                        {
                            if (itr->name == v[1])
                            {
                                Book.erase(itr);
                                v.clear();
                                break;
                            }
                        }
                    }
                    else if (v.size() == 3) {
                        std::vector<AddressBook>::iterator itr;
                        for (itr = Book.begin(); itr != Book.end(); ++itr)
                        {
                            if ((itr->name == v[1] && itr->address == v[2]))
                            {
                                Book.erase(itr);
                                v.clear();
                                break;
                            }
                        }
                        std::cout << "cannot find field to delete" << std::endl;
                        v.clear();
                        continue;
                    }
                    else if (v.size() == 4) {
                        std::vector<AddressBook>::iterator itr;
                        for (itr = Book.begin(); itr != Book.end(); ++itr)
                        {
                            if ((itr->name == v[1] && itr->address == v[2] && itr->phone == v[3]))
                            {
                                Book.erase(itr);
                                v.clear();
                                break;
                            }
                        }
                    }
                    else {
                        std::cout << "cannot find field to delete" << std::endl;
                        v.clear();
                        continue;
                    }
                }
                else  if (v[0] == "ls")
                {
                    for (auto elem : Book)
                    {
                        std::cout << "name : " << elem.name << " ";
                        std::cout << "address : " << elem.address << " ";
                        std::cout << "phone : " << elem.phone << " ";
                        std::cout << std::endl;
                    }
                    v.clear();
                }
                else if (v[0] == "help")
                {
                    std::cout << "add : adding element in AddressBook " << std::endl;
                    std::cout << "remove : remove element from AddressBook " << std::endl;
                    std::cout << "ls : lists elemients of AddressBook " << std::endl;
                    v.clear();
                }
                else {
                    std::cout << "wrong query " << std::endl;
                    v.clear();
                    continue;
                }
            }
        }
    }
    return 0;
}
