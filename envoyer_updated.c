#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void start();
void end();
void class_ip(int first,int second,int third,int end);
void content_type();
void recuperation_ip();
void removePluses(char *str) ;
int main()
{
	
	content_type();
	start();
	recuperation_ip();
	end();
	
	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void removePluses(char *str) 
{
    int i;
    int j = 0;
    int length = strlen(str);
    
															// Parcourez la chaîne d'origine
    for (i = 0; i < length; i++) 
    {
															// Copiez les caractères non '+' à la position 'j'
        if (str[i] != '+') 
        {
            str[j++] = str[i];
        }
    }
															// Terminez la chaîne avec un caractère null
    str[j] = '\0';
}
void recuperation_ip()
{
	char *chaine;
	char *token;
	int first;
	int second;
	int third;
	int end;
	int i=0;
	int j=0;
	int nbr=0;
	int compte=0;
	chaine=getenv("QUERY_STRING");
		
		token=strtok(chaine,"=");
		token=strtok(NULL," ");
		
		if(token != NULL)
		{
				removePluses(token);
				while(token[i] != '\0')
				{
					
					if(token[i] == '.' && token[i+1] != '\0' && token[i+1] != '.' && token[i-1] != '.'  )
					{
						nbr++;
					}	
					i++;
				}
			
				while(token[j] != '\0')
				{
						if(!isdigit(token[j]))
						{ 
							compte++;
							
						}
					j++;
					
				}
			if(compte == 3 && nbr == 3)
			{
				
				token=strtok(token,".");
				char *init=token;
				first=atoi(init);
				
				token=strtok(NULL,".");
				char *nbr_two=token;
				second=atoi(nbr_two);
				
				token=strtok(NULL,".");
				char *nbr_three=token;
				third=atoi(nbr_three);

				token=strtok(NULL,".");
				char *nbr_end=token;
				end=atoi(nbr_end);
				
				if(first > 255 || second>255 || third > 255 || end >255 )
				{
					
					
					printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
						<B>INVALID ADRESSE IP</B><DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\
						 <BR><BR>\
						  <INPUT TYPE=\"TEXT\" placeholder=\"Please retype your adress\" NAME=\"adresse\">\
						   <BR><BR>\
						   <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\" />\n\
						   </FORM></DIV>\n");
					
				}
				else
				{
					class_ip(first,second,third,end);

				}
				
				
			}
			else
			{
						printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
						<B>INVALID ADRESSE IP</B><DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\
						 <BR><BR>\
						  <INPUT TYPE=\"TEXT\" placeholder=\"Please retype your adress\" NAME=\"adresse\">\
						   <BR><BR>\
						   <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\" />\n\
						   </FORM></DIV>\n");
			}
		}
		else
		{
						printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
						<B>Please fill out the form</B><DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\
						 <BR><BR>\
						  <INPUT TYPE=\"TEXT\" placeholder=\"Your adresse\" NAME=\"adresse\">\
						   <BR><BR>\
						   <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\" />\n\
						   </FORM></DIV>\n");
		}	
	
}
void class_ip(int first,int second,int third,int end)
{
	if(first >0 && first < 128)
	{
		printf("votre adresse IP est de classe A");
	}
	else if(first >127 && first < 192)
	{
		printf("votre adresse IP est de classe B");
	}
	else if(first >191 && first < 224)
	{
		printf("votre adresse IP est de classe C");
	}
	else if(first >223 && first < 240)
	{
		printf("votre adresse IP est de classe D");
	}
	else
	{
		printf("votre adresse IP est de classe E");
	}
	
}

void start()
{
		printf("<HTML>\n"
				" <HEAD> "
				"    <TITLE>ADRESSSE IP</TITLE>"
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
				"width:500px;"
				"position:relative;"
				"top:100px;"
				"left:30%%;}"
				
				".body:{"
				"justify-content:center;"
				"align-items:center;}"
				
			   "input[type=\"text\"] {"
			   " width: 470px; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"submit\"] {"
			   "   	width: 470px; /* Largeur fixe en pixels */"
			   " 	padding: 10px;"
			   "  	border: none;"
			   " 	border-radius: 4px;"
			   " 	background-color: #28a745;"
			   "	color: #fff;"
			   "font-size: 16px;"
			   " cursor: pointer;"
			   " text-align: center;"
			   "}"
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
