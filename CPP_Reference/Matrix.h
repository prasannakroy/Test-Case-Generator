template<typename t>
class Matrix {
private:
	t data;
	int sz;
	bool flag;

public:
	vector<Matrix*> nxt;
	Matrix(int sz, t val) : sz(sz), data(val) {
		if (sz) 
			this->flag = 0;
		else 
			this->flag = 1;
		nxt.resize(sz);
	}

	t getData();
	Matrix<t>& operator[] (int);
	void printArray();
};

template<typename t>
t Matrix<t>::getData() { return data; }

template<typename t>
Matrix<t>& Matrix<t>::operator[] (int idx) {
	return *nxt[idx];
}

template<typename t>
void Matrix<t>::printArray() {
	if (flag) return void(cout << data << " ");
	for (int i = 0; i < nxt.size(); i++) {
		(*nxt[i]).printArray();
	}
	cout << "\n";
}