#pragma once


// CMytabel

class CMytabel : public CStatic
{
	DECLARE_DYNAMIC(CMytabel)

public:
	CMytabel();
	virtual ~CMytabel();
	void OnPaint();

protected:
	DECLARE_MESSAGE_MAP()
};


