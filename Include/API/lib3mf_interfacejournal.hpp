/*++

Copyright (C) 2018 3MF Consortium (Original Author)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract: This is an autogenerated C++ header file in order to allow easy
development of the 3MF Library. It provides an automatic Journaling mechanism for the library implementation.
Interface version: 1.2.2

*/

#ifndef __LIB3MF_INTERFACEJOURNAL_HEADER
#define __LIB3MF_INTERFACEJOURNAL_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <list>
#include <mutex>
#include <chrono>
#include "lib3mf_types.h"

/*************************************************************************************************************************
 Class CLib3MFInterfaceJournal 
**************************************************************************************************************************/

class CLib3MFInterfaceJournal;

class CLib3MFInterfaceJournalEntry {

	protected:

		CLib3MFInterfaceJournal * m_pJournal;
		Lib3MFResult m_ErrorCode;
		std::string m_sClassName;
		std::string m_sMethodName;
		std::string m_sInstanceHandle;
		unsigned long long m_nInitTimeStamp;
		unsigned long long m_nFinishTimeStamp;
		std::list<std::pair<std::pair<std::string, std::string>, std::string>> m_sParameters;
		std::list<std::pair<std::pair<std::string, std::string>, std::string>> m_sResultValues;	

		std::string getXMLString();
		void addParameter (const std::string & sName, const std::string & sParameterType, const std::string & sParameterValue);
		void addResult (const std::string & sName, const std::string & sResultType, const std::string & sResultValue);

	public:
		CLib3MFInterfaceJournalEntry(CLib3MFInterfaceJournal * pJournal, std::string sClassName, std::string sMethodName, Lib3MFHandle pInstanceHandle);
		~CLib3MFInterfaceJournalEntry();

		void writeSuccess ();
		void writeError (Lib3MFResult nErrorCode);

		void addBooleanParameter(const std::string & sName, const bool bValue);
		void addUInt8Parameter(const std::string & sName, const unsigned char nValue);
		void addUInt16Parameter(const std::string & sName, const unsigned short nValue);
		void addUInt32Parameter(const std::string & sName, const unsigned int nValue);
		void addUInt64Parameter(const std::string & sName, const unsigned long long nValue);
		void addFloatParameter(const std::string & sName, const float fValue);
		void addDoubleParameter(const std::string & sName, const double dValue);
		void addStringParameter(const std::string & sName, const char * pValue);
		void addHandleParameter(const std::string & sName, const Lib3MFHandle pHandle);
		void addEnumParameter(const std::string & sName, const std::string & sEnumType, unsigned int nValue);

		void addBooleanResult(const std::string & sName, const bool bValue);
		void addUInt8Result(const std::string & sName, const unsigned char nValue);
		void addUInt16Result(const std::string & sName, const unsigned short nValue);
		void addUInt32Result(const std::string & sName, const unsigned int nValue);
		void addUInt64Result(const std::string & sName, const unsigned long long nValue);
		void addFloatResult(const std::string & sName, const float fValue);
		void addDoubleResult(const std::string & sName, const double dValue);
		void addStringResult(const std::string & sName, const char * pValue);
		void addHandleResult(const std::string & sName, const Lib3MFHandle pHandle);
		void addEnumResult(const std::string & sName, const std::string & sEnumType, unsigned int nValue);

		friend class CLib3MFInterfaceJournal;

};

typedef std::shared_ptr<CLib3MFInterfaceJournalEntry> PLib3MFInterfaceJournalEntry;



class CLib3MFInterfaceJournal {

	protected:

		std::string m_sFileName;
		std::mutex m_Mutex;
		std::ofstream m_Stream;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
		void writeEntry (CLib3MFInterfaceJournalEntry * pEntry);
		unsigned long long getTimeStamp ();

	public:

		CLib3MFInterfaceJournal (const std::string & sFileName);
		~CLib3MFInterfaceJournal ();
		PLib3MFInterfaceJournalEntry beginClassMethod (const Lib3MFHandle pHandle, const std::string & sClassName, const std::string & sMethodName);
		PLib3MFInterfaceJournalEntry beginStaticFunction (const std::string & sMethodName);
		friend class CLib3MFInterfaceJournalEntry;
};

typedef std::shared_ptr<CLib3MFInterfaceJournal> PLib3MFInterfaceJournal;

#endif // __LIB3MF_INTERFACEJOURNAL_HEADER

