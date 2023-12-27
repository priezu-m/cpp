/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: trim.hpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 13:12:41                                            */
/*   Updated:  2023/11/27 19:46:37                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

std::string			   trim(std::string const &str, std::string const &whitespace = " \t");

#pragma GCC diagnostic pop
