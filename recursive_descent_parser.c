//DOESNT WORK


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char str[100];
int i = 0;
int S();
int A();

int S(){

    if(str[i] == 'c'){
        i++;
        if(A()){
            if(str[i] == 'd')
            {
                i++;
                return 1;
            }
        }
    }

    return 0;
}

// int A(){

//     if(str[i] == 'a'){
//         i++;
//         if(str[i] == 'b'){
//             i++;
//             return 1;
//         }
//         return 1;
//     }


//     return 0;
// }

int Adash(){
    if(str[i] == 'b'){
        i++;
        return 1;
    }
    return 1;
}

int A(){
    if(str[i]=='a'){
        i++;
        if(Adash() == 1){
            return 1;
        }
    }

    return 0;
}

void main(){
    printf("Enter the input string : ");
    scanf("%s", &str);

    if(str[i] == '\0' && S() == 1)
        printf("String Accepted");
    else
        printf("String not accepted");
}