//Author: Jaeha Huh
//File Name: rec08.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rational {
	friend ostream& operator<<(ostream& os, const Rational& rhs) {
		if (rhs.denominator != 1) {
			os << rhs.numerator << "/" << rhs.denominator << endl;
		}
		else {
			os << rhs.numerator;
		}
		return os;
	}
	friend istream& operator>>(istream& is, Rational& rhs) {
		char symbol;
		is >> rhs.numerator >> symbol >> rhs.denominator;
		rhs.normalize();
		return is;
	}
	friend bool operator==(const Rational& lhs, const Rational& rhs) {
		return (lhs.numerator * rhs.denominator) == (rhs.numerator * lhs.denominator);
	}
	friend bool operator<(const Rational& lhs, const Rational& rhs) {
		return (lhs.numerator / lhs.denominator) < (rhs.numerator / rhs.denominator);
	}
public:
	Rational(int numerator = 0, int denominator = 1)
		:numerator(numerator), denominator(denominator) {
		normalize();
	}
	Rational& operator+=(const Rational& rhs) {
		numerator = (numerator * (rhs.denominator)) + (denominator * (rhs.numerator));
		denominator = denominator * (rhs.denominator);
		normalize();
		return *this;
	}
	int greatestCommonDivisor(int x, int y) const {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}
	void normalize() {
		while (denominator == 0) {
			cout << "Denominator cannot be zero!" << endl;
			cout << "Please enter another num: ";
			cin >> denominator;
		}
		int divider = greatestCommonDivisor(numerator, denominator);
		numerator /= divider;
		denominator /= divider;
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
	explicit operator bool() const { return !(numerator == 0); } //explicit????

	Rational& operator++() {
		numerator += denominator;
		normalize();
		return *this;
	}
	Rational operator++(int) {
		Rational temp(numerator, denominator);
		++* this;
		normalize();
		return temp;
	}
private:
	int numerator, denominator;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational result = lhs;
	result += rhs;
	return result;
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
	return !(lhs == rhs);
}
Rational& operator--(Rational& rhs) { //pre-decrement
	rhs += -1;
	rhs.normalize();
	return rhs;
}
Rational operator--(Rational& lhs, int) { // post-decrement
	Rational result = lhs;
	(lhs += -1).normalize();
	return result;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	return (lhs < rhs || lhs == rhs);
}
bool operator>(const Rational& lhs, const Rational& rhs) {
	return !(lhs < rhs) && !(lhs == rhs);
}
bool operator>=(const Rational& lhs, const Rational& rhs) {
	return !(lhs < rhs);
}



int main() {
	Rational a, b;
	cout << "Input a rational number, e.g. 6/9.\n";
	cout << "a: ";
	cin >> a;
	cout << "Input a rational number, e.g. 6/9.\n";
	cout << "b: ";
	cin >> b;
	const Rational one = 1;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;

	// Implement as non-member, but not a friend
	cout << "a + one: " << (a + one) << endl;
	cout << "a == one: " << boolalpha << (a == one) << endl;

	// How does this manage to work?
	// It does NOT require writing another == operator. 
	cout << "1 == one: " << boolalpha << (1 == one) << endl;

	// Do not implement as friend.
	cout << "a != one: " << boolalpha << (a != one) << endl;

	cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
	cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;

	cout << "++ ++a = " << (++ ++a) << endl;
	cout << "a = " << a << endl;
	cout << "-- --a = " << (-- --a) << endl;
	cout << "a = " << a << endl;

	cout << "a++ ++ = " << (a++ ++) << endl;
	cout << "a = " << a << endl;

	// Even though the above example, (a++ ++), compiled, the
	// following shouldn't.
	// But some compiler vendors might let it...  Is your compiler
	// doing the right thing?
	//cout << "a-- -- = " << (a-- --) << endl;
	cout << "a = " << a << endl;


	// Should report that 1 is true
	if (Rational(1)) {
		cout << "1 is true" << endl;
	}
	else {
		cout << "1 is false" << endl;
	}

	// Should report that 0 is false
	if (Rational(0)) {
		cout << "0 is true" << endl;
	}
	else {
		cout << "0 is false" << endl;
	}

	cout << "Comparisons\n";
	Rational twoFifths(2, 5);
	Rational threeHalves(3, 2);
	Rational minusFive(-5);
	cout << twoFifths << " < " << threeHalves << " : "
		<< (twoFifths < threeHalves) << endl;
	cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
	cout << threeHalves << " < " << twoFifths << " : "
		<< (threeHalves < twoFifths) << endl;
	cout << threeHalves << " > " << threeHalves << " : "
		<< (threeHalves > threeHalves) << endl;
	cout << threeHalves << " >= " << threeHalves << " : "
		<< (threeHalves >= threeHalves) << endl;
	cout << minusFive << " >= " << threeHalves << " : "
		<< (minusFive >= threeHalves) << endl;
}