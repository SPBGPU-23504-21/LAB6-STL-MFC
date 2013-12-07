
// LAB6(STL)-MFCDlg.h : файл заголовка
//
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <time.h>
#include <algorithm>
#include "afxwin.h"
using namespace std;
#pragma once

typedef struct{
	int x, y;
} Point;

typedef struct{
	int vertex_num;
	char *type;
	vector<Point> vertexes;
} Shape;

// диалоговое окно CLAB6STLMFCDlg
class CLAB6STLMFCDlg : public CDialogEx
{
// Создание
public:
	CLAB6STLMFCDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LAB6STLMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	string read_file(char *filename);
	list<string> find_word(string str);
	void print_words(list<string> list1);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedPart1();
	CListBox Vector;
	CListBox InData;

	template<typename T>T RandomElement(T r1, T r2);
	vector<Shape> CreateVector(int size);
	vector<Shape> SortVector(vector<Shape> v);
	int FindPoints(vector<Shape> v);
	void FindShapes(vector<Shape> v);
	vector<Shape> DeleteShape(vector<Shape>v, int vertex);
	void PrintVector(vector<Shape> v, string state);
	void part2(void);
	CListBox InDataShapes;
	afx_msg void OnBnClickedPart2();
	CListBox ResShapeData;
	afx_msg void OnBnClickedFindWords();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
