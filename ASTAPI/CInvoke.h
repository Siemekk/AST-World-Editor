#pragma once

#include "CHookInfo.h"
#include "CUntyped.h"

enum zTIvkMode
{
	IVK_DISABLED	= 1 << 1,
	IVK_NORMAL		= 1 << 2,
	IVK_AUTO		= 1 << 3,
	IVK_REDEFINE	= 1 << 4,
	IVK_PROTECTED	= 1 << 5,
	IVK_READONLY	= IVK_DISABLED
};

//namespace AST { /* [namespace AST] */

template <class T>
class CInvoke
{
	CHookInfo m_data;

public:

	CInvoke(const UNTYPED&, const UNTYPED& = NULL, const zINT32& = IVK_NORMAL);

			zBOOL		Attach(const UNTYPED&, const UNTYPED& = NULL, const zINT32& = IVK_NORMAL);
			zBOOL		Commit();
			zBOOL		Detach();
			zBOOL		DetachTree();
			zVOID		Protect();
			zVOID		Unprotect();
	const	CHookInfo&	GetHookInfo ();

	operator T();
};

template <class T>
CInvoke<T>::CInvoke(const UNTYPED& from, const UNTYPED& to, const zINT32& flag)
{
	Attach (from, to, flag);
}

template <class T>
zBOOL CInvoke<T>::Attach(const UNTYPED& from, const UNTYPED& to, const zINT32& flag)
{
	// abort operation if current hook already exist
	if (CCallBack::IsExist (m_data))
		return FALSE;

	// set armor to this hook
	m_data.Protected = (flag & IVK_PROTECTED) != 0;

	// replace address in auto mode
	if (flag & IVK_AUTO)	m_data.Original	= (T)CCallBack::Auto((zUINT32)from.data);
	else					m_data.Original	= (T)from.data;

	m_data.Pointer	= m_data.Original;
	m_data.Detour	= to;

	if(!to || (flag & IVK_DISABLED))
		return FALSE;

	// redefine hook to this
	if (flag & IVK_REDEFINE)
		return CCallBack::Redefine(m_data);
	// create hook
	return CCallBack::Attach(m_data);
}

template <class T>
zBOOL CInvoke<T>::Commit()
{
	return CCallBack::Commit (m_data);
}

template <class T>
zBOOL CInvoke<T>::Detach()
{
	return CCallBack::Detach(m_data);
}

template <class T>
zBOOL CInvoke<T>::DetachTree()
{
	return CCallBack::DetachTree(m_data);
}

template <class T>
zVOID CInvoke<T>::Protect()
{
	m_data.Protected = TRUE;
}

template <class T>
zVOID CInvoke<T>::Unprotect()
{
	m_data.Protected = FALSE;
}

template <class T>
const CHookInfo& CInvoke<T>::GetHookInfo()
{
	return m_data;
}

template <class T>
CInvoke<T>::operator T()
{
	return (T&)m_data.Pointer;
}