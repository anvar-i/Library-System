#include <iostream>
#include <vector>
using namespace std;

//class BookNode stores information about books
class BookNode {
public:
    int ID;
    string title;
    BookNode(int ID, string title) {
        this->ID = ID;
        this->title = title;
    }
    ~BookNode() {}
};
