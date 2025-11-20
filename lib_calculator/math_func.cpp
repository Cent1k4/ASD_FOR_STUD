#include"../lib_calculator/math_func.h"
const double PI = 3.141592653589793;

int fuct(int val) {
	if (val == 0)
		return 1;
	else if (val == 1)
		return 1;
	else
		return val * fuct(val - 1);
}


double my_sin(double val) {
	double val_radians = val * (PI / 180);
	double rez = 0;
	for (int i = 0; i < 13; i++) {
		rez += (pow(-1, i) * pow(val_radians, 2 * i + 1) )/ fuct(2 * i + 1);
	}
	return rez;
}


double my_cos(double val) {
	double rez = 0;
	for (int i = 0; i < 6; i++) {
		rez += (pow(-1, i) * pow(val, 2 * i)) / fuct(2 * i);
	}
	return rez;
}


double my_tg(double val) {
	if (my_cos(val) != 0)
		return my_sin(val) / my_cos(val);
}


double my_ln(double val){
	if (fabs(val - 1) >= 1)
		return log(val);
	double rez = 0;
	for (int i = 1; i < 6; i++) {
		rez += pow(-1, i + 1) * (pow((val - 1), i) / i);
	}
	return rez;
}


double my_sqrt(double val) {
	if (fabs(val - 1) >= 1)
		return sqrt(val);
	double rez = 0;
	for (int n = 0; n < 10; n++) {
		double numerator = pow(-1, n) * fuct(2 * n);
		double denominator = (1 - 2 * n) * pow(fuct(n), 2) * pow(4, n);
		rez += (numerator / denominator) * pow(val - 1, n);
	}
	return rez;
}