
// MFCApplicationGUIView.h: интерфейс класса CMFCApplicationGUIView
//

#pragma once
#include "Cudp2Socket.h"


class CMFCApplicationGUIView : public CView
{
protected: // создать только из сериализации
	CMFCApplicationGUIView() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationGUIView)

// Атрибуты
public:
	CMFCApplicationGUIDoc* GetDocument() const;
	Cudp2Socket* pCudp2Socket;

// Операции
public:

protected:
// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
// Реализация

public:
	virtual ~CMFCApplicationGUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MFCApplicationGUIView.cpp
inline CMFCApplicationGUIDoc* CMFCApplicationGUIView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationGUIDoc*>(m_pDocument); }
#endif

