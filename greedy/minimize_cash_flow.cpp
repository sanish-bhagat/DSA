#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

vector<vector<int>> minCashFlow(vector<vector<int>> transaction)
{
    int n = transaction.size();

    // queues to sort the people in two grps - who gives money and ones who recieves
    priority_queue<vector<int>> debitors, creditors;

    for (int personId = 0; personId < n; personId++)
    {
        int netAmt = 0;

        // total amount of receive money(owed money to someone)
        // checks the matrix row wise for the curr person that
        // who will pay him money
        for (int fromPerson = 0; fromPerson < n; fromPerson++)
            netAmt += transaction[fromPerson][personId];

        // total amount the person is in debt(owes money from someone)
        // checks the matrix column wise for the curr person that
        // who he has to pay money
        for (int toPerson = 0; toPerson < n; toPerson++)
            netAmt -= transaction[personId][toPerson];

        // grp the person with debitors if he will give money(debt)
        if (netAmt < 0)
            debitors.push({abs(netAmt), personId});

        // grp the person with creditors if he will recieve money(credit)
        else if (netAmt > 0)
            creditors.push({netAmt, personId});
    }

    // initialsie the res[][] with 0 amount
    vector<vector<int>> res(n, vector<int>(n, 0));

    while (!debitors.empty())
    {
        // match the highest creditor with the highest debitor
        int debtAmt = debitors.top()[0];
        int creditAmt = creditors.top()[0];
        int debtorId = debitors.top()[1];
        int creditorId = creditors.top()[1];

        // pop the matched ones
        debitors.pop();
        creditors.pop();

        // transfer the min amount of what ones needs to pay and what one needs to recieve
        int transferAmt = min(creditAmt, debtAmt);

        // store the transfer amt in the res[][]
        res[debtorId][creditorId] = transferAmt;

        // update the credit and debit amounts after the transfer of money
        creditAmt -= transferAmt;
        debtAmt -= transferAmt;

        // if debtor still have debt remaining, push back it into debitors grp
        if (debtAmt > 0)
            debitors.push({debtAmt, debtorId});

        // if creditor stills have to recieve more, push back it into the creditos grp
        else if (creditAmt > 0)
            creditors.push({creditAmt, creditorId});
    }

    return res;
}

int main()
{
    int n = 3;
    vector<vector<int>> transaction = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0}};

    vector<vector<int>> result = minCashFlow(transaction);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}