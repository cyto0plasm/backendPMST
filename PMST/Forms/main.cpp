#include "Dashboard.h"  
#include "../Database/DBConnection.h"
#include "../Forms/Register.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args)
{
	MessageBox::Show("Main started");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	/*PharmacyManagementSystem::Dashboard^ form = gcnew PharmacyManagementSystem::Dashboard();
	Application::Run(form);*/

	/*try {
		Application::Run(gcnew PMST::Dashboard());
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}*/

	try
	{
		auto testConn = DBConnection::GetConnection();  // now returns SQLiteConnection^
		testConn->Open();                               // will throw if bad
		// enable foreign keys if you rely on FKs
		{
			auto fkCmd = gcnew SQLiteCommand("PRAGMA foreign_keys = ON;", testConn);
			fkCmd->ExecuteNonQuery();
		}
		testConn->Close();
		MessageBox::Show(
			"SQLite database connection successful!",
			"Connection Test",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(
			"Database connection FAILED:\n" + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
		return -1;  // abort launch
	}


	// Only run app if connection is fine
	try
	{
		Application::Run(gcnew PMST::Register());
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error launching Dashboard: " + ex->Message);
	}


	return 0;
}
