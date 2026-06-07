#include "cpp_html_generator/Document.hpp"
#include "cpp_html_generator/HTMLElement.hpp"

#include <memory>

int main() {
  Document doc;

  std::unique_ptr<HTMLElement> paragraph = create_element("p");
  paragraph->contents("Hello from C++! This document was generated.");
  doc.push_back(paragraph);

  std::unique_ptr<HTMLElement> button = create_element("button");
  button->contents("Click me");
  doc.push_back(button);

  std::unique_ptr<HTMLElement> signature = create_element("p");
  signature->contents("Made by Keenan.");
  doc.push_back(signature);

  doc.save("generated/index.html");
}
