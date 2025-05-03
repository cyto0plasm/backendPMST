#pragma once
#include "../Forms/Login.h"
#include "../Controllers/UsersController.h"
#include "../Controllers/PharmaciesController.h"
namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void);
	protected:
		~Register();
	private:
		System::Void NavToLoginBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Windows::Forms::Panel^ Title;
	protected:
	private: System::Windows::Forms::Label^ FormTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ pharmacyPanel;
	private: System::Windows::Forms::Panel^ pharmacyFormPanel;
	private: System::Windows::Forms::TextBox^ pharmLocttxt;
	private: System::Windows::Forms::Button^ NavToLoginBtn;
	private: System::Windows::Forms::Button^ RegisterBtn;
	private: System::Windows::Forms::Label^ pharmLocLabel;
	private: System::Windows::Forms::Label^ pharmNameLabel;
	private: System::Windows::Forms::TextBox^ pharmNametxt;
	private: System::Windows::Forms::Panel^ pharmacyLabPanel;
	private: System::Windows::Forms::Label^ pharmacyPanelTitle;
	private: System::Windows::Forms::Panel^ userPanel;
	private: System::Windows::Forms::Panel^ userFormPanel;
	private: System::Windows::Forms::TextBox^ emailtxt;
	private: System::Windows::Forms::TextBox^ passwordtxt;
	private: System::Windows::Forms::TextBox^ passwordreptxt;
	private: System::Windows::Forms::TextBox^ nametxt;
	private: System::Windows::Forms::Label^ emaillab;
	private: System::Windows::Forms::Label^ namelabel;
	private: System::Windows::Forms::Label^ passwordlab;
	private: System::Windows::Forms::Label^ passwordreplab;
	private: System::Windows::Forms::Panel^ userLabPanel;
	private: System::Windows::Forms::Label^ UserPanelTitle;
	//private:Login^ loginForm;
	protected:







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Title = (gcnew System::Windows::Forms::Panel());
			this->FormTitle = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pharmacyPanel = (gcnew System::Windows::Forms::Panel());
			this->pharmacyFormPanel = (gcnew System::Windows::Forms::Panel());
			this->pharmLocttxt = (gcnew System::Windows::Forms::TextBox());
			this->NavToLoginBtn = (gcnew System::Windows::Forms::Button());
			this->RegisterBtn = (gcnew System::Windows::Forms::Button());
			this->pharmLocLabel = (gcnew System::Windows::Forms::Label());
			this->pharmNameLabel = (gcnew System::Windows::Forms::Label());
			this->pharmNametxt = (gcnew System::Windows::Forms::TextBox());
			this->pharmacyLabPanel = (gcnew System::Windows::Forms::Panel());
			this->pharmacyPanelTitle = (gcnew System::Windows::Forms::Label());
			this->userPanel = (gcnew System::Windows::Forms::Panel());
			this->userFormPanel = (gcnew System::Windows::Forms::Panel());
			this->emailtxt = (gcnew System::Windows::Forms::TextBox());
			this->passwordtxt = (gcnew System::Windows::Forms::TextBox());
			this->passwordreptxt = (gcnew System::Windows::Forms::TextBox());
			this->nametxt = (gcnew System::Windows::Forms::TextBox());
			this->emaillab = (gcnew System::Windows::Forms::Label());
			this->namelabel = (gcnew System::Windows::Forms::Label());
			this->passwordlab = (gcnew System::Windows::Forms::Label());
			this->passwordreplab = (gcnew System::Windows::Forms::Label());
			this->userLabPanel = (gcnew System::Windows::Forms::Panel());
			this->UserPanelTitle = (gcnew System::Windows::Forms::Label());
			this->Title->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->pharmacyPanel->SuspendLayout();
			this->pharmacyFormPanel->SuspendLayout();
			this->pharmacyLabPanel->SuspendLayout();
			this->userPanel->SuspendLayout();
			this->userFormPanel->SuspendLayout();
			this->userLabPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Title->Controls->Add(this->FormTitle);
			this->Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->Title->Location = System::Drawing::Point(0, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(688, 54);
			this->Title->TabIndex = 9;
			// 
			// FormTitle
			// 
			this->FormTitle->AutoSize = true;
			this->FormTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->FormTitle->Location = System::Drawing::Point(265, 9);
			this->FormTitle->Name = L"FormTitle";
			this->FormTitle->Size = System::Drawing::Size(149, 31);
			this->FormTitle->TabIndex = 0;
			this->FormTitle->Text = L"تسجيل الدخول";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->pharmacyPanel);
			this->flowLayoutPanel1->Controls->Add(this->userPanel);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 54);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(688, 415);
			this->flowLayoutPanel1->TabIndex = 10;
			// 
			// pharmacyPanel
			// 
			this->pharmacyPanel->Controls->Add(this->pharmacyFormPanel);
			this->pharmacyPanel->Controls->Add(this->pharmacyLabPanel);
			this->pharmacyPanel->Location = System::Drawing::Point(5, 5);
			this->pharmacyPanel->Margin = System::Windows::Forms::Padding(5);
			this->pharmacyPanel->Name = L"pharmacyPanel";
			this->pharmacyPanel->Size = System::Drawing::Size(330, 390);
			this->pharmacyPanel->TabIndex = 0;
			// 
			// pharmacyFormPanel
			// 
			this->pharmacyFormPanel->AccessibleName = L"userFormPanel";
			this->pharmacyFormPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pharmacyFormPanel->Controls->Add(this->pharmLocttxt);
			this->pharmacyFormPanel->Controls->Add(this->NavToLoginBtn);
			this->pharmacyFormPanel->Controls->Add(this->RegisterBtn);
			this->pharmacyFormPanel->Controls->Add(this->pharmLocLabel);
			this->pharmacyFormPanel->Controls->Add(this->pharmNameLabel);
			this->pharmacyFormPanel->Controls->Add(this->pharmNametxt);
			this->pharmacyFormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pharmacyFormPanel->Location = System::Drawing::Point(0, 62);
			this->pharmacyFormPanel->MaximumSize = System::Drawing::Size(330, 335);
			this->pharmacyFormPanel->MinimumSize = System::Drawing::Size(330, 335);
			this->pharmacyFormPanel->Name = L"pharmacyFormPanel";
			this->pharmacyFormPanel->Size = System::Drawing::Size(330, 335);
			this->pharmacyFormPanel->TabIndex = 1;
			// 
			// pharmLocttxt
			// 
			this->pharmLocttxt->AccessibleName = L"pharmLocttxt";
			this->pharmLocttxt->Location = System::Drawing::Point(34, 123);
			this->pharmLocttxt->Multiline = true;
			this->pharmLocttxt->Name = L"pharmLocttxt";
			this->pharmLocttxt->Size = System::Drawing::Size(254, 33);
			this->pharmLocttxt->TabIndex = 4;
			this->pharmLocttxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->pharmLocttxt->UseSystemPasswordChar = true;
			// 
			// NavToLoginBtn
			// 
			this->NavToLoginBtn->AccessibleName = L"NavToLoginBtn";
			this->NavToLoginBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NavToLoginBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->NavToLoginBtn->Location = System::Drawing::Point(21, 169);
			this->NavToLoginBtn->Name = L"NavToLoginBtn";
			this->NavToLoginBtn->Size = System::Drawing::Size(134, 41);
			this->NavToLoginBtn->TabIndex = 5;
			this->NavToLoginBtn->Text = L"تسجيل الدخول";
			this->NavToLoginBtn->UseVisualStyleBackColor = true;
			this->NavToLoginBtn->Click += gcnew System::EventHandler(this, &Register::NavToLoginBtn_Click);
			// 
			// RegisterBtn
			// 
			this->RegisterBtn->AccessibleName = L"RegisterBtn";
			this->RegisterBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->RegisterBtn->Location = System::Drawing::Point(172, 169);
			this->RegisterBtn->Name = L"RegisterBtn";
			this->RegisterBtn->Size = System::Drawing::Size(134, 41);
			this->RegisterBtn->TabIndex = 5;
			this->RegisterBtn->Text = L"انشاء حساب";
			this->RegisterBtn->UseVisualStyleBackColor = true;
			this->RegisterBtn->Click += gcnew System::EventHandler(this, &Register::RegisterBtn_Click);
			// 
			// pharmLocLabel
			// 
			this->pharmLocLabel->AccessibleName = L"pharmLocLabel";
			this->pharmLocLabel->AutoSize = true;
			this->pharmLocLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmLocLabel->Location = System::Drawing::Point(164, 89);
			this->pharmLocLabel->Name = L"pharmLocLabel";
			this->pharmLocLabel->Size = System::Drawing::Size(118, 23);
			this->pharmLocLabel->TabIndex = 7;
			this->pharmLocLabel->Text = L"عنوان الصيدلية";
			// 
			// pharmNameLabel
			// 
			this->pharmNameLabel->AccessibleName = L"pharmNameLabel";
			this->pharmNameLabel->AutoSize = true;
			this->pharmNameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmNameLabel->Location = System::Drawing::Point(176, 10);
			this->pharmNameLabel->Name = L"pharmNameLabel";
			this->pharmNameLabel->Size = System::Drawing::Size(106, 23);
			this->pharmNameLabel->TabIndex = 7;
			this->pharmNameLabel->Text = L"اسم الصيدلية";
			// 
			// pharmNametxt
			// 
			this->pharmNametxt->AccessibleName = L"pharmNametxt";
			this->pharmNametxt->Location = System::Drawing::Point(36, 43);
			this->pharmNametxt->Margin = System::Windows::Forms::Padding(0);
			this->pharmNametxt->Multiline = true;
			this->pharmNametxt->Name = L"pharmNametxt";
			this->pharmNametxt->Size = System::Drawing::Size(254, 33);
			this->pharmNametxt->TabIndex = 4;
			this->pharmNametxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->pharmNametxt->UseSystemPasswordChar = true;
			// 
			// pharmacyLabPanel
			// 
			this->pharmacyLabPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pharmacyLabPanel->Controls->Add(this->pharmacyPanelTitle);
			this->pharmacyLabPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->pharmacyLabPanel->Location = System::Drawing::Point(0, 0);
			this->pharmacyLabPanel->Name = L"pharmacyLabPanel";
			this->pharmacyLabPanel->Size = System::Drawing::Size(330, 62);
			this->pharmacyLabPanel->TabIndex = 0;
			// 
			// pharmacyPanelTitle
			// 
			this->pharmacyPanelTitle->AutoSize = true;
			this->pharmacyPanelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyPanelTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->pharmacyPanelTitle->Location = System::Drawing::Point(71, 14);
			this->pharmacyPanelTitle->Name = L"pharmacyPanelTitle";
			this->pharmacyPanelTitle->Size = System::Drawing::Size(160, 31);
			this->pharmacyPanelTitle->TabIndex = 0;
			this->pharmacyPanelTitle->Text = L"بيانات الصيداية";
			// 
			// userPanel
			// 
			this->userPanel->Controls->Add(this->userFormPanel);
			this->userPanel->Controls->Add(this->userLabPanel);
			this->userPanel->Location = System::Drawing::Point(345, 5);
			this->userPanel->Margin = System::Windows::Forms::Padding(5);
			this->userPanel->Name = L"userPanel";
			this->userPanel->Size = System::Drawing::Size(330, 390);
			this->userPanel->TabIndex = 0;
			// 
			// userFormPanel
			// 
			this->userFormPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->userFormPanel->Controls->Add(this->emailtxt);
			this->userFormPanel->Controls->Add(this->passwordtxt);
			this->userFormPanel->Controls->Add(this->passwordreptxt);
			this->userFormPanel->Controls->Add(this->nametxt);
			this->userFormPanel->Controls->Add(this->emaillab);
			this->userFormPanel->Controls->Add(this->namelabel);
			this->userFormPanel->Controls->Add(this->passwordlab);
			this->userFormPanel->Controls->Add(this->passwordreplab);
			this->userFormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->userFormPanel->Location = System::Drawing::Point(0, 62);
			this->userFormPanel->MaximumSize = System::Drawing::Size(330, 335);
			this->userFormPanel->MinimumSize = System::Drawing::Size(330, 335);
			this->userFormPanel->Name = L"userFormPanel";
			this->userFormPanel->Size = System::Drawing::Size(330, 335);
			this->userFormPanel->TabIndex = 1;
			// 
			// emailtxt
			// 
			this->emailtxt->AccessibleName = L"emailtxt";
			this->emailtxt->Location = System::Drawing::Point(44, 123);
			this->emailtxt->Multiline = true;
			this->emailtxt->Name = L"emailtxt";
			this->emailtxt->Size = System::Drawing::Size(254, 33);
			this->emailtxt->TabIndex = 4;
			this->emailtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->emailtxt->UseSystemPasswordChar = true;
			// 
			// passwordtxt
			// 
			this->passwordtxt->AccessibleName = L"passwordtxt";
			this->passwordtxt->Location = System::Drawing::Point(46, 204);
			this->passwordtxt->Multiline = true;
			this->passwordtxt->Name = L"passwordtxt";
			this->passwordtxt->PasswordChar = '*';
			this->passwordtxt->Size = System::Drawing::Size(254, 33);
			this->passwordtxt->TabIndex = 3;
			this->passwordtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->passwordtxt->UseSystemPasswordChar = true;
			// 
			// passwordreptxt
			// 
			this->passwordreptxt->AccessibleName = L"passwordreptxt";
			this->passwordreptxt->Location = System::Drawing::Point(44, 287);
			this->passwordreptxt->Multiline = true;
			this->passwordreptxt->Name = L"passwordreptxt";
			this->passwordreptxt->PasswordChar = '*';
			this->passwordreptxt->Size = System::Drawing::Size(254, 33);
			this->passwordreptxt->TabIndex = 3;
			this->passwordreptxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->passwordreptxt->UseSystemPasswordChar = true;
			// 
			// nametxt
			// 
			this->nametxt->AccessibleName = L"nametxt";
			this->nametxt->Location = System::Drawing::Point(46, 43);
			this->nametxt->Margin = System::Windows::Forms::Padding(0);
			this->nametxt->Multiline = true;
			this->nametxt->Name = L"nametxt";
			this->nametxt->Size = System::Drawing::Size(254, 33);
			this->nametxt->TabIndex = 4;
			this->nametxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nametxt->UseSystemPasswordChar = true;
			// 
			// emaillab
			// 
			this->emaillab->AccessibleName = L"emaillab";
			this->emaillab->AutoSize = true;
			this->emaillab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emaillab->Location = System::Drawing::Point(174, 89);
			this->emaillab->Name = L"emaillab";
			this->emaillab->Size = System::Drawing::Size(124, 23);
			this->emaillab->TabIndex = 7;
			this->emaillab->Text = L"البريد الالكتروني";
			// 
			// namelabel
			// 
			this->namelabel->AccessibleName = L"namelabel";
			this->namelabel->AutoSize = true;
			this->namelabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->namelabel->Location = System::Drawing::Point(186, 10);
			this->namelabel->Name = L"namelabel";
			this->namelabel->Size = System::Drawing::Size(112, 23);
			this->namelabel->TabIndex = 7;
			this->namelabel->Text = L"اسم المستخدم";
			// 
			// passwordlab
			// 
			this->passwordlab->AccessibleName = L"passwordlab";
			this->passwordlab->AutoSize = true;
			this->passwordlab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordlab->Location = System::Drawing::Point(206, 169);
			this->passwordlab->Name = L"passwordlab";
			this->passwordlab->Size = System::Drawing::Size(92, 23);
			this->passwordlab->TabIndex = 6;
			this->passwordlab->Text = L"الرقم السري";
			// 
			// passwordreplab
			// 
			this->passwordreplab->AccessibleName = L"passwordreplab";
			this->passwordreplab->AutoSize = true;
			this->passwordreplab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordreplab->Location = System::Drawing::Point(167, 251);
			this->passwordreplab->Name = L"passwordreplab";
			this->passwordreplab->Size = System::Drawing::Size(131, 23);
			this->passwordreplab->TabIndex = 6;
			this->passwordreplab->Text = L"تاكيد الرقم السري";
			// 
			// userLabPanel
			// 
			this->userLabPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->userLabPanel->Controls->Add(this->UserPanelTitle);
			this->userLabPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->userLabPanel->Location = System::Drawing::Point(0, 0);
			this->userLabPanel->Name = L"userLabPanel";
			this->userLabPanel->Size = System::Drawing::Size(330, 62);
			this->userLabPanel->TabIndex = 0;
			// 
			// UserPanelTitle
			// 
			this->UserPanelTitle->AutoSize = true;
			this->UserPanelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserPanelTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->UserPanelTitle->Location = System::Drawing::Point(77, 14);
			this->UserPanelTitle->Name = L"UserPanelTitle";
			this->UserPanelTitle->Size = System::Drawing::Size(169, 31);
			this->UserPanelTitle->TabIndex = 0;
			this->UserPanelTitle->Text = L"بيانات المستخدم";
			// 
			// Register
			// 
			this->AccessibleName = L"Register";
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 469);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximumSize = System::Drawing::Size(710, 520);
			this->Name = L"Register";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->Title->ResumeLayout(false);
			this->Title->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->pharmacyPanel->ResumeLayout(false);
			this->pharmacyFormPanel->ResumeLayout(false);
			this->pharmacyFormPanel->PerformLayout();
			this->pharmacyLabPanel->ResumeLayout(false);
			this->pharmacyLabPanel->PerformLayout();
			this->userPanel->ResumeLayout(false);
			this->userFormPanel->ResumeLayout(false);
			this->userFormPanel->PerformLayout();
			this->userLabPanel->ResumeLayout(false);
			this->userLabPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion






};
}
