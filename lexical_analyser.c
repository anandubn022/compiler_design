#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main(){
    char token[100], c;
    int i;
    FILE *fp1 = fopen("C:/Users/GALAXY/Documents/c_programs/input_lexical_analyser.txt", "r");
    if (fp1 == NULL)
        printf("FILE NOT FOUND\n");
    else
        printf("FILE FOUND\n");
    
    c = fgetc(fp1);
    while(c!=EOF){

        if(c=='/'){
            c = fgetc(fp1);
            if(c=='/'){
                do{
                    c = fgetc(fp1);
                }while(c!=EOF && c!='\n');
            }
            else{
                printf("\n/\tOperator");
            }
        }

        else if (c=='*' || c=='+' || c=='-' || c=='%')
        {
            /* code */
            printf("\n%c\tOperator", c);
            c= fgetc(fp1);
        }
        
        else if (c=='(' || c==')' || c==';' || c=='{' || c=='}')
        {
            /* code */
            printf("\n%c\tSpecial Character", c);
            c= fgetc(fp1);
        }
        
        else if(isalpha(c) && c!=EOF && c!='\n'){
            i=0;
            while(isalpha(c) && c!=EOF && c!= '\n'){
                token[i] = c;
                i++;
                c = fgetc(fp1);

            }
            token[i] = '\0';
            if(strcmp("void", token)==0 || strcmp("int", token)==0 || strcmp("float", token)==0 || strcmp("char", token)==0)
                printf("\n%s\tKeyword", token);
            else
                printf("\n%s\tIdentifier", token);
        }

        else if (isdigit(c) && c!=EOF && c!='\n')
        {
            /* code */
            i=0;
            while(isdigit(c) && c!=EOF && c!= '\n'){
                token[i] = c;
                i++;
                c = fgetc(fp1);

            }
            token[i] = '\0';
            printf("\n%s\tNumber", token);
        }
        
        else{
            c=fgetc(fp1);
        }
    }

    printf("\n");
    fclose(fp1);
}