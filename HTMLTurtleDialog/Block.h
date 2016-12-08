#pragma once
#include <vector>
#include "Mshape.hpp"
#include <random>
//�� help�� ��Ÿ���ִ� ���� ũ�⿡ ���� ���๮�ڸ� �־�����մϴ�. \r\n���� (�����۾�����)
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
		Help = L"��Ȯ�ϰ� <!DOCTYPE html> �� html�±װ� �ƴմϴ�.\r\n<!DOCTYPE html>�� ������ ���� �� ����(DTD:Document Type Definition)�̸�\r\n���� ������ html �� html5���� ��Ÿ���� �����Դϴ�.";
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
		Help = L"<html>�� ���������� �̹����� HTML������°��� �˷��ݴϴ�\r\n<html>�±״� �ٸ�,��� html��Ҹ� ���Դϴ�.";
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
		Help = L"<head>�� ��� ��� ��������� �����̳��Դϴ�\r\n����Ҵ� html ������ \r\n<title>,<style>,<base>,<link>,<meta>,<script>,<noscript>\r\n�� �����մϴ�.";
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
		Help = L"��� html�������� �䱸�ϰ� <title>�±״� ������ ������ �����մϴ�\r\n(Ex:www.kpu.ac.kr�� �����ϸ� '�ѱ����������б�' �� ��Ÿ�������� title �±��Դϴ�)";
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
		Help = L"body�±״� ������ ��ü���� �������ݴϴ�.\r\n�ٵ��� ��Ҵ� html������ ��� ������ �����մϴ�.\r\n(Ex:�ؽ�Ʈ,�����۸�ũ,�̹���,ǥ,����Ʈ ���";
	}
};
struct HTag : public Block
{
	HTag(int select)
	{
		Help = L"h�±״� h1,h2,h3,h4,h5,h6 �� ������ \r\nh1�� ���� ���� ū�������� ��Ʈ�� ��Ÿ�����ϴ� \r\n������� ��Ʈ�� ��� �۾�����.\r\n�ַ� ������ ��Ÿ���� ����մϴ�.";
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
		Help = L"division �� ���ڷν�\r\n���� �Ǵ� html������ �κ��� �����մϴ�\r\n<div>��CSS�Ǽ����� �׷� �� ��ҷ� ���˴ϴ�.\r\n(������ ��������,�׷칭�� �뵵�� ����մϴ�.)";
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
		Help = L"<ol>�±״�  ordered list �� ���ڷν� \r\n����Ʈ�鿡�� ������� ���ڸ� �ٿ��� ǥ�� �ϰԵ˴ϴ� \r\nEx:\r\n <ol>\r\n   <li>���</li>\r\n   <li>��</li>\r\n   <li>����</li>\r\n</ol>\r\n\r\n ��������ȭ�� :\r\n1.���\r\n2.��\r\n3.����";
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
		Help = L"<ul>�±״� unordered list�� ���ڷν� ���ĵ������� ����� �����մϴ�";
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
		Help = L"list�� ���ڷν� ��� �׸����� �����մϴ�\r\n�����±׷� <ul> or <ol>�±׿� �Բ� ���˴ϴ�";
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
		Help = L"<a>�±״� anchor�� ���ڷ�\r\n herf�Ӽ��� ���� �ּҷ� ������������� �̵��ϴ� �����۸�ũ�� �ɾ��ݴϴ�.";
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
		Help = L"<p>�±״� paragraph�� ���ڷ� ������ �����մϴ�.\r\n p�±״� �������� �±����� ������ �߰��� �ݴϴ�.";
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
		Help = L"<br>�±״� �ٹٲ��� �������ִ� ��Ȱ�� �մϴ�";
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
		Help = L"�����͸� �Է����ִ� ��Ȱ�� �մϴ� \r\n�Ӽ��� ���� �پ��� ��ư �ּ�, ��¥, ��ȭ��ȣ ��� �پ��� ������ ������ �Է��ϰ� �մϴ�";
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
		Help = L"�̹����� ���Խ����ִ� �±��Դϴ�\r\n src�Ӽ��� �̿��Ͽ� �Ӽ��� ��ο� �ִ� �̹����� �����ݴϴ�.";
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
		Help = L"html table�� �������ݴϴ�(ǥ�� �������ݴϴ�)\r\n������ҷ� tr,th,td�±׸� ����մϴ�.";
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
		Help = L"<tr> �±״� ǥ�� row(��)�� �����մϴ� ������ҷ� td,th�� �����ϰ� �ֽ��ϴ�.";
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
		Help = L"ǥ�� ��� ���� �����մϴ� tr�� ��κа����� ������� �뵵�� ���ϰ� ��� ������ �ʿ��� ������ϋ� ����մϴ�";
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
		Help = L"ǥ�� ���� ���� ���ݴϴ� �⺻������ �������ĵǾ��ֽ��ϴ�.";
	}
};
