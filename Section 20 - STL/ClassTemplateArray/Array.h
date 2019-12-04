#pragma once
/*
	- Note: Since C++11 the STL has std::array which is a template-based array class
	- Use std::array instead of raw arrays whenever possible
	- Note: We can have non-type template parameters, which is N in this case
*/

template <typename T, int N>
class Array {
	friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {
		os << "[ ";
		for (const auto& val : arr.values)
			os << val << " ";
		os << "]" << std::endl;
		return os;
	}
private:
	int size{ N };	// how do we get the N??
	T values[N];	// N needs to be known at compile time
public:
	Array() = default;
	Array(T init_val) {
		for (auto &item : values)
			item = init_val;
	}
	void fill(T val) {
		for (auto &item : values)
			item = val;
	}
	int get_size() const {
		return size;
	}
	// Overloaded Subscript Operator
	T &operator[](int index) {
		return values[index];
	}
};

