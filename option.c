#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void condition(char *chaine);
void create_account(char *info);
void logIN(char *info);
void content_type();
void start();
void end();

int main()
{

	char *chaine;
	chaine=getenv("QUERY_STRING");
	content_type();
	start();
	condition(chaine);
	
	end();
	
	
	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}

void condition(char *chaine)
{
	
	char *token;
	char info[256];
	strcpy(info,chaine);
	token=strtok(chaine,"=");
	if(strcmp(token,"new_login") == 0)
	{
		
		create_account(info);
	
	}
	else
	{
		logIN(info);
	
	
	}
}
void logIN(char *info)
{
	FILE *fichier=fopen("account.txt","r+");
	char *token;

	if(fichier == NULL)
	{
		printf("Opening file ERROR");
		exit(1);
	}
	else
	{
		char *rest;
		int i=0;
		int error=0;
		char line[256];
		char *tok;
		int found=0;
		token=strtok(info,"=");
		token=strtok(NULL,"&");
		char *login_with_space=token;
		
		token=strtok(NULL,"=");
		token=strtok(NULL," ");
		char *pswd=token;      //
		
		token=strtok(login_with_space,"+");
		rest=strtok(NULL," ");
		
		char *login=token;   
		if(rest != NULL)
		{  
			while(rest[i] != '\0')
			{
				if(rest[i] != '+')
				{
					error=1;
					
				}
				i++;
			}
		}
		if(token != NULL && pswd != NULL  )
		{
			while(fgets(line,sizeof(line),fichier))
			{
				token=strtok(line,";");
				tok=strtok(NULL,"\n");
				
				if(strstr(login,token) != NULL && strstr(pswd,tok) != NULL && error != 1)
				{
					
					printf("<div class=\"container\">\n");
					printf("<h1>Welcome back!</h1>\n");
					printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"ip.cgi?connected/%s\" class=\"link\">CLASSE D'ADRESSE IP</A></DIV>",login);
					printf("<DIV class=\"connect\"><A HREF=\"log_out.cgi\" class=\"link\">Settings</A></DIV></DIV></DIV>");
					found=1;
					break;
				}
				else if(strstr(login,token) != NULL && strstr(pswd,tok) == NULL && error != 1)
				{
					
					printf("<div class=\"container\">\n");
					printf("<h1>Incorrect password</h1>\n");
					printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
					printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">TRY AGAIN</A></DIV>");
					printf("<DIV class=\"connect\"><A HREF=\"accueil.cgi\" class=\"link\">RETURN</A></DIV></DIV></DIV>");
					found=1;
					break;
				}
			}
			if(found != 1 || error == 1)
			{
					printf("<div class=\"container\">\n");
					printf("<h1>This account does not exist</h1>\n");
					printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
					printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">TRY AGAIN</A></DIV>");
					printf("<DIV class=\"connect\"><A HREF=\"log_out.cgi\" class=\"link\">RETURN</A></DIV></DIV></DIV>");
			}
	}
	else
	{
		printf("<div class=\"container\">\n");
		printf("<h1>Username or password is missing.Please enter the necessary information to proceed</h1>\n");
		printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");			
		printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">TRY AGAIN</A></DIV></DIV>");
	
		
	}
		fclose(fichier);
	}
}
void create_account(char *info)
{
	FILE *fichier=fopen("account.txt","r+");
	char *token;
	char *tok;
	char *pswd;
	if(fichier == NULL)
	{
		printf("Opening file ERROR");
		exit(1);
	}
	else
	{
		int i=0;
		int j=0;
		int k=0;
		int error=0;
		token=strtok(info,"=");
		token=strtok(NULL,"&");
		char *login_with_space=token;
		
		//---------------------------------------------------
		pswd=strtok(NULL,"=");
		pswd=strtok(NULL," ");    //the password
		
		
		if(pswd != NULL)
		{
			while(pswd[k] != '\0')
			{
				if(pswd[k] == '+')
				{
					
					error=1;
					break;
				}
				k++;
			}
		 }
	
		//-------------------------------
		token=strtok(login_with_space,"+");  
		char *login=token;     //the login
		token=strtok(NULL," ");

		if(token != NULL)
		{
			while(token[j] != '\0')
			{
				if(token[j] != '+')
				{
				
					error=1;
					break;
				}
				j++;
			}
		}	
		if(login != NULL)
		{
			while(login[i] != '\0')
			{
				if(!isalpha(login[i]) && !isdigit(login[i]) && login[i] != '_' && login[i] != '.')
				{
					
					error=1;
					break;
				}
				i++;
			}
		}
		//---------------------------------------------------
		if(pswd == NULL || login == NULL)
		{
			error=3;
		}	
		if(error == 0)  ////////////////sans erreur
		{
			char line[256];
			int exist=0;
				while(fgets(line,sizeof(line),fichier))
				{
					token=strtok(line,";");
					tok=strtok(NULL,"\n");
					if(strstr(login,token) != NULL && strstr(pswd,tok) != NULL)
					{
							printf("<div class=\"container\">\n");
							printf("<h1>Oops! It looks like this account already exists.<BR>Please try logging in or use a different Username.</h1>\n");
							printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
							printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">LOG IN</A></DIV>");
							printf("<DIV class=\"connect\"><A HREF=\"create.cgi\" class=\"link\">Create new account<BR>using a different username</A></DIV></DIV>");
							printf("</div>\n");
					 
					  exist=1;
					  break;
					}
				 }
				if(exist == 0)
				{
						fprintf(fichier,"%s;%s\n",login,pswd);
						printf("<div class=\"container\">\n");
						printf("<h1>Account created successfully.</h1>\n");
						printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"ip.cgi?connected/%s\" class=\"link\">LOG IN</A></DIV>",login);
						printf("<DIV class=\"connect\"><A HREF=\"log_out.cgi\" class=\"link\">Settings</A></DIV></DIV></DIV>");

				}		
		}
		else if(error == 1) ////////////pswd ou login contient des espaces
		{
			printf("<div class=\"container\">\n");
			printf("<h1>The password must not contain spaces.<BR>The login must only contain letters,<BR>numbers, periods (.), and underscores (_). No spaces are allowed.</h1>\n");
			printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
			printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"create.cgi\" class=\"link\">TRY AGAIN</A></DIV>");
			printf("<DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">RETURN</A></DIV></DIV></DIV>");
			
		}
		else if(error == 3) ////////////pswd ou login est null
		{
			printf("<div class=\"container\">\n");
			printf("<h1>Username or password is missing.Please enter the necessary information to proceed</h1>\n");
			printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");			
			printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"create.cgi\" class=\"link\">TRY AGAIN</A></DIV>");
			printf("<DIV class=\"connect\"><A HREF=\"log_out.cgi\" class=\"link\">RETURN</A></DIV></DIV></DIV>");
			
		}
			
	}
		
		fclose(fichier);
	
}

void start()
{
		printf("<HTML> \n");
		printf(" <HEAD> ");
		printf("    <TITLE> CONDITION </TITLE>");
		printf("        <META charset=\"UTF-8\">");
		printf("<STYLE>");
		printf("body {\n");
		printf("font-family: Arial, sans-serif;\n");
		printf("    background-color: #f4f4f4;\n");
		printf("    color: #333;\n");
		printf("    text-align: center;\n");
		printf("    margin: 0;\n");
		printf("    padding: 0;\n");
		printf("}\n");
		printf("h1 {\n");
		printf("    color:black;\n");
		printf("	font-size: 15px;\n");
		printf("}\n");
		printf("img {\n");
		printf("    width: 100px;\n");
		printf("    height: auto;\n");
		printf("    margin-top: 20px;\n");
		printf("}");
		printf(".container {\n");
		printf("	font-size:15px;");
		printf("    width: 80%%;\n");
		printf("    margin: auto;\n");
		printf("    padding: 20px;\n");
		printf("    background: white;\n");
		printf("    border-radius: 8px;\n");
		printf("    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n");
		printf("}\n");
		printf(".button-submit "
				"{\n"
				"background-color: rgb(0, 102, 204);\n"
				"color: rgb(255, 255, 255);\n"
				"border: none;\n"
				"padding: 10px 20px;\n"
				"text-align: center;\n"
				"text-decoration: none;\n"
				"display: inline-block;\n"
				"font-size: 16px;\n"
			    "margin: 4px 2px;\n"
				"cursor: pointer;\n"
				"border-radius: 5px;\n"
				"transition: background-color 0.3s;\n"
			    "}\n"	
			    ".button:hover {\n"
			    "    background-color: #0056b3;}\n"
			
			    ".stick img"
				"{"
					"width: 30px; "
					"height: auto;"
					"transition: opacity 0.3s;"
				"}"
				".cont {"
                "	display: flex;"
				"	gap: 100px; /* Space between the boxes */"
				"}"
			   ".connect{"
			   "	width:50%%;"
			   "    padding:3px;"
			   "	border: 1px solid pink;"
			   " 	border-radius: 20px;"
			   "    background-color:#0080ff;}\n"
			   "    text-align:center;"
			   "	font-size:20px;"
			   "}"
			   "connect:hover{"
			   "	border: 1px solid #16B84E;"
			   "    background-color: #16B84E;}\n"
			   ".link{"
			   "	font-size:20px;"
			   "	text-decoration:none;"
			   "	color:pink;}"
				"</STYLE>"
				"</HEAD>"
				"<BODY>");
							 
}	

void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
