﻿//ТЕЛЕФОН
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int  rooms = 1, num = 1;
	cout << "Введите количество комнат в коридоре" << endl;
	cin >> rooms;
	vector <bool> roomsm;//Массив со всеми комнатами
	vector <int> lengthm, numbers;// Массив длин для каждой из комнат
	for (unsigned short z = 0; z < rooms + 1; z++) { // ЗАЛИВАЮ REDBULL, ДО ПОСЛЕДНЕГО ВКЛЮЧИТЕЛЬНО (ПОТОМ УБРАТЬ)
		roomsm.push_back(false);
	}
	for (unsigned short z = 0; z < rooms + 1; z++) { // ЗАЛИВАЮ REDBULL, ДО ПОСЛЕДНЕГО ВКЛЮЧИТЕЛЬНО (ПОТОМ УБРАТЬ)
		lengthm.push_back(0);
	}


	while (num != 0) {
		cout << "Введите номер комнаты, для установки. Для остановки - введите '0'" << endl;
		cin >> num;
		if (num > 0) {
			roomsm[num] = true; //ОНО ТЕРЯЕТ ПЕРВЫЙ ЭЛЕМЕНТ (НУЛЕВОЙ КОТОРЫЙ)
		}
		else {
			break;
		}

	}
	for (double i = 1; i != rooms + 1; i++) { // Комнаты, от которых считаем
		for (double j = 1; j != rooms + 1; j++) { // Комнаты, до которых считаем
			if (!roomsm[j]) {
				continue;
			}
			lengthm[i] += abs(i - j);
		}
	}
	int minValue = lengthm[1], number = 0;
	for (int i = 1; i != rooms + 1; i++) {
		if (minValue < lengthm[i]) {
			continue;
		}
		if (minValue == lengthm[i]) {
			numbers.push_back(i);
			continue;
		}
		else {
			minValue = lengthm[i];
			numbers.push_back(i);
		}
	}
	reverse(numbers.begin(), numbers.end());
	if (lengthm[numbers[0]] == lengthm[numbers[1]]) {
		cout << "Оптимальные комнаты для установки: " << numbers[1] << " и " << numbers[0];
	}
	else {
		cout << "Оптимальная комната для установки: " << numbers[0] << endl;
		cout << numbers[0] << "" << numbers[1];
	}
	cout << "." << endl;
	cout << "Длина кабеля составит: " << minValue << "." << endl;




	return 0;
}
