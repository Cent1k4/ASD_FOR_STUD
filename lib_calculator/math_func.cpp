#include"../lib_calculator/math_func.h"

int fuct(int val) {
	if (val == 0)
		return 1;
	else if (val == 1)
		return 1;
	else
		return val * fuct(val - 1);
}


double my_sin(double val) {
	val = val * M_PI / 180.0;
	val = fmod(val, 2 * M_PI);
	if (val > M_PI) 
		val -= 2 * M_PI;

	else if (val < -M_PI) 
		val += 2 * M_PI;

	double rez = 0, temp = val, two_val = val*val;
	for(int i = 0; i < 10; i++){
		rez += temp;
		temp *= (-two_val) / ((2 * i + 2) * (2 * i + 3));
	}
	return rez;
}


double my_cos(double val) {
	val = val * M_PI / 180.0;
	val = fmod(val, 2 * M_PI);
	if (val > M_PI)
		val -= 2 * M_PI;

	else if (val < -M_PI)
		val += 2 * M_PI;

	double rez = 0, temp = 1, two_val = val * val;
	for (int i = 0; i < 10; i++) {
		rez += temp;
		temp *= (-two_val) / ((2 * i + 1) * (2 * i + 2));
	}
	return rez;
}


double my_tg(double val) {
	double eps = 0.0000001, co = my_cos(val);
	if (fabs(co) < eps)
		throw std::logic_error("cos(val) = 0");
	else
		return my_sin(val) / co;
}


double my_ñtg(double val) {
	double eps = 0.0000001, si = my_sin(val);
	if (fabs(si) < eps)
		throw std::logic_error("sin(val) = 0");
	else
		return my_cos(val) / si;
}


double my_ln(double val) {
	if (val <= 0) 
		throw std::logic_error("ln(x) x <= 0");
	

	int power = 0;
	double normalized = val;
	while (normalized > 2) {
		normalized /= 2;
		power++;
	}

	while (normalized < 0) {
		normalized *= 2;
		power--;
	}

	double mini_val = normalized - 1, rez = 0, term = mini_val;
	for (int i = 1; i <= 10; i++) {
		rez += term / i;
		term *= -mini_val;
	}

	return rez + power * log(2);
}


double my_sqrt(double val) {
	if (val < 0)
		throw std::logic_error("sqrt(x) x <= 0");

	else if (val == 0)
		return 0;

	else if (val == 1)
		return 1;

	else if (val >= 2 || val < 0)
		return sqrt(val);

	double rez = 0.0, temp = 1;
	val--;
	for (int i = 0; i < 10; i++) {
		rez += temp;
		temp *= val * ((0.5 - i) / (i + 1));
	}
	return rez;
}