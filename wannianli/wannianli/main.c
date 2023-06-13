//
//  main.c
//  wannianli
//
//  Created by HiLau on 2023/6/13.
//

#include "stdio.h"

long int f(int year,int month)
{/*f(ƒÍ£¨‘¬)£ΩƒÍ£≠1£¨»Á‘¬<3;∑Ò‘Ú£¨f(ƒÍ£¨‘¬)£ΩƒÍ*/
    if(month<3) return year-1;
    else return year;
}

long int g(int month)
{/*g(‘¬)£Ω‘¬£´13£¨»Á‘¬<3;∑Ò‘Ú£¨g(‘¬)£Ω‘¬£´1*/
    if(month<3) return month+13;
    else return month+1;
}

long int n(int year,int month,int day)
{
  /*N=1461*f(ƒÍ°¢‘¬)/4+153*g(‘¬)/5+»’*/
    return 1461L*f(year,month)/4+153L*g(month)/5+day;
}

int w(int year,int month,int day)
{
  /*w=(N-621049)%7(0<=w<7)*/
    return(int)((n(year,month,day)%7-621049L%7+7)%7);
}

int date[12][6][7];
int day_tbl[ ][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
            {31,29,31,30,31,30,31,31,30,31,30,31}};
main()
{int sw,leap,i,j,k,wd,day;
 int year;/*ƒÍ*/
 char title[]="SUN MON TUE WED THU FRI SAT";
clrscr();
printf("Please input the year whose calendar you want to know: ");/* ‰»ÎƒÍ*/
scanf("%d%*c",&year);/* ‰»ÎƒÍ∑›÷µ∫Õ¬”π˝÷µ∫Ûµƒªÿ≥µ*/
sw=w(year,1,1);
leap=year%4==0&&year%100||year%400==0;/*≈–»ÚƒÍ*/
for(i=0;i<12;i++)
    for(j=0;j<6;j++)
        for(k=0;k<7;k++)
            date[i][j][k]=0;/*»’∆⁄±Ì÷√0*/
for(i=0;i<12;i++)/*“ªƒÍ Æ∂˛∏ˆ‘¬*/
    for(wd=0,day=1;day<=day_tbl[leap][i];day++)
    {/*Ω´µ⁄i£´1‘¬µƒ»’∆⁄ÃÓ»Î»’∆⁄±Ì*/
     date[i][wd][sw]=day;
    sw=++sw%7;/*√ø–«∆⁄∆ﬂÃÏ£¨“‘0÷¡6º∆ ˝*/
    if(sw==0) wd++;/*»’∆⁄±Ì√ø∆ﬂÃÏ“ª––£¨–«∆⁄ÃÏø™ º–¬µƒ“ª––*/
    }

    printf("\n|==================The Calendar of Year %d =====================|\n|",year);
for(i=0;i<6;i++)
{/*œ»≤‚À„µ⁄i+1‘¬∫Õµ⁄i+7‘¬µƒ◊Ó¥Û–«∆⁄ ˝*/
    for(wd=0,k=0;k<7;k++)/*»’∆⁄±Ìµƒµ⁄¡˘––”–»’∆⁄£¨‘Úwd!=0*/
        wd+=date[i][5][k]+date[i+6][5][k];
    wd=wd?6:5;
    printf("%2d  %s  %2d  %s |\n|",i+1,title,i+7,title);
    for(j=0;j<wd;j++)
    {
        printf("   ");/* ‰≥ˆÀƒ∏ˆø’∞◊∑˚*/
        /*◊Û¿∏Œ™µ⁄i+1‘¬£¨”“¿∏Œ™µ⁄i+7‘¬*/
        for(k=0;k<7;k++)
            if(date[i][j][k])
                printf("%4d",date[i][j][k]);
            else printf("    ");
        printf("     ");/* ‰≥ˆ Æ∏ˆø’∞◊∑˚*/
        for(k=0;k<7;k++)
            if(date[i+6][j][k])
                printf("%4d",date[i+6][j][k]);
            else printf("    ");
        printf(" |\n|");
    }
    /*scanf("%*c");/*º¸»Îªÿ≥µ ‰≥ˆœ¬“ª∏ˆ‘¬µƒ»’¿˙*/
 
}
puts("=================================================================|");
puts("\n Press any key to quit...");
getch();
    
}
}
