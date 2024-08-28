#include <stdio.h>

void formulaire();
void content_type();
void start();
void end();

int main()
{
	
	content_type();
	start();
	formulaire();
	
	end();
	
	
	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void formulaire()
{
	printf("<DIV class=\"deco\" ><FORM ACTION=\"option.cgi\" METHOD=\"GET\">\n\
			<B>WELCOME</B>"
			" <BR><BR>"
			   " <div class=\"login-container\">\n"
			   "                <INPUT TYPE=\"TEXT\" placeholder=\"Login\" NAME=\"new_login\">\n"
			   "                <div class=\"info\">\n"
			   "                    &#9654; <!-- Symbole de flèche (▶) -->\n"
			   "                    <span class=\"tooltip\">The login must only contain letters,<BR>numbers, periods (.), and underscores (_).<BR> No spaces are allowed.</span>\n"
			   "                </div>\n"
			   "            </div>\n"
			   "<div class=\"login-container\">\n"
			   " <INPUT TYPE=\"PASSWORD\" placeholder=\"Password\" NAME=\"password\">"
			   "                <div class=\"info\">\n"
			   "                    &#9654; <!-- Symbole de flèche (▶) -->\n"
			   "                    <span class=\"tooltip\">The password cannot contain spaces</span>\n"
			   "                </div>\n"
			   " <BR><BR>"
			   " <INPUT TYPE=\"SUBMIT\" VALUE=\"Create new account\"/>\n");
			
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
				" width: 90%%; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"text\"] {"
			   " width: 90%%; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"submit\"] {"
			   "    left:3px;"
			   "   	width: 90%%; /* Largeur fixe en pixels */"
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
			   " .info {\n"
           "            position: relative;\n"
           "            display: inline-block;\n"
           "            cursor: pointer;\n"
           "            color: pink;\n"
           "            font-size: 1.5em;\n"
           "        }\n"
           "        .info:hover .tooltip {\n"
           "            visibility: visible;\n"
           "            opacity: 1;\n"
           "        }\n"
           "        .tooltip {\n"
           "            position: absolute;\n"
           "            bottom: 90%%;\n"
           "            left: 10%%;\n"
           "            transform: translateX(-100%%);\n"
           "            background-color: #333;\n"
           "            color: pink;\n"
           "            padding: 3px;\n"
           "            border-radius: 5px;\n"
           "            white-space: nowrap;\n"
           "            visibility: hidden;\n"
           "            opacity: 0;\n"
           "            transition: opacity 0.3s;\n"
           "            z-index: 1;\n"
           "        }\n"
           "        .login-container input {\n"
           "            flex: 1;\n"
           "        }\n"
			   "</STYLE></HEAD><BODY>\n");
			   
			   
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
