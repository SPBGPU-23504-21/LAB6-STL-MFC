
// LAB6(STL)-MFC.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CLAB6STLMFCApp:
// � ���������� ������� ������ ��. LAB6(STL)-MFC.cpp
//

class CLAB6STLMFCApp : public CWinApp
{
public:
	CLAB6STLMFCApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CLAB6STLMFCApp theApp;