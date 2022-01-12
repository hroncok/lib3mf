/*++

Copyright (C) 2019 3MF Consortium

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

Abstract:

NMR_ModelWriterNode_KeyStore.h defines the Model Writer KeyStore Node Class.
This is the class for exporting the 3mf keystore stream root node.

--*/

#ifndef __NMR_MODELWRITERNODE_KEYSTORE
#define __NMR_MODELWRITERNODE_KEYSTORE

#include "Model/Classes/NMR_KeyStore.h" 
#include "Model/Writer/NMR_ModelWriterNode_KeyStoreBase.h" 

namespace NMR {

	class CModelWriterNode_KeyStore : public CModelWriterNode_KeyStoreBase {
	private:
		std::map<PKeyStoreConsumer, nfUint64> m_consumerIndexes;

		nfUint64 m_CustomNameSpaceID;
		std::map<std::string, std::string> m_customNameSpaces;

		std::string registerNameSpace(const std::string & sNameSpace);

	protected:
		void writeWrapAlgorithmAttribute(eKeyStoreWrapAlgorithm ea);
		void writeMgf(eKeyStoreMaskGenerationFunction mgf);
		void writeDigest(eKeyStoreMessageDigest md);
		void writeEncryptionAlgorithmAttribute(eKeyStoreEncryptAlgorithm ea);
		void writeConsumers();
		void writeResourceDatagroup();
		void writeAccessRight(PKeyStoreAccessRight const & ar);
		void writeResourceData(PKeyStoreResourceData const & rd);
	public:
		CModelWriterNode_KeyStore(_In_ CXmlWriter* pXMLWriter, _In_ PProgressMonitor pProgressMonitor, _In_ PKeyStore pKeyStore);
		CModelWriterNode_KeyStore() = delete;
		virtual void writeToXML();
	};

}

#endif // __NMR_MODELWRITERNODE_KEYSTORE
