#include "cpp_html_generator/Document.hpp"

#include <fstream>
#include <stdexcept>

// Each block represents some object that can be described in HTML. When we push 
// a block to our document, we are adding the block to the end of the Documents
// body. When the document is created or saved, we will generate the HTML described 
// by the blocks and add them to the body of the Document in order
void Document::push_back(const std::string& html)
{
  contents_.push_back(html);
}

void Document::push_back(const std::unique_ptr<HTMLElement>& element)
{
  contents_.push_back(element->render());
}

// Each Document is represented by a header, footer, and vector of Blocks. When we 
// create a document, we return a string that composes our HTML document. The string 
// will always start with the document_head and end with the document_tail. Anything
// in between, in the body of the document, comes from a Block
std::string Document::compose() const
{
  // All documents begin with the same head
  std::string document = document_head_;
  
  // Add the html described by each block to the contents of the document's body in 
  // the same order that the blocks were added
  for (const std::string& html : contents_) { document += html; }

  // All documents end with the same tail
  document.append(document_tail_);
  return document;
}

// save the HTML document to a file with the given file_name
void Document::save(std::string file_name) const
{
  // initialize the output file using the givin file_name. If the file does not end with 
  // the .html extension, then add it to the filename 
  if (file_name.length() < 5 || file_name.substr(file_name.length() - 5) != ".html")
  {
    file_name.append(".html");
  }

  // initialize the output file stream and verify the file is open
  std::ofstream html_file(file_name);

  // throw an error if we are unable to open the file
  if (!html_file)
  {
    throw std::runtime_error("Could not open file: " + file_name);
  }
  
  // write document contents into the html_file
  html_file << compose();
}
