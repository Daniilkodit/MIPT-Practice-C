#include<stdio.h>
#include<regex.h>
const char* mail_reg = "^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\\.[a-zA-Z0-9_-]{2,}$";
int main()
{
	char email[100];
	int res = 0;
	regex_t regex;
	scanf("%s",email);
	regcomp(&regex, mail_reg, REG_EXTENDED);
	res = regexec(&regex, email, 0, NULL, 0);
	if(res==0) printf("1\n");
	else printf("0\n");
	regfree(&regex);
}
