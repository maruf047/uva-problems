#include <stdio.h>

int main() {

    int duration, depreciation_records, month, result;
    double down_payment, loan, depreciation_rate, worth, ongoing_depreciation_rate, monthly_payment;
    register int i, j;

    scanf("%d %lf %lf %d", &duration, &down_payment, &loan, &depreciation_records);
    while (duration > 0) {
        result = -1;
        worth = loan + down_payment;
        monthly_payment = loan / duration;
        scanf("%d %lf", &month, &depreciation_rate);
        ongoing_depreciation_rate = depreciation_rate;
        worth = worth - worth * ongoing_depreciation_rate;
        if (worth > loan) {
            result = 0;
        }
        j = 1;

        for (i = 1; i < depreciation_records; ++i) {
            scanf("%d %lf", &month, &depreciation_rate);
            if (worth <= loan) {
                while (j < month) {
                    loan = loan - monthly_payment;
                    worth = worth - worth * ongoing_depreciation_rate;
                    if (worth > loan) {
                        result = j;
                        break;
                    }
                    ++j;
                }
            }
            ongoing_depreciation_rate = depreciation_rate;
        }

        if (worth <= loan) {
            while (j <= duration) {
                loan = loan - monthly_payment;
                worth = worth - worth * ongoing_depreciation_rate;
                if (worth > loan) {
                    result = j;
                    break;
                }
                ++j;
            }
        }
        printf("%d month", result);
        if (result != 1) {
            printf("s\n");
        } else {
            printf("\n");
        }
        scanf("%d %lf %lf %d", &duration, &down_payment, &loan, &depreciation_records);
    }
    return 0;
}

