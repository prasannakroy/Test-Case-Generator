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
};

template<typename t>
t Matrix<t>::getData() { return data; }

template<typename t>
Matrix<t>& Matrix<t>::operator[] (int idx) {
	return *nxt[idx];
}