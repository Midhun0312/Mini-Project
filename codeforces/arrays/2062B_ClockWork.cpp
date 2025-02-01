// You have a sequence of 𝑛
//     time clocks arranged in a line,
//     where the initial time on the 𝑖 - th clock is 𝑎𝑖
//  .In each second, the following happens in order :

//     Each clock's time decreases by 1
//         .If any clock's time reaches 0 ,
//     you lose immediately.You can choose to move to an adjacent clock or stay at the clock you are currently on.
//     You can reset the time of the clock you are on back to its initial value 𝑎𝑖
// .Note that the above events happen in order.If the time of a clock reaches 0 in a certain second,
//     even if you can move to this clock and reset its time during that second, you will still lose.
// You can start from any clock.Determine if it is possible to continue this process indefinitely without losing

while (t--)
{
    int n;
    cin >> n;
    int a[n];
    int flag = 1;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 2 * max(i, n - i - 1) + 1)
        {
            flag = 0;
            cout << "No" << endl;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
}