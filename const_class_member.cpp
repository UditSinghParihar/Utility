#include <iostream>
#include <array>

using namespace std;

class Point{
private:
	const int m_x = 2;
	const int m_y;
public:
	Point(int 	y):m_y{y}{};
	array<int, 2> get_coordinates(void){
		return array<int, 2>{m_x, m_y};
	}
	
};

int main(int argc, char const *argv[]){
	Point obj{3};
	int x, y;
	std::array<int, 2>coordinates = obj.get_coordinates(); 
	cout << coordinates[0] << "\t" << coordinates[1] << endl;
	return 0;
}