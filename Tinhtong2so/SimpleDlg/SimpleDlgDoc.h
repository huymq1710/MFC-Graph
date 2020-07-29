
// SimpleDlgDoc.h : interface of the CSimpleDlgDoc class
//


#pragma once


class CSimpleDlgDoc : public CDocument
{
protected: // create from serialization only
	CSimpleDlgDoc() noexcept;
	DECLARE_DYNCREATE(CSimpleDlgDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	//y=ax+b
	int GetA1(){ return m_a1; }
	int GetB1() { return m_b1; }
	CString GetText() { return m_text1; }

	//y=ax^2+bx+c
	float GetA2() { return m_a2; }
	float GetB2() { return m_b2; }
	float GetC2() { return m_c2; }
	CString GetText2() { return m_text2; }

	//(x-a)^2+(y-b)^2=R^2
	int GetA4() { return m_a4; }
	int GetB4() { return m_b4; }
	int GetR() { return m_r; }

	virtual ~CSimpleDlgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnGraph1Draw();
private:
	int m_a1{ 0 };
	int m_b1{ 0 };
	CString m_text1{ "This is a name of the Graph 1" };

public:
	afx_msg void OnGraph2Draw();
private:
	float m_a2{ 0 };
	float m_b2{ 0 };
	float m_c2{ 0 };
	CString m_text2{ "This is a name of the Graph 2" };
public:
	afx_msg void OnGraphCircle();
private:
	int m_a4{ 0 };
	int m_b4{ 0 };
	int m_r{ 0 };
};
