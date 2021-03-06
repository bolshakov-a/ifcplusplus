// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// IfcQueryMFCView.h : interface of the CIfcQueryMFCView class
//

#pragma once
#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include <Inventor/Win/viewers/SoWinConstrainedViewer.h>
#include "SceneGraph/SoPtr.h"
class SoWinExaminerViewer;
class SoWinCADViewer;

#define WM_ViewToFrame WM_APP+15
class IfcQueryMFCView : public CView
{
protected: // create from serialization only
	IfcQueryMFCView();
	DECLARE_DYNCREATE(IfcQueryMFCView)

// Attributes
public:
	IfcQueryDoc* GetDocument() const;
	SoWinCADViewer* getViewer() const { return m_viewer; }
	void zoomToModelNode();

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~IfcQueryMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );

protected:
	SoWinCADViewer* m_viewer = nullptr;

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IfcQueryMFCView.cpp
inline IfcQueryDoc* IfcQueryMFCView::GetDocument() const
   { return reinterpret_cast<IfcQueryDoc*>(m_pDocument); }
#endif
