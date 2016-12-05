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
	 mIsLbutton = mIsLbutton == false ? true : false;
 }

void Mouse::SetLbutton() {
	 mIsRbutton = mIsRbutton == false ? true : false;
 }
