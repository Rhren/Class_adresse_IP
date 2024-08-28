#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void end();
void start();
void content_type();
void fonction();
void edit_login(char *old,char *login,char *pswd);
void edit_password(char *old_pswd,char *login,char *pswd);
void delete(char *login,char *pswd);

int main()
{
	content_type();
	start();
	fonction();
	end();
	

	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void fonction()
{
	FILE *file=NULL;
	
	file=fopen("account.txt","r");
	char *chaine;
	char *pswd;
	char *login;
	char *old_name;
	char *tok;
	int a;
	int i=0;	
	int out=0;
	char line[256];
	chaine=getenv("QUERY_STRING");
	
	tok=strtok(chaine,"+");   											//login ou pswd ou delete//
	
	if(strcmp(tok,"login") == 0)
	{
		old_name=strtok(NULL,"+");
		login=strtok(NULL,"=");
		login=strtok(NULL,"&");
		pswd=strtok(NULL,"=");
		pswd=strtok(NULL," ");
		
		char *one;
		char *two;
		
		if(pswd != NULL)
		{
			while(login[i]  != '\0')
			{
				if(!isalpha(login[i]) && !isdigit(login[i]) && login[i] != '_' && login[i] != '.')
				{
					out=1;
				}
				i++;
			}
			while(fgets(line,sizeof(line),file) != NULL)	
			{
				one=strtok(line,";");
				two=strtok(NULL," ");
				if(strstr(one,old_name) !=NULL && strstr(two,pswd) != NULL)
				{
					
					a=1;
					break;
				}
			}	
			
			fclose(file);
			if(a == 1 && out != 1)
			{
				
				edit_login(old_name,login,pswd);    						          //edit login	
				
				
				printf("<div class=\"container\">\n");
				printf("<h1>Modification terminée avec succès</h1>\n");
				printf("<DIV class=\"stick\"><img src=\"succes.png\" alt=\"succes Icon\"></DIV>\n");
				printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"ip.cgi?connected/%s\" class=\"link\">RETURN</A></DIV></DIV></DIV>",login);

			}
			else if(out == 1)
			{
				printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
				<B>The login must only contain letters,numbers, periods (.), and underscores (_). No spaces are allowed.!TRY AGAIN</B>\
				 <BR><BR>\
				 New login:<BR>\
				  <INPUT TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"login %s name\">\
				  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
				   </FORM></DIV>\n",old_name,old_name);
				
			}
			else
			{
				printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
				<B>INCORRECT PASSWORD !TRY AGAIN</B>\
				 <BR><BR>\
				 New login:<BR>\
				  <INPUT TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"login %s name\">\
				  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
				   </FORM></DIV>\n",old_name,old_name);
				
			}
		}
		else
		{
			
			printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
			<B>Password is required to edit your login!</B>\
			 <BR><BR>\
			 New login:<BR>\
			  <INPUT TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"login %s name\">\
			  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
			   </FORM></DIV>\n",old_name,old_name);
			
		}	
	}
										//password
	else if(strcmp(tok,"pswd") == 0)
	{
		char *old_pswd;
		char *one;
		char *two;
		int i=0;
		int out=0;
		
		login=strtok(NULL,"+");
		old_pswd=strtok(NULL,"=");
		old_pswd=strtok(NULL,"&");
		pswd=strtok(NULL,"=");
		pswd=strtok(NULL," ");
		if(old_pswd  != NULL && pswd  != NULL)
		{
			while(pswd[i]  != '\0')
			{
				if(pswd[i] == '+')
				{
					out=1;
				}
				i++;
			}	
			while(fgets(line,sizeof(line),file) != NULL)	
			{
				one=strtok(line,";");
				two=strtok(NULL," ");
				if(strstr(one,login) != NULL && strstr(two,old_pswd) != NULL)
				{
					a=1;
					break;
				}
			}	
			fclose(file);
			if(a == 1 && out != 1)
			{
				edit_password(old_pswd,login,pswd);    //edit login
								
				printf("<div class=\"container\">\n");
				printf("<h1>Modification terminée avec succès</h1>\n");
				printf("<DIV class=\"stick\"><img src=\"succes.png\" alt=\"succes Icon\"></DIV>\n");
				printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"ip.cgi?connected/%s\" class=\"link\">RETURN</A></DIV></DIV></DIV>",login);
				
				
			}
			else if(out == 1)
			{
				printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
				<B>Password must not contain spaces.Try again</B>\
				 <BR><BR>\
				 Old password:<BR>\
				  <INPUT TYPE=\"PASSWORD\"  NAME=\"pswd %s old_pswd\">\
				  New password:<BR>\
				  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
				   </FORM></DIV>\n",login);	
				
			}
			else
			{
				printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
				<B>INCORRECT PASSWORD !TRY AGAIN</B>\
				 <BR><BR>\
				 Old password:<BR>\
				  <INPUT TYPE=\"PASSWORD\"  NAME=\"pswd %s old_pswd\">\
				  New password:<BR>\
				  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
				   </FORM></DIV>\n",login);	
				
			}
		}
		else
		{
			printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
			<B>Password is required </B>\
			 <BR><BR>\
			 Old password:<BR>\
			  <INPUT TYPE=\"PASSWORD\"  NAME=\"pswd %s old_pswd\">\
			  New password:<BR>\
			  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
			   </FORM></DIV>\n",login);	
			   
		}
	}
	else if(strcmp(tok,"delete") == 0)
	{
		char *one;
		char *two;
		
		login=strtok(NULL,"+");
		pswd=strtok(NULL,"=");
		pswd=strtok(NULL," ");
		if(pswd  != NULL)
		{
			while(fgets(line,sizeof(line),file) != NULL)	
			{
				one=strtok(line,";");
				two=strtok(NULL," ");
				if(strstr(one,login) != NULL && strstr(two,pswd) != NULL)
				{
					a=1;
					break;
				}
			}
			fclose(file);
			if(a == 1)
			{
				delete(login,pswd);
				
				printf("<div class=\"container\">\n");
				printf("<h1> Suppression terminée avec succès</h1>\n");
				printf("<DIV class=\"stick\"><img src=\"succes.png\" alt=\"succes Icon\"></DIV>\n");
				printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\" class=\"link\">RETURN</A></DIV></DIV></DIV>");
				
			}
			else
			{
				printf("<DIV class=\"deco\"><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
						<B>Incorrect Password !Try again to delete the account</B>\
						 <BR><BR>\
						 Password:<BR>\
						  <INPUT TYPE=\"PASSWORD\"  NAME=\"delete %s pswd\">\
						   <BR><BR>\
						   <INPUT TYPE=\"SUBMIT\" VALUE=\"Delete the account\"/>\n\
						   </FORM></DIV>\n",login);
				
			}
		}
		else
		{
		
			printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
				<B> Password is required to delete the account</B>\
				 <BR><BR>\
				 Password:<BR>\
				  <INPUT TYPE=\"PASSWORD\"  NAME=\"delete %s pswd\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Delete the account\"/>\n\
				   </FORM></DIV>\n",login);
			
		
		}	
	
	}
	
	
}
void edit_login(char *old,char *login,char *pswd)
{
	char line[256];
	char *tok;
	char stock[256];
	FILE *file=NULL;
	FILE *fichier=NULL;
	
	file=fopen("account.txt","r+");
	fichier=fopen("copy.txt","w+");
	
	if(fichier == NULL || file == NULL)
	{
		printf("error");
	}
	
	while(fgets(line,sizeof(line),file) != NULL)
	{
		strcpy(stock,line);
		tok=strtok(line,";");
		
		if(strstr(tok,old) != NULL)
		{
			fprintf(fichier,"%s;%s\n",login,pswd);
		}
		else
		{
			fprintf(fichier,"%s",stock);
			
		}
	}
	
	rewind(fichier);
	fclose(file);
	file=fopen("account.txt","w+");
	while(fgets(line,sizeof(line),fichier) != NULL)
	{
		fprintf(file,"%s",line);
	
	}
	fclose(fichier);
	fclose(file);

}

void edit_password(char *old_pswd,char *login,char *pswd)
{
	char line[256];
	char *tok;
	char stock[256];
	FILE *file=NULL;
	FILE *fichier=NULL;
	char *token;
	file=fopen("account.txt","r+");
	fichier=fopen("copy.txt","w+");
	
	if(fichier == NULL || file == NULL)
	{
		printf("error");
		exit(1);
	}
	else
	{
	while(fgets(line,sizeof(line),file) != NULL)
	{
		strcpy(stock,line);
		tok=strtok(line,";");
		token=strtok(NULL," ");
		if(strstr(tok,login) != NULL && strstr(token,old_pswd) != NULL)
		{
			fprintf(fichier,"%s;%s\n",login,pswd);
		}
		else
		{
			fprintf(fichier,"%s",stock);
		}
	}
	
	rewind(fichier);
	fclose(file);
	file=fopen("account.txt","w+");
	while(fgets(line,sizeof(line),fichier) != NULL)
	{
		fprintf(file,"%s",line);
	
	}
	fclose(fichier);
	fclose(file);
	}
}
void delete(char *login,char *pswd)
{
	char line[256];
	char stock[256];
	FILE *file=NULL;
	FILE *fichier=NULL;
	
	file=fopen("account.txt","r+");
	fichier=fopen("copy.txt","w+");
	
	if(fichier == NULL || file == NULL)
	{
		printf("error");
		exit(1);
	}
	else
	{
		char *tok;
		char *token;
		
		while(fgets(line,sizeof(line),file) != NULL)
		{
			strcpy(stock,line);
			tok=strtok(line,";");
			token=strtok(NULL," ");
			
			if(strstr(tok,login) == NULL && strstr(token,pswd) == NULL)
			{
				fprintf(fichier,"%s",stock);
			}
			
		}
		rewind(fichier);
		fclose(file);
		
		file=fopen("account.txt","w+");
		while(fgets(line,sizeof(line),fichier) != NULL)
		{
			fprintf(file,"%s",line);
		
		}
		
	}
	
		
		
		
		
	
	fclose(file);
	fclose(fichier);
	
}
void start()
{
		printf("<HTML>\n"
				" <HEAD> "
				"    <TITLE>Connexion</TITLE>"
				"        <META charset=\"UTF-8\">"
				"<STYLE>"
			
				".color{"
				"  background-color:#008060;}"
				".deco{"
				"color:white;"
				"border: 1px solid #008080;"
				"border-radius:6px;"
				"background-color:#008080;"
				"padding:20px;"
				"width:30%%;"
				"height:300px;"
				"position:relative;"
				"top:100px;"
				"left:30%%;"
				"align-items:center;}"
				
				"input[type=\"password\"] {"
				" width: 100%%; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"text\"] {"
			   " width: 100%%; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"submit\"] {"
			   "   	width: 100%%; /* Largeur fixe en pixels */"
			   " 	padding: 10px;"
			   "  	border: none;"
			   " 	border-radius: 10px;"
			   " 	background-color: #28a745;"
			   "	color: #fff;"
			   "font-size: 16px;"
			   " cursor: pointer;"
			   " text-align: center;"
			   "   }"
			   "input[type=\"submit\"]:hover {"
			   "   background-color: #218838;"
			   " }"
			     ".stick img{"
			   "width: 40px; "
			   "height:autopx;"
			   "transition: opacity 0.3s;"
			   "}"
					"</STYLE>"                           
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
