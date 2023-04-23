/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataSource.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:43:40 by amorion-          #+#    #+#             */
/*   Updated: 2023/04/21 16:43:41 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DataSource.hpp"
DataSource::DataSource()
{
	std::ifstream ifs("./data.csv", std::ifstream::in);
	if(!ifs.good())
		throw DataSource::InvalidDataSourceExcepton();
	std::string line;
	std::string strdate;
	std::tm date;

	std::getline(ifs, line);
	while(std::getline(ifs, line))
	{
		strdate = line.substr(0, line.find(','));
		line = line.erase(0, line.find(',') + 1);
		if(!strptime(strdate.c_str(),"%F", &date))
		{
			ifs.close();
			throw(DataSource::InvalidDataSourceExcepton());
		}
		this->Data[mktime(&date)] = std::stof(line);
	}

}

DataSource::DataSource(DataSource const &src)
{
	this->Data = src.Data;
}

DataSource	const	&DataSource::operator=(DataSource const &rhs)
{
	this->Data = rhs.Data;
	return(*this);
}

std::ostream &operator<<(std::ostream &os, const DataSource &d)
{
	std::map<std::time_t, float> map = d.GetData();
	char buf[11];

	for(std::map<std::time_t, float>::iterator it = map.begin(); it != map.end(); ++it)
	{
		std::strftime(buf, 11, "%Y-%m-%d", std::localtime(&it->first));
		os << buf << "," << it->second << std::endl;
	}
	return os;

}

DataSource::~DataSource()
{}

std::map<std::time_t, float> const &DataSource::GetData() const
{
	return(this->Data);
}

void	DataSource::SetData(std::map<std::time_t, float> change)
{
	this->Data = change;
}

const char*	DataSource::InvalidDataSourceExcepton::what() const _NOEXCEPT
{
	return("Invalid Data Source");
}

void	DataSource::Evaluate(std::time_t date, float amount)
{
	std::time_t							t;
	std::map<std::time_t, float>::iterator	lb = this->Data.lower_bound(date);
	std::map<std::time_t, float>::iterator 	prev = std::prev(lb);
	if(lb == this->Data.end())
		t = prev->first;
	else if(lb == this->Data.begin())
		t = lb->first;
	else if(date - prev->first < lb->first - date)
		t = prev->first;
	else
		t = lb->first;

	char	buf[11];
	std::strftime(buf, 11, "%Y-%m-%d", localtime(&date));
	std::cout << buf << " => " << amount << " = " << amount * this->Data[t] << std::endl;
}
