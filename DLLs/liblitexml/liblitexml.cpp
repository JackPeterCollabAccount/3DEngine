#pragma once

#include "liblitexml.h"
#include <fstream>

namespace LiteXML {

 liblitexml::liblitexml(std::string f) 
 {
  this->memblock = NULL;
  std::fstream file;

  try
  {
   file.open (f, std::ios::in);

   if(file.is_open())
   {
    std::ifstream::pos_type size;
    size = file.tellg();
    this->memblock = new char[static_cast<unsigned int>(size)];
    file.read(this->memblock, size);
    file.close();
   }
   else
   {
    file.close();
    throw IOException("File is not open for reading");
   }
  }
  catch(...)
  {
   file.close();
   throw IOException("Error opening file");
  }
 }

 liblitexml::~liblitexml()
 {
  if(this->memblock != NULL)
  {
   delete[] this->memblock;
   this->memblock = NULL;
  }
 }

 double liblitexml::Add(double a, double b)
 {
  return a + b;
 }

 std::string LiteXMLException::what()
 {
  return this->why;
 }

 std::string IOException::what()
 {
  return LiteXMLException::what();
 }
}