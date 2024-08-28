#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void end();
void start();
void content_type();
void display();
int main()
{
	content_type();
	start();
	display();
	end();
	

	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void display()
{
	
	char *chaine;
	char *token;
	char *opt;
	chaine=getenv("QUERY_STRING");
	
	token=strtok(chaine,"/");
	opt=strtok(NULL," ");

		
		if( token!= NULL )
		{
			printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
				<B>IP address class</B>\
				 <BR><BR>\
				  <INPUT TYPE=\"TEXT\" placeholder=\"192.29.100.6\" NAME=\"adresse\">\
				   <BR><BR>\
				   <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\" />\n\
				   </FORM>\n\
					<DIV class=\"connect\"><A HREF=\"settings.cgi?%s\"><DIV class=\"link\">Settings<DIV></A>\
					</DIV></DIV>",opt);
				   
			
		}   
		else
		{
					printf("<div class=\"container\">\n");
					printf("<h1>Please log in!</h1>\n");
					printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
					printf("<DIV class=\"cont\" ><DIV class=\"connect\"><A HREF=\"log.cgi\"><DIV class=\"link\">TRY AGAIN/RETURN</DIV></A></DIV></DIV></DIV>");
			
			
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
				"width:30%%;"
				"height:200px;"
				"position:relative;"
				"top:100px;"
				"left:30%%;"
				"align-items:center;}"
				
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
			   " 	border-radius: 4px;"
			   " 	background-color: #28a745;"
			   "	color: #fff;"
			   "font-size: 16px;"
			   " cursor: pointer;"
			   " text-align: center;"
			"   }"
			"input[type=\"submit\"]:hover {"
			"   background-color: #218838;"
			".container {\n"
			"	font-size:15px;"
			"    width: 80%%;\n"
			"    margin: auto;\n"
			"    padding: 20px;\n"
			"    background: white;\n"
			"    border-radius: 8px;\n"
			"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n"
			"}\n"
			 ".connect{"
			 
			   "	width:50%%;"
			   "    padding:3px;"
			   "	border: 1px solid pink;"
			   " 	border-radius: 20px;"
			   "    background-color:#0080ff;\n"
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
			   ".stick img"
				"{"
					"width: 30px; "
					"height: auto;"
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

