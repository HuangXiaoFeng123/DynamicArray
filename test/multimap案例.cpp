#include <iostream>
#include <vector>
#include <map>
#define Number 10
#define CAIGOU 0
#define MEISHU 1
#define YANFA 2
using namespace std;

class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void CreateWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	Worker worker;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < Number; i++)
	{
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}
void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	vector<Worker>::iterator it;
	srand((unsigned int)time(NULL));
	for (it = v.begin(); it != v.end(); it++)
	{
		int key = rand() % 3;
		m.insert(make_pair(key, *it));
	}
}
void ShowInfo(multimap<int, Worker>& m)
{
	cout << "采购部门：" << endl;
	multimap<int, Worker>::iterator pos;
	pos = m.find(CAIGOU);
	int count = m.count(CAIGOU);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
}
int main(void)
{
	vector<Worker> v;
	multimap<int, Worker> m;
	CreateWorker(v);
	SetGroup(v, m);
	ShowInfo(m);
	return 0;
}