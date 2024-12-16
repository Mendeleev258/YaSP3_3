import Sequence;
import Vector3D;

#include <iostream>
#include <fstream>
#include <string>

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);
int check_file(std::ifstream& file);
std::ifstream read_filename();
bool check_type(short x) { return x >= 1 && x <= 4; }
bool check_choice(short x) { return x >= 1 && x <= 11; }
short type_menu();
short task_menu();


int main()
{
    short choice{}, type{};
    do
    {
        type = type_menu();
        std::ifstream inp_file = read_filename();
        Sequence<int> seq_int(inp_file);
        Sequence<std::string> seq_string(inp_file);
        Sequence<vector3D> seq_vector(inp_file);
        switch (type)
        {
        case 1:
            
        }
    } while (choice != 11);

}



template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
    std::cout << message << "\n>>> ";
    while (!(std::cin >> x && condition(x)))
    {
        std::cout << "Input error!" << '\n';
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << message << "\n>>> ";
    }
}

int check_file(std::ifstream& file)
{
    int res = 1;
    if (!file)
    {
        res = -1; // file not found
    }
    else
        if (file.peek() == EOF)
            res = 0; // file is empty
    return res;
}

std::ifstream read_filename()
{
    while (true)
    {
        std::cout << "Enter filename (with spec)\n>>> ";
        std::string filename{};
        std::cin >> filename;
        std::ifstream file(filename);
        if (check_file(file) == 1)
            return file;
        else
            std::cout << "Input error!" << '\n';
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
}

short type_menu()
{
    std::cout << "Choose the type of Sequence:\n" <<
        "1. int\n" <<
        "2. string\n" <<
        "3. vector3D\n" <<
        "4. Exit\n";
    short res{};
    validation(res, *check_type, "");
    return res;
}

short task_menu()
{
    std::cout << " *-<===> Task Menu <===>-* \n" <<
        "1. Print to console\n" <<
        "2. Print to file\n" <<
        "3. Append\n" <<
        "4. Find index of the element\n" <<
        "5. Find the first index of subsequence\n" <<
        "6. Get element by index\n" <<
        "7. Change element by index\n" <<
        "8. Delete element by index\n" <<
        "9. Make subsequence\n" << 
        "10. Change type\n" << 
        "11 Exit\n";
    short res{};
    validation(res, *check_choice, "");
    return res;
}

void task_env(std::ifstream& file)
{

}

