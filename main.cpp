#include <iostream>
#include <math.h>

using namespace std;

void Palindrom(int *a);

int main(void){
    int a;

    cout << "Enter: ";
    cin >> a;
    cout << endl;

    Palindrom(&a);
    
    cout << "Answer: " << a << endl;

    return 0;
}

inline void Palindrom(int *a){
    int count = 0, num0 = (*a);
    
    int num, num3, count1;

    for (int i = 1; i < 1000000000; i *= 10){
        num3 = num0 / i;

        if (num3 == 0)
            break;

        count += 1;
    }
    int num2[count];

    link:
    count1 = 0;

    for (int i = 1, j = count - 1; i < pow(10, count); i *= 10, j--){
        num = (num0 / i) % 10;
        num2[j] = num;
    }
    for (int i = 0, j = count - 1; i < count / 2; i++, j--){
        if (num2[i] == num2[j]){
            count1 += 1;
        }
        else {
            break;
        }
    }

    if (count1 == (count / 2)){
        (*a) = num0;
    }
    else {
        num0++;
        goto link;
    }
}