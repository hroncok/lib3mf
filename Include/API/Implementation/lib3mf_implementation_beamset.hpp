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

Abstract: This is the class declaration of CInternalLib3MFBeamSet
Interface version: 1.2.2

*/


#ifndef __LIB3MF_LIB3MFBEAMSET
#define __LIB3MF_LIB3MFBEAMSET

#include "lib3mf_interfaces.hpp"


// Include custom headers here.


namespace Lib3MF {


/*************************************************************************************************************************
 Class declaration of CInternalLib3MFBeamSet 
**************************************************************************************************************************/

class CInternalLib3MFBeamSet : public virtual IInternalLib3MFBeamSet {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	void SetName (const std::string sName);

	std::string GetName ();

	void SetIdentifier (const std::string sIdentifier);

	std::string GetIdentifier ();

	unsigned int GetReferenceCount ();

	void SetReferences (const unsigned int nReferencesBufferSize, const unsigned int * pReferencesBuffer);

	void GetReferences (unsigned int nReferencesBufferSize, unsigned int * pReferencesNeededCount, unsigned int * pReferencesBuffer);

};

}

#endif // __LIB3MF_LIB3MFBEAMSET
