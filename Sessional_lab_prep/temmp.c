#include<stdio.h>
#include<string.h>
int main(){
   int i,j,n;
   char str[150][150],s[150];
   printf("Enter number of names: ");
   scanf("%d",&n);
   printf("\nEnter names:\n");
   for(i=0;i<n;i++){
      scanf("%s",str[i]);
   }
   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(strcmp(str[i],str[j])>0){
            strcpy(s,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],s);
         }
      }
   }
   printf("\nThe sorted names are:\n");
   for(i=0;i<n;i++){
      printf("%s\n",str[i]);
   }
   printf("\nName starting with vowels:\n");
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
      	if(str[i][0]=='A'||str[i][0]=='a'||str[i][0]=='E'||str[i][0]=='e'||str[i][0]=='I'||str[i][0]=='i'||str[i][0]=='O'||str[i][0]=='o'||str[i][0]=='U'||str[i][0]=='u')
		  {
      	printf("%s\n",str[i]);
      	break;
	  }
	  }
   }
}