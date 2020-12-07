#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	return (x * x) * exp(sin(x));
}

int main() {
	setlocale(LC_ALL, "Russian");
	//MIN-MAX
	const double A = 9, B = 14;
	double a = 9, b = 14;
	int N = 1;
	double min = A + (B - A) / (N + 1);
	double d_n = (B - A) / (N + 1);
	cout << "_________________________" << endl;
	cout << "|Количество| Значение x |" << endl;
	cout << "|точек (N) | в минимуме |" << endl;
	cout << "-------------------------" << endl;
	while (d_n >= 0.1) {
		for (int i = 1; i < N; i++) {
			if (f(A + (i * (B - A) / (N + 1))) > f(A + ((i + 1) * (B - A) / (N + 1)))) {
				a = A + (i * (B - A) / (N + 1));
				min = A + ((i + 1) * (B - A) / (N + 1));
			}
			else if (f(A + (i * (B - A) / (N + 1))) == f(A + ((i + 1) * (B - A) / (N + 1)))) {
				a = A + ((i + 1) * (B - A) / (N + 1));
				min = A + ((i + 1) * (B - A) / (N + 1));
			}
			else if (f(A + (i * (B - A) / (N + 1))) < f(A + ((i - 1) * (B - A) / (N + 1)))) {
				b = A + ((i + 1) * (B - A) / (N + 1));
				min = A + (i * (B - A) / (N + 1));
				break;
			}
		}
		cout << "|    " << N << "    | " << "  " << min << " " << "+-" << " " << d_n << " |" << endl;
		N++;
		d_n = (B - A) / (N + 1);
	}
	cout << "---------------------------" << endl;

	//DIXOTOMIA
	double del = 0.025;
	b = 14;
	a = 9;
	double x1 = A + (b - a) / 2 - del, x2 = A + (b - a) / 2 + del;
	double l_k = b - a;
	std::cout << " _________________________________________________________________________" << std::endl;
	std::cout << "|   Начало   |   Конец    |    Длина    |                |                |" << std::endl;
	std::cout << "|  интервала | интервала  |  интервала  |     f(ak)      |      f(bk)     |" << std::endl;
	std::cout << "|     (ak)   |    (bk)    |     (l)     |                |                |" << std::endl;
	std::cout << " _________________________________________________________________________" << std::endl;
	std::cout <<"|     "<< a << "     |      " <<b << "     |     " <<l_k 
					<< "    |      " << f(x1) << "      |     " << f(x2) <<"     |"<< std::endl;
	while (l_k >= 0.1) {
		if (f(x1) > f(x2)) {
			a = x1;
		}
		else {
			b = x2;
		}
		x1 = a + (b - a) / 2 - del;
		x2 = a + (b - a) / 2 + del;
		l_k = b - a;
		std::cout << "|  " << a << "  |    " << b << "   |   " << l_k
			<< "  |      " << f(x1) << "      |     " << f(x2) << "    |" << std::endl;
	}

	std::cout << " _________________________________________________________________________" << std::endl;
	std::cout << "Минимальное значение функции достигается при x = " << (b - a) / 2 << " ± " << l_k / 2 << std::endl;
	return 0;
}
