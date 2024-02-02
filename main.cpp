#include"main.h"

/**
 * !USER
*/
User::User() : win(false), name('\0'){}
/**
 * !HUMAN
*/
Human::Human() : win(false), name('\0'){}
string  Human::getName(string &name){
    this->name = name;
    return this->name; 
}
bool Human::win_not(){
    return this->win;
}
User *Human::get_Instance()
{
    if (human == nullptr)
    {
        human = new Human();
    }
    return human;
}
/**
 * !COMPUTER
*/
Computer::Computer() : name('\0'),win(false) {}
User* Computer::get_Instance(){
    if(computer == nullptr){
        computer = new Computer();
    }
    return computer;
}
string Computer::getName(string &name) {
    this->name = name;
    return this->name;
}
bool Computer::win_not() {
    return this->win;
}
/**
 * !IMPLEMENT CLASS
 */
// Implement::Implement() : human(nullptr), computer(nullptr){}
// User* Implement::createComputer(){
//     if(computer == nullptr){
//         computer = new Computer();
//     }
//     return computer;
// }

User* Implement::getHuman(){
    return this->human->get_Instance();
}
User* Implement::getComputer(){
    return this->computer->get_Instance();
}
void Implement::run(){
    
    return;
}
    int main()
{
    return 0;
}

/**
 * !INTERFACE
*/