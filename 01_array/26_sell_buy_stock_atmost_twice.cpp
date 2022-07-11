/*
    link: https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
//  very simple and nice solution (for any no. of buy and sell);
// here main logic is we dont care about when to sell or buy just track the profit and acc. it has sold in between.
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = 7;

    // adding array
    int profit = 0;

    // Initializing variable
    // valley-peak approach
    for (int i = 1; i < n; i++)
    {
        // traversing through array from (i+1)th
        // position
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }
    cout << "Maximum Profit=" << profit;
    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// just for almost twice- o(n) space o1
// C++ implmenetation to find
// maximum possible profit
// with at most two transactions

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum
// profit with two transactions
// on a given list of stock prices
int maxProfit(int price[], int n)
{

	// buy1 - Money lent to buy 1 stock
	// profit1 - Profit after selling
	// the 1st stock buyed.
	// buy2 - Money lent to buy 2 stocks
	// including profit of selling 1st stock
	// profit2 - Profit after selling 2 stocks
	int buy1, profit1, buy2, profit2;

	// Set initial buying values to
	// INT_MAX as we want to minimize it
	buy1 = buy2 = INT_MAX;

	// Set initial selling values to
	// zero as we want to maximize it
	profit1 = profit2 = 0;

	for (int i = 0; i < n; i++) {

		// Money lent to buy the stock
		// should be minimum as possible.
		// buy1 tracks the minimum possible
		// stock to buy from 0 to i-1.
		buy1 = min(buy1, price[i]);

		// Profit after selling a stock
		// should be maximum as possible.
		// profit1 tracks maximum possible
		// profit we can make from 0 to i-1.
		profit1 = max(profit1, price[i] - buy1);

		// Now for buying the 2nd stock,
		// we will integrate profit made
		// from selling the 1st stock
		buy2 = min(buy2, price[i] - profit1);

		// Profit after selling a 2 stocks
		// should be maximum as possible.
		// profit2 tracks maximum possible
		// profit we can make from 0 to i-1.
		profit2 = max(profit2, price[i] - buy2);
	}

	return profit2;
}

// Driver Code
int main()
{
	int price[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	cout << "Maximum Profit = "
		<< maxProfit(price, n);
	return 0;
}
///////////////////////////////////
int maxProfit(int price[], int n)
{
    // Create profit array and
    // initialize it as 0
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    /* Get the maximum profit with only one transaction allowed. After this loop, profit[i] contains maximum
       profit from price[i..n-1] using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // max_price has maximum
        // of price[i..n-1]
        if (price[i] > max_price) max_price = price[i];

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at max_price
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    // here profit[0] will be having max profit by 1 transaction

    /* Get the maximum profit with two transactions allowed After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price) min_price = price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak
    return result;
}