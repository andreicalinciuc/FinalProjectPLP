//
// Created by andrei on 10.12.2018.
//

#include "HtmlParsing.h"
#include <iostream>
#include <cstring>
#include<vector>
#include <fstream>

using namespace std;

void HtmlParsing::ReadFile() {
    FILE* fp = fopen("/home/andrei/Documents/k/facultatate/Final project/date.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char* list = NULL;

    size_t len = 0;
    while ((getline(&list, &len, fp)) != -1) {
    strcat(line,list);

    }
    fclose(fp);

}



void HtmlParsing::CheckComand() {
    
   char*  str=line;
    char *token = strtok(str,"\n");
    ofstream myfile;
    myfile.open ("/home/andrei/Documents/k/facultatate/Final project/test.html");
    myfile<<"<!DOCTYPE html>\n"<<endl<<
            "<html>\n"<<endl<<
            "<head>"<<endl<<
            "<link rel=\"stylesheet\" type=\"text/css\" href=\"inputcss.css\">"<<endl<<
        "</head>"<<endl<<
        "<body>"<<endl;
    while (token)
    {
        cout<<token[0]<<endl;
            myfile<<"<pre>"<<token<<"</pre>"<<endl;
            token = strtok(NULL,"\n");
    }
    myfile << "\n"
              "</body>\n"<<endl<<
              "</html>"<<endl;
    myfile.close();
}

void HtmlParsing::CreateCSSFile() {
    ofstream myfile;
    myfile.open ("/home/andrei/Documents/k/facultatate/Final project/inputcss.css");

    myfile<<".k{\n"
            "    content: \"<k>\";\n"
            "}";
    myfile.close();

}


