#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

void help() {
    cout << "������� ������\n{\n1 - ����������\\�������� �������\n2 - ������� �������\n3 - ������� �������\n/help - ������� ���� ����\n/exit - ������� ���������\n}\n";
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string name;
    string time;
    string info;

    cout << "EXCEL 2077 \\\\ MEGA ULTRA PRE-ALPHA EDITION\n";
    string command;
    help();
    while (1) {
        cin >> command;

        if (command == "/exit") {
            exit(0);
        }
        if (command == "/help") { //����� ������
            help();
        }

        if (command == "2") { // ��������
            ofstream DataList("D:\\DataList.ban", std::ios::binary | std::ios::app);
            cout << "~~~�������� ��������~~~\n������� ��� \\\\ ����� \\\\ ���. ���� ����� enter\n";
            bool cont = true;
            while (cont == true) {
                cin.ignore();

                getline(cin, name);

                getline(cin, time);

                getline(cin, info);


                DataList << name << "\n" << time << "\n" << info << "\n";
                cout << "����������? 1\\0: ";
                cin >> cont;
            }
        }

        if (command == "1") { // ��������
            string lineread;
            ifstream fin("D:\\DataList.ban");          
            int stage = 1;
            cin.ignore();
            int stc = 1;
            cout << "~~~������� �������� �����~~~\n";
            while (!fin.eof()) {
                getline(fin, lineread);
             
                if (stage == 1) { cout <<stc<<". "<< lineread << " \\\\ "; stage++; continue; }
                if (stage == 2) { cout << lineread << " \\\\ "; stage++; continue; }
                if (stage == 3) { cout << lineread <<endl; stage = 1;  stc++; continue; }
               
            }
            cout << endl;
        }

        if (command == "3") {
            setlocale(LC_ALL,"Russian");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            int linedel;
            string delread;
            cout << "����� ������� ����� �������?";
            cin >> linedel;

            
            ifstream fin("D:\\DataList.ban", ios::in);
            int line_no = 0;
            while (line_no != linedel) {
                getline(fin, delread);
                ++line_no;
            }
            ofstream jojo("D:\\DataList.ban", ios::out | ios::app);
            jojo << "?";

           


        }
    }
        return 0;
   
}