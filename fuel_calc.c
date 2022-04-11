#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 128



FILE *oldf;

struct line
{
 char line[1000];
}lines[100000];



struct customer {

    float charges[1000]; // store customers' spendings here
    float sumofcharges; // store customers' total spending here


}customers[1000];


int main(){
    int i,j,k,l,lines_count,ret;
    char fname[20], *dum;

    printf("Please enter the name of file that you want to make the fuel calculations.(Do not forget to add .txt at the end of the file name.)\n");
    scanf("%s",fname);


    if((oldf = fopen(fname,"r"))== NULL){// open the old file in read mod
        printf("The file could not opened!"); // checking if old file returns NULL
        exit(1);
    }
    i=0;
    while(fgets(lines[i].line,SIZE,oldf)) // read line by line into the array line[]
    {
        i++;
    }
    lines_count = i;

    for(i=0; i<lines_count;i++)
        {
                if((dum=strchr(lines[i].line,'\n')) != NULL)
            {
                *dum = '\0'; // to be able to compare strings with plates delete new lines
            }

        }



    for(j=0; j<lines_count; j++)
    {
        for(k=0; k<strlen(lines[j].line); k++)
            {
             if(strlen(lines[j].line)>8)
             {
                 if(lines[j].line[k]== '.')
                 {
                     l=k;
                     while(l<(strlen(lines[j].line)))
                     {
                         lines[j].line[l] = lines[j].line[l+1];
                         l++;
                     }
                 }

             }
               else if  (lines[j].line[k] == '.')
                {
                    lines[j].line[k] = lines[j].line[k-1]; // removing dots
                    lines[j].line[k-1] = ' ';
                }
                else if (lines[j].line[k]== ',')
                {
                    lines[j].line[k] = '.'; // replacing comas with dots
                }


            }

    }





   for(i=0;i<1000;i++){
    customers[i].sumofcharges = 0.00; // for sum operation with its self set initially 0 to do not get error .
   }
            char plate[] = "45F8730";
            l=0; // initially set l to 0
            for(i=40; i<(lines_count-24);i++) // which line ?
            {

                ret=(strcmp(plate,(lines[i].line)));
                if(ret==0) // Is the line same with plate ?
                {
                  (customers[0].charges[l]) = (atof(lines[i+12].line)); // after 12 lines, there is the charge for the customer. Convert charge's line's form from char to float
                  (customers[0].sumofcharges) = (customers[0].sumofcharges) + (customers[0].charges[l]); // add charges to find sum.
                  l++;
                }
            }

            customers[1].sumofcharges =  (atof(lines[(lines_count)-5].line)) - (customers[0].sumofcharges);


    printf("Last month, Ahmet has bought fuel worth %.2f Turkish Liras.\n",customers[0].sumofcharges);
    printf("Last month, Yunus Emre has bought fuel worth %.2f Turkish Liras.\n",customers[1].sumofcharges);

    fclose(oldf);


return 0;
}
