#include "pch.h"
#include "accountmanager.h"
#include "Usermanager.h"

void accountmanager::ProcessLogin() {

	//acountLock
	lock_guard<mutex> guard(m);


	//userLock
	User* user = Usermanager::Instance()->GetUser(100);
}