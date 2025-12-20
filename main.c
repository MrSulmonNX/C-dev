#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
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


//main関数//
int main(void) {

	credit(); //作成者表示関数//
	programmain(); //プログラムのmain関数//
}

//作成者表示関数//
int credit(void) {

	printf("\n");
	printf("Coded by @SalmonNX.\n");
	printf("\n");

}

//プログラムの判別関数//
int programmain(void) {

    printf("If You Wanna Test This Program, Please Enter 1 or 2.\n");

    int var1;

    scanf("%d", &var1);

    if (var1 == 1) {

        nkai();
		printf("Test Finished\n");

    }
    else if (var1 == 2) {

		printf("2Return\n");
		printf("\n");

		calculator();

		printf("\n");
		printf("Test Finished.\n");
    }
    else{
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

}
