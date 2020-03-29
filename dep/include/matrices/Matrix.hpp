#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdexcept>
#include <vector>

template <typename T>
class Matrix {
	private:
		size_t m_rows;
		size_t m_cols;
		T** values;

	public:
		Matrix(const size_t, const size_t);
		Matrix(const std::vector<std::vector<T>>&);
		Matrix(const Matrix<T>&);
		Matrix(Matrix<T>&&);
		~Matrix();

		inline size_t rows() const { return m_rows; }
		inline size_t cols() const { return m_cols; }

		Matrix<T> add(const Matrix&) const;
		Matrix<T> subtract(const Matrix&) const;
		Matrix<T> multiplyBy(const Matrix&) const;

		void set(const size_t, const size_t, const T);

		T& at(const size_t, const size_t);
		T* operator[](const size_t);

	private:
		T guaranteedDotProductWith(const Matrix<T>&, const size_t, const size_t) const;
};

template <typename T>
Matrix<T>::Matrix(const size_t row, const size_t col)
	: m_rows(row),
		m_cols(col),
		values(new T*[m_rows])
{
	for (size_t i = 0; i < m_rows; ++i) {
		values[i] = new T[m_cols];
		for (size_t j = 0; j < m_cols; ++j) {
			values[i][j] = static_cast<T>(0);
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& items)
	: m_rows(items.size()),
		m_cols(m_rows > 0 ? items[0].size() : 0),
		values(new T*[m_rows])
{
	for (size_t i = 0; i < m_rows; ++i) {
		values[i] = new T[m_cols];

		for (size_t j = 0; j < m_cols; ++j) {
			values[i][j] = j < items[i].size()
				? items[i][j]
				: static_cast<T>(0);
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) {
	m_rows = other.m_rows;
	m_cols = other.m_cols;

	values = new T*[m_rows];

	for (size_t i = 0; i < m_rows; ++i) {
		values[i] = new T[m_cols];

		for (size_t j = 0; j < m_cols; ++j) {
			values[i][j] = other.values[i][j];
		}
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& old) {
	m_rows = old.m_rows;
	m_cols = old.m_cols;
	values = old.values;

	old.values = nullptr;
}

template <typename T>
Matrix<T>::~Matrix() {
	if (values) {
		for (size_t i = 0; i < m_rows; ++i) {
			delete[] values[i];
		}
		delete[] values;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

template<typename T>
Matrix<T> Matrix<T>::add(const Matrix& other) const {
	if (m_rows != other.m_rows) {
		throw std::range_error("Attempted to add Matrices of unequal rows");
	}
	else if (m_cols != other.m_cols) {
		throw std::range_error("Attempted to add Matrices of unequal cols");
	}

	Matrix<T> mat(*this);

	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_cols; ++j) {
			mat[i][j] += other.values[i][j];
		}
	}
	return mat;
}

template<typename T>
Matrix<T> Matrix<T>::subtract(const Matrix& other) const {
	if (m_rows != other.m_rows) {
		throw std::range_error("Attempted to subtract Matrices of unequal rows");
	}
	else if (m_cols != other.m_cols) {
		throw std::range_error("Attempted to subtract Matrices of unequal cols");
	}

	Matrix<T> mat(*this);

	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_cols; ++j) {
			mat[i][j] -= other.values[i][j];
		}
	}
	return mat;
}

// NOTE: Will still multiply if the given order is invalid, but the flipped order is valid
template<typename T>
Matrix<T> Matrix<T>::multiplyBy(const Matrix& other) const {
	if (m_cols == other.m_rows) {
		Matrix<T> product(m_rows, other.m_cols);

		for (size_t row = 0; row < m_rows; ++row) {
			for (size_t col = 0; col < other.m_cols; ++col) {
				product[row][col] = guaranteedDotProductWith(other, row, col);
			}
		}
		return product;
	}
	else if (m_rows == other.m_cols) {
		return other.multiplyBy(*this);
	}
	throw std::range_error("Tried to multiply matrices with incompatible dimensions");
}

template <typename T>
void Matrix<T>::set(const size_t row, const size_t col, const T value) {
	values[row][col] = value;
}

template <typename T>
T& Matrix<T>::at(const size_t x, const size_t y) {
	return values[x][y];
}

////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////

template <typename T>
T* Matrix<T>::operator[](const size_t x) {
	return values[x];
}

////////////////////////////////////////////////////////////////////////////////
// Private
////////////////////////////////////////////////////////////////////////////////

template <typename T>
T Matrix<T>::guaranteedDotProductWith(const Matrix<T>& other, const size_t row, const size_t col) const {
	T result = 0;

	for (size_t i = 0; i < m_cols; ++i) {
		result += values[row][i] * other.values[i][col];
	}
	return result;
}
#endif