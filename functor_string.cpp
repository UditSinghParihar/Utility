#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Mystring{
private:
	string m_line;
public:
	Mystring(string line):m_line{line}{};

	string operator()(int start, int length){
		assert((start+length) <= m_line.size() && "Last index of word's length.");		
		string result{};
		for(size_t index=start; index < (start+length); ++index){
			result += m_line[index];
		}
		return result;
	}
};

int main(int argc, char const *argv[]){
	Mystring str("Hello, world!");
	cout << str(7, 7) << endl;
	return 0;
}