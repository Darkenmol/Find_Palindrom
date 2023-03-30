#include <iostream>
#include <math.h>

using namespace std;

void Palindrom(int *a);
void FindPalindrom(int *a, int *count);

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
    int count = 0;

    int num;

    for (int i = 1; i < 1000000000; i *= 10){
        num = (*a) / i;

        if (num == 0)
            break;

        count += 1;
    }

    FindPalindrom(&(*a), &count);
}

void FindPalindrom(int *a, int *count){
    int num2[(*count)], num, num0 = *a, count1;

    for (int i = 1, j = (*count) - 1; i < pow(10, (*count)); i *= 10, j--){
        num = (num0 / i) % 10;
        num2[j] = num;
    }
    for (int i = 0, j = (*count) - 1; i < j; i++, j--){
        if (num2[i] == num2[j]){
            count1 += 1;
        }
        else {
            break;
        }
    }

    if (count1 == ((*count) / 2)){
        (*a) = num0;
    }
    else {
        num0++;
        FindPalindrom(&(*a), *(&count));
    }
}