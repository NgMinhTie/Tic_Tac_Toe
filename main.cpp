#include "main.h"
static bool User1_Win = false;
static bool User2_Win = false;
static char **Table;
static bool info = false;
static int const ROW = 3;
static int const COLUMN = 3;
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
void Implement::takeTurn(int const& num){
    while (!User1_Win && !User2_Win)
    {
        //* PLAY USER 1
        cout << "Enter the number 1-9" << endl;
        int count;
        cin >> count;
        int i = 0, j = 0;
        bool flag = false;
        for (; i < 3; i++)
        {
            j = 0;
            for (; j < 3; j++)
            {
                if (1 + i * 3 + j - count == 0)
                    {
                        flag = true;
                        break;
                    }
            }
            if (flag)
                break;
        }
        ////cout << i << j << endl;
        Table[i][j] = 'O';
        this->print_Table();
        User1_Win = this->checkWin(i, j, 'O');
        if(User1_Win)
            {
                cout << human->getName() << " Win!!!!!!!";
                return;
            }
        ////cout << "DEBUG" << endl;
        cout << "\n";
        //*PLAY USER 2
        if (num == 1)
        {
            cout << "Enter the number 1-9" << endl;
            cin >> count;
            i = 0;
            j = 0;
            flag = false;
            for (; i < 3; i++)
            {

                j = 0;
                for (; j < 3; j++)
                {
                    if (1 + i * 3 + j - count == 0)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            ////cout << i << j << endl;
            Table[i][j] = 'X';
            User2_Win = this->checkWin(i, j, 'X');
            if (User2_Win)
            {
                cout << computer->getName() << " Win!!!!!!!";
                return;
            }
        }
        else if (num == 2)
        {
            std::srand(static_cast<unsigned>(std::time(0)));
            while(true){
                int randomNumber = rand() % 9 + 1;
                i = 0;
                j = 0;
                flag = false;
                for (; i < 3; i++)
                {
                    j = 0;
                    for (; j < 3; j++)
                    {
                        if (1 + i * 3 + j - randomNumber == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                if(Table[i][j] == 'O')
                    continue;
                else{
                    Table[i][j] = 'X';
                    User2_Win = this->checkWin(i, j, 'X');
                    if (User2_Win)
                    {
                        cout << computer->getName() << " Win!!!!!!!";
                        return;
                    }
                    break;
                }
            }
        }
        this->print_Table();
    }
}
bool Implement::checkWin(int const &row, int const &column, char const &type){
    ////bool result = false;
    int count = 1;
    int r = row, c = column;
    //TODO: LEFT & RIGHT
    //* LEFT
    while ((c >= 0 && c < 3) || count < 3){
        --c;
        if(c < 0|| c >= COLUMN || r < 0 || r >= ROW)
            break;
        if(Table[r][c] == type)
            count += 1;
        else
            break;
    }
    c = column;
    while ((c >= 0 && c < 3) || count < 3)
    {
        ++c;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    if(count >= 3)
        return true;
    else{
        r = row;
        c = column;
        count = 1;
    }
    //TODO:  UP & DOWN
    while ((r >= 0 && r < 3) || count < 3)
    {
        --r;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    r = row;
    while ((r >= 0 && r < 3) || count < 3)
    {
        ++r;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    if (count >= 3)
        return true;
    else
    {
        r = row;
        c = column;
        count = 1;
    }
    
    //TODO:  DIAGONAL
    while (((r >= 0 && r < 3) && (c >= 0 && c < 3)) || count < 3)
    {
        --r;
        --c;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
            if (Table[r][c] == type)
                count += 1;
            else
                break;
    }
    r = row;
    c = column;
    while (((r >= 0 && r < 3) && (c >= 0 && c < 3)) || count < 3)
    {
        ++r;
        ++c;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    if (count >= 3)
        return true;
    else
    {
        r = row;
        c = column;
        count = 1;
    }
    //*************
    while (((r >= 0 && r < 3) && (c >= 0 && c < 3)) || count < 3)
    {
        --r;
        ++c;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    r = row;
    c = column;
    while (((r >= 0 && r < 3) && (c >= 0 && c < 3)) || count < 3)
    {
        ++r;
        --c;
        if (c < 0 || c >= COLUMN || r < 0 || r >= ROW)
            break;
        if (Table[r][c] == type)
            count += 1;
        else
            break;
    }
    if (count >= 3)
        return true;
    else
    {
        r = row;
        c = column;
        count = 1;
    }
    return false;
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
    this->takeTurn(num);
}
/**
 * !INTERFACE CLASS
 */
Interface::Interface(Implement *guest) : guest(guest) {}
void Interface::instruction()
{
    cout << "----------------TIC_TAC_TOE--------------" << endl
         << "The User 1 will play first, and the another one will take turn afterwards." << endl
         << "If you choose to play with human. Press 1.\nIf you choose to play with computer. Press 2."
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
    delete implement;
    delete interface;
    return 0;
}