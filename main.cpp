#include <iostream>
#include <clocale>
#include <queue>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void head(){
    cout << "+------------------------+" << endl;
    cout << "|Практическая работа #9  |" << endl;
    cout << "+------------------------+" << endl;
    cout << "|Выполнил: Сабиров Ильназ|" << endl;
    cout << "|Группа: П-23            |" << endl;
    cout << "+------------------------+" << endl;
}


int main(){
    string input_name;
    int input_age;

    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    queue<string>start; //0-25
    queue<string>mid; //26-60
    queue<string>end; //61+

    head();

    while (true){
        cout << "Введите фамилию(stop для выхода из цикла):> ";
        cin >> input_name; 

        if(input_name == "stop"){
            cout << "STOP" << endl;
            break;
        }   

        cout << "Введите возраст:> ";
        cin >> input_age;

        if(cin.fail() || input_age < 0 ){
            cout << "ОШИБКА! введите корректный возраст" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input_name = "";
        }


        if(input_age <= 25){
            start.push(input_name);
        }

        if(input_age >= 26 && input_age <= 60){
            mid.push(input_name);
        }

        if(input_age >= 61){
            end.push(input_name);
        }
   
    }  

    cout << "0-25: ";
    while(!start.empty()){
        cout << start.front() << " ";
        start.pop();
    }
    cout << endl;

    cout << "26-60: ";
    while(!mid.empty()){
        cout << mid.front() << " ";
        mid.pop();
    }
    cout << endl;

    cout << "61+: ";
    while(!end.empty()){
        cout << end.front() << " ";
        end.pop();
    }
    cout << endl;

    return 0;
}