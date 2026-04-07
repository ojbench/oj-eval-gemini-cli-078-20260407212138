#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
    Evil(int st = 0, int ed = 0, int val = 0) : st(st), ed(ed), val(val) {
        int len = ed - st + 1;
        int alloc_len = len > 0 ? len : 1;
        data = new int[alloc_len];
        for (int i = 0; i < alloc_len; ++i) {
            data[i] = 0;
        }
    }

    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int len = ed - st + 1;
        int alloc_len = len > 0 ? len : 1;
        data = new int[alloc_len];
        for (int i = 0; i < alloc_len; ++i) {
            data[i] = other.data ? other.data[i] : 0;
        }
    }

    ~Evil() {
        if (data) {
            delete[] data;
        }
    }

    Evil& operator=(const Evil& other) {
        if (this == &other) return *this;
        if (data) {
            delete[] data;
        }
        st = other.st;
        ed = other.ed;
        val = other.val;
        int len = ed - st + 1;
        int alloc_len = len > 0 ? len : 1;
        data = new int[alloc_len];
        for (int i = 0; i < alloc_len; ++i) {
            data[i] = other.data ? other.data[i] : 0;
        }
        return *this;
    }

    int& operator[](int i) {
        if (i >= st && i <= ed) {
            return data[i - st];
        } else {
            return data[0];
        }
    }

    Evil& operator++() {
        ++val;
        return *this;
    }

    Evil operator++(int) {
        Evil temp(*this);
        ++val;
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Evil& e) {
        os << e.val << " ";
        int len = e.ed - e.st + 1;
        for (int i = 0; i < len; ++i) {
            os << e.data[i] << " ";
        }
        os << "\n";
        return os;
    }

    void Print(){
	    cout << val << " ";
	    for(int i = 0;i < ed-st+1;++i)
	        cout << data[i] <<" ";
	    cout << endl;
	}
};

#endif//EVIL_HPP
