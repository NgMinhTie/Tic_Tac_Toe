#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Implement;
class Interface;
class User
{
protected:
    string name;
    // bool win;
    ////static User *computer;

public:
    User();
    void setName(string const &name);
    string getName();
};

class Implement
{
private:
    User *human;
    User *computer;

public:
    Implement();

public:
    User *getHuman();
    User *getComputer();
    void setUp_Table();
    void print_Table();
    void run(int const &num); // To know whether play H or C
};

class Interface
{
private:
    Implement *guest;

public:
    Interface(Implement *guest);
    void instruction();
};