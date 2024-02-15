#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vector2f
{
	public:
		double x, y;
		Vector2f friend operator+(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator-(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator*(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator/(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator+=(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator-=(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator*=(Vector2f opnd1, Vector2f opnd2);
    	Vector2f friend operator/=(Vector2f opnd1, Vector2f opnd2);
		void friend printV(Vector2f exmpl);
};

Vector2f operator+(Vector2f opnd1, Vector2f opnd2){
    Vector2f res;
    res.x = opnd1.x + opnd2.x;
    res.y = opnd1.y + opnd2.y;
    return res;
}

Vector2f operator-(Vector2f opnd1, Vector2f opnd2){
    Vector2f res;
    res.x = opnd1.x - opnd2.x;
    res.y = opnd1.y - opnd2.y;
    return res;
}

Vector2f operator*(Vector2f opnd1, Vector2f opnd2){
    Vector2f res;
    res.x = opnd1.x * opnd2.x;
    res.y = opnd1.y * opnd2.y;
    return res;
}

Vector2f operator/(Vector2f opnd1, Vector2f opnd2){
    Vector2f res;
    res.x = opnd1.x / opnd2.x;
    res.y = opnd1.y / opnd2.y;
    return res;
}

Vector2f operator+=(Vector2f opnd1, Vector2f opnd2){
    opnd1.x += opnd2.x;
    opnd1.y += opnd2.y;
    return opnd1;
}

Vector2f operator-=(Vector2f opnd1, Vector2f opnd2){
    opnd1.x -= opnd2.x;
    opnd1.y -= opnd2.y;
    return opnd1;
}

Vector2f operator*=(Vector2f opnd1, Vector2f opnd2){
    opnd1.x *= opnd2.x;
    opnd1.y *= opnd2.y;
    return opnd1;
}

Vector2f operator/=(Vector2f opnd1, Vector2f opnd2){
    opnd1.x /= opnd2.x;
    opnd1.y /= opnd2.y;
    return opnd1;
}

void printV(Vector2f exmpl)
{
	cout << '('<<exmpl.x<<','<<exmpl.y<<')';
}

int main()
{
	Vector2f a, b;
	cout << "enter vectors!" << endl;
	cout << "first vector:" << endl;
	cin >> a.x >> a.y;
	cout << "second vector" << endl;
	cin >> b.x >> b.y;

	cout << "a + b = ";
    printV(a + b);
    cout << endl << "a - b = ";
    printV(a - b);
    cout << endl << "a * b = ";
    printV(a * b);
    cout << endl << "a / b = ";
    printV(a / b);
    cout << endl << "a += b = ";
    printV(a += b);
    cout << endl << "a -= b = ";
    printV(a -= b);
    cout << endl << "a *= b = ";
    printV(a *= b);
    cout << endl << "a /= b = ";
    printV(a /= b);
	return 0;
}