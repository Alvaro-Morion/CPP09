/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataSource.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:34:46 by amorion-          #+#    #+#             */
/*   Updated: 2023/04/21 16:34:48 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASOURCE_HPP
# define DATASOURCE_HPP
# include<map>
# include<ctime>
# include<string>
# include<iostream>
# include<fstream>

class DataSource
{
private:
	std::map<std::time_t, float> Data;
	DataSource(DataSource const &src);

	class InvalidDataSourceExcepton : public std::exception
	{
		public:
			const char* what() const _NOEXCEPT;
	};
public:
	DataSource();
	~DataSource();

	DataSource	const	&operator=(DataSource const &rhs);

	std::map<std::time_t, float> const &GetData() const;
	void	SetData(std::map<std::time_t, float> change);


	void	Evaluate(std::time_t, int amount);
};

std::ostream &operator <<(std::ostream &os, const DataSource &d);
#endif

