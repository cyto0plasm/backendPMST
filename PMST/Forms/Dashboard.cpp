
#include "Dashboard.h"
#include "../Models/UserModel.h"
#include "../Models/PharmacyModel.h"
using namespace PMST;
Dashboard::Dashboard(UserModel^ user, PharmacyModel^ pharmacy)
{
	if (user == nullptr || pharmacy == nullptr) {
		throw gcnew ArgumentNullException("User or Pharmacy cannot be null");
	}
	currentUser = user;
	currentPharmacy = pharmacy;

	
	InitializeComponent(); 
	if (this->userBtn == nullptr) {
		throw gcnew Exception("userBtn control not found");
	}
	UpdateUserInfoDisplay();

	resources = gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid);



	// Save the original image and create resized versions
	originalUserImage = this->userBtn->Image; // Original from resources
	collapsedUserImage = ResizeImage(originalUserImage, 48, 48); // Smaller size
	expandedUserImage = ResizeImage(originalUserImage, 65, 65);  // Larger size
	this->maximizeIcon = (resources->GetObject(L"max2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max2")) :
		nullptr;

	this->minimizeIcon = (resources->GetObject(L"min2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min2")) :
		nullptr;

	// Set initial image
	if (this->maximizeIcon != nullptr) {
		this->minMax->Image = this->maximizeIcon;
	}

}
void Dashboard::UpdateUserInfoDisplay() {
	try {
		// Set button text with both username and pharmacy
		/*this->userBtn->Text = String::Format(L"👤 {0}\n🏥 {1}",
			currentUser->Username,
			currentPharmacy->Name);*/

		// Or if you have separate controls:
		 this->userBtn->Text = currentUser->Username;
		 this->pharmacyName->Text = currentPharmacy->Name;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error updating user info: " + ex->Message);
	}
}