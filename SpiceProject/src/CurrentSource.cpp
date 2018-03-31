/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */

#include "SPICE/CurrentSource.h"
#include <sstream>

//source code goes here
CurrentSource::CurrentSource(const std::string *componentNames, std::stringstream &restOfLine, std::map<std::string, Node> &myMap)
 : Component::Component(componentNames, myMap) {
  //we use the first argument to call the component constructor 

  //This part of the cconstructor only needs to worry about its special eleements
  std::string tempString;
  restOfLine >> tempString;
  Suffix tempSuff;
  dcVal_ = getValueFromString(tempString, tempSuff);
  dcSuff_ = tempSuff;
  tempString = "";
  restOfLine >> tempString;
  acVal_ = getValueFromString(tempString, tempSuff);
  acSuff_ = tempSuff;
  tempString = "";
  restOfLine >> tempString;
  freq_ = getValueFromString(tempString, tempSuff);
  freqSuff_ = tempSuff;
}
std::ostream& operator<<(std::ostream &os, const CurrentSource &cs) {
  //the ostreaam for Current sources
  os << cs.name_ << " ";
  os << "Current" << " ";
  os << "DC = " << cs.dcVal_ << cs.dcSuff_;
  os << "AC = " << cs.acVal_ << cs.acSuff_;
  os << "FREQ = " << cs.freq_ << cs.freqSuff_;
  return os;
} 