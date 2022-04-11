// Персон6альный шаблон С++
#include < iostream>
using namespace std;
void myswap(int n, int m) {
	int tmp = n;
	n = m;
	m = tmp;
}


// функция перемены местами
void pSwap(int* pn, int* pm) {		//С помощью указателей
	int tmp = *pn;
	*pn = *pm;
	*pm = tmp;
}


//Функция меняет значение переданных двух переменных местами. Стандартная функция swap
void refSwap(int& refn, int& refm) {		//С помощью ссылок
	int tmp = refn;
	refn = refm;
	refm = tmp;
}


void multiply(int& refn1, int& refn2, int num = 2) {
	refn1 *= num;
	refn2 *= num;
}

int a[10][2];

int& rf(int index) {
	return a[index][1];
}

//функция на максимальный элемент массива
int& maxl(int array[], int length) {
	int imax = 0;// изначально инициализируем как 0
	for (int i = 1; i < length; i++)// тут мы перебираем массив и запоминаем место где стоит макс элемент
		if (array[i] > array[imax])
			imax = i;
	return array[imax];
}

void z1(int& nref, int& mref);


int main() {
	setlocale(LC_ALL, "Russian");
	int n = 11, m = 20;
	int& refn = n;
	int* pn = &n;

	// вывод значения
	cout << refn << endl;
	cout << pn << endl;

	//адрес разименования
	//cout << *refa << endl;// ошибка у ссылки нет разименования
	cout << *pn << endl;

	// меняем через ссылку и указатель
	refn = 12;
	cout << n << endl;
	*pn = 13;
	cout << n << endl;


	// перенаправляем
	refn = m;
	pn = &m;


	// задача с двумерным массивом
	cout << "Ввод значений в массив." << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Введите " << i << " элемент: ";
		cin >> a[i][0];
		rf(i) = a[i][0];
	}
	cout << " итоговый массив:\n";

	for (int i = 0; i < 10; i++)
		cout << a[i][0] << "\t" << rf(i) << endl;

	int arr[5] = { 4,5, 3,8,6 };
	cout << "Изначальный массив:\n[";			//нахождение максимума
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";

	cout << "Макс = " << maxl(arr, 5) << endl;
	maxl(arr, 5) = 0;							//обнуление максимального элемента.
	cout << "Итоговый массив:\n[";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";



	//Задача 1
	cout << "Введите два числа: ";
	int a, b;
	cin >> a >> b;
	z1(a, b);
	cout << a << " " << b << endl << endl;

	//Задача 2
	cout << "Задача 2\nПервый массив:\n[";
	int z2_1[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		cout << z2_1[i] << ", ";
	cout << "\b\b]\n";

	cout << "Второй массив:\n[";				//Массив задом наперёд.
	int z2_2[5];
	int* pz2_1 = &z2_1[0];
	int* pz2_2 = &z2_2[0];
	for (int i = 0; i < 5; i++)
		*(pz2_2 + 4 - i) = *(pz2_1 + i);
	for (int i = 0; i < 5; i++)
		cout << *(pz2_2 + i) << ", ";

	cout << "\b\b]\n";



	//функции swap
	int n, m;
	cout << "Введите 2 числа \n ";
	cin >> n >> m;
	myswap(n, m);// функции swap
	cout << n << " " << m << endl;
	cout << "----------------" << endl;
	pSwap(&n, &m);//обязательно нужно ставить амперсант при обращении к функции.
	cout << n << " " << m << endl;
	cout << "----------------" << endl;


	int a = 50, b = 60;
	cout << a << " " << b << endl;
	cout << "Функция сработала." << endl;
	refSwap(a, b);
	cout << a << " " << b << endl;

	cout << "Функция умножения на 2" << endl;
	multiply(a, b);
	cout << a << " " << b << endl;



	return 0;
}

//Задача 1
void z1(int& nref, int& mref) {
	if (nref > mref) {
		nref *= nref;		//либо pow(nref,2);
		mref *= mref;
	}
	else {
		nref = 0;
		mref = 0;
	}
}