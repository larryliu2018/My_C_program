
// LotteryDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Lottery.h"
#include "LotteryDlg.h"
#include "afxdialogex.h"
#include "Mytabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLotteryDlg 对话框



CLotteryDlg::CLotteryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOTTERY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLotteryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NUM1, m_num1);
	DDX_Control(pDX, IDC_NUM2, m_num2);
	DDX_Control(pDX, IDC_NUM3, m_num3);
	DDX_Control(pDX, IDC_NUM4, m_num4);
	DDX_Control(pDX, IDC_NUM5, m_num5);
	DDX_Control(pDX, IDC_NUM6, m_num6);
	DDX_Control(pDX, IDC_NUM7, m_num7);
	DDX_Control(pDX, IDC_HINT, m_Hint);
}

BEGIN_MESSAGE_MAP(CLotteryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEGIN, &CLotteryDlg::OnBnClickedBegin)
	ON_BN_CLICKED(IDC_END, &CLotteryDlg::OnBnClickedEnd)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLotteryDlg 消息处理程序

BOOL CLotteryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_List[0] = &m_num1;
	m_List[1] = &m_num2;
	m_List[2] = &m_num3;
	m_List[3] = &m_num4;
	m_List[4] = &m_num5;
	m_List[5] = &m_num6;
	m_List[6] = &m_num7;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLotteryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLotteryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CMytabel::OnPaint()
{
	CPaintDC dc(this);
	CFont m_font;//自己添加

	CString str;
	GetWindowText(str);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0, 0, 255));
	dc.SelectObject(&m_font);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLotteryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLotteryDlg::OnBnClickedBegin()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 1; i < 8; i++)
	{
		SetTimer(i, 100, NULL);
	}
}


void CLotteryDlg::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str, text,strz;
	str = "";
	for (int i = 1; i < 8; i++)
	{
		KillTimer(i);
		m_List[i - 1]->GetWindowText(text);
		text = text + _T("\t");//显示分开一下
		str += text;
	}
	strz = _T("本期中奖号码为：");
	strz += str;
	m_Hint.SetWindowText(strz);
}


void CLotteryDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	int t1 = 0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0;
	switch (nIDEvent)
	{
	case 1:
		t1 = rand() % 33 +1;
		if (t1 < 34)
		{
			str.Format(_T("%d"), t1);
			m_num1.SetWindowText(str);
			//m_List[0]->SetTextColor(RGB(255, 0, 0));
		}
		break;
	case 2:
		t2 = rand() % 33 +1;
		for (; t2 == t1;)
		{
			t2 = rand() % 33 + 1;
		}
		if (t2 < 34)
		{
			str.Format(_T("%d"), t2);
			m_num2.SetWindowText(str);
		}
		break;
	case 3:
		t3 = rand() % 33 + 1;
		for (; t3 == t1 || t3 == t2;)
		{
			t3 = rand() % 33 + 1;
		}
		if (t3 < 34)
		{
			str.Format(_T("%d"), t3);
			m_num3.SetWindowText(str);
		}
		break;
	case 4:
		t4 = rand() % 33 + 1;
		for (; t4 == t1 || t4 == t2 || t4 == t3;)
		{
			t4 = rand() % 33 + 1;
		}
		if (t4 < 34)
		{
			str.Format(_T("%d"), t4);
			m_num4.SetWindowText(str);
		}
		break;
	case 5:
		t5 = rand() % 33 + 1;
		for (; t5 == t1 || t5 == t2 || t5 == t3 || t5 == t4;)
		{
			t5 = rand() % 33 + 1;
		}
		if (t5 < 34)
		{
			str.Format(_T("%d"), t5);
			m_num5.SetWindowText(str);
		}
		break;
	case 6:
		t6 = rand() % 33 + 1;
		for (; t6 == t1 || t6 == t2 || t6 == t3 || t6 == t4 || t6 == t5;)
		{
			t6 = rand() % 33 + 1;
		}
		if (t6 < 34)
		{
			str.Format(_T("%d"), t6);
			m_num6.SetWindowText(str);
		}
		break;
	case 7:
		t7 = rand() % 16 + 1;
		if (t7 < 17)
		{
			str.Format(_T("%d"), t7);
			m_num7.SetWindowText(str);
		}
		break;

	}

	CDialogEx::OnTimer(nIDEvent);
}


HBRUSH CLotteryDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_NUM1 || pWnd->GetDlgCtrlID() == IDC_NUM2||
		pWnd->GetDlgCtrlID() == IDC_NUM3 || pWnd->GetDlgCtrlID() == IDC_NUM4||
		pWnd->GetDlgCtrlID() == IDC_NUM5 || pWnd->GetDlgCtrlID() == IDC_NUM6 )
	{
		pDC->SetTextColor(RGB(250, 0, 0));
	}
	if(pWnd->GetDlgCtrlID() == IDC_NUM7)
	{
		pDC->SetTextColor(RGB(0, 0, 250));
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
