#ifndef __UIRESOURCEMANAGER_H__
#define __UIRESOURCEMANAGER_H__
#pragma once

namespace DuiLib {
	// �ؼ����ֲ�ѯ�ӿ�
	class UILIB_API IQueryControlText
	{
	public:
		virtual LPCTSTR QueryControlText(LPCTSTR lpstrId, LPCTSTR lpstrType) = 0;
	};

	class UILIB_API CResourceManager
	{
	private:
		CResourceManager(void);
		~CResourceManager(void);

	public:
		static CResourceManager* GetInstance()
		{
			return &m_Instance;
		};

	public:
		BOOL LoadResource(STRINGorID xml, LPCTSTR type = NULL);
		BOOL LoadResource(CMarkupNode Root);
		void ResetResourceMap();
		LPCTSTR GetImagePath(LPCTSTR lpstrId);
		LPCTSTR GetXmlPath(LPCTSTR lpstrId);

	public:
		void SetLanguage(LPCTSTR pstrLanguage) { m_sLauguage = pstrLanguage; }
		LPCTSTR GetLanguage() { return m_sLauguage; }
		BOOL LoadLanguage(LPCTSTR pstrXml);

	public:
		void SetTextQueryInterface(IQueryControlText* pInterface) { m_pQuerypInterface = pInterface; }
		CDuiString GetText(LPCTSTR lpstrId, LPCTSTR lpstrType = NULL);
		void ReloadText();
		void ResetTextMap();

	private:
		static CResourceManager m_Instance;
		CStdStringPtrMap m_mTextResourceHashMap;
		IQueryControlText*	m_pQuerypInterface;
		CStdStringPtrMap m_mImageHashMap;
		CStdStringPtrMap m_mXmlHashMap;
		CMarkup m_xml;
		CDuiString m_sLauguage;
		CStdStringPtrMap m_mTextHashMap;
	};

} // namespace DuiLib

#endif // __UIRESOURCEMANAGER_H__