// ConsoleApplication_Mullayarov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Vector>
using namespace std;
struct tube {
    int kmMark;
    long len;
    short diam;
    bool isWorking;
    static int choose;
public:
    tube(int kmMark,
    long len,
    short diam,
    bool isWorking) {
        this->kmMark = kmMark;
        this->len = len;
        this->diam = diam;
        this->isWorking = isWorking;
    }
    void cout() {
        std::cout << "Километровая отметка: " << this->kmMark << endl << "Длина трубы: " << len << endl << "Состояние работы трубы"
            << isWorking << endl;
    }
};
struct KS {
    string name;
    int amountWorkshops;
    int amountWorhshopsNow;
    int effectiveness;
    int choose;
public:
    KS(string name, int amountWorkshops, int amountWorhshopsNow) {
        this->name = name;
        this->amountWorkshops = amountWorkshops;
        this->amountWorhshopsNow = amountWorhshopsNow;
    }
    void cout() {
        std::cout << "Имя: " << name << endl << "Количество цехов :" << amountWorkshops << endl <<
            "Количество цехов в работе: " << amountWorhshopsNow << endl;
    }

};
int checkint(int num) {
    char c;
    cin >> c; // читаем символ из потока
    if (isdigit(c)) // если это цифра или минус
    {
        cin.unget(); // возвращаем символ обратно в поток
        cin >> num; // читаем число
        return num;
    }
    else
        cout << "Input data error\n";
        return 0;

}
int main()
{
    int kmMark{};
    long len{};
    double diam{};
    bool isWorking{};
    int choose{};
    int answer;
    string name;
    int amountWorkshops{};
    int amountWorkshopsNow{};
    int effectiveness{};
    int count = 0;
    int tubechoise1;
    setlocale(LC_ALL, "ru");
    vector<tube> Tubes;
    vector<KS> KSS;
    while (true) {
        std::cout << "1)Добавить трубу\n";
        std::cout << "2)Добавить КС\n";
        std::cout << "3)Просмотр всех объектов\n";
        std::cout << "4)Редактировать трубу\n";
        std::cout << "5)Редактировать КС\n";
        std::cout << "6)Сохранить\n";
        std::cin >> answer;
        if ((answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 5 || answer == 6)) {
            switch (answer) {
            case 1:
                try {
                    cout << "Введите отметку в км\n";
                    kmMark = checkint(kmMark);
                    if (kmMark == 0) {
                        break;
                    }
                    cout << "Введите длину \n";
                    len = checkint(len);
                    if (len == 0) {
                        break;
                    }
                    cout << "Ввeдите диаметр\n";
                    diam = checkint(diam);
                    if (diam == 0) {
                        break;
                    }
                    cout << "Вводите состояние работы, где 1 - работает, 0 - нет \n";
                    std::cin >> isWorking;
                    if (isWorking != 0 && isWorking != 1) {
                        break;
                    }
                    tube tube(kmMark, len, diam, isWorking);
                    Tubes.push_back(tube);
                    tube.cout();
                    break;
                }
                catch (exception exp) {
                    std::cout << ":(((((^\n";
                }
            case 2:
                try {
                    std::cout << "Введите ks\n";
                    cout << "Введи имя\n";
                    cin >> name;
                    cout << "Введите Количество цехов\n";
                    amountWorkshops = checkint(amountWorkshops);
                    if (amountWorkshops == 0) {
                        break;
                    }
                    cout << "Введите Количество цехов в работе\n";
                    amountWorkshopsNow = checkint(amountWorkshopsNow);
                    if (amountWorkshopsNow == 0) {
                        break;
                    }
                    cin.clear();
                    KS ks(name,amountWorkshops,amountWorkshopsNow);
                    KSS.push_back(ks);
                    break;
                }
                catch (exception exp) {
                    std::cout << ":(((((^\n";
                }
            case 3:
                cout << "Вывод труб :\n";
                for (int i = 0; i < Tubes.size(); i++) {
                    Tubes[i].cout();
                    cout << "Это была " << i << " Труба" << endl;
                }
                cout << "Вывод КС :\n";
                for (int i = 0; i < KSS.size(); i++) {
                    KSS[i].cout();
                }
                break;
            case 4:
                cout << "Введите номер трубы:\n ";
                for (int i = 0; i < Tubes.size(); i++) {
                    cout << i+1 << endl;
                }
                cin >> choose;
                choose--;
                for (int i = 0; i < Tubes.size(); i++) {
                    if (choose == i) {
                        count++;
                    }
                }

                if (count >= 1 && count != 0) {
                    std::cout << "Изменить состояние работы";
                    std::cout << "1)Вкл";
                    std::cout << "2)Выкл";
                    cin >> tubechoise1;
                    if (tubechoise1 == 1) {
                        Tubes[choose].isWorking = true;
                    }
                    else if (tubechoise1 == 2) {
                        Tubes[choose].isWorking = false;
                    }
                    else
                        cout << "Неверный ввод :(";
                }
                else
                    cout << "Нет такой трубы\n";
                break;
            default: cout << "Неверный ввод:( ";
                break;
            }
        }
    }
}
