

#include "lib3mf_resourcedatagroup.hpp"
#include "lib3mf_interfaceexception.hpp"

#include "lib3mf_consumer.hpp"
#include "lib3mf_accessright.hpp"

#include "Model/Classes/NMR_KeyStoreFactory.h"
namespace Lib3MF {
	namespace Impl {
		CResourceDataGroup::CResourceDataGroup(NMR::PKeyStoreResourceDataGroup const & dg)
		: m_pDataGroup(dg)
		{
			if (!dg)
				throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
		}

		IAccessRight * CResourceDataGroup::AddAccessRight(IConsumer * pConsumer, const Lib3MF::eWrappingAlgorithm eWrappingAlgorithm, const Lib3MF::eMgfAlgorithm eMgfAlgorithm, const Lib3MF::eDigestMethod eDigestMethod) {
			CConsumer * c = dynamic_cast<CConsumer *>(pConsumer);
			if (nullptr == c)
				throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
			NMR::PKeyStoreAccessRight ar = NMR::CKeyStoreFactory::makeAccessRight(
				c->consumer(), 
				(NMR::eKeyStoreWrapAlgorithm)eWrappingAlgorithm, 
				(NMR::eKeyStoreMaskGenerationFunction)eMgfAlgorithm, 
				(NMR::eKeyStoreMessageDigest)eDigestMethod);
			m_pDataGroup->addAccessRight(ar);
			return new CAccessRight(ar);
		}

		IAccessRight * CResourceDataGroup::FindAccessRightByConsumer(IConsumer * pConsumerInstance) {
			NMR::PKeyStoreAccessRight ar = m_pDataGroup->findAccessRightByConsumerID(pConsumerInstance->GetConsumerID());
			if (!ar)
				return nullptr;
			return new CAccessRight(ar);
		}

		void CResourceDataGroup::RemoveAccessRight(IConsumer * pConsumerInstance) {
			m_pDataGroup->removeAccessRight(pConsumerInstance->GetConsumerID());
		}

		std::string CResourceDataGroup::GetKeyUUID() {
			return m_pDataGroup->getKeyUUID()->toString();
		}

		void CResourceDataGroup::AddCustomInformation(const std::string& sNameSpace, const std::string& sName, const std::string& sValue)
		{
			m_pDataGroup->customInformation()->add (sNameSpace, sName, sValue);
		}

		bool CResourceDataGroup::HasCustomInformation(const std::string& sNameSpace, const std::string& sName)
		{
			return m_pDataGroup->customInformation()->has (sNameSpace, sName);
		}

		bool CResourceDataGroup::RemoveCustomInformation(const std::string& sNameSpace, const std::string& sName)
		{
			return m_pDataGroup->customInformation()->remove (sNameSpace, sName);
		}
	
		std::string CResourceDataGroup::GetCustomInformation(const std::string& sNameSpace, const std::string& sName)
		{
			if (!m_pDataGroup->customInformation()->has (sNameSpace, sName))
				throw ELib3MFInterfaceException( LIB3MF_ERROR_CUSTOMINFORMATIONNOTFOUND);

			return m_pDataGroup->customInformation()->get (sNameSpace, sName);

		}

	}
}