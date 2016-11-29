#pragma once
struct Block
{

	void setRect(CRect rect) {
		rect = rect;
	}
	CString mTag;
	CString mStartTag;
	CString mContext;
	CString mProperty;
	CString mEndTag;
	CString mHelp;
	CRect mRect;


};

struct DoctypeTag : public Block
{
	DoctypeTag()
	{
		mTag = L"doctype";
		mStartTag = L"<!DOCTYPE html";
		mProperty = L"";
		mContext = "";
		mEndTag = ">";
		mHelp = "";
	}
};

struct HtmlTag : public Block
{
	HtmlTag()
	{
		mTag = L"html";
		mStartTag = L"<html";
		mProperty = L">";
		mContext = "";
		mEndTag = "</html>";
		mHelp = "";
	}
};

struct HeadTag : public Block
{
	HeadTag()
	{
		mTag = L"head";
		mStartTag = L"<head";
		mProperty = L">";
		mContext = "";
		mEndTag = "</head>";
		mHelp = "";
	}
};
struct BodyTag : public Block
{
	BodyTag()
	{
		mTag = L"body";
		mStartTag = L"<body";
		mProperty = L">";
		mContext = "";
		mEndTag = "</body>";
		mHelp = "";
	}
};
struct HTag : public Block
{
	HTag(int select)
	{
		//Help="한글로 일관된 설명 가능 ex:h태그는 h1,h2,h3,h4,h5순으로 큰 폰트사이즈로 제목을나타내주는 태그이다"
		switch (select)
		{
		case 1:
			mTag = L"H1";
			mStartTag = L"<h1";
			mProperty = L">";
			mContext = "";
			mEndTag = "</h1>";
			break;
		case 2:
			mTag = L"H2";
			mStartTag = L"<h2";
			mProperty = L">"; 
			mContext = "";
			mEndTag = "</h2>";
			break;
		case 3:
			mTag = L"H3";
			mStartTag = L"<h3";
			mProperty = L">";
			mContext = "";
			mEndTag = "</h3>";
			break;
		case 4:
			mTag = L"H4";
			mStartTag = L"<h4";
			mProperty = L">"; 
			mContext = "";
			mEndTag = "</h4>";
			break;
		case 5:
			mTag = L"H5";
			mStartTag = L"<h5";
			mProperty = L">"; 
			mContext = "";
			mEndTag = "</h5>";
			break;
		default:
			break;
		}
		
		
	}
};

struct DivTag : public Block
{
	DivTag()
	{
		mTag = L"div";
		mStartTag = L"<div";
		mProperty = L">";
		mContext = "";
		mEndTag = "</div>";
		mHelp = "";
	}
};

struct OlTag : public Block
{
	OlTag()
	{
		mTag = L"ol";
		mStartTag = L"<ol";
		mProperty = L">"; 
		mContext = "";
		mEndTag = "</ol>";
		mHelp = "";
	}
};

struct UlTag : public Block
{
	UlTag()
	{
		mTag = L"ul";
		mStartTag = L"<ul";
		mProperty = L">";
		mContext = "";
		mEndTag = "</ul>";
		mHelp = "";
	}
};

struct LiTag : public Block
{
	LiTag()
	{
		mTag = L"li";
		mStartTag = L"<li";
		mProperty = L">";
		mContext = "";
		mEndTag = "</p>";
		mHelp = "";
	}
};

struct ATag : public Block
{
	ATag()
	{
		mTag = L"a";
		mStartTag = L"<a";
		mProperty = L">";
		mContext = "";
		mEndTag = "</a>";
		mHelp = "";
	}
};

struct PTag : public Block
{
	PTag()
	{
		mTag = L"p";
		mStartTag = L"<p";
		mProperty = L">";
		mContext = "";
		mEndTag = "</p>";
		mHelp = "";
	}
};
struct BrTag : public Block
{
	BrTag()
	{
		mTag = L"br";
		mStartTag = L"<br";
		mProperty = L"/>";
		mContext = "";
		mEndTag = "";
		mHelp = "";
	}
};

struct InputTag : public Block
{
	InputTag()
	{
		mTag = L"input";
		mStartTag = L"<input";
		mProperty = L"";
		mContext = "";
		mEndTag = ">";
		mHelp = "";
	}
};

struct ImgTag : public Block
{
	ImgTag()
	{
		mTag = L"img";
		mStartTag = L"<img";
		mProperty = L"";
		mContext = "";
		mEndTag = "/>";
		mHelp = "";
	}
};

struct TableTag : public Block
{
	TableTag()
	{
		mTag = L"table";
		mStartTag = L"<table";
		mProperty = L">";
		mContext = "";
		mEndTag = "</table>";
		mHelp = "";
	}
};

struct TrTag : public Block
{
	TrTag()
	{
		mTag = L"tr";
		mStartTag = L"<tr";
		mProperty = L">";
		mContext = "";
		mEndTag = "</tr>";
		mHelp = "";
	}
};

struct ThTag : public Block
{
	ThTag()
	{
		mTag = L"th";
		mStartTag = L"<th";
		mProperty = L">";
		mContext = "";
		mEndTag = "</th>";
		mHelp = "";
	}
};

struct TdTag : public Block
{
	TdTag()
	{
		mTag = L"td";
		mStartTag = L"<td";
		mProperty = L">";
		mContext = "";
		mEndTag = "</td>";
		mHelp = "";
	}
};

