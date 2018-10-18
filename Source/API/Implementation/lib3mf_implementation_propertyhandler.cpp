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

Abstract: This is a stub class definition of CInternalLib3MFPropertyHandler
Interface version: 1.2.2

*/

#include "lib3mf_implementation_propertyhandler.hpp"
#include "lib3mf_interfaceexception.hpp"

// Include custom headers here.


using namespace Lib3MF;

/*************************************************************************************************************************
 Class definition of CInternalLib3MFPropertyHandler 
**************************************************************************************************************************/

void CInternalLib3MFPropertyHandler::RemoveProperty (const unsigned int nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::RemoveAllProperties ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

eLib3MFPropertyType CInternalLib3MFPropertyHandler::GetPropertyType (const unsigned int nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::GetBaseMaterial (const unsigned int nIndex, unsigned int & nMaterialGroupId, unsigned int & nMaterialIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetBaseMaterial (const unsigned int nIndex, const unsigned int nMaterialGroupId, const unsigned int nMaterialIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetBaseMaterialArray (const unsigned int nMaterialGroupIdsBufferSize, const unsigned int * pMaterialGroupIdsBuffer, const unsigned int nMaterialIndicesBufferSize, const unsigned int * pMaterialIndicesBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::GetBaseMaterialArray (unsigned int nMaterialGroupIdsBufferSize, unsigned int * pMaterialGroupIdsNeededCount, unsigned int * pMaterialGroupIdsBuffer, unsigned int nMaterialIndicesBufferSize, unsigned int * pMaterialIndicesNeededCount, unsigned int * pMaterialIndicesBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetSingleColor (const unsigned int nIndex, const sLib3MFColorRGBA Color)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetSingleColorRGB (const unsigned int nIndex, const unsigned char nRed, const unsigned char nGreen, const unsigned char nBlue)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetSingleColorRGBA (const unsigned int nIndex, const unsigned char nRed, const unsigned char nGreen, const unsigned char nBlue, const unsigned char nAlpha)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetSingleColorFloatRGB (const unsigned int nIndex, const float fRed, const float fGreen, const float fBlue)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CInternalLib3MFPropertyHandler::SetSingleColorFloatRGBA (const unsigned int nIndex, const float fRed, const float fGreen, const float fBlue, const float fAlpha)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

