
// LAB6(STL)-MFC.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLAB6STLMFCApp:
// О реализации данного класса см. LAB6(STL)-MFC.cpp
//

class CLAB6STLMFCApp : public CWinApp
{
public:
	CLAB6STLMFCApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLAB6STLMFCApp theApp;