#include "pch.h"
#include "Usermanager.h"
#include "accountmanager.h"

void Usermanager::ProcessSave() {
	
	//userLock
	lock_guard<mutex> guard(m);

	Account* account = accountmanager::Instance()->GetAccout(100);

}