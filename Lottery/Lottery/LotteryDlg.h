
// LotteryDlg.h: 头文件
//

#pragma once
#include "Mytabel.h"


// CLotteryDlg 对话框
class CLotteryDlg : public CDialogEx
{
// 构造
public:
	CLotteryDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOTTERY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMytabel m_num1;
	CMytabel m_num2;
	CMytabel m_num3;
	CMytabel m_num4;
	CMytabel m_num5;
	CMytabel m_num6;
	CMytabel m_num7;
	CMytabel m_Hint;

	CStatic *m_List[7];
	afx_msg void OnBnClickedBegin();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
