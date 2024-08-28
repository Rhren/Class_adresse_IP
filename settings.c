#include <stdio.h>
#include <stdlib.h>



void end();
void start();
void content_type();

int main()
{
	content_type();
	start();
	end();
	

	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void start()
{
	char *chaine;
	chaine=getenv("QUERY_STRING");
	
		printf("<HTML>\n"
				" <HEAD> "
				"    <TITLE>Connexion</TITLE>"
				"        <META charset=\"UTF-8\">"
				"<STYLE>"

				".deco{"
				"	color:white;"
				"	border: 1px solid  #34495e ;"
				"	border-radius:6px;"
				"	background-color: #34495e ;"
				"	padding:20px;"
				"	width:30%%;"
				"	height:auto;"
				"	position:relative;"
				"	top:5%%;"
				"}"
				"        .container {"
			   "            display: flex;"
			   "            flex-direction: column;"
			   "            align-items: center;"
			   "            justify-content: center;"
			   "            height: 100vh;"
			   "        }"
			   "        .item {"
			   "			color:pink;"
			   "            margin: 20px 0;"
			   "            padding: 10px;"
			   "			gap:2px;"
			   "            border:1px solid  #2ecc71;"
			   "            border-radius: 4px;"
			   "            width: 80%%;"
			   "            text-align: center;"
			   "        }"
			   ".item:hover"
			   "{"
			   "	 background-color: #2ecc71  ;}"
			   ".link{"
			   "	text-decoration:none;"
			   "	color:pink;}"
			   ".link:hover{"
			   "	color:Blue;}"
			   "    </STYLE>"
			   "</HEAD>\n"
			   "<BODY>\n"
			   "    <DIV class=\"container\">\n"
			   "        <DIV class=\"deco\">\n"
			   "            <DIV class=\"item\"><A HREF=\"edit.cgi?login/%s\"><DIV class=\"link\">Edit login</DIV></A></DIV>\n"
			   "            <DIV class=\"item\"><A HREF=\"edit.cgi?pswd/%s\"><DIV class=\"link\">Edit password</DIV></A></DIV>\n"
			   "            <DIV class=\"item\"><A HREF=\"edit.cgi?delete/%s\"><DIV class=\"link\">Delete the account</DIV></A></DIV>\n"
			   "            <!-- Add more items as needed -->\n"
			   "        </DIV>\n"
			   "    </DIV>\n"
			   "</BODY>\n"
			   "</HTML>\n",chaine,chaine,chaine);
						
			 
			   
			   
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}				
				
				
				
				
				
				
