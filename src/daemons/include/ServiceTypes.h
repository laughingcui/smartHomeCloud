/********************************************************************************
  Copyright (C), 2016-2017, Everyoo Co., Ltd.
  File name:      ServiceTypes.h
  Author: cuishiyang      Version: 0.1.0       Date: 2016/02/26
  Description:  thrift service types header file
  History:
    1. Date:
       Author:
       Modification:
    2. ...
********************************************************************************/
#ifndef _SERVICE_TYPES_H_
#define _SERVICE_TYPES_H_

#include <iosfwd>
#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>
#include <thrift/cxxfunctional.h>

#include "SharedTypes.h"

namespace service {

struct Operation {
	enum type {
		ADD = 1,
		SUBTRACT = 2,
		MULTIPLY = 3,
		DIVIDE = 4
	};
};

extern const std::map<int, const char*> _Operation_VALUES_TO_NAMES;

typedef int32_t MyInteger;

class Work;

class InvalidOperation;

typedef struct _Work__isset {
  	_Work__isset() : num1(true), num2(false), op(false), comment(false) {}
  	bool num1 :1;
  	bool num2 :1;
  	bool op :1;
  	bool comment :1;
} _Work__isset;

class Work {
 	public:
		Work(const Work&);
  		Work& operator=(const Work&);
  		Work() : num1(0), num2(0), op((Operation::type)0), comment() {
  	}
		virtual ~Work() throw();
		int32_t num1;
		int32_t num2;
		Operation::type op;
		std::string comment;
		_Work__isset __isset;

		void __set_num1(const int32_t val);
		void __set_num2(const int32_t val);
		void __set_op(const Operation::type val);
		void __set_comment(const std::string& val);

		bool operator == (const Work & rhs) const{
			if (!(num1 == rhs.num1))
				return false;
			if (!(num2 == rhs.num2))
				return false;
			if (!(op == rhs.op))
				return false;
			if (__isset.comment != rhs.__isset.comment)
				return false;
			else if (__isset.comment && !(comment == rhs.comment))
				return false;
			return true;
		}
  
		bool operator != (const Work &rhs) const {
			return !(*this == rhs);
		}
  
		bool operator < (const Work & ) const;
		uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
		uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
		virtual void printTo(std::ostream& out) const;
};

void swap(Work &a, Work &b);

inline std::ostream& operator<<(std::ostream& out, const Work& obj){
  	obj.printTo(out);
  	return out;
}

typedef struct _InvalidOperation__isset {
  	_InvalidOperation__isset() : whatOp(false), why(false) {}
  	bool whatOp :1;
  	bool why :1;
} _InvalidOperation__isset;

class InvalidOperation : public ::apache::thrift::TException {
	public:
		InvalidOperation(const InvalidOperation&);
		InvalidOperation& operator=(const InvalidOperation&);
		InvalidOperation() : whatOp(0), why() {
  
		}
 
		virtual ~InvalidOperation() throw();
		int32_t whatOp;

		std::string why;
		_InvalidOperation__isset __isset;
  
		void __set_whatOp(const int32_t val);
		void __set_why(const std::string& val);
		
		bool operator == (const InvalidOperation & rhs) const{
			if (!(whatOp == rhs.whatOp))
				return false;
			if (!(why == rhs.why))
				return false;
			return true;
		}

		bool operator != (const InvalidOperation &rhs) const {
			return !(*this == rhs);
		}
  
		bool operator < (const InvalidOperation & ) const;
		uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
		uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
		virtual void printTo(std::ostream& out) const;
		mutable std::string thriftTExceptionMessageHolder_;
		const char* what() const throw();
};

void swap(InvalidOperation &a, InvalidOperation &b);

inline std::ostream& operator<<(std::ostream& out, const InvalidOperation& obj){
  	obj.printTo(out);
  	return out;	
}

} // namespace

#endif  //_SERVICE_TYPES_H_
