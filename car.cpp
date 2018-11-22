#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Car{
private:
	string m_manufacturer;
	string m_model;
public:
	Car(string manufacturer, string model):
		m_manufacturer{manufacturer}, m_model{model}{};

	friend bool operator<(const Car&, const Car&);
	friend ostream& operator<<(ostream&, const Car&);
};

	bool operator<(const Car& car1, const Car& car2){
		if(car1.m_manufacturer < car2.m_manufacturer){
			return true;			
		}
		else if(car1.m_manufacturer > car2.m_manufacturer){
			return false;
		}
		else if(car1.m_model < car2.m_model){
			return true;
		}
		else{
			return false;
		}
	}

	ostream& operator<<(ostream& out, const Car& car){
		out << "Car(" << car.m_manufacturer << ", " << car.m_model << ")";
		return out;
	}

int main(int argc, char const *argv[]){
	vector<Car> cars;
	cars.push_back(Car("Toyota", "Corolla"));
	cars.push_back(Car("Honda", "Accord"));
	cars.push_back(Car("Toyota", "Camry"));
	cars.push_back(Car("Honda", "Civic"));

	std::sort(cars.begin(), cars.end());
	for(auto &car : cars){
		cout << car << endl;
	}

	return 0;
}