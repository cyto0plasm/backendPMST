#pragma once
#include "Register.h"
namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>

	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void);
	protected:
		~Login();
	private:
		//void InitializeComponent(void);
	private: System::Void LoginBtn_Click(System::Object^ sender, System::EventArgs^ e);
	
		   void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Windows::Forms::Panel^ userFormPanel;
	protected:

	private: System::Windows::Forms::TextBox^ passwordtxt;

	private: System::Windows::Forms::TextBox^ nametxt;

	private: System::Windows::Forms::Label^ namelabel;
	private: System::Windows::Forms::Label^ passwordlab;

	private: System::Windows::Forms::Panel^ Title;
	private: System::Windows::Forms::Label^ FormTitle;
	private: System::Windows::Forms::Button^ LoginBtn;

	private: System::Windows::Forms::Button^ RegisterBtn;
		   //Register^ registerForm;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->userFormPanel = (gcnew System::Windows::Forms::Panel());
			this->LoginBtn = (gcnew System::Windows::Forms::Button());
			this->RegisterBtn = (gcnew System::Windows::Forms::Button());
			this->passwordtxt = (gcnew System::Windows::Forms::TextBox());
			this->nametxt = (gcnew System::Windows::Forms::TextBox());
			this->namelabel = (gcnew System::Windows::Forms::Label());
			this->passwordlab = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Panel());
			this->FormTitle = (gcnew System::Windows::Forms::Label());
			this->userFormPanel->SuspendLayout();
			this->Title->SuspendLayout();
			this->SuspendLayout();
			// 
			// userFormPanel
			// 
			this->userFormPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->userFormPanel->Controls->Add(this->LoginBtn);
			this->userFormPanel->Controls->Add(this->RegisterBtn);
			this->userFormPanel->Controls->Add(this->passwordtxt);
			this->userFormPanel->Controls->Add(this->nametxt);
			this->userFormPanel->Controls->Add(this->namelabel);
			this->userFormPanel->Controls->Add(this->passwordlab);
			this->userFormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->userFormPanel->Location = System::Drawing::Point(0, 54);
			this->userFormPanel->Name = L"userFormPanel";
			this->userFormPanel->Size = System::Drawing::Size(337, 326);
			this->userFormPanel->TabIndex = 10;
			// 
			// LoginBtn
			// 
			this->LoginBtn->AccessibleName = L"LoginBtn";
			this->LoginBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LoginBtn->Location = System::Drawing::Point(174, 194);
			this->LoginBtn->Name = L"LoginBtn";
			this->LoginBtn->Size = System::Drawing::Size(134, 41);
			this->LoginBtn->TabIndex = 8;
			this->LoginBtn->Text = L"تسجيل الدخول";
			this->LoginBtn->UseVisualStyleBackColor = true;
			this->LoginBtn->Click += gcnew System::EventHandler(this, &Login::LoginBtn_Click);
			// 
			// RegisterBtn
			// 
			this->RegisterBtn->AccessibleName = L"RegisterBtn";
			this->RegisterBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->RegisterBtn->Location = System::Drawing::Point(34, 194);
			this->RegisterBtn->Name = L"RegisterBtn";
			this->RegisterBtn->Size = System::Drawing::Size(134, 41);
			this->RegisterBtn->TabIndex = 9;
			this->RegisterBtn->Text = L"انشاء حساب";
			this->RegisterBtn->UseVisualStyleBackColor = true;
			this->RegisterBtn->Click += gcnew System::EventHandler(this, &Login::RegisterBtn_Click);
			// 
			// passwordtxt
			// 
			this->passwordtxt->AccessibleName = L"passwordtxt";
			this->passwordtxt->Location = System::Drawing::Point(46, 136);
			this->passwordtxt->Multiline = true;
			this->passwordtxt->Name = L"passwordtxt";
			this->passwordtxt->PasswordChar = '*';
			this->passwordtxt->Size = System::Drawing::Size(254, 33);
			this->passwordtxt->TabIndex = 3;
			this->passwordtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->passwordtxt->UseSystemPasswordChar = true;
			// 
			// nametxt
			// 
			this->nametxt->AccessibleName = L"nametxt";
			this->nametxt->Location = System::Drawing::Point(46, 54);
			this->nametxt->Margin = System::Windows::Forms::Padding(0);
			this->nametxt->Multiline = true;
			this->nametxt->Name = L"nametxt";
			this->nametxt->Size = System::Drawing::Size(254, 33);
			this->nametxt->TabIndex = 4;
			this->nametxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nametxt->UseSystemPasswordChar = true;
			// 
			// namelabel
			// 
			this->namelabel->AccessibleName = L"namelabel";
			this->namelabel->AutoSize = true;
			this->namelabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->namelabel->Location = System::Drawing::Point(186, 21);
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
			this->passwordlab->Location = System::Drawing::Point(206, 101);
			this->passwordlab->Name = L"passwordlab";
			this->passwordlab->Size = System::Drawing::Size(92, 23);
			this->passwordlab->TabIndex = 6;
			this->passwordlab->Text = L"الرقم السري";
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Title->Controls->Add(this->FormTitle);
			this->Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->Title->Location = System::Drawing::Point(0, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(337, 54);
			this->Title->TabIndex = 11;
			// 
			// FormTitle
			// 
			this->FormTitle->AutoSize = true;
			this->FormTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->FormTitle->Location = System::Drawing::Point(97, 12);
			this->FormTitle->Name = L"FormTitle";
			this->FormTitle->Size = System::Drawing::Size(149, 31);
			this->FormTitle->TabIndex = 0;
			this->FormTitle->Text = L"تسجيل الدخول";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 380);
			this->Controls->Add(this->userFormPanel);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximumSize = System::Drawing::Size(359, 431);
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->userFormPanel->ResumeLayout(false);
			this->userFormPanel->PerformLayout();
			this->Title->ResumeLayout(false);
			this->Title->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	


};
}
