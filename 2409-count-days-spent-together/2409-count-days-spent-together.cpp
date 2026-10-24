
class Solution {
public:
    int dateToDay(string date) {
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int a1 = dateToDay(arriveAlice);
        int a2 = dateToDay(leaveAlice);
        int b1 = dateToDay(arriveBob);
        int b2 = dateToDay(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
