
// MFCApplicationGUIView.cpp: реализация класса CMFCApplicationGUIView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplicationGUI.h"
#endif

#include "MFCApplicationGUIDoc.h"
#include "MFCApplicationGUIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


// CMFCApplicationGUIView

IMPLEMENT_DYNCREATE(CMFCApplicationGUIView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationGUIView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplicationGUIView


CMFCApplicationGUIView::CMFCApplicationGUIView() noexcept
{
	// TODO: добавьте код создания
	printf("\nHello world!\n");
	std::cout << "It works!" << endl;
	std::cout << "это по русски!ЭТО ПО РУССКИ - THIS IS CYRILLIC" << endl;
	pCudp2Socket = new Cudp2Socket();
}

CMFCApplicationGUIView::~CMFCApplicationGUIView()
{
}

BOOL CMFCApplicationGUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMFCApplicationGUIView
	
void CMFCApplicationGUIView::OnDraw(CDC* pDC)
{
	CMFCApplicationGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	POINT point;
	COLORREF crColor = 0;
	point.x = 0;
	point.y = 0;
	/*
	const int nrolls = 10000;  // number of experiments
	const int nstars = 1000;    // maximum number of stars to distribute

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(5.0, 2.0);

	int p[90] = {};

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		pDC->SetPixelV(i,number*10, crColor);
		if ((number >= 0.0) && (number < 90.0)) ++p[int(number)];
	}

	std::cout << "normal_distribution (5.0,2.0):" << std::endl;
	
	for (int i = 0; i < 90; i += 5) {
		std::cout << i << "-" << (i + 4) << ": ";
		std::cout << p[i] * nstars / nrolls;
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
	*/
	for(unsigned int i = 0; i < 750; i++)
	{
		random_device dev;
		mt19937 rng(dev());

		uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 1600]
	  if(i<12)	cout << dist6(rng) << " =end ";
	
		point.x += 2;
		crColor++;
		point.y = 100 + dist6(rng)*5;
		pDC->SetPixelV(point, crColor);
//		pDC->TextOutW(point.x, point.y, dist6(rng));
	}
	cout << endl;

//pDoc->
	{
	}
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CMFCApplicationGUIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationGUIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}
// Диагностика CMFCApplicationGUIView

#ifdef _DEBUG
void CMFCApplicationGUIView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationGUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationGUIDoc* CMFCApplicationGUIView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationGUIDoc)));
	return (CMFCApplicationGUIDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApplicationGUIView
