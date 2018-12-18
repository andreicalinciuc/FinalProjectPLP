//
// Created by andrei on 10.12.2018.
//

#include "HtmlParsing.h"
#include <iostream>
#include <cstring>
#include<vector>
#include <fstream>
#include <algorithm>
using namespace std;


string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

void HtmlParsing::ReadFile() {
    FILE* fp = fopen("/home/andrei/Documents/FinalProjectPLP/Final project/date.txt", "r");
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
    myfile.open ("/home/andrei/Documents/FinalProjectPLP/Final project/test.html");
    myfile<<"<!DOCTYPE html>\n"<<endl<<
            "<html>\n"<<endl<<
            "<head>"<<endl<<
            "</head>"<<endl<<
             "<body>"<<endl;

    while (token)
    {
            string str=  ReplaceAll(token,"<","&lt;");
            str=  ReplaceAll(str,"/>","/&gt;");

        myfile<<"<pre>"<<str<<"</pre>"<<endl;
            token = strtok(NULL,"\n");
    }

    myfile << "\n"
              "</body>\n"<<endl<<
              "</html>"<<endl;
    myfile.close();
}




