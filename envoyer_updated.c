#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void start();
void end();
void class_ip(int first,int second,int third,int end);
void content_type();
void recuperation_ip();
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
	
		
		while(chaine[i] != '\0')
		{
			if(chaine[i] == '.' && (chaine[i+1] != '\0' || chaine[i+1] != '.' || chaine[i+1] != '+')  )
			{
				
				nbr++;
			}	
			i++;
		}
		token=strtok(chaine,"=");
		token=strtok(NULL," ");
		while(token[j] != '\0')
		{
			if(isalpha(token[j]))
			{ 
				compte++;
			}
			j++;
			
		}
	if(nbr == 3 && compte == 0)
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
			printf("Invalid Adress IP");
			
			printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
				<B>CLASSE D'ADRESSE IP</B>\
				 <BR><BR>\
				  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre adresse\" NAME=\"adresse\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Envoyer\" />\n\
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
				<B>VEUILLEZ RETAPER VOTRE ADRESSE IP</B>\
				 <BR><BR>\
				  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre adresse\" NAME=\"adresse\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Envoyer\" />\n\
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
				"height:200px;"
				"position:relative;"
				"top:100px;"
				"left:420px;}"
				
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
			"   }"
			"input[type=\"submit\"]:hover {"
			"   background-color: #218838;"
			" }"
				"</STYLE>"                           
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
