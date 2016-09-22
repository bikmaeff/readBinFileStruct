#include <iostream>
#include <fstream>
#include "student.cpp"


using namespace std;

int main()
{
    Student stud;

    fstream file;
    file.open("/home/ramil/Qt/read_bin_file_struct/student.dat", ios::in | ios::out | ios::binary);

    if (file.fail())
    {
        cout << "ERROR: Cannot open the file..." << endl;
        exit(0);
    }

    file.read(stud.name, sizeof(stud.name));
    file.read(reinterpret_cast<char *>(&stud.quiz1), sizeof(stud.quiz1));
    file.read(reinterpret_cast<char *>(&stud.quiz2), sizeof(stud.quiz2));
    file.read(reinterpret_cast<char *>(&stud.quiz3), sizeof(stud.quiz3));

    while(!file.eof())
    {
        cout << left
             << stud.name
             << stud.quiz1
             << stud.quiz2
             << stud.quiz3
             << endl;

        // Reading the next record
        file.read(stud.name, sizeof(stud.name));
        file.read(reinterpret_cast<char *>(&stud.quiz1), sizeof(stud.quiz1));
        file.read(reinterpret_cast<char *>(&stud.quiz2), sizeof(stud.quiz2));
        file.read(reinterpret_cast<char *>(&stud.quiz3), sizeof(stud.quiz3));
    }

    return 0;
}

