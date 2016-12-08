#pragma once
class CCustomDC : public CDC {
private:
	CBitmap		m_bitmap;		// Offscreen bitmap
	CBitmap*	m_oldBitmap;	// bitmap originally found in CMemDC
	CDC*		m_pDC;			// Saves CDC passed in constructor
	CRect		m_rect;			// Rectangle of drawing area.
	BOOL		m_bMemDC;		// TRUE if CDC really is a Memory DC.
public:

	CCustomDC(CDC* pDC, const CRect* pRect = NULL);

	~CCustomDC();

	// Allow usage as a pointer	
	CCustomDC* operator->()
	{
		return this;
	}

	// Allow usage as a pointer	
	operator CCustomDC*()
	{
		return this;
	}
};