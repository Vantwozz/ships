#include <fstream>
#include<vector>
#include"List.h"


int main()
{
    ifstream fin("SHIPS.in");
    ofstream fout("SHIPS.out");
    if (!fin.is_open()) {//проверка на открытие
        cerr << "Input file wasn't oppened try again";
        fout << "Input file wasn't oppened try again";
        return 0;
    }
    if (fin.peek() == EOF) { //проверка на пустоту
        cerr << "Input file is empty.";
        fout << "Input file is empty.";
        return 0;
    }
    List queue;
    int num;
    string data;
    vector<string> port;
    int n;
    fin >> n;
    if (n <= 0 || n > 10) {//проверка на количество пирсов
        cerr << "wrong number of pieres" << endl;
        fout<< "wrong number of pieres" << endl;
        return 0;
    }
    fin.ignore();
    for (int i = 0; i != n; i++){//создание порта на n пирсов
        port.push_back("");
    }
    while (fin >> num) {
        if (num == 1) {
            fin.ignore();
            getline(fin, data);
            for (int i = 0; i != port.size(); i++) {//добавление корабля в порт/очередь
                if (port[i] == "") {
                    fout << data << " comming to pier number " << i+1 << endl;
                    port[i] = data;
                    break;
                }
                if (i == port.size() - 1) {
                    fout << data << " comming to port but will wait in queue because there are no free pieres" << endl;
                    queue.push_back(data);
                }
            }
        }
        else if (num == 2) {
            fin >> n;
            if (queue.GetSize() != 0) {//добавление нового корабля из очереди в порт.
                if (n <= port.size() && n > 0) {
                    n--;
                    fout << port[n] << " is leaving port. " << queue[0] << " is comming to pier number " << n + 1 << endl;
                    port[n] = queue[0];
                    queue.pop_front();
                }
                else {
                    cerr << "wrong pier number" << endl;
                    fout<< "wrong pier number" << endl;
                    return 0;
                }
            }
            else {
                if (n <= port.size() && n > 0) {//для случая, когда очередь пустая
                    n--;
                    fout << port[n] << " is leaving port."  << endl;
                    port[n] = "";
                }
                else {
                    cerr << "wrong pier number" << endl;
                    fout << "wrong pier number" << endl;
                    return 0;
                }
            }
        }
        else if (num == 3) {
            if (queue.GetSize() != 0) {//вывод кораблей в очереди
                fout << "There are " << queue.GetSize() << " ship(s) in queue: " << endl;
                for (int i = 0; i != queue.GetSize(); i++) {
                    fout << i + 1 << ". " << queue[i] << endl;
                }
            }
            else {
                fout << "There are no ships in queue." << endl;
            }
        }
        else if (num == 4) {
            fout << "There are " << port.size() << " pier(es) in port. Ships near pieres: " << endl;
            for (int i = 0; i != port.size(); i++) {//вывод кораблей в порту/вывод информации о пустых причалах
                if (port[i] != "") {
                    fout << i + 1 << ". " << port[i] << endl;
                }
                else {
                    fout << "Pier number " << i + 1 << " is free." << endl;
                }
            }
        }
        else {
            cerr << "wrong input number" << endl;
            fout << "wrong input number" << endl;
            return 0;
        }
        fout << endl;
    }
    fin.close();
    fout.close();
}