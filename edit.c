#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void end();
void start();
void content_type();
void fonction();
void edit_login(char *word);
void edit_password(char *name);
void delete(char *name);
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
	char *chaine;
	char *token;
	char *name;
	chaine=getenv("QUERY_STRING");
	
	token=strtok(chaine,"/");
	name=strtok(NULL," ");
	
	if(strcmp(token,"login") == 0)
	{
		edit_login(name);
		
	}
	else if(strcmp(token,"pswd") == 0)
	{
		
		edit_password(name);
	}
	else if(strcmp(token,"delete") == 0)
	{
		
		delete(name);
	}
	
	
}
void edit_login(char *name)
{
	printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
			<B>Edit login</B>\
			 <BR><BR>\
			 New login:<BR>\
			  <INPUT TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"login %s name\">\
			  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
			   </FORM></DIV>\n",name,name);
	
}
void edit_password(char *name)
{
	printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
			<B>Edit Password</B>\
			 <BR><BR>\
			 Old password:<BR>\
			  <INPUT TYPE=\"PASSWORD\"  NAME=\"pswd %s old_pswd\">\
			  New password:<BR>\
			  <INPUT TYPE=\"PASSWORD\" NAME=\"pswd\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modify\" />\n\
			   </FORM></DIV>\n",name);	
	
	
}
void delete(char *name)
{
	
	printf("<DIV class=\"deco\" ><FORM ACTION=\"action.cgi\" METHOD=\"GET\">\n\
			<B>Delete the account</B>\
			 <BR><BR>\
			 Password:<BR>\
			  <INPUT TYPE=\"PASSWORD\"  NAME=\"delete %s pswd\">\
			   <BR><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Delete the account\"/>\n\
			   </FORM></DIV>\n",name);
	
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
					"</STYLE>"                           
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}


