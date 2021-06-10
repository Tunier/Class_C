#include <stdio.h>
#include <stdlib.h>



/**********************
	** [제어문]
***********************/


int main(void)
{
	/************************************************
		** [반복문]

		1. while
			
		2. for

	************************************************/
	/*
	int i = 0;

	while (i < 10)
	{
		i++;

		printf_s("%d : Hello World!! \n", i);
	}
	*/



	//** 구구단 프로그램 [반복문 중복 사용 예]
	/*
	int i = 2;
	int j = 1;

	while (i < 10)
	{
		j = 1;

		while (j < 10)
		{
			printf_s("%d x %d = %d\n", i, j, (i * j));
			j++;
		}

		i++;
		printf_s("\n");
	}
	
	system("pause");
	system("cls");
	*/









	/********************************************************************************
		** [while]

		* [PPT 참고 ->  (../Resource/Step_05.pptx)]

		* 결과창에 다음과 같이 출력하시오.

			A.			  B. 		 c. 		    d. 
			         *	  *			 **********		**********
			        **	  **		  *********		*********
			       ***	  ***		   ********		********
			      ****	  ****		    *******		*******
			     *****	  *****		     ******		******
			    ******	  ******		  *****		*****
			   *******	  *******		   ****		****
			  ********	  ********	        ***		***
			 *********	  *********		     **		**
			**********	  **********          *		*

	*********************************************************************************/

	//** [실습]

	int i = 10, j = 0;
	
	/*
	printf_s("1\n");

	while (i-- > 0)
	{
		while (j++ < 10)
		{
			if (i < j)
				printf_s("*");
			else
				printf_s(" ");
		}
		printf_s("\n");
		j = 0;
	}

	printf_s("2\n");
	i = 1;
	while (i++ <= 10)
	{
		while (j++ < 10)
		{
			if(i <= j)
				printf_s(" ");
			else
				printf_s("*");
		}
		printf_s("\n");
		j = 0;
	}
	
	printf_s("3\n");
	i = 1;
	while (i++ <= 10)
	{
		while (j++ < 10)
		{
			if (i <= j)
				printf_s("*");
			else
				printf_s(" ");
		}
		printf_s("\n");
		j = 0;
	}

	printf_s("4\n");
	i = 10;
	while (i-- > 0)
	{
		while (j++ < 10)
		{
			if (i < j)
				printf_s(" ");
			else
				printf_s("*");
		}
		printf_s("\n");
		j = 0;
	}
	*/



	/*
	123456789*987654321
	12345678***87654321
	1234567*****7654321
	123456*******654321
	12345*********54321
	1234***********4321
	125*************321
	12***************21
	1*****************1
	*******************
	*/

	//(iCenter * (-1)) + 20 = ??

/*
	int y = 0, x = 0;
	int iHeigth = 0;

	printf_s("높이 입력 : ");
	scanf_s("%d", &iHeigth);

	int iWidth = iHeigth * 2;
	int iCenter = iWidth / 2;
	int iStart = iCenter, iEnd = iCenter;

	while (y++ < iHeigth)
	{
		while (x++ < iWidth)
		{
			if (x <= iCenter)
			{
				if(x >= iStart )
					printf_s("*");
				else
					printf_s(" ");
			}
			else
			{
				if (x <= iEnd)
					printf_s("*");
				else
					printf_s(" ");
			}
		}

		iStart = iCenter - y;
		iEnd = ((iCenter - y) * (-1)) + iWidth;

		printf_s("\n");
		x = 0;
	}

	system("pause");
	system("cls");
*/


	/****************************************************************
		** [for]

		* [PPT 참고 ->  (../Resource/Step_05.pptx)]

		* 예제)

			* 미국 원주민들은 1627년 뉴욕 멘헤튼 섬을 
			  네덜란드 이주자들에게 단돈 $24 에 팔았다고 합니다. 
			  
			  지금 생각하면 헐값에 판 것 같지만, 
			  이 돈을 지금 까지 은행에 넣어두고 8%의 이자를 
			  복리로 받았다면 엄청난 금액이 되어 있을 거라고 합니다.
			  
			  2019년을 기준으로 이 돈의 가치가 얼마나 되는지 
			  계산하는 프로그램을 작성해보세요.

	*****************************************************************/

/*
	double fMoney = 24;

	int iYear = 2019 - 1627;

	for (int i = 0; i < iYear; i++)
	{
		//fMoney = fMoney + (fMoney * 0.08);
		//fMoney += (fMoney * 0.08);
		fMoney *= 1.08;
	}

	printf_s("%lf\n\n", fMoney);
*/

	system("pause");
	return 0;
}

