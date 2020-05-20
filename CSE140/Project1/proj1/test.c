#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    unsigned int num = 0x000a5782;
    int binary[32];
    int address = 0;

    for( int i = 0; i < 32; i++)
    {
        binary[i] = num % 2;
        num = num / 2;
    }
    int opcode = 0;
    int power = 5;
    int temp = 1;

    int regis = 0;
        int regit = 0;
        int regid = 0;
        int sham = 0;
        int fun = 0;
        for(int r = 25; r >= 0; r--)
        {
            if(r >= 21)
            {
                if(r == 25)
                {
                 power = 4;
                }
                for(int s = power; s > 0; s--)
                {
                    temp = temp * 2;
                }
                temp = temp * binary[r];
                regis = regis + temp;
             power--;
                temp = 1;
            }
            else if(r >= 16)
            {
                if(r == 20)
                {
                 power = 4;
                }
                for(int s = power; s > 0; s--)
                {
                    temp = temp * 2;
                }
                temp = temp * binary[r];
                regit = regit + temp;
             power--;
                temp = 1;
            }
            else if(r >= 11)
            {
                if(r == 15)
                {
                 power = 4;
                }
                for(int s = power; s > 0; s--)
                {
                    temp = temp * 2;
                }
                temp = temp * binary[r];
                regid = regid + temp;
             power--;
                temp = 1;
            }
            else if(r >= 6)
            {
                if(r == 10)
                {
                 power = 4;
                }
                for(int s = power; s > 0; s--)
                {
                    temp = temp * 2;
                }
                temp = temp * binary[r];
                sham = sham + temp;
             power--;
                temp = 1;
            }
            else
            {
                if(r == 5)
                {
                 power = 5;
                }
                for(int s = power; s > 0; s--)
                {
                    temp = temp * 2;
                }
                temp = temp * binary[r];
                fun = fun + temp;
             power--;
                temp = 1;
            }
        }

        for(int a = 0; a < 32; a++)
        {
            printf("%d", binary[a]);
        }

        printf("\n");
        
    printf("%d, %d, %d, %d, %d, %d\n", opcode, regis, regit, regid, sham, fun);

    int num2 = 5;
    int num3 = 5;

    printf("%d", num2 == num3);
}