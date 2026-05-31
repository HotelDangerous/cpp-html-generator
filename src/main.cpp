#include "cpp_html_generator/Document.hpp"

int main() {
  Document doc;

  doc.push_back("<p>Hello from C++</p>\n");
  doc.push_back("<button>Click me</button>\n");

  doc.save("generated/index.html");
}
