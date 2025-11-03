#include <stdio.h>
int main(int argc, char *argv[])
{
        unsigned char mask,comm;
        unsigned char reg1,reg2;
        char *abr[] = {"ADD","SUB","MUL","DIV","IN","OUT"};
	unsigned char reg[4] = {0};
	for(int i=1;i<argc && sscanf(argv[i],"%hhx",&comm) == 1;i++)
        {
                mask = (1<<7);
                if((mask&comm) == 0) {reg[3] = ((~mask)&comm);}
                else
                {
                        reg1 = (comm<<4);
                        reg2 = (comm<<6);
                        reg1 = (reg1>>6);
                        reg2 = (reg2>>6);
                        mask = (comm>>4);
                        mask -=8;
                        if(mask<4)
			{
				switch (mask)
				{
					case 0: reg[reg1] += reg[reg2]; reg[reg1]%=256; break;
					case 1: reg[reg1] -= reg[reg2]; reg[reg1]%=256; break;
					case 2: reg[reg1] *= reg[reg2]; reg[reg1]%=256; break;
					case 3: reg[reg1] /= reg[reg2]; reg[reg1]%=256; break;

				}
			}
                        else
                        {

                       		reg1 = comm<<5;
                        	reg1 = reg1>>7;
                                if(reg1==0) scanf("%hhd",&reg[reg2]);
                                else printf("%hhu\n",reg[(reg2)]);
                        }

                }


        }
}
