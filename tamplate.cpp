// ������6������ ������ �++
#include < iostream>
using namespace std;
void myswap(int n, int m) {
	int tmp = n;
	n = m;
	m = tmp;
}


// ������� �������� �������
void pSwap(int* pn, int* pm) {		//� ������� ����������
	int tmp = *pn;
	*pn = *pm;
	*pm = tmp;
}


//������� ������ �������� ���������� ���� ���������� �������. ����������� ������� swap
void refSwap(int& refn, int& refm) {		//� ������� ������
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

//������� �� ������������ ������� �������
int& maxl(int array[], int length) {
	int imax = 0;// ���������� �������������� ��� 0
	for (int i = 1; i < length; i++)// ��� �� ���������� ������ � ���������� ����� ��� ����� ���� �������
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

	// ����� ��������
	cout << refn << endl;
	cout << pn << endl;

	//����� �������������
	//cout << *refa << endl;// ������ � ������ ��� �������������
	cout << *pn << endl;

	// ������ ����� ������ � ���������
	refn = 12;
	cout << n << endl;
	*pn = 13;
	cout << n << endl;


	// ��������������
	refn = m;
	pn = &m;


	// ������ � ��������� ��������
	cout << "���� �������� � ������." << endl;
	for (int i = 0; i < 10; i++) {
		cout << "������� " << i << " �������: ";
		cin >> a[i][0];
		rf(i) = a[i][0];
	}
	cout << " �������� ������:\n";

	for (int i = 0; i < 10; i++)
		cout << a[i][0] << "\t" << rf(i) << endl;

	int arr[5] = { 4,5, 3,8,6 };
	cout << "����������� ������:\n[";			//���������� ���������
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";

	cout << "���� = " << maxl(arr, 5) << endl;
	maxl(arr, 5) = 0;							//��������� ������������� ��������.
	cout << "�������� ������:\n[";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";



	//������ 1
	cout << "������� ��� �����: ";
	int a, b;
	cin >> a >> b;
	z1(a, b);
	cout << a << " " << b << endl << endl;

	//������ 2
	cout << "������ 2\n������ ������:\n[";
	int z2_1[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		cout << z2_1[i] << ", ";
	cout << "\b\b]\n";

	cout << "������ ������:\n[";				//������ ����� ������.
	int z2_2[5];
	int* pz2_1 = &z2_1[0];
	int* pz2_2 = &z2_2[0];
	for (int i = 0; i < 5; i++)
		*(pz2_2 + 4 - i) = *(pz2_1 + i);
	for (int i = 0; i < 5; i++)
		cout << *(pz2_2 + i) << ", ";

	cout << "\b\b]\n";



	//������� swap
	int n, m;
	cout << "������� 2 ����� \n ";
	cin >> n >> m;
	myswap(n, m);// ������� swap
	cout << n << " " << m << endl;
	cout << "----------------" << endl;
	pSwap(&n, &m);//����������� ����� ������� ��������� ��� ��������� � �������.
	cout << n << " " << m << endl;
	cout << "----------------" << endl;


	int a = 50, b = 60;
	cout << a << " " << b << endl;
	cout << "������� ���������." << endl;
	refSwap(a, b);
	cout << a << " " << b << endl;

	cout << "������� ��������� �� 2" << endl;
	multiply(a, b);
	cout << a << " " << b << endl;



	return 0;
}

//������ 1
void z1(int& nref, int& mref) {
	if (nref > mref) {
		nref *= nref;		//���� pow(nref,2);
		mref *= mref;
	}
	else {
		nref = 0;
		mref = 0;
	}
}