#include "main.h"
static bool User1_Win = false;
static bool User2_Win = false;
static char **Table;
static bool info = false;
/**
 * !USER CLASS
 */
User::User() : name("") {}
void User::setName(string const &name)
{
    this->name = name;
}
string User ::getName()
{
    return this->name;
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

User *Implement::getHuman()
{
    return this->human;
}
User *Implement::getComputer()
{
    return this->computer;
}
Implement ::Implement()
{
    this->human = new User();
    this->computer = new User();
}

void Implement::print_Table()
{
    for (int count = 0; count < 3; count++)
    {
        if (count != 0)
        {
            for (int i = 0; i < 11; i++)
            {
                cout << "-";
            }
            cout << "\n";
        }
        cout << " "<< Table[count][0]
             << " | " << Table[count][1]
             << " | " << Table[count][2]
             << endl;
    }
}
void Implement::setUp_Table()
{
    Table = new char *[3];
    for (int i = 0; i < 3; ++i)
    {
        Table[i] = new char[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Table[i][j] = '1' + i*3 + j;
        }
    }
    return;
}
void Implement::run(int const &num)
{
    if (info == false)
    {
        string temp;
        cout << "Enter the User1's name: \n";
        cin.ignore();
        getline(cin, temp);
        human->setName(temp);
        cout << "Enter the User2's name: \n";
        // cin.ignore();
        std::getline(std::cin, temp);
        computer->setName(temp);
        // cout << human->getName() << "" << computer->getName();
        this->setUp_Table();
        info = true;
    }
    this->print_Table();
    while (User1_Win || User2_Win)
    {
        //* PLAY USER 1

        //*PLAY USER 2
        if (num == 1)
        {
        }
        else if (num == 2)
        {
        }
        return;
    }
}
/**
 * !INTERFACE CLASS
 */
Interface::Interface(Implement *guest) : guest(guest) {}
void Interface::instruction()
{
    cout << "----------------TIC_TAC_TOE--------------" << endl
         << "The User 1 will play first, and the another one will take turn afterwards." << endl
         << "If you choose to play with human. Press 1.\nIf you choose to play with computer. Press 2.\n"
         << endl;
    int num;
    cin >> num;
    guest->run(num);
}

int main()
{
    Implement *implement = new Implement();
    Interface *interface = new Interface(implement);

    interface->instruction();
    return 0;
}