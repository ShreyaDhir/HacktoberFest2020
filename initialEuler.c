#include<stdio.h>
#include<stdlib.h>
void main()
{
  FILE *fp;
  char f[100];
  char s[5]="%f";
  char i[5]="%d";
  /*fp=fopen("Euler.c","w+");
  for(int i=1;i<=500;i++)
  {
       fseek(fp,0L,2);
       fprintf(fp,"\b");
  }
  fclose(fp);*/
  printf("Enter f(x,y):");
  scanf("%s",f);
  fp=fopen("Euler.c","w");
  fprintf(fp,"#include<stdio.h>\n#include<math.h>\nvoid main()\n{float a,y,h,end; \n printf(\"\\nEnter Xo:\");\n scanf(\"%s\",&a);\n printf(\"\\nEnter Yo:\");\n scanf(\"%s\",&y);\n printf(\"\\nEnter h:\");\n scanf(\"%s\",&h);\n printf(\"\\nEvaluate upto X=\");\n scanf(\"%s\",&end);\n int n=0;\n for(float x=a;x<end;x+=h)\n {\n n++;\n     y=y+h*( %s );\n printf(\"Y%s= %s\\n\",n,y);\n}\n }",s,s,s,s,f,i,s);
  fclose(fp);
  system("gcc Euler.c -lm");
  system("./a.out");
}
