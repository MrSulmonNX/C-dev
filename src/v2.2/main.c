//Simple Utility v2.2
double version = 2.2 ;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//#include<time.h>
//#include<unistd.h>
//#include<io.h>
//#include<windows.h>
#pragma warning(disable: 4996)


//プロトタイプ宣言//
int nkai(void);
int credit(void);
int programmain(void);
int calculator(void);
int infinite(void);
int waiting(void);
int ideal_gas(void);
int gettime(void);

//main関数//
int main(void) {

    credit(); //作成者表示関数//
    programmain(); //プログラムのmain関数//

	return 0;
}

//作成者表示関数//
int credit(void) {

	printf("\n");
    printf("Simple Utility v%0.1f\n", version);
    printf("\n");
    printf("Coded by @SalmonNX.\n");
    printf("\n");
	

    return 0;

}

//プログラムの判別関数//
int programmain(void) {

    printf("If You Want to Test This Program, Please Enter 1, 2, 3, 4, 5 or 6.\n");
    printf("\n");
    printf("1:Show ''N回目'' ~ 15\n");
    printf("2:Calculator\n");
    printf("3:Infinity Loop test (DANGER!!). to exit loop, Press Ctrl + C.\n");
    printf("4:Waiting Function (UNDER CONSTRUCTION...)\n");
    printf("5:Ideal Gas Law Calculator (pv = nRT)\n");
    printf("6:Get Current Time (From your computer)\n");
    printf("\n");

    int var1;

    scanf("%d", &var1);

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
        printf("Test(option3) Finished.\n");

    }
    else if (var1 == 4) {

        waiting();
        printf("Test(option4) Finished.\n");
    }
    else if (var1 == 5) {

        ideal_gas();
        printf("Test(option5) Finished.\n");
    }
    else if (var1 == 6) {
        gettime();
        printf("Test(option6) Finished.\n");
	}
    else {
        printf("Please Enter a Valid Number.\n");
        printf("\n");
        programmain();
    }
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
    scanf("%lf", &d);

    printf("%09f 回目\n", d);
    printf("\n");

    return 0;
}

//電卓関数 -オプション2//
int calculator(void) {


    double num1, num2, result;
    char operator;

    printf("Please enter a formula (example: 1 + 2): ");

    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
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

    scanf("%d", &wait);

    printf("Waiting for %d seconds...\n", wait);

    for (int i = 0; i < 10; i++) {
        printf(".\n");
        //sleep(1); //UNIX系OS用
        Sleep(1000); //Windows用
	}

   

    printf("Waited for %d seconds.\n", wait);

    printf("\n");

    return 0;
}

//理想気体関数 - オプション5//
int ideal_gas(void) {

    double p1, v, n, T;
    double R = 8310;


    printf("This finction calculates Values Based on ''pv = nRT''. (R = 8.31 10^3)\n");
    printf("if u wanna calc preassure[Pa] , pls enter values in order v[L]→n[mol]→T[K](pls divide values by half space)\n");
    scanf("%lf", &v);
    scanf("%lf", &n);
    scanf("%lf", &T);

    p1 = (n * R * T) / v;

    printf("p = %lf[Pa]\n", p1);

    return 0;
}

//時間関数_オプション6//
int gettime(void) {
    time_t t = time(NULL);
    if (t == (time_t)-1) {
        printf("time() failed.\n");
        return 1;
    }

    struct tm tm_buf;
    struct tm *tm_ptr = NULL;

#if defined(_MSC_VER)
    if (localtime_s(&tm_buf, &t) != 0) {
        printf("localtime_s failed.\n");
        return 1;
    }
    tm_ptr = &tm_buf;
#elif defined(_POSIX_THREADS) || defined(__unix__) || defined(__APPLE__)
    if (localtime_r(&t, &tm_buf) == NULL) {
        printf("localtime_r failed.\n");
        return 1;
    }
    tm_ptr = &tm_buf;
#else
    tm_ptr = localtime(&t);
    if (tm_ptr == NULL) {
        printf("localtime failed.\n");
        return 1;
    }
#endif

    char buf[128];
    if (strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S %Z", tm_ptr) == 0) {
        printf("strftime failed.\n");
        return 1;
    }

    printf("Current Time: %s\n\n", buf);
    return 0;
}
