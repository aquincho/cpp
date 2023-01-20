/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:09:50 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 10:57:19 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_REPLACE_HPP
# define STR_REPLACE_HPP

# include <iostream>
# include <fstream>

class StrReplace
{
private:
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::string		_buffer;
	int				_pos;
	int				_status;
public:
	StrReplace();
	~StrReplace();

	int		getStatus(void) const;
	void	setStatus(int status);
	int		open(char *file);
	void	close(void);
	void	replace(char *s1, char *s2);
};

#endif