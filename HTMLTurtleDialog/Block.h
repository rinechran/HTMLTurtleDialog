#pragma once
#include <vector>
#include "Mshape.hpp"
#include <random>
//각 help에 나타내주는 상자 크기에 맞춰 개행문자를 넣어줘야합니다. \r\n으로 (추후작업예정)
struct Block
{
	Block() {
		std::random_device rd;
		std::mt19937 dg(rd());
		std::uniform_int_distribution<> un(0, 255);
		int R = un(dg);
		int G = un(dg);
		int B = un(dg);
		rgb.setColor(R,G,B);
	}
	void setRect(CRect rect) {
		//첫번째 블럭
		mMainBlock = rect;
		//두번쨰 블럭
		mAddBlock = mMainBlock;
		mAddBlock.MoveToXY(50,51);//xy좌표 이동 ,파라미터 각각 x,y좌표에 영향줌
		//마지막 블럭
		dynamicBlock = mMainBlock;
		dynamicBlock.MoveToY(102);//y좌표만 이동
	}
	template <typename T>
	void OnDrew(T & dc) {
		CBrush * oldBrush, newBrush;
		newBrush.CreateSolidBrush(rgb);
		oldBrush = dc.SelectObject(&newBrush);
		dc.Rectangle(mMainBlock);
		dc.DrawText(mTag, -1, &mMainBlock, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		dc.SelectObject(oldBrush);

	}

	CString mTag;
	CString mStartTag;
	CString mContext;
	CString mProperty;
	CString mEndTag;
	CString Help;
	CRect mMainBlock;
	CRect dynamicBlock;
	//std::vector<CRect> dynamicBlock ;
	CRect mAddBlock;
	EunMfc::RGB rgb;

};

struct DoctypeTag : public Block
{
	DoctypeTag()
	{
		mTag = L"Doctype";
		mStartTag = L"<!DOCTYPE html";
		mProperty = L"";
		mContext = "";
		mEndTag = ">";
		Help = L"정확하게 <!DOCTYPE html> 은 html태그가 아닙니다.\r\n<!DOCTYPE html>는 문서형 정의 및 선언(DTD:Document Type Definition)이며\r\n여러 버전의 html 중 html5임을 나타내는 선언입니다.";
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
		Help = L"<html>은 브라우저에게 이문서가 HTML문서라는것을 알려줍니다\r\n<html>태그는 다른,모든 html요소를 감쌉니다.";
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
		Help = L"<head>는 모든 헤드 구성요소의 컨테이너입니다\r\n헤드요소는 html 문서의 \r\n<title>,<style>,<base>,<link>,<meta>,<script>,<noscript>\r\n를 포함합니다.";
	}
};
struct TitleTag : public Block
{
	TitleTag()
	{
		mTag = L"title";
		mStartTag = L"<title";
		mProperty = L">";
		mContext = "";
		mEndTag = "</title>";
		Help = L"모든 html문서에서 요구하고 <title>태그는 문서의 제목을 정의합니다\r\n(Ex:www.kpu.ac.kr에 접속하면 '한국산업기술대학교' 로 나타나지것이 title 태그입니다)";
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
		Help = L"body태그는 문서의 몸체임을 정의해줍니다.\r\n바디의 요소는 html문서의 모든 내용을 포함합니다.\r\n(Ex:텍스트,하이퍼링크,이미지,표,리스트 등등";
	}
};
struct HTag : public Block
{
	HTag(int select)
	{
		Help = L"h태그는 h1,h2,h3,h4,h5,h6 가 있으며 \r\nh1이 가장 굵고 큰사이즈의 폰트로 나타내집니다 \r\n순서대로 폰트가 얇고 작아지고.\r\n주로 제목을 나타낼때 사용합니다.";
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
		case 6:
			mTag = L"H6";
			mStartTag = L"<h6";
			mProperty = L">";
			mContext = "";
			mEndTag = "</h6>";
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
		Help = L"division 의 약자로써\r\n분할 또는 html문서의 부분을 정의합니다\r\n<div>는CSS의서식을 그룹 블럭 요소로 사용됩니다.\r\n(간단히 구역분할,그룹묶기 용도로 사용합니다.)";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
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
		Help = "";
	}
};
