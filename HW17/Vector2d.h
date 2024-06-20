#include <ostream>
#include <istream>
#include <iostream>
#include <cmath>

class Vector2d
{
public:

	static int count;

	Vector2d();
	Vector2d(float x, float y);
	
	Vector2d(const Vector2d& other);
        
	~Vector2d() { count--; }

	Vector2d& operator=(const Vector2d& other);
	
	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector); 
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
	
	void operator*=(float scalar);

	float operator()();

	const float& operator[](std::size_t idx) const;

	friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector);
	friend std::istream& operator>>(std::istream& is, Vector2d& vector);

	static int getCount() { return count; }

	void printVector();

private:

	float x;
	float y;
};
