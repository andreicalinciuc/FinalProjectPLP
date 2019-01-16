//
// Created by andrei on 10.12.2018.
//

#include "HtmlParsing.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;
struct elements{
    string tag;
    string str;

}e[5000];
string ReplaceAll(std::string str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}
string GetTag(char tag[1024]){
    char name_tag[1024]="\0";
    int    size=0;
    bzero(name_tag,1024);

    for (int i = 0; i < strlen(tag); i++)
        if (tag[0] == '/') {
            if (tag[i] != ' ')
            {
                if(tag[i]!='/' && tag[i]!='<' && tag[i]!='>' && tag[i]!=':')
                    name_tag[size++]=tag[i];

            }
            else
            {

                break;
            }
        }
    return name_tag;
}

string GetValues(char lines[1024])
{
    char name_tag[1024]="\0";
    int    size=0;
    bzero(name_tag,1024);
    int poz_rec=0;
    for (int i = 0; i < strlen(lines); i++)
    {
        if(lines[i]==' ' || lines[i]=='<')
        {
            poz_rec=i;
            break;
        }


    }

    for (int i = poz_rec; i < strlen(lines); i++)
        cout<<lines[i];



        return name_tag;

}
void HtmlParsing::ReadFile() {
    FILE *fp = fopen("../date.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char *list = NULL;
    char *tag = NULL;
    size_t len = 0;
    int cnt=0;
    while ((getline(&list, &len, fp)) != -1) {

        strcat(line, list);
        tag = list;
        e[cnt].tag=GetTag(tag);
        e[cnt++].str=GetValues(list);


    }
    fclose(fp);
}


void HtmlParsing::CheckComand() {

    char *str = line;
    char *token = strtok(str, "\n");
    ofstream myfile;
    myfile.open("../test.html");
    myfile << "<!DOCTYPE html>\n" << endl <<
           "<html>\n" << endl <<
           "<head>" << endl << "<link rel=\"stylesheet\" type=\"text/css\" href=\"test.css\">"

                               "</head>" << endl <<
           "<body>" << endl;
    myfile << "<pre>";
    while (token) {
        string str = ReplaceAll(token, "<", "&lt;");
        str = ReplaceAll(str, "/>", "/&gt;");

        myfile << str << endl;
        token = strtok(NULL, "\n");
    }
    myfile << "</pre>";

    myfile << "\n"
              "</body>\n" << endl <<
           "</html>" << endl;
    myfile.close();
}




