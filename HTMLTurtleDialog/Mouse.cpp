#include "stdafx.h"
#include "Mouse.h"

 Mouse::Mouse() : mIsLbutton(false), mIsRbutton(false) {

}

 bool Mouse::getLbutton() {
	 return mIsLbutton;
 }

bool Mouse::getRbutton() {
	 return mIsRbutton;
 }

void Mouse::SetRbutton() {
	mIsRbutton = mIsRbutton == false ? true : false;
 }

void Mouse::SetLbutton() {
	 mIsLbutton = mIsLbutton == false ? true : false;
 }

void Mouse::SetRbutton(bool condition)
{ 
	mIsRbutton = condition;
}

void Mouse::SetLbutton(bool condition)
{
	mIsLbutton = condition;
}
