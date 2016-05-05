/*************************************************************************
  Copyright (C), 2016-2017, Everyoo Co., Ltd.
  FileName: SharedTypes.cpp
  Author: cuishiyang       Version : 0.1.0          Date: 2016/02/26
  Description:    thrift shared types cpp file      
  Version:         0.1.0
  History:         
      <author>           <time>           <version >       <desc>
      cuishiyang          2016/02/26        0.1.0        create this file 
*************************************************************************/
#include <algorithm>
#include <ostream>
#include <thrift/TToString.h>

#include "SharedTypes.h"

namespace shared {


SharedStruct::~SharedStruct() throw() {}

void SharedStruct::__set_key(const int32_t val) {
	this->key = val;
}

void SharedStruct::__set_value(const std::string& val) {
 	 this->value = val;
}

uint32_t SharedStruct::read(::apache::thrift::protocol::TProtocol* iprot) {

 	apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  	uint32_t xfer = 0;
  	std::string fname;
  	::apache::thrift::protocol::TType ftype;
  	int16_t fid;

  	xfer += iprot->readStructBegin(fname);

  	using ::apache::thrift::protocol::TProtocolException;

  while (true){
    	xfer += iprot->readFieldBegin(fname, ftype, fid);
    	if (ftype == ::apache::thrift::protocol::T_STOP) {
			break;
    	}
   
		switch (fid){
      
			case 1:
     
				if (ftype == ::apache::thrift::protocol::T_I32) {
					xfer += iprot->readI32(this->key);
					this->__isset.key = true;
				} else {
					xfer += iprot->skip(ftype);
				}
				break;
  
			case 2:
    
				if (ftype == ::apache::thrift::protocol::T_STRING) {
					xfer += iprot->readString(this->value);
					this->__isset.value = true;
				} else {
					xfer += iprot->skip(ftype);
				}
				break;
 
			default:
				xfer += iprot->skip(ftype);
				break;
		}
		xfer += iprot->readFieldEnd();
  }
  
  xfer += iprot->readStructEnd();
 
  return xfer;
}

uint32_t SharedStruct::write(::apache::thrift::protocol::TProtocol* oprot) const {
  	uint32_t xfer = 0;
  	apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  	xfer += oprot->writeStructBegin("SharedStruct");

  	xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_I32, 1);
  	xfer += oprot->writeI32(this->key);
  	xfer += oprot->writeFieldEnd();

  	xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  	xfer += oprot->writeString(this->value);
  	xfer += oprot->writeFieldEnd();

  	xfer += oprot->writeFieldStop();
  	xfer += oprot->writeStructEnd();
  	return xfer;
}

void swap(SharedStruct &a, SharedStruct &b) {
  	using ::std::swap;
  	swap(a.key, b.key);
  	swap(a.value, b.value);
  	swap(a.__isset, b.__isset);
}

SharedStruct::SharedStruct(const SharedStruct& other0) {
  	key = other0.key;
  	value = other0.value;
  	__isset = other0.__isset;
}

SharedStruct& SharedStruct::operator=(const SharedStruct& other1) {
  	key = other1.key;
  	value = other1.value;
  	__isset = other1.__isset;
  	return *this;
}

void SharedStruct::printTo(std::ostream& out) const {
  	using ::apache::thrift::to_string;
  	out << "SharedStruct(";
  	out << "key=" << to_string(key);
  	out << ", " << "value=" << to_string(value);
  	out << ")";
}

} // namespace
