#pragma once
#include "../Models/CategoryModel.h"
#include "../Controllers/CategoryController.h"
#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"
#include "../Models/PharmacyModel.h"

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{

	public:PMST::Dashboard::Dashboard(UserModel^ user, PharmacyModel^ pharmacy);
		  UserModel^ currentUser;
		  PharmacyModel^ currentPharmacy;

	protected:
	private:
		//panels user controls
		System::Windows::Forms::Panel^ infoPanel;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::FlowLayoutPanel^ flowMainPanel;
		System::Windows::Forms::Button^ category;
		System::Windows::Forms::Button^ supplier;
		System::Windows::Forms::Button^ product;
		System::Windows::Forms::Panel^ Header;
		System::Windows::Forms::Panel^ FooterPanel;
		System::Windows::Forms::Panel^ RightPanel;
		System::Windows::Forms::FlowLayoutPanel^ NavPanel;
		System::Windows::Forms::Panel^ UserPanel;
		System::Windows::Forms::Panel^ CenterPanel;

		System::Windows::Forms::Button^ homeBtn;
		System::Windows::Forms::Button^ cashierBtn;
		System::Windows::Forms::Button^ productBtn;
		System::Windows::Forms::Button^ categoryBtn;
		System::Windows::Forms::Button^ supplierBtn;
		System::Windows::Forms::Button^ stockBtn;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ logo;

		System::Windows::Forms::Button^ close;
		System::Windows::Forms::Button^ minMax;
		System::Windows::Forms::Button^ minimize;
		System::Windows::Forms::Button^ collaps;
		System::Drawing::Image^ maximizeIcon;
		System::Drawing::Image^ minimizeIcon;
		System::ComponentModel::ComponentResourceManager^ resources;
		System::Windows::Forms::Button^ userBtn;
		System::Drawing::Image^ originalUserImage;
		System::Drawing::Image^ collapsedUserImage;
		System::Drawing::Image^ expandedUserImage;
		System::Windows::Forms::FlowLayoutPanel^ HomePanel;


	private: System::Windows::Forms::Panel^ cashierPanel;
	private: System::Windows::Forms::Panel^ stockPanel;
	private:System::Windows::Forms::Panel^ supplierPanel;
	private: System::Windows::Forms::Panel^ productPanel;
	private: System::Windows::Forms::Panel^ categoryPanel;
	private: System::Windows::Forms::Label^ pharmacyNameLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ pharmacyName;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ expandBtn;
	private: System::Windows::Forms::Button^ totalSales;
	private: System::Windows::Forms::FlowLayoutPanel^ fastNav;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::FlowLayoutPanel^ recentSalesPanel;
	private: System::Windows::Forms::DataGridView^ recentSalesTable;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::FlowLayoutPanel^ Cards;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ CardPanelHead;
	private: System::Windows::Forms::Label^ CardPanelTitle;
	private: System::Windows::Forms::Button^ button8;




















		   //DATABASE
	private:
		//UTILS FUNCTIONS
	private:
		Bitmap^ ResizeImage(Image^ image, int maxWidth, int maxHeight) {
			double ratioX = (double)maxWidth / image->Width;
			double ratioY = (double)maxHeight / image->Height;
			double ratio = Math::Min(ratioX, ratioY);

			int newWidth = (int)(image->Width * ratio);
			int newHeight = (int)(image->Height * ratio);

			Bitmap^ resizedImage = gcnew Bitmap(newWidth, newHeight);
			Graphics^ g = Graphics::FromImage(resizedImage);
			g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
			g->DrawImage(image, 0, 0, newWidth, newHeight);
			delete g;
			return resizedImage;
		}

		// Generic event handlers for all DataGridView controls
		System::Void DataGridView_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			// Get the DataGridView that triggered the event
			DataGridView^ dgv = safe_cast<DataGridView^>(sender);

			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewCell^ cell = dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
					static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(75)));
			}
			else if (e->RowIndex == -1 && e->ColumnIndex >= 0) {
				// Header hover effect
				dgv->Columns[e->ColumnIndex]->HeaderCell->Style->BackColor = System::Drawing::Color::FromArgb(
					static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
					static_cast<System::Int32>(static_cast<System::Byte>(80)));
			}
		}

		System::Void DataGridView_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			// Get the DataGridView that triggered the event
			DataGridView^ dgv = safe_cast<DataGridView^>(sender);

			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewCell^ cell = dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				if (e->RowIndex % 2 == 0) {
					cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
						static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
				}
				else {
					cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
						static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
				}
			}
			else if (e->RowIndex == -1 && e->ColumnIndex >= 0) {
				// Reset header hover effect
				dgv->Columns[e->ColumnIndex]->HeaderCell->Style->BackColor = System::Drawing::Color::FromArgb(
					static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
					static_cast<System::Int32>(static_cast<System::Byte>(65)));
			}
		}

		System::Void DataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			// Get the DataGridView that triggered the event
			DataGridView^ dgv = safe_cast<DataGridView^>(sender);

			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewCell^ cell = dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				// Handle cell click event here
				// Example: MessageBox::Show("Cell clicked: " + cell->Value);

				// You might want to handle differently based on which table was clicked
				// Example:
				if (dgv->Name == "recentSalesTable") {
					// Handle recentSalesTable click
				}
				else if (dgv->Name == "inventoryTable") {
					// Handle inventoryTable click
				}
			}
		}
		void UpdateUserInfoDisplay(); // New method to update UI


	private: System::Windows::Forms::Button^ cashier;


		   ~Dashboard()
		   {
			   if (components)
			   {
				   delete components;
			   }
			   if (maximizeIcon) delete maximizeIcon;
			   if (minimizeIcon) delete minimizeIcon;
		   }

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Header = (gcnew System::Windows::Forms::Panel());
			this->minMax = (gcnew System::Windows::Forms::Button());
			this->minimize = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->logo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FooterPanel = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pharmacyName = (gcnew System::Windows::Forms::Label());
			this->pharmacyNameLabel = (gcnew System::Windows::Forms::Label());
			this->RightPanel = (gcnew System::Windows::Forms::Panel());
			this->NavPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->homeBtn = (gcnew System::Windows::Forms::Button());
			this->cashierBtn = (gcnew System::Windows::Forms::Button());
			this->productBtn = (gcnew System::Windows::Forms::Button());
			this->categoryBtn = (gcnew System::Windows::Forms::Button());
			this->supplierBtn = (gcnew System::Windows::Forms::Button());
			this->stockBtn = (gcnew System::Windows::Forms::Button());
			this->UserPanel = (gcnew System::Windows::Forms::Panel());
			this->userBtn = (gcnew System::Windows::Forms::Button());
			this->collaps = (gcnew System::Windows::Forms::Button());
			this->expandBtn = (gcnew System::Windows::Forms::Button());
			this->CenterPanel = (gcnew System::Windows::Forms::Panel());
			this->categoryPanel = (gcnew System::Windows::Forms::Panel());
			this->HomePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->fastNav = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->totalSales = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->recentSalesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->recentSalesTable = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cards = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CardPanelHead = (gcnew System::Windows::Forms::Panel());
			this->CardPanelTitle = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->cashierPanel = (gcnew System::Windows::Forms::Panel());
			this->stockPanel = (gcnew System::Windows::Forms::Panel());
			this->supplierPanel = (gcnew System::Windows::Forms::Panel());
			this->productPanel = (gcnew System::Windows::Forms::Panel());
			this->Header->SuspendLayout();
			this->FooterPanel->SuspendLayout();
			this->RightPanel->SuspendLayout();
			this->NavPanel->SuspendLayout();
			this->UserPanel->SuspendLayout();
			this->CenterPanel->SuspendLayout();
			this->HomePanel->SuspendLayout();
			this->fastNav->SuspendLayout();
			this->recentSalesPanel->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recentSalesTable))->BeginInit();
			this->Cards->SuspendLayout();
			this->CardPanelHead->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->AccessibleName = L"headerPanel";
			this->Header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Header->Controls->Add(this->minMax);
			this->Header->Controls->Add(this->minimize);
			this->Header->Controls->Add(this->close);
			this->Header->Controls->Add(this->logo);
			this->Header->Controls->Add(this->label1);
			this->Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Margin = System::Windows::Forms::Padding(4);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(1920, 84);
			this->Header->TabIndex = 0;
			// 
			// minMax
			// 
			this->minMax->AccessibleName = L"minMax";
			this->minMax->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minMax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->minMax->FlatAppearance->BorderSize = 0;
			this->minMax->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minMax->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->minMax->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minMax.Image")));
			this->minMax->Location = System::Drawing::Point(1829, 26);
			this->minMax->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->minMax->Name = L"minMax";
			this->minMax->Size = System::Drawing::Size(30, 30);
			this->minMax->TabIndex = 3;
			this->minMax->UseVisualStyleBackColor = false;
			this->minMax->Visible = false;
			this->minMax->Click += gcnew System::EventHandler(this, &Dashboard::button5_Click_1);
			// 
			// minimize
			// 
			this->minimize->AccessibleName = L"cashierBtn";
			this->minimize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minimize->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->minimize->FlatAppearance->BorderSize = 0;
			this->minimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimize->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->minimize->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize.Image")));
			this->minimize->Location = System::Drawing::Point(1791, 26);
			this->minimize->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->minimize->Name = L"minimize";
			this->minimize->Size = System::Drawing::Size(30, 30);
			this->minimize->TabIndex = 3;
			this->minimize->UseVisualStyleBackColor = false;
			this->minimize->Click += gcnew System::EventHandler(this, &Dashboard::minimize_Click);
			// 
			// close
			// 
			this->close->AccessibleName = L"close";
			this->close->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.Image")));
			this->close->Location = System::Drawing::Point(1867, 26);
			this->close->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(30, 30);
			this->close->TabIndex = 3;
			this->close->UseVisualStyleBackColor = false;
			this->close->Click += gcnew System::EventHandler(this, &Dashboard::button4_Click);
			// 
			// logo
			// 
			this->logo->AutoSize = true;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(11, 5);
			this->logo->Margin = System::Windows::Forms::Padding(5, 5, 2, 0);
			this->logo->MaximumSize = System::Drawing::Size(0, 80);
			this->logo->MinimumSize = System::Drawing::Size(250, 20);
			this->logo->Name = L"logo";
			this->logo->Padding = System::Windows::Forms::Padding(40, 35, 70, 35);
			this->logo->Size = System::Drawing::Size(250, 80);
			this->logo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AccessibleName = L"AppTitle";
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(615, 22);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L" ...مدير الصيدلية";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FooterPanel
			// 
			this->FooterPanel->AccessibleName = L"FooterPanel";
			this->FooterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FooterPanel->Controls->Add(this->label4);
			this->FooterPanel->Controls->Add(this->label3);
			this->FooterPanel->Controls->Add(this->pharmacyName);
			this->FooterPanel->Controls->Add(this->pharmacyNameLabel);
			this->FooterPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->FooterPanel->Location = System::Drawing::Point(0, 774);
			this->FooterPanel->Margin = System::Windows::Forms::Padding(4);
			this->FooterPanel->Name = L"FooterPanel";
			this->FooterPanel->Size = System::Drawing::Size(1920, 108);
			this->FooterPanel->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AccessibleName = L"pharmacyName";
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Silver;
			this->label4->Location = System::Drawing::Point(9, 48);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(192, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"All rights reserved.";
			this->label4->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// label3
			// 
			this->label3->AccessibleName = L"pharmacyName";
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Silver;
			this->label3->Location = System::Drawing::Point(2, 19);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(313, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Copyright © 2025 Cyto0plasm .";
			this->label3->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// pharmacyName
			// 
			this->pharmacyName->AccessibleName = L"pharmacyName";
			this->pharmacyName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyName->AutoSize = true;
			this->pharmacyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyName->ForeColor = System::Drawing::Color::Lime;
			this->pharmacyName->Location = System::Drawing::Point(1666, 35);
			this->pharmacyName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyName->Name = L"pharmacyName";
			this->pharmacyName->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyName->Size = System::Drawing::Size(0, 38);
			this->pharmacyName->TabIndex = 0;
			this->pharmacyName->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// pharmacyNameLabel
			// 
			this->pharmacyNameLabel->AccessibleName = L"pharmacyNameLabel";
			this->pharmacyNameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyNameLabel->AutoSize = true;
			this->pharmacyNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->Location = System::Drawing::Point(1708, 37);
			this->pharmacyNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
			this->pharmacyNameLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyNameLabel->Size = System::Drawing::Size(0, 38);
			this->pharmacyNameLabel->TabIndex = 0;
			this->pharmacyNameLabel->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// RightPanel
			// 
			this->RightPanel->AccessibleName = L"RightPanel";
			this->RightPanel->Controls->Add(this->NavPanel);
			this->RightPanel->Controls->Add(this->UserPanel);
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->RightPanel->Location = System::Drawing::Point(1660, 84);
			this->RightPanel->Margin = System::Windows::Forms::Padding(4);
			this->RightPanel->MaximumSize = System::Drawing::Size(260, 690);
			this->RightPanel->MinimumSize = System::Drawing::Size(70, 690);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(260, 690);
			this->RightPanel->TabIndex = 2;
			// 
			// NavPanel
			// 
			this->NavPanel->AccessibleName = L"NavPanel";
			this->NavPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NavPanel->Controls->Add(this->homeBtn);
			this->NavPanel->Controls->Add(this->cashierBtn);
			this->NavPanel->Controls->Add(this->productBtn);
			this->NavPanel->Controls->Add(this->categoryBtn);
			this->NavPanel->Controls->Add(this->supplierBtn);
			this->NavPanel->Controls->Add(this->stockBtn);
			this->NavPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NavPanel->Location = System::Drawing::Point(0, 146);
			this->NavPanel->Margin = System::Windows::Forms::Padding(4);
			this->NavPanel->MaximumSize = System::Drawing::Size(294, 711);
			this->NavPanel->Name = L"NavPanel";
			this->NavPanel->Size = System::Drawing::Size(260, 544);
			this->NavPanel->TabIndex = 1;
			// 
			// homeBtn
			// 
			this->homeBtn->AccessibleName = L"homeBtn";
			this->homeBtn->AutoEllipsis = true;
			this->homeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->homeBtn->FlatAppearance->BorderSize = 0;
			this->homeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->homeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->homeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"homeBtn.Image")));
			this->homeBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->homeBtn->Location = System::Drawing::Point(4, 6);
			this->homeBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->homeBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->homeBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->homeBtn->Name = L"homeBtn";
			this->homeBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->homeBtn->Size = System::Drawing::Size(250, 80);
			this->homeBtn->TabIndex = 1;
			this->homeBtn->Text = L"الرئيسية";
			this->homeBtn->UseVisualStyleBackColor = false;
			this->homeBtn->Click += gcnew System::EventHandler(this, &Dashboard::homeBtn_Click);
			// 
			// cashierBtn
			// 
			this->cashierBtn->AccessibleName = L"cashierBtn";
			this->cashierBtn->AutoEllipsis = true;
			this->cashierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->cashierBtn->FlatAppearance->BorderSize = 0;
			this->cashierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cashierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->cashierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cashierBtn.Image")));
			this->cashierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->cashierBtn->Location = System::Drawing::Point(4, 96);
			this->cashierBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->cashierBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->cashierBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->cashierBtn->Name = L"cashierBtn";
			this->cashierBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->cashierBtn->Size = System::Drawing::Size(250, 80);
			this->cashierBtn->TabIndex = 2;
			this->cashierBtn->Text = L"كاشير";
			this->cashierBtn->UseVisualStyleBackColor = false;
			this->cashierBtn->Click += gcnew System::EventHandler(this, &Dashboard::cashierBtn_Click);
			// 
			// productBtn
			// 
			this->productBtn->AccessibleName = L"productBtn";
			this->productBtn->AutoEllipsis = true;
			this->productBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->productBtn->FlatAppearance->BorderSize = 0;
			this->productBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->productBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->productBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"productBtn.Image")));
			this->productBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->productBtn->Location = System::Drawing::Point(4, 186);
			this->productBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->productBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->productBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->productBtn->Name = L"productBtn";
			this->productBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->productBtn->Size = System::Drawing::Size(250, 80);
			this->productBtn->TabIndex = 3;
			this->productBtn->Text = L"المنتجات";
			this->productBtn->UseVisualStyleBackColor = false;
			this->productBtn->Click += gcnew System::EventHandler(this, &Dashboard::productBtn_Click);
			// 
			// categoryBtn
			// 
			this->categoryBtn->AccessibleName = L"categoryBtn";
			this->categoryBtn->AutoEllipsis = true;
			this->categoryBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->categoryBtn->FlatAppearance->BorderSize = 0;
			this->categoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->categoryBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->categoryBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"categoryBtn.Image")));
			this->categoryBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->categoryBtn->Location = System::Drawing::Point(4, 276);
			this->categoryBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->categoryBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->categoryBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->categoryBtn->Name = L"categoryBtn";
			this->categoryBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->categoryBtn->Size = System::Drawing::Size(250, 80);
			this->categoryBtn->TabIndex = 4;
			this->categoryBtn->Text = L"الاصناف";
			this->categoryBtn->UseVisualStyleBackColor = false;
			this->categoryBtn->Click += gcnew System::EventHandler(this, &Dashboard::categoryBtn_Click);
			// 
			// supplierBtn
			// 
			this->supplierBtn->AccessibleName = L"supplierBtn";
			this->supplierBtn->AutoEllipsis = true;
			this->supplierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->supplierBtn->FlatAppearance->BorderSize = 0;
			this->supplierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->supplierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->supplierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"supplierBtn.Image")));
			this->supplierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->supplierBtn->Location = System::Drawing::Point(4, 366);
			this->supplierBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->supplierBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->supplierBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->supplierBtn->Name = L"supplierBtn";
			this->supplierBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->supplierBtn->Size = System::Drawing::Size(250, 80);
			this->supplierBtn->TabIndex = 5;
			this->supplierBtn->Text = L"الموردين";
			this->supplierBtn->UseVisualStyleBackColor = false;
			this->supplierBtn->Click += gcnew System::EventHandler(this, &Dashboard::supplierBtn_Click);
			// 
			// stockBtn
			// 
			this->stockBtn->AccessibleName = L"stockBtn";
			this->stockBtn->AutoEllipsis = true;
			this->stockBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->stockBtn->FlatAppearance->BorderSize = 0;
			this->stockBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->stockBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->stockBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stockBtn.Image")));
			this->stockBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->stockBtn->Location = System::Drawing::Point(4, 456);
			this->stockBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->stockBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->stockBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->stockBtn->Name = L"stockBtn";
			this->stockBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->stockBtn->Size = System::Drawing::Size(250, 80);
			this->stockBtn->TabIndex = 6;
			this->stockBtn->Text = L"المخزون";
			this->stockBtn->UseVisualStyleBackColor = false;
			this->stockBtn->Click += gcnew System::EventHandler(this, &Dashboard::stockBtn_Click);
			// 
			// UserPanel
			// 
			this->UserPanel->AccessibleName = L"UserPanel";
			this->UserPanel->Controls->Add(this->userBtn);
			this->UserPanel->Controls->Add(this->collaps);
			this->UserPanel->Controls->Add(this->expandBtn);
			this->UserPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserPanel->Location = System::Drawing::Point(0, 0);
			this->UserPanel->Margin = System::Windows::Forms::Padding(4);
			this->UserPanel->Name = L"UserPanel";
			this->UserPanel->Size = System::Drawing::Size(260, 146);
			this->UserPanel->TabIndex = 0;
			// 
			// userBtn
			// 
			this->userBtn->AccessibleName = L"userBtn";
			this->userBtn->AutoEllipsis = true;
			this->userBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->userBtn->FlatAppearance->BorderSize = 0;
			this->userBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->userBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userBtn.Image")));
			this->userBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->userBtn->Location = System::Drawing::Point(5, 42);
			this->userBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->userBtn->MaximumSize = System::Drawing::Size(250, 96);
			this->userBtn->MinimumSize = System::Drawing::Size(80, 96);
			this->userBtn->Name = L"userBtn";
			this->userBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->userBtn->Size = System::Drawing::Size(250, 96);
			this->userBtn->TabIndex = 5;
			this->userBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->userBtn->UseVisualStyleBackColor = false;
			// 
			// collaps
			// 
			this->collaps->AccessibleName = L"collapsBtn";
			this->collaps->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->collaps->FlatAppearance->BorderSize = 0;
			this->collaps->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->collaps->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->collaps->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"collaps.Image")));
			this->collaps->Location = System::Drawing::Point(19, 10);
			this->collaps->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->collaps->Name = L"collaps";
			this->collaps->Size = System::Drawing::Size(30, 30);
			this->collaps->TabIndex = 3;
			this->collaps->UseVisualStyleBackColor = false;
			this->collaps->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// expandBtn
			// 
			this->expandBtn->AccessibleName = L"expandBtn";
			this->expandBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->expandBtn->FlatAppearance->BorderSize = 0;
			this->expandBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->expandBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->expandBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expandBtn.Image")));
			this->expandBtn->Location = System::Drawing::Point(19, 10);
			this->expandBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->expandBtn->Name = L"expandBtn";
			this->expandBtn->Size = System::Drawing::Size(30, 30);
			this->expandBtn->TabIndex = 3;
			this->expandBtn->UseVisualStyleBackColor = false;
			this->expandBtn->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// CenterPanel
			// 
			this->CenterPanel->AccessibleName = L"Home";
			this->CenterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CenterPanel->Controls->Add(this->categoryPanel);
			this->CenterPanel->Controls->Add(this->HomePanel);
			this->CenterPanel->Controls->Add(this->cashierPanel);
			this->CenterPanel->Controls->Add(this->stockPanel);
			this->CenterPanel->Controls->Add(this->supplierPanel);
			this->CenterPanel->Controls->Add(this->productPanel);
			this->CenterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterPanel->Location = System::Drawing::Point(0, 84);
			this->CenterPanel->Margin = System::Windows::Forms::Padding(4);
			this->CenterPanel->Name = L"CenterPanel";
			this->CenterPanel->Size = System::Drawing::Size(1660, 690);
			this->CenterPanel->TabIndex = 3;
			// 
			// categoryPanel
			// 
			this->categoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->categoryPanel->Location = System::Drawing::Point(0, 0);
			this->categoryPanel->Margin = System::Windows::Forms::Padding(2);
			this->categoryPanel->Name = L"categoryPanel";
			this->categoryPanel->Size = System::Drawing::Size(1658, 688);
			this->categoryPanel->TabIndex = 2;
			// 
			// HomePanel
			// 
			this->HomePanel->Controls->Add(this->fastNav);
			this->HomePanel->Controls->Add(this->recentSalesPanel);
			this->HomePanel->Controls->Add(this->Cards);
			this->HomePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePanel->Location = System::Drawing::Point(0, 0);
			this->HomePanel->Margin = System::Windows::Forms::Padding(2);
			this->HomePanel->Name = L"HomePanel";
			this->HomePanel->Size = System::Drawing::Size(1658, 688);
			this->HomePanel->TabIndex = 0;
			// 
			// fastNav
			// 
			this->fastNav->AutoSize = true;
			this->fastNav->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->fastNav->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fastNav->Controls->Add(this->totalSales);
			this->fastNav->Controls->Add(this->button8);
			this->fastNav->Controls->Add(this->button1);
			this->fastNav->Controls->Add(this->button2);
			this->fastNav->Controls->Add(this->button3);
			this->fastNav->Dock = System::Windows::Forms::DockStyle::Top;
			this->fastNav->Location = System::Drawing::Point(0, 0);
			this->fastNav->Margin = System::Windows::Forms::Padding(0);
			this->fastNav->MinimumSize = System::Drawing::Size(1900, 110);
			this->fastNav->Name = L"fastNav";
			this->fastNav->Size = System::Drawing::Size(1900, 112);
			this->fastNav->TabIndex = 1;
			// 
			// totalSales
			// 
			this->totalSales->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->totalSales->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->totalSales->FlatAppearance->BorderSize = 0;
			this->totalSales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->totalSales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalSales->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->totalSales->Location = System::Drawing::Point(3, 3);
			this->totalSales->Name = L"totalSales";
			this->totalSales->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->totalSales->Size = System::Drawing::Size(328, 104);
			this->totalSales->TabIndex = 0;
			this->totalSales->Text = L"الة حاسبة";
			this->totalSales->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button8->Location = System::Drawing::Point(337, 3);
			this->button8->Name = L"button8";
			this->button8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button8->Size = System::Drawing::Size(328, 104);
			this->button8->TabIndex = 0;
			this->button8->Text = L"المورد المتميز";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button1->Location = System::Drawing::Point(671, 3);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button1->Size = System::Drawing::Size(328, 104);
			this->button1->TabIndex = 0;
			this->button1->Text = L"اضافة مورد";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button2->Location = System::Drawing::Point(1005, 3);
			this->button2->Name = L"button2";
			this->button2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button2->Size = System::Drawing::Size(328, 104);
			this->button2->TabIndex = 0;
			this->button2->Text = L"اضافة صنف";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button3->Location = System::Drawing::Point(1339, 3);
			this->button3->Name = L"button3";
			this->button3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button3->Size = System::Drawing::Size(328, 104);
			this->button3->TabIndex = 0;
			this->button3->Text = L"اضافة منتج";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// recentSalesPanel
			// 
			this->recentSalesPanel->Controls->Add(this->panel7);
			this->recentSalesPanel->Controls->Add(this->recentSalesTable);
			this->recentSalesPanel->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->recentSalesPanel->Location = System::Drawing::Point(5, 122);
			this->recentSalesPanel->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->recentSalesPanel->Name = L"recentSalesPanel";
			this->recentSalesPanel->Size = System::Drawing::Size(798, 439);
			this->recentSalesPanel->TabIndex = 2;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->label2);
			this->panel7->Location = System::Drawing::Point(6, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(789, 79);
			this->panel7->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoEllipsis = true;
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(242, 22);
			this->label2->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 34);
			this->label2->TabIndex = 7;
			this->label2->Text = L"اخر الفواتير";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// recentSalesTable
			// 
			this->recentSalesTable->AccessibleName = L"recentSalesTable";
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->recentSalesTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->recentSalesTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->recentSalesTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->recentSalesTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->recentSalesTable->ColumnHeadersHeight = 50;
			this->recentSalesTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->recentSalesTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle4->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->DefaultCellStyle = dataGridViewCellStyle4;
			this->recentSalesTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->recentSalesTable->EnableHeadersVisualStyles = false;
			this->recentSalesTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->recentSalesTable->Location = System::Drawing::Point(9, 95);
			this->recentSalesTable->Margin = System::Windows::Forms::Padding(10);
			this->recentSalesTable->Name = L"recentSalesTable";
			this->recentSalesTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->recentSalesTable->RowHeadersVisible = false;
			this->recentSalesTable->RowHeadersWidth = 51;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle5->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->recentSalesTable->RowTemplate->Height = 40;
			this->recentSalesTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->recentSalesTable->Size = System::Drawing::Size(779, 335);
			this->recentSalesTable->StandardTab = true;
			this->recentSalesTable->TabIndex = 0;
			this->recentSalesTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::recentSalesTable_CellClick_1);
			this->recentSalesTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::recentSalesTable_CellMouseEnter);
			this->recentSalesTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::recentSalesTable_CellMouseLeave);
			this->recentSalesTable->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Dashboard::recentSalesTable_DataBindingComplete);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->DataPropertyName = L"id";
			this->dataGridViewTextBoxColumn1->HeaderText = L"رقم الفاتورة";
			this->dataGridViewTextBoxColumn1->MaxInputLength = 10;
			this->dataGridViewTextBoxColumn1->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ToolTipText = L"الرقم التعريفي للفاتورة";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->DataPropertyName = L"createdAt";
			this->dataGridViewTextBoxColumn2->HeaderText = L"التاريخ";
			this->dataGridViewTextBoxColumn2->MaxInputLength = 15;
			this->dataGridViewTextBoxColumn2->MinimumWidth = 100;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ToolTipText = L"تاريخ دفع الفاتورة";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->DataPropertyName = L"quantity";
			this->dataGridViewTextBoxColumn3->HeaderText = L"الكمية";
			this->dataGridViewTextBoxColumn3->MaxInputLength = 20;
			this->dataGridViewTextBoxColumn3->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->DataPropertyName = L"total_price";
			dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(8);
			this->dataGridViewTextBoxColumn4->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewTextBoxColumn4->HeaderText = L"المبلغ ";
			this->dataGridViewTextBoxColumn4->MaxInputLength = 50;
			this->dataGridViewTextBoxColumn4->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// Cards
			// 
			this->Cards->Controls->Add(this->CardPanelHead);
			this->Cards->Controls->Add(this->panel5);
			this->Cards->Controls->Add(this->panel3);
			this->Cards->Controls->Add(this->panel4);
			this->Cards->Controls->Add(this->panel6);
			this->Cards->Location = System::Drawing::Point(813, 122);
			this->Cards->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->Cards->MaximumSize = System::Drawing::Size(840, 600);
			this->Cards->Name = L"Cards";
			this->Cards->Size = System::Drawing::Size(837, 439);
			this->Cards->TabIndex = 4;
			// 
			// CardPanelHead
			// 
			this->CardPanelHead->Controls->Add(this->CardPanelTitle);
			this->CardPanelHead->Location = System::Drawing::Point(5, 3);
			this->CardPanelHead->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->CardPanelHead->Name = L"CardPanelHead";
			this->CardPanelHead->Size = System::Drawing::Size(813, 79);
			this->CardPanelHead->TabIndex = 8;
			// 
			// CardPanelTitle
			// 
			this->CardPanelTitle->AutoEllipsis = true;
			this->CardPanelTitle->AutoSize = true;
			this->CardPanelTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CardPanelTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CardPanelTitle->ForeColor = System::Drawing::Color::White;
			this->CardPanelTitle->Location = System::Drawing::Point(350, 22);
			this->CardPanelTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->CardPanelTitle->Name = L"CardPanelTitle";
			this->CardPanelTitle->Size = System::Drawing::Size(140, 34);
			this->CardPanelTitle->TabIndex = 7;
			this->CardPanelTitle->Text = L"احصائيات";
			this->CardPanelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->listBox3);
			this->panel5->Controls->Add(this->button6);
			this->panel5->Location = System::Drawing::Point(10, 95);
			this->panel5->Margin = System::Windows::Forms::Padding(10);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(394, 157);
			this->panel5->TabIndex = 5;
			// 
			// listBox3
			// 
			this->listBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->listBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox3->ForeColor = System::Drawing::Color::White;
			this->listBox3->FormattingEnabled = true;
			this->listBox3->IntegralHeight = false;
			this->listBox3->ItemHeight = 28;
			this->listBox3->Location = System::Drawing::Point(0, 40);
			this->listBox3->Name = L"listBox3";
			this->listBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox3->Size = System::Drawing::Size(394, 117);
			this->listBox3->TabIndex = 1;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button6->Dock = System::Windows::Forms::DockStyle::Top;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button6->Location = System::Drawing::Point(0, 0);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button6->Size = System::Drawing::Size(394, 40);
			this->button6->TabIndex = 0;
			this->button6->Text = L"احدث المنتجات";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->listBox1);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Location = System::Drawing::Point(424, 95);
			this->panel3->Margin = System::Windows::Forms::Padding(10);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(394, 157);
			this->panel3->TabIndex = 3;
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->ForeColor = System::Drawing::Color::White;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->IntegralHeight = false;
			this->listBox1->ItemHeight = 28;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"ارباح اليوم:", L"ارباح الشهر:", L"ارباح السنة:" });
			this->listBox1->Location = System::Drawing::Point(0, 40);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox1->Size = System::Drawing::Size(394, 117);
			this->listBox1->TabIndex = 1;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button4->Size = System::Drawing::Size(394, 40);
			this->button4->TabIndex = 0;
			this->button4->Text = L"الارباح";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->listBox2);
			this->panel4->Controls->Add(this->button5);
			this->panel4->Location = System::Drawing::Point(10, 272);
			this->panel4->Margin = System::Windows::Forms::Padding(10);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(394, 157);
			this->panel4->TabIndex = 4;
			// 
			// listBox2
			// 
			this->listBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->listBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->ForeColor = System::Drawing::Color::White;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->IntegralHeight = false;
			this->listBox2->ItemHeight = 28;
			this->listBox2->Location = System::Drawing::Point(0, 40);
			this->listBox2->Name = L"listBox2";
			this->listBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox2->Size = System::Drawing::Size(394, 117);
			this->listBox2->TabIndex = 1;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button5->Location = System::Drawing::Point(0, 0);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button5->Size = System::Drawing::Size(394, 40);
			this->button5->TabIndex = 0;
			this->button5->Text = L"احدث الاصناف";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->listBox4);
			this->panel6->Controls->Add(this->button7);
			this->panel6->Location = System::Drawing::Point(424, 272);
			this->panel6->Margin = System::Windows::Forms::Padding(10);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(394, 157);
			this->panel6->TabIndex = 6;
			// 
			// listBox4
			// 
			this->listBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->listBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox4->ForeColor = System::Drawing::Color::White;
			this->listBox4->FormattingEnabled = true;
			this->listBox4->IntegralHeight = false;
			this->listBox4->ItemHeight = 28;
			this->listBox4->Location = System::Drawing::Point(0, 40);
			this->listBox4->Name = L"listBox4";
			this->listBox4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox4->Size = System::Drawing::Size(394, 117);
			this->listBox4->TabIndex = 1;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button7->Size = System::Drawing::Size(394, 40);
			this->button7->TabIndex = 0;
			this->button7->Text = L"احدث الموردين";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// cashierPanel
			// 
			this->cashierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cashierPanel->Location = System::Drawing::Point(0, 0);
			this->cashierPanel->Margin = System::Windows::Forms::Padding(2);
			this->cashierPanel->Name = L"cashierPanel";
			this->cashierPanel->Size = System::Drawing::Size(1658, 688);
			this->cashierPanel->TabIndex = 1;
			// 
			// stockPanel
			// 
			this->stockPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->stockPanel->Location = System::Drawing::Point(0, 0);
			this->stockPanel->Margin = System::Windows::Forms::Padding(2);
			this->stockPanel->Name = L"stockPanel";
			this->stockPanel->Size = System::Drawing::Size(1658, 688);
			this->stockPanel->TabIndex = 5;
			// 
			// supplierPanel
			// 
			this->supplierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->supplierPanel->Location = System::Drawing::Point(0, 0);
			this->supplierPanel->Margin = System::Windows::Forms::Padding(2);
			this->supplierPanel->Name = L"supplierPanel";
			this->supplierPanel->Size = System::Drawing::Size(1658, 688);
			this->supplierPanel->TabIndex = 4;
			// 
			// productPanel
			// 
			this->productPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->productPanel->Location = System::Drawing::Point(0, 0);
			this->productPanel->Margin = System::Windows::Forms::Padding(2);
			this->productPanel->Name = L"productPanel";
			this->productPanel->Size = System::Drawing::Size(1658, 688);
			this->productPanel->TabIndex = 3;
			// 
			// Dashboard
			// 
			this->AccessibleName = L"DashboardFrame";
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(1920, 882);
			this->Controls->Add(this->CenterPanel);
			this->Controls->Add(this->RightPanel);
			this->Controls->Add(this->FooterPanel);
			this->Controls->Add(this->Header);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimizeBox = false;
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->FooterPanel->ResumeLayout(false);
			this->FooterPanel->PerformLayout();
			this->RightPanel->ResumeLayout(false);
			this->NavPanel->ResumeLayout(false);
			this->UserPanel->ResumeLayout(false);
			this->CenterPanel->ResumeLayout(false);
			this->HomePanel->ResumeLayout(false);
			this->HomePanel->PerformLayout();
			this->fastNav->ResumeLayout(false);
			this->recentSalesPanel->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recentSalesTable))->EndInit();
			this->Cards->ResumeLayout(false);
			this->CardPanelHead->ResumeLayout(false);
			this->CardPanelHead->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == System::Windows::Forms::FormWindowState::Normal)
		{
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}
		else
		{
			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the application
		//this->Close();
		//Environment::Exit(0);
		Application::Exit();
	}

	private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Normal) {
			this->WindowState = FormWindowState::Maximized;
			if (this->minimizeIcon != nullptr) {
				//this->minMax->Image = this->minimizeIcon;
			}
		}
		else {
			this->WindowState = FormWindowState::Normal;
			if (this->maximizeIcon != nullptr) {
				//this->minMax->Image = this->maximizeIcon;
			}
		}
		this->minMax->Refresh();

	}
	private: System::Void minimize_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Normal) {
			this->WindowState = FormWindowState::Minimized;
		}
		else {
			this->WindowState = FormWindowState::Normal;
		}
		this->minMax->Refresh();
	}

	private: System::Void collaps_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->RightPanel->Width > 200) {
			this->RightPanel->Width = 70;
			array<Button^>^ navButtons = {
			   homeBtn, cashierBtn, productBtn,
			   categoryBtn, supplierBtn, stockBtn
			};

			for each (Button ^ btn in navButtons) {
				btn->Text = "";
				btn->ImageAlign = ContentAlignment::MiddleCenter;
				btn->Padding = System::Windows::Forms::Padding(0);
				btn->Width = 45; // Set fixed width for collapsed state
			}
			userBtn->Image = collapsedUserImage;
			userBtn->ImageAlign = ContentAlignment::MiddleLeft; // Center image when collapsed
			userBtn->TextImageRelation = TextImageRelation::ImageBeforeText;
			userBtn->Text = "";

			collaps->SendToBack();

		}
		else {
			this->RightPanel->Width = 260;
			homeBtn->Text = L"الرئيسية";
			cashierBtn->Text = L"كاشير";
			productBtn->Text = L"المنتجات";
			categoryBtn->Text = L"الاصناف";
			supplierBtn->Text = L"الموردين";
			stockBtn->Text = L"المخزون";
			array<Button^>^ navButtons = {
			   homeBtn, cashierBtn, productBtn,
			   categoryBtn, supplierBtn, stockBtn
			};

			for each (Button ^ btn in navButtons) {
				btn->ImageAlign = ContentAlignment::MiddleRight;
				btn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
				btn->Width = 280; // Restore original width
			}
			userBtn->Image = expandedUserImage;
			userBtn->ImageAlign = ContentAlignment::MiddleRight; // Align right when expanded
			userBtn->TextImageRelation = TextImageRelation::TextBeforeImage;
			//userBtn->Text = userName->IsNullOrEmpty?"اسم المستخدم": userName;
			userBtn->Text = L"اسم المستخدم";
			collaps->BringToFront();
		}
		this->RightPanel->Refresh();
	}

	private: System::Void homeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		HomePanel->BringToFront();
	}
	private: System::Void cashierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		cashierPanel->BringToFront();
	}
	private: System::Void productBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		productPanel->BringToFront();
	}
	private: System::Void categoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		categoryPanel->BringToFront();
	}
	private: System::Void supplierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		supplierPanel->BringToFront();
	}
	private: System::Void stockBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		stockPanel->BringToFront();
	}
	private: System::Void pharmacyName_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:System::Void recentSalesTable_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewCell^ cell = recentSalesTable->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
					static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(75)));
			}
			else if (e->RowIndex == -1 && e->ColumnIndex >= 0) {
				// Header hover effect
				recentSalesTable->Columns[e->ColumnIndex]->HeaderCell->Style->BackColor = System::Drawing::Color::FromArgb(
					static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
					static_cast<System::Int32>(static_cast<System::Byte>(80)));
			}
		}
	private:System::Void recentSalesTable_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewCell^ cell = recentSalesTable->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				if (e->RowIndex % 2 == 0) {
					cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
						static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
				}
				else {
					cell->Style->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
						static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
				}
			}
			else if (e->RowIndex == -1 && e->ColumnIndex >= 0) {
				// Reset header hover effect
				recentSalesTable->Columns[e->ColumnIndex]->HeaderCell->Style->BackColor = System::Drawing::Color::FromArgb(
					static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
					static_cast<System::Int32>(static_cast<System::Byte>(65)));
			}
		}
	private: System::Void recentSalesTable_CellClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
			DataGridViewCell^ cell = recentSalesTable->Rows[e->RowIndex]->Cells[e->ColumnIndex];
			// Handle cell click event here
			MessageBox::Show("Cell clicked: " + cell->Value);
		}
	}
	private: System::Void recentSalesTable_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		for (int i = 0; i < this->recentSalesTable->Rows->Count; i++) {
			DataGridViewRow^ row = this->recentSalesTable->Rows[i];
			row->Height = 40; // Ensure all rows have the same height
		}
	}
//Database	
//private: System::Void saveCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
//	String^ name = nameFeild->Text->Trim();
//	String^ description = descriptionFeild->Text->Trim();
//
//	if (String::IsNullOrEmpty(name))
//	{
//		MessageBox::Show("Category name cannot be empty.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
//		return;
//	}
//
//	PMST::CategoryModel^ newCategory = gcnew PMST::CategoryModel();
//	newCategory->Name = name;
//	newCategory->Description = description;
//
//	// IMPORTANT: set pharmacy_id properly
//	newCategory->Pharmacy_Id; // replace this!
//
//	PMST::CategoryController^ controller = gcnew PMST::CategoryController();
//	bool success = controller->CreateCategory(newCategory);
//
//	if (success)
//	{
//		MessageBox::Show("Category saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
//
//		// Clear fields after success
//		nameFeild->Text = "";
//		descriptionFeild->Text = "";
//	}
//	else
//	{
//		MessageBox::Show("Failed to save category.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//	}
//	}
//	







private: System::Void ctor() {
	this->InitializeComponent();
}
};
}

