/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:14:28 by amorion-          #+#    #+#             */
/*   Updated: 2023/10/28 17:14:34 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include<map>
# include<ctime>
# include<cstring>
# include<iostream>
# include<fstream>
# include<stdlib.h>

class BitcoinExchange
{
private:
	std::map<std::time_t, float>Data;
	BitcoinExchange(BitcoinExchange const &src);

	class InvalidBitcoinExchangeExcepton : public std::exception
	{
		public:
			const char* what() const throw();
	};
public:
	BitcoinExchange();
	~BitcoinExchange();

	BitcoinExchange	const	&operator=(BitcoinExchange const &rhs);

	std::map<std::time_t, float> const &GetData() const;
	void	SetData(std::map<std::time_t, float> change);


	void	Evaluate(std::time_t date, float amount);
};

std::ostream &operator <<(std::ostream &os, const BitcoinExchange &d);
#endif

