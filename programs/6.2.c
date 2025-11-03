#include <stdio.h>
int main()
{
        unsigned char mask,comm;
        unsigned char reg1,reg2;
        char *abr[] = {"ADD","SUB","MUL","DIV","IN","OUT"};
        char reg[] = "ABCD";
        for(;scanf("%hhx",&comm) == 1;)
        {
                mask = (1<<7);
                if((mask&comm) == 0) printf("MOVI %d\n",((~mask)&comm));
                else
                {
                        reg1 = (comm<<4);
                        reg2 = (comm<<6);
                        reg1 = (reg1>>6);
                        reg2 = (reg2>>6);
                        mask = (comm>>4);
                        mask -=8;
                        if(mask<4) printf("%s %c, %c\n",abr[mask],reg[reg1],reg[reg2]);
                        else
                        {
                        		reg1 = comm<<5;
                        		reg1 = reg1>>7;
                                if(reg1==0) printf("IN %c\n",reg[reg2]);
                                else printf("OUT %c\n",reg[(reg2)]);
                        }

                }


        }
}
