#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#pragma warning(disable: 4996)


//プロトタイプ宣言//
int nkai(void);
int credit(void);
int programmain(void);
int calculator(void);
int infinite(void);
int waiting(void);


//main関数//
int main(void) {

    credit(); //作成者表示関数//
    programmain(); //プログラムのmain関数//

	return 0;
}

//作成者表示関数//
int credit(void) {

    printf("\n");
    printf("Coded by @SalmonNX.\n");
    printf("\n");

    return 0;

}

//プログラムの判別関数//
int programmain(void) {

    int var1;

    while (1) {

        printf("If You Wanna Test This Program, Please Enter 1, 2, 3 or 4.\n");

        if (scanf("%d", &var1) != 1) {
            int c;
            while ((c = getchar()) != EOF && c != '\n'); // 入力バッファをクリア
            printf("Please Enter a Valid Number.\n\n");
            continue;
        }

        if (var1 == 1) {

            nkai();
            printf("Test(option1) Finished\n");

        }
        else if (var1 == 2) {

            printf("\n");

            calculator();

            printf("\n");
            printf("Test(option2) Finished.\n");
        }
        else if (var1 == 3) {

            infinite();
            printf("Test(option3) Finished\n");

        }
        else if (var1 == 4){

			waiting();
			printf("Test(option4) Finished.\n");
		}
        else
		{
            printf("Please Enter a Valid Number.\n");
            printf("\n");
            continue;
        }

        break; // 正常終了したらループを抜ける

    }

	return 0;
}

//n回表示関数 -オプション1//
int nkai(void) {


    int i;
    double d;


    for (i = 1; i <= 15; i++) {
        printf("%03d 回目\n", i);
    }
    printf("\n");
    printf("Please Enter a Number.\n");
    if (scanf("%lf", &d) != 1) {
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        printf("Invalid input.\n\n");
        return 1;
    }

    printf("%09.0f 回目\n", d);
    printf("\n");

    return 0;
}

//電卓関数 -オプション2//
int calculator(void) {


    double num1, num2, result;
    char operator;

    printf("Please enter a formula (example: 1 + 2): ");

    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        printf("Input format is incorrect.\n");
        printf("\n");
        return 1;
    }

    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            printf("Cannot be divided by zero...\n");
            printf("\n");
            return 1;
        }
        break;
    default:
        printf("Invalid operator.\n");
        printf("\n");
        return 1;
    }
    printf("\n");
    printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    printf("\n");

    return 0;
}

//無限ループ関数 -オプション3//
int infinite(void) {

	int i;

    printf("This is an infinite loop test. To exit, enter CTRL + C.\n");

    for (i = 1;i > 0;i++) {
        printf("Infinite Looping... No.%d\n",i);
	}
    printf("\n");

    return 0;
}

//待機関数 - オプション4//
int waiting(void) {

    int wait;
    printf("(THIS FUNCTION IS UNDER CONSTRUCTION!!!)Enter the number of seconds to wait: ");

    if (scanf("%d", &wait) != 1) {
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        printf("Invalid input.\n\n");
        return 1;
    }

    if (wait < 0) {
        printf("Please enter a non-negative number.\n\n");
        return 1;
    }

    printf("Waiting for %d seconds...\n", wait);

    for (int i = 0; i < wait; i++) {
        printf(".\n");
#ifdef _WIN32
        Sleep(1000); // Windows
#else
        sleep(1); // UNIX系
#endif
	}

    printf("Waited for %d seconds.\n", wait);

    printf("\n");

    return 0;
}
