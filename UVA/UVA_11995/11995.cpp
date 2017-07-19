#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main() {
	int Case, type, data;
	bool is_s, is_q, is_p_q;
	queue<int> q;
	priority_queue<int> pq;
	stack<int> s;
	while(cin >> Case) {
		is_s = true;
		is_q = true;
		is_p_q = true;
		for(int i=0;i<Case;i++) {
			cin >> type >> data;
			if(type == 1) {
				pq.push(data);
				s.push(data);
				q.push(data);
			}
			if(type == 2) {
				if(!s.empty()) {
					if(s.top() != data)	is_s = false;
					if(q.front() != data) is_q = false;
					if(pq.top() != data) is_p_q = false;
					s.pop();
					q.pop();
					pq.pop();
				}
				else {
					is_s = false;
					is_q = false;
					is_p_q = false;
				}
			}
		}
		if(is_s) {
			if(is_q || is_p_q)	cout << "not sure" << endl;
			else	cout << "stack" << endl;
		}
		else if(is_q) {
			if(is_s || is_p_q)	cout << "not sure" << endl;
			else	cout << "queue" << endl;
		}
		else if(is_p_q) {
			if(is_s || is_q)	cout << "not sure" << endl;
			else	cout << "priority queue" << endl;
		}
		else	cout << "impossible" << endl;

		while(pq.empty() == false)		pq.pop();
		while(q.empty() == false)		q.pop();
		while(s.empty() == false)		s.pop();
	}
	return 0;
}
