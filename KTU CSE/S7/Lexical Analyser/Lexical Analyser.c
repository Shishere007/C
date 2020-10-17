#include<string.h>
#include<conio.h>
#include<ctype.h> 
#include<stdio.h>

  void main() {
    FILE * f1;
    char c, str[10], special[15], keyw[10][10], identifier[10][10];
    int lineno = 1, number_arr[10], number = 0, i = 0, numberi = 0, speci = 0, keyi = 0, ideni = 0;
    f1 = fopen("input.txt", "r");
    while ((c = getc(f1)) != EOF) {
      if (isdigit(c)) {
        number = c - 48;
        c = getc(f1);
        while (isdigit(c)) {
          number = number * 10 + (c - 48);
          c = getc(f1);
        }
        number_arr[numberi++] = number;
        ungetc(c, f1);
      } else if (isalpha(c)) {
        str[i++] = c;
        c = getc(f1);
        while (isdigit(c) || isalpha(c) || c == '_' || c == '$') {
          str[i++] = c;
          c = getc(f1);
        }
        str[i++] = '\0';
        if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0) {
            strcpy(keyw[keyi++], str);
        }
        else
		{
		strcpy(identifier[ideni++], str);	
		}
        ungetc(c, f1);
        i = 0;
      } else if (c == ' ' || c == '\t') {} else if (c == '\n') {
      	lineno++;
	  }
      else {
      special[speci++] = c;	
	  }
	  
    }
    printf("numberbers in the program are:");
    for (i = 0; i < numberi; i++) {printf("%d ", number_arr[i]);}
    printf("\nNo of numberbers in the program are:%d\n", numberi);
    printf("\nKeywords in the program are:");
    for (i = 0; i < keyi; i++) {printf("%s ", keyw[i]);}
    printf("\nNo of Keywords in the program are:%d\n", keyi);
    printf("\nIdentifiers in the program are:");
    for (i = 0; i < ideni; i++) {printf("%s ", identifier[i]);}
    printf("\nNo of Identifiers in the program are:%d\n", ideni);
    printf("\nSpecial characters in the program are:");
    for (i = 0; i < speci; i++) {printf("%c ", special[i]);}
    printf("\nNo of Special characters in the program are:%d\n", speci);
    printf("\nTotal no. of lines are: %d\n", lineno);
    fclose(f1);
    getch();
  }
