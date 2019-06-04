#include <iostream>
#include <vector>

using namespace std;

class Cent{
private:
	int m_cent;

public:
	Cent(int cent): m_cent{cent}{};

	Cent& operator+=(const Cent &b){ 
		m_cent += b.m_cent;
		return *this;
	}

	Cent& operator/=(int num){
		m_cent /= num;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cent &a){
		out << a.m_cent << " cents.";
		return out;
	}
};

template <typename T>
T average(const vector<T>& v){
	T ans = 0;
	for(const auto &e : v){
		ans += e;
	}
	ans /= v.size();

	return ans;
}

int main(int argc, char const *argv[]){
	vector<Cent> array1{Cent(8), Cent(2), Cent(7), Cent(3)};
	vector<double> array2{8, 3, 7, 1};

	cout << average(array1) << endl;
	cout << average(array2) << endl;

	return 0;
}