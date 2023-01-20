/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:09:50 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 09:42:24 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRREPLACE_HPP
# define STRREPLACE_HPP

# include <iostream>
# include <fstream>

class strReplace
{
private:
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::string		_buffer;
	int				_pos;
	int			_status;
public:
	strReplace();
	~strReplace();

	int		getStatus(void) const;
	void	setStatus(int status);
	int		open(char *file);
	void	close(void);
	void	replace(char *s1, char *s2);
};

#endif