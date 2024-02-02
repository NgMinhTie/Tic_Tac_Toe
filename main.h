#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class User{
    protected:
        string name;
        bool win;
        static User *computer;

    public:
        User();
        virtual string getName(string &name)  = 0;
        virtual bool win_not()  = 0;
};

class Human : public User{
    private:
        string name;
        bool win;
        static User *human;

        Human(){}
        Human(const Human &) = delete;
        Human &operator=(const Human &) = delete;
    public:
        Human();
        string getName(string &name)  override;
        bool win_not()  override;
        User *get_Instance();
};

class Computer : public User{
private:
    string name;
    bool win;
    static User *computer;

    //*Limit of construct and copy
    Computer() {}
    Computer(const Computer &) = delete;
    Computer &operator=(const Computer &) = delete;

public:
    //Computer();
    string getName(string &name) override;
    bool win_not()  override;
    static User *get_Instance();
};

class Implement{
    private:
        Human *human;
        Computer *computer;

    public:
        User *getHuman();
        User *getComputer();
        void run();
};

class Interface{
};