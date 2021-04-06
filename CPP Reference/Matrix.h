template<typename t>
class Matrix {
public:
	t data;
	int sz;
	bool flag;
	vector<Matrix*> nxt;

	Matrix(int sz, t val) : sz(sz), data(val) {
		if (sz) 
			this->flag = 0;
		else 
			this->flag = 1;
		nxt.resize(sz);
	}

	Matrix<t>& operator[] (int);
};

template<typename t>
Matrix<t>& Matrix<t>::operator[] (int idx) {
	return *nxt[idx];
}