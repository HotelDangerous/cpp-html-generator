#pragma once

#include <string>
#include <utility>
#include <memory>
#include <stdexcept>

// Base Class
class HTMLElement
{
  public:
    // Standard constructor
    explicit HTMLElement(std::string tag) : tag_(std::move(tag)) {}

    // Virtual distructor: Critical, allows unique_ptr to clean up derived classes
    virtual ~HTMLElement() = default;

    virtual std::string render() const = 0;

    // Getters
    std::string contents() const { return contents_; }
    std::string tag() const { return tag_; }

    // Setter
    void contents(std::string contents) { contents_ = contents; }


  protected:
    std::string tag_;
    std::string contents_;
};


// Derived Class Paragraph
class HTMLParagraph : public HTMLElement
{
  public:
    // Call the base constructor in the initializer list
    HTMLParagraph() : HTMLElement("p") {}

    std::string render() const override
    {
      return "<p>" + contents_ + "</p>\n";
    }
};


// Derived Class Button
class HTMLButton : public HTMLElement
{
  public:
    // Call the base constructor in the initializer list
    HTMLButton() : HTMLElement("button") {}

    std::string render() const override
    {
      return "<button>" + contents_ + "</button>\n";
    }
};


// HTMLElement factory function
inline std::unique_ptr<HTMLElement> create_element(const std::string& tag)
{
  if (tag == "p" || tag == "<p>" || tag == "paragraph")
  {
    return std::make_unique<HTMLParagraph>();
  }
  else if (tag == "<button>" || tag == "button")
  {
    return std::make_unique<HTMLButton>();
  }
  else
  {
    throw std::invalid_argument("Unknown tag: " + tag);
  }
}
