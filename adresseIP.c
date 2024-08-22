#include <stdio.h>

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
	FILE *fichier=NULL;
	fichier=fopen("file.html","r");
	
	if(fichier == NULL)
	{
		printf("ERROR");
	}
	else
	{
		printf("<DIV class=\"deco\" ><FORM ACTION=\"envoyer.cgi\" METHOD=\"GET\">\n\
			<B>CLASSE D'ADRESSE IP</B>\
			 <BR><BR>\
			  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre adresse\" NAME=\"adresse\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Envoyer\" />\n\
			   </FORM></DIV>\n");
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

