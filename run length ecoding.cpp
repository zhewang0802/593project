//
//  main.cpp
//  RLC
//
//  Created by zhe wang on 16/4/10.
//  Copyright © 2016年 RLC. All rights reserved.
//

#include<stdio.h>
void reverseRLE(char *);
void reverse(char *, int , int);
int main()
{
    char ch, s[10000],str[100];
    int i, count = 0, start = 0, end = 0;
    printf("Enter the string \n");
    gets(s);
    ch = s[0];
    i = 1;
    count = 1;
    int j = 0;
    while( s[i] != '\0')
    {
        if(s[i] == ch)
        {
            //counting no. of occurances
            i++;
            count++;
        }
        else
        {
            //storing the count and the charcter in an array
            printf("%d%c ", count, ch);
            start = j;
            while(count/10 != 0)
            {
                str[j++] = count % 10 + '0';
                count = count/10;
            }
            str[j++] = count + '0';
            end = j-1;
            reverse(str, start, end);
            str[j++] = ch; 
            ch = s[i];
            count = 1;
            i++;
        }
    }
    printf("%d%c ", count, ch);
    if(str[0] != '\0')
    {
        start = j;
        while(count/10 != 0)
        {
            str[j++] = count % 10 + '0';
            count = count/10;
        }
        str[j++] = count + '0';
        end = j-1;
        str[j++] = ch;
        str[j] = '\0';
        reverse(str, start, end);
    }
    reverseRLE(str);
}

void reverse(char *s, int start , int end)
{
    int temp = 0;
    while(start < end)
    {
        temp = s[end] - '0';
        s[end] = s[start];
        s[start] = temp + '0';
        start++;
        end--;
        
    }
}
void reverseRLE(char * s)
{
    int count=0, j = 0, i = 0;
    while(s[i] != '\0')
    {
        if(s[i] > '0' && s[i] < '9')
        {
            count = count*10 + (s[i]-'0');
            j++;
        }
        else
        {
            for(int k =0;k<count;k++)
                printf("%c",s[i]);
            count = 0;
        }
        i++;
    }
    for(int k =0;k<count;k++)
        printf("%c",s[i]);
}