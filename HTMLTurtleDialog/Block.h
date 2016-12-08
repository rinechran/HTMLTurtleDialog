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
		rgb.setColor(R, G, B);

	}
	void initBlock(CRect rect) {
		mMainBlock = rect;
		leftRect.SetRect(
			rect.left,
			rect.top + 50,
			rect.right - 50,
			rect.bottom + 50
		);

		rightRect.SetRect(
			rect.right - 50,
			rect.bottom,
			rect.right,
			rect.bottom + 50
		);

	}
	template <typename T>
	void OnDrew(T & dc) {
		CBrush * oldBrush, newBrush;
		newBrush.CreateSolidBrush(rgb);
		oldBrush = dc.SelectObject(&newBrush);
		dc.Rectangle(mMainBlock);
		dc.SetBkMode(TRANSPARENT);
		dc.DrawText(mTag, -1, &mMainBlock, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		dc.SelectObject(oldBrush);
	}

	void BlockMoveXY(CPoint &point) {
		mMainBlock.MoveToXY(point);
		leftRect.MoveToXY(CPoint(point.x, point.y + 50));
		rightRect.MoveToXY(CPoint(point.x + 50, point.y + 50));
		//rightRect.MoveToXY();
	}
	void LeftRectPush() {

		leftRect.MoveToY(leftRect.top + 50);
		//rightRect.MoveToXY();
	}


	using DynamicBlock = std::vector<Block>;

	CString mTag;
	CString mStartTag;
	CString mContext;
	CString mProperty;
	CString mEndTag;
	CString Help;
	//
	CRect mMainBlock;
	DynamicBlock dynamicBlock;
	CRect leftRect;
	CRect rightRect;
	EunMfc::RGB rgb;

};
struct EnrtyBlcok : public Block
{
	EnrtyBlcok()
	{
		mTag = L"EnrtyBlcok";
	}
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
		Help = L"<ol>태그는  ordered list 의 약자로써 \r\n리스트들에게 순서대로 숫자를 붙여서 표현 하게됩니다 \r\nEx:\r\n <ol>\r\n   <li>사과</li>\r\n   <li>배</li>\r\n   <li>포도</li>\r\n</ol>\r\n\r\n 보여지는화면 :\r\n1.사과\r\n2.배\r\n3.포도";
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
		Help = L"<ul>태그는 unordered list의 약자로써 정렬되지않은 목록을 정의합니다";
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
		Help = L"list의 약자로써 목록 항목을을 정의합니다\r\n상위태그로 <ul> or <ol>태그와 함께 사용됩니다";
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
		Help = L"<a>태그는 anchor의 약자로\r\n herf속성에 적힌 주소로 연결된페이지로 이동하는 하이퍼링크를 걸어줍니다.";
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
		Help = L"<p>태그는 paragraph의 약자로 문단을 정의합니다.\r\n p태그는 브라우저가 태그전에 여백을 추가로 줍니다.";
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
		Help = L"<br>태그는 줄바꿈을 시행해주는 역활을 합니다";
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
		Help = L"데이터를 입력해주는 역활을 합니다 \r\n속성에 따라 다양한 버튼 주소, 날짜, 전화번호 등등 다양한 데이터 형식을 입력하게 합니다";
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
		Help = L"이미지를 삽입시켜주는 태그입니다\r\n src속성을 이용하여 속성의 경로에 있는 이미지를 보여줍니다.";
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
		Help = L"html table을 정의해줍니다(표를 정의해줍니다)\r\n하위요소로 tr,th,td태그를 사용합니다.";
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
		Help = L"<tr> 태그는 표의 row(행)을 정의합니다 하위요소로 td,th를 포함하고 있습니다.";
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
		Help = L"표의 헤더 셀을 정의합니다 tr과 대부분같으나 제목등의 용도로 진하고 가운데 정렬이 필요한 헤더셀일떄 사용합니다";
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
		Help = L"표준 셀을 정의 해줍니다 기본적으로 왼쪽정렬되어있습니다.";
	}
};
