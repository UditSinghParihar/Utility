#include <iostream>
#include <vector>

using namespace std;

class Table{
private:
	static vector<int> m_enteries;
	static int id_generator;
	int m_id;
public:
	Table():m_id{++id_generator}{};
	const int get_id(void){
		return m_id; 
	}
	void push(int num){
		m_enteries.push_back(num);
	}
	static void get_enteries(void){
		for(int i=0;i<m_enteries.size();++i){
			cout << m_enteries[i] << " ";
		}
		cout << endl;
	}
};

int Table::id_generator=0;
vector<int> Table::m_enteries{};

int main(int argc, char const *argv[]){
	Table obj1;
	Table obj2;
	fprintf(stdout, "obj1 id: %d\nobj2 id: %d\n", obj1.get_id(), obj2.get_id());
	obj1.push(2);
	obj2.push(3);
	Table::get_enteries();
	return 0;
}