/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: account.hpp                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/28 01:16:41                                            */
/*   Updated:  2023/11/28 01:17:07                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Account
{

	public:
		typedef Account t;

		static int		getNbAccounts(void);
		static int		getTotalAmount(void);
		static int		getNbDeposits(void);
		static int		getNbWithdrawals(void);
		static void		displayAccountsInfos(void);

		explicit Account(int initial_deposit);
		~Account(void);

		void makeDeposit(int deposit);
		bool makeWithdrawal(int withdrawal);
		int	 checkAmount(void) const;
		void displayStatus(void) const;

	private:
		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		static void _displayTimestamp(void);

		int			_accountIndex;
		int			_amount;
		int			_nbDeposits;
		int			_nbWithdrawals;

		Account(void);
};

#pragma GCC diagnostic pop
