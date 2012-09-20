// liblitexml.
#pragma once

#include <string>
#include <stdexcept>

namespace LiteXML
{
 class liblitexml {
 public:
  __declspec(dllexport) liblitexml(std::string f);
  __declspec(dllexport) ~liblitexml();

  // Returns a + b
        static double __declspec(dllexport) Add(double a, double b);

 private:
  char *memblock;
 };

 class LiteXMLException
 {
 public:
  __declspec(dllexport) LiteXMLException(std::string why) : why(why) {}
  std::string __declspec(dllexport) virtual what();
 private:
  std::string why;
 };

 class IOException : public LiteXMLException
 {
 public:
  __declspec(dllexport) IOException(std::string why) : LiteXMLException(why) {}
  std::string __declspec(dllexport) virtual what();
 };

}