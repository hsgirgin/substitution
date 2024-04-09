#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
string key;
int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
       for(int i = 0,n = strlen(argv[1]); i < n; i++){
        if isalpha(argv[1][i]){
            for(int i1 = 0,n1 = strlen(argv[1]); i1 < i; i1++){
                if(argv[1][i1] == tolower(argv[1][i])){
                    printf("no");
                    return 1;
                }
            }
            argv[1][i] = tolower(argv[1][i]);
        }
        else{
            printf("no\n");
            return 1;
        }
       }
    }
    else
    {

        printf("no\n");
        return 1;
    }
    key = argv[1];
    string text = get_string("Text: ");
    char new_text[strlen(text)];
    for(int i = 0,n = strlen(text); i <= n; i++){
        if(isalpha(text[i])){
            if(islower(text[i])){
                new_text[i] = key[((int) text[i])-97];
            }
            else{
                new_text[i] = toupper(key[((int) text[i])-65]);            }
        }
        else{
            new_text[i] = text[i];
        }
    }
    if(strlen(text) == 1){
        printf("ciphertext: %c\n",new_text[0]);
        return 0;
    }
    printf("ciphertext: %s\n",(string) new_text);
    return 0;

}
