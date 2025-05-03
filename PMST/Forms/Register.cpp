#include "Register.h"
#include "Dashboard.h"

namespace PMST {
Register::Register(void) {
	InitializeComponent();
}

Register::~Register() {
	if (components) delete components;
}

System::Void Register::RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1. Read inputs
		String^ username = this->nametxt->Text;
		String^ password = this->passwordtxt->Text;
		String^ email = this->emailtxt->Text;

		// 2. Call UserController::Register
		auto newUser = PMST::UserController::Register(username, password, email);

		// 3. (Optional) Automatically create a default pharmacy for this user
		auto pharm = gcnew PMST::PharmacyModel();
		pharm->Owner_Id = newUser->Id;
		pharm->Name = this->pharmNametxt->Text;
		pharm->Location = this->pharmLocttxt->Text;
		PMST::PharmacyController::Create(pharm);

		// 4. Notify success
		MessageBox::Show(
			"User registered (Id=" + newUser->Id + ") and default pharmacy created.",
			"Success",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
		this->Hide();
		Dashboard^ dashboard = gcnew Dashboard(newUser, pharm);
		dashboard->ShowDialog(this);
	}
	catch (Exception^ ex) {
		// 5. Handle validation or DB errors
		MessageBox::Show(
			ex->Message,
			"Registration Failed",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
		
	}

}

void Register::NavToLoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Navigate back to Login form
	this->Hide();
	Login^ loginForm = gcnew Login();
	loginForm->ShowDialog();
}
}