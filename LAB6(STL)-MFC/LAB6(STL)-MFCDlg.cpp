
// LAB6(STL)-MFCDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "LAB6(STL)-MFC.h"
#include "LAB6(STL)-MFCDlg.h"
#include "afxdialogex.h"
#include <string>
#include <atlstr.h>
#include <fstream>
#include <list>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении
string s1;
vector<Shape> V;
string stateOut = "Out";

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CLAB6STLMFCDlg



CLAB6STLMFCDlg::CLAB6STLMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLAB6STLMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLAB6STLMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_LBString(pDX, IDC_LIST1, VectorDATA);
	DDX_Control(pDX, IDC_LIST1, Vector);
	DDX_Control(pDX, IDC_LIST2, InData);
	DDX_Control(pDX, IDC_LIST3, InDataShapes);
	DDX_Control(pDX, IDC_LIST4, ResShapeData);
}

BEGIN_MESSAGE_MAP(CLAB6STLMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BT_EXIT, &CLAB6STLMFCDlg::OnBnClickedExit)
	ON_BN_CLICKED(BT_PART1, &CLAB6STLMFCDlg::OnBnClickedPart1)
	ON_BN_CLICKED(BT_PART2, &CLAB6STLMFCDlg::OnBnClickedPart2)
	ON_BN_CLICKED(BT_FIND_WORDS, &CLAB6STLMFCDlg::OnBnClickedFindWords)
	ON_BN_CLICKED(IDC_BUTTON2, &CLAB6STLMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CLAB6STLMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CLAB6STLMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CLAB6STLMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CLAB6STLMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CLAB6STLMFCDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// обработчики сообщений CLAB6STLMFCDlg

BOOL CLAB6STLMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLAB6STLMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLAB6STLMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLAB6STLMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CLAB6STLMFCDlg::OnBnClickedExit()
{
	// TODO: добавьте свой код обработчика уведомлений
	int iResult = MessageBox("Do u want exit from program?", "Exit", MB_YESNO+MB_ICONQUESTION);
	if(iResult == IDYES)
	{
		CDialogEx::OnOK();
	}
}

//КОД STL part 1()
string CLAB6STLMFCDlg::read_file(char *filename){
	ifstream data;
	char *tmp;
	int tmp_size;
	InData.ResetContent();
	data.open(filename);
	if(data.is_open()){
		data.seekg(0, ios_base::end);
		tmp_size = data.tellg();
		data.seekg(0, ios_base::beg);
		tmp = (char *)malloc(tmp_size*sizeof(char));
		data.read(tmp, tmp_size);
		string str(tmp, tmp_size);
		free(tmp);
		data.close();
		CString tmp = str.c_str();
		InData.AddString(tmp);
		return str;
	}
	else{
		MessageBox(_T("Error while openning file"));
		return NULL;
	}
}

list<string> CLAB6STLMFCDlg::find_word(string str){
	list<string>list1;
	int pos = 0, cpos = 0;
	char *ends_of_word[] = {" ", "\t", "\n"};
	string word;
	string::iterator iter = str.begin();
	while( (pos = (int)str.find(ends_of_word[1])) != str.npos && (pos=(int)str.find(ends_of_word[2])) != str.npos ){
		if(str.compare(pos+1, 1, ends_of_word[1]) == 1 || str.compare(pos+1, 1, ends_of_word[2]) == 1){
			str.replace(pos, 1, ends_of_word[0]);
		}
		pos++;
	}
	pos = 0;
	while (iter != str.end()-1)
	{
		cpos = str.find(ends_of_word[0], pos);
		word = str.substr(pos, cpos-pos);
		list1.push_back(word);
		iter = str.begin();
		iter = iter+(cpos+1);
		pos = cpos + 1;
		if(cpos == -1){break;}
	}
	return list1;
}

void CLAB6STLMFCDlg::print_words(list<string> list1){
	list<string>::iterator iter = list1.begin();
	string tmp1;
	Vector.ResetContent();
	while(iter != list1.end()){
		tmp1 = *iter;
		CString tmp = tmp1.c_str();
		Vector.AddString(tmp);
		iter++;
	}
}

void CLAB6STLMFCDlg::OnBnClickedPart1()
{
	// TODO: добавьте свой код обработчика уведомлений
	char *filename = {"../input.txt"};
	s1 = read_file(filename);
}

//КОД STL part2()
template<typename T>T CLAB6STLMFCDlg::RandomElement(T r1, T r2)
{
	return r1 + rand() % (r2-r1+1);
}

vector<Shape> CLAB6STLMFCDlg::CreateVector( int size){
	int i = 0, k1 = 3, k2 = 5, r1 = -100, r2 = 100;
	vector<Shape> v;
    Shape data;
	Point point;
	while(i != size){
		data.vertex_num = RandomElement(k1, k2);
		if(data.vertex_num == 3){
			data.type = "Trinagle";
		}
		else if(data.vertex_num == 4){
			data.type = "Square";
		}
		else{
			data.type = "5angles";
		}
		point.x = RandomElement(r1, r2);
		point.y = RandomElement(r1, r2);
		data.vertexes.push_back(point);
        v.push_back(data);
		i++;
    }
	return v;
}

void CLAB6STLMFCDlg::PrintVector(vector<Shape> v, string state){
	int i = 0;
	 char* t = {"\t"};
	for(int i = 0; i != v.size(); i++) {
		//cout << v[i].type << " Coordinats vertex: (" << v[i].vertexes[i].x <<", " << v[i].vertexes[i].y << ")" << endl;
		string tmp(v[i].type);
		CString str = tmp.c_str();
		if(state == "In"){
			InDataShapes.AddString(str);
		}
		else
		{
			ResShapeData.AddString(str);
		}
    }
}
int CLAB6STLMFCDlg::FindPoints(vector<Shape> v){
	vector<Shape>::iterator iter = v.begin();
	int summ = 0;
	for(iter = v.begin(); iter != v.end(); iter++){
		summ = iter->vertex_num + summ;
	}
	return summ;
}

void CLAB6STLMFCDlg::FindShapes(vector<Shape> v){
	int i = 0, summTrin = 0, summSqr = 0, summ5ang = 0;
	for(i = 0; i != v.size(); i++){
		if(v[i].vertex_num == 3){
			summTrin = summTrin + 1;
		}
		else if(v[i].vertex_num == 4){
			summSqr = summSqr + 1;
		}
		else if(v[i].vertex_num == 5){
			summ5ang = summ5ang + 1;
		}
	}
	//cout << "Summ triangels = " << summTrin << ", Summ square = " << summSqr << ", Summ 5angles = " << summ5ang << endl;
	CString tmp1, tmp2, tmp3, tmp;
	tmp1.Format("%i", summTrin);
	tmp2.Format("%i", summSqr);
	tmp3.Format("%i", summ5ang);
	tmp = "Triangles = " + tmp1 + " Square = " + tmp2 + " Fiveangles = " + tmp3;
	MessageBox(tmp, "FindShapes");
}

vector<Shape> CLAB6STLMFCDlg::SortVector(vector<Shape> v){
	bool t = true;
	vector<Shape>::iterator iter = v.begin();
	vector<Shape>::iterator iter1 = v.begin()+1;
	while(iter != v.end())
	{
		if(iter->vertex_num < iter1->vertex_num)
		{
			iter_swap(iter, iter1);
		}
		iter++;
		iter1++;
	}
	return v;
}

vector<Shape> CLAB6STLMFCDlg::DeleteShape(vector<Shape> v, int vertex){
	size_t i, place = 0;
	for(i = 0; i != v.size(); ++i){
		if(v[i].vertex_num != vertex){
			v[place] = v[i];
			++place;
		}
	}
	v.resize(place);
	return v;
}

void CLAB6STLMFCDlg::OnBnClickedPart2()
{
	// TODO: добавьте свой код обработчика уведомлений
	InDataShapes.ResetContent();
	srand((int)time(0));
	string stateIn = "In";
	V = CreateVector(10);
	PrintVector(V, stateIn);
}


void CLAB6STLMFCDlg::OnBnClickedFindWords()
{
	// TODO: добавьте свой код обработчика уведомлений
	list<string> sl1 = find_word(s1);
	print_words(sl1);
}


void CLAB6STLMFCDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	int summ1 = FindPoints(V);
	CString str;
	str.Format("%i", summ1);
	MessageBox(str, "Find Points");
}


void CLAB6STLMFCDlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	FindShapes(V);
}


void CLAB6STLMFCDlg::OnBnClickedButton5()
{
	// TODO: добавьте свой код обработчика уведомлений
	ResShapeData.ResetContent();
	V = SortVector(V);
	PrintVector(V, stateOut);
}


void CLAB6STLMFCDlg::OnBnClickedButton6()
{
	// TODO: добавьте свой код обработчика уведомлений
	ResShapeData.ResetContent();
	int iResult = MessageBox("Вы точно хотите удалить все треугольники из списка?", "Удалить треугольники", MB_YESNO+MB_ICONQUESTION);
	if(iResult == IDYES)
	{
		V = DeleteShape(V, 3);
		PrintVector(V, stateOut);
	}
}


void CLAB6STLMFCDlg::OnBnClickedButton7()
{
	// TODO: добавьте свой код обработчика уведомлений
	ResShapeData.ResetContent();
	int iResult = MessageBox("Вы точно хотите удалить все четырехугольники из списка?", "Удалить четырехугольники", MB_YESNO+MB_ICONQUESTION);
	if(iResult == IDYES)
	{
		V = DeleteShape(V, 4);
		PrintVector(V, stateOut);
	}
}


void CLAB6STLMFCDlg::OnBnClickedButton8()
{
	// TODO: добавьте свой код обработчика уведомлений
	ResShapeData.ResetContent();
	int iResult = MessageBox("Вы точно хотите удалить все пятиугольники из списка?", "Удалить пятиугольники", MB_YESNO+MB_ICONQUESTION);
	if(iResult == IDYES)
	{
		V = DeleteShape(V, 5);
		PrintVector(V, stateOut);
	}
}
