#pragma once

#include <string>
#include <vector>

class Document
{
  public:

    // Add the HTML, represented by the block, to the end of the document
    void push_back(const std::string& html);

    // Return the complete contents of the HTML document that this object 
    // describes as a string 
    std::string compose() const;

    // save the HTML document to a file with the given file_name
    void save(std::string file_name) const;


  private:
    // Every document begins with the same set of HTML tags
    std::string document_head_ = 
      "<!DOCTYPE HTML>\n"
      "<html>\n"
      "<head>\n"
      " <meta charset=utf-8\n"
      " <title>Generated Document</title>\n"
      "</head>\n"
      "<body>\n";


    // Every document ends with the same HTML tag
    std::string document_tail_ = 
      "</body>\n"
      "</html>\n";
    
    // Document contents are represented by a vector of Blocks. When we create 
    // a document, we append the HTML strings in each Block together to form the 
    // document. We flank this with the document_head and document_tail, which 
    // are always the same for every HTML document
    std::vector<std::string> contents_;
};
