#include <iostream>
using namespace std;



class BancAcount
{
public:
    BancAcount(double nomerbankcheta, int balacne) {

        this->nomerbankcheta = nomerbankcheta;
        this->balacne = balacne;

        intereste = 0;





    }
public:
    double deposit(double skeli) {
        balacne += skeli;
        cout << "Ваш баланс: " << balacne << "На счете:" << nomerbankcheta << endl;
        return balacne;




    }
    double withdraw(double skeli) {
        balacne -= skeli;
        cout << "Ваш баланс: " << balacne << "На чсете: " << nomerbankcheta << endl;
        return balacne;
    }
    double getBalance() {
        double new_balacne = balacne - balacne;
        balacne = new_balacne;
        return balacne;





    }
    BancAcount& setInteresRate(double intereste) {
        this->intereste = intereste;
        cout << "Ваша новая процетная ставка = " << intereste << endl;
        return *this;





    }
    double getInterest() {
        balacne = (balacne * intereste - balacne) * intereste * 1 / 12;
        return balacne;

    }
    int getNum() {
        return nomerbankcheta;
    }
    double transfer(int perchet, int vtorchet, int sum) {
        if (sum <= balacne) {
            balacne -= sum;
            cout << "Перевод успешно проведен:  " << "Ваш баланс: " << balacne << endl;
            cout << "Баланс на счете" << vtorchet << "Равен  " << sum << endl;
        }
        else {
            cout << "Перевод не выполнин " << "Ваш баланс: " << balacne << endl;
        }
        return balacne;
    }
    double snztbalance() {
        return balacne - balacne;

    }
    double balance() {
        return balacne;
    }







private:
    int accnum;
    double balacne;
    int nomerbankcheta;
    double intereste;
    double balacne_vtor = 0;

};



int main()
{
    setlocale(LC_ALL, "Russian");
    int vubormenu;
    BancAcount banc(80085, 500);




    do
    {
        cout << "\nВыберите действие";
        cout << "\n1. Внести деньги";
        cout << "\n2. Снять деньги";
        cout << "\n3. Расчитать и вернуть баланс ";
        cout << "\n4. Сумма процентов";
        cout << "\n5. Новая процентная ставка";
        cout << "\n6.  Получить номер бансковского счета ";
        cout << "\n7.  Перевод ";
        cout << "\n";
        cin >> vubormenu;
        if (vubormenu == 1) {

            double shekili;

            cout << "Введите сумму для поплнения " << endl;
            cin >> shekili;
            if (shekili < 0) {
                cout << "Вы не можете положить отрицательный баланс " << endl;
                continue;
            }
            else if (shekili == 0) {
                cout << "Вы должны ввести кокую-небудь сумму " << endl;
                continue;
            }
            // процедура для подсчета суммы 
            banc.deposit(shekili);
        }
        if (vubormenu == 2) {
            double shekili;
            cout << "Введите сумму для вывода " << endl;
            cin >> shekili;
            if (shekili < 0) {
                cout << "Вы не можете положить отрицательный баланс " << endl;
                continue;
            }
            else if (shekili == 0) {
                cout << "Вы должны ввести кокую-небудь сумму " << endl;
                continue;
            }
            else if (shekili > banc.balance()) {
                cout << "Нельзя снять больше чему вас есть " << endl;
                continue;
            }
            // процедура для подсчета суммы для снятия
            banc.withdraw(shekili);
        }
        if (vubormenu == 3) {
            // Вывод баланса
            banc.getBalance();
            cout << "ваш баланс = " << banc.balance() << endl;
        }
        if (vubormenu == 4) {
            // Вывод  процентов
            cout << "Сумма процентов" << banc.getInterest() << endl;

        }
        if (vubormenu == 5) {
            double new_proc;
            cout << "Введите новую процентную ставку, которая не больше 10%" << endl;
            cin >> new_proc;
            if (new_proc > 10) {
                cout << "Процентная ставка слишком велика" << endl;
                continue;
            }
            // процедура для устоновки нового процента
            banc.setInteresRate(new_proc);

        }
        if (vubormenu == 6) {
            // Получение нового счета
            cout << "Ваш счет " << banc.getNum() << endl;
        }
        if (vubormenu == 7) {
            cout << "Введите свой счет" << endl;
            int chet;
            cin >> chet;
            if (chet != 80085) {
                cout << "Такого счета нет" << endl;
                continue;
            }
            int vtot_chet;
            cout << "Введите второй счет" << endl;
            cin >> vtot_chet;
            int sum;
            cout << "Введите сумму" << endl;
            cin >> sum;
            if (sum > banc.balance()) {
                cout << "Вы не можите отправить больше чем у вас есть " << endl;
                continue;

            }

            //процедура для перевода денег
            banc.transfer(chet, vtot_chet, sum);



        }
        if (vubormenu > 8) {
            cout << "Такой команды нет";
        }

    } while (vubormenu != 8);




}
