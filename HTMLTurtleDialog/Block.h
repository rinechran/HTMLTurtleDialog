#pragma once
struct Block
{
	CString Tag;
	CString startTag;
	CString context;
	CString property;
	CString endTag;
	CString Help;
	CRect rect;
};

struct DoctypeTag : public Block
{
	DoctypeTag()
	{
		Tag = L"doctype";
		startTag = L"<!DOCTYPE html";
		property = L"";
		context = "";
		endTag = ">";
		Help = "";
	}
};

struct HtmlTag : public Block
{
	HtmlTag()
	{
		Tag = L"html";
		startTag = L"<html";
		property = L">";
		context = "";
		endTag = "</html>";
		Help = "";
	}
};

struct HeadTag : public Block
{
	HeadTag()
	{
		Tag = L"head";
		startTag = L"<head";
		property = L">";
		context = "";
		endTag = "</head>";
		Help = "";
	}
};
struct BodyTag : public Block
{
	BodyTag()
	{
		Tag = L"body";
		startTag = L"<body";
		property = L">";
		context = "";
		endTag = "</body>";
		Help = "";
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
			Tag = L"H1";
			startTag = L"<h1";
			property = L">";
			context = "";
			endTag = "</h1>";
			break;
		case 2:
			Tag = L"H2";
			startTag = L"<h2";
			property = L">"; 
			context = "";
			endTag = "</h2>";
			break;
		case 3:
			Tag = L"H3";
			startTag = L"<h3";
			property = L">";
			context = "";
			endTag = "</h3>";
			break;
		case 4:
			Tag = L"H4";
			startTag = L"<h4";
			property = L">"; 
			context = "";
			endTag = "</h4>";
			break;
		case 5:
			Tag = L"H5";
			startTag = L"<h5";
			property = L">"; 
			context = "";
			endTag = "</h5>";
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
		Tag = L"div";
		startTag = L"<div";
		property = L">";
		context = "";
		endTag = "</div>";
		Help = "";
	}
};

struct OlTag : public Block
{
	OlTag()
	{
		Tag = L"ol";
		startTag = L"<ol";
		property = L">"; 
		context = "";
		endTag = "</ol>";
		Help = "";
	}
};

struct UlTag : public Block
{
	UlTag()
	{
		Tag = L"ul";
		startTag = L"<ul";
		property = L">";
		context = "";
		endTag = "</ul>";
		Help = "";
	}
};

struct LiTag : public Block
{
	LiTag()
	{
		Tag = L"li";
		startTag = L"<li";
		property = L">";
		context = "";
		endTag = "</p>";
		Help = "";
	}
};

struct ATag : public Block
{
	ATag()
	{
		Tag = L"a";
		startTag = L"<a";
		property = L">";
		context = "";
		endTag = "</a>";
		Help = "";
	}
};

struct PTag : public Block
{
	PTag()
	{
		Tag = L"p";
		startTag = L"<p";
		property = L">";
		context = "";
		endTag = "</p>";
		Help = "";
	}
};
struct BrTag : public Block
{
	BrTag()
	{
		Tag = L"br";
		startTag = L"<br";
		property = L"/>";
		context = "";
		endTag = "";
		Help = "";
	}
};

struct InputTag : public Block
{
	InputTag()
	{
		Tag = L"input";
		startTag = L"<input";
		property = L"";
		context = "";
		endTag = ">";
		Help = "";
	}
};

struct ImgTag : public Block
{
	ImgTag()
	{
		Tag = L"img";
		startTag = L"<img";
		property = L"";
		context = "";
		endTag = "/>";
		Help = "";
	}
};

struct TableTag : public Block
{
	TableTag()
	{
		Tag = L"table";
		startTag = L"<table";
		property = L">";
		context = "";
		endTag = "</table>";
		Help = "";
	}
};

struct TrTag : public Block
{
	TrTag()
	{
		Tag = L"tr";
		startTag = L"<tr";
		property = L">";
		context = "";
		endTag = "</tr>";
		Help = "";
	}
};

struct ThTag : public Block
{
	ThTag()
	{
		Tag = L"th";
		startTag = L"<th";
		property = L">";
		context = "";
		endTag = "</th>";
		Help = "";
	}
};

struct TdTag : public Block
{
	TdTag()
	{
		Tag = L"td";
		startTag = L"<td";
		property = L">";
		context = "";
		endTag = "</td>";
		Help = "";
	}
};

