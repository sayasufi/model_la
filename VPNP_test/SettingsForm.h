#pragma once
#include "MainForm.h"

namespace VPNPtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		VPNPtest::MainForm^ mf;
		void SetIP(String^ IP, String^ Port);

		SettingsForm(void)
		{
			InitializeComponent();
//			MFI_IP = gcnew String ("192.168.001.001");
//			MFI_port = gcnew String("1001");
			this->IP_text->Text = MFI_IP;
			this->PortNmb->Text = MFI_port;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ IP_text;
	private: System::Windows::Forms::TextBox^ PortNmb;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ bt_OK;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		String^ MFI_IP;
		String^ MFI_port;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cb_VPNPselect;

		   /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bt_OK = (gcnew System::Windows::Forms::Button());
			this->PortNmb = (gcnew System::Windows::Forms::TextBox());
			this->IP_text = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cb_VPNPselect = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Адрес сети МФИ\r\n(\"192.168.2.255\")";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Номер порта";
			// 
			// bt_OK
			// 
			this->bt_OK->Location = System::Drawing::Point(82, 183);
			this->bt_OK->Name = L"bt_OK";
			this->bt_OK->Size = System::Drawing::Size(208, 42);
			this->bt_OK->TabIndex = 2;
			this->bt_OK->Text = L"OK";
			this->bt_OK->UseVisualStyleBackColor = true;
			this->bt_OK->Click += gcnew System::EventHandler(this, &SettingsForm::bt_OK_Click);
			// 
			// PortNmb
			// 
			this->PortNmb->Location = System::Drawing::Point(187, 74);
			this->PortNmb->Name = L"PortNmb";
			this->PortNmb->Size = System::Drawing::Size(148, 26);
			this->PortNmb->TabIndex = 3;
			// 
			// IP_text
			// 
			this->IP_text->Location = System::Drawing::Point(187, 25);
			this->IP_text->Name = L"IP_text";
			this->IP_text->Size = System::Drawing::Size(148, 26);
			this->IP_text->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Источник данных";
			// 
			// cb_VPNPselect
			// 
			this->cb_VPNPselect->DisplayMember = L"0";
			this->cb_VPNPselect->FormattingEnabled = true;
			this->cb_VPNPselect->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ВПНП1", L"ВПНП2" });
			this->cb_VPNPselect->Location = System::Drawing::Point(187, 127);
			this->cb_VPNPselect->Name = L"cb_VPNPselect";
			this->cb_VPNPselect->Size = System::Drawing::Size(148, 28);
			this->cb_VPNPselect->TabIndex = 5;
			this->cb_VPNPselect->Text = L"ВПНП1";
			this->cb_VPNPselect->ValueMember = L"2";
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(365, 246);
			this->Controls->Add(this->cb_VPNPselect);
			this->Controls->Add(this->IP_text);
			this->Controls->Add(this->PortNmb);
			this->Controls->Add(this->bt_OK);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройка";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bt_OK_Click(System::Object^ sender, System::EventArgs^ e);
};
}
