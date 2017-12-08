#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>

namespace dauphine
{

	class matrix
	{
	public:
		matrix(std::size_t nb_rows, std::size_t nb_cols);
		std::size_t nb_rows() const;
		std::size_t nb_cols() const;
		void resize(std::size_t nb_rows, std::size_t nb_cols);
		double& operator()(std::size_t i, std::size_t j);
		const double& operator()(std::size_t i, std::size_t j) const;
		matrix& operator+=(const matrix& rhs);
		matrix& operator-=(const matrix& rhs);
		matrix& operator*=(const matrix& rhs);
		matrix& operator/=(const matrix& rhs);
		matrix& operator+=(double rhs);
		matrix& operator-=(double rhs);
		matrix& operator*=(double rhs);
		matrix& operator/=(double rhs);
	private:
		std::size_t m_nb_rows;
		std::size_t m_nb_cols;
		std::vector<double> m_data;

	};
	void init(matrix& m, size_t rows, size_t cols)
	{
		m.resize(rows, cols);
		for (size_t i = 0; i < rows; ++i)
		{
			for size_t j = 0; j < cols; ++j)
			{
			m(i, j) = 2 * i + j;
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const matrix& m);
}

#endif

