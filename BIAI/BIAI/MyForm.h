#pragma once
#include "GameController.h"

namespace BIAI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:GameController *gameController;
	public:
		static MyForm ^ view;

		MyForm(void)
		{
			InitializeComponent();
			view = this;
			gameController = new GameController();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  b1_1;
	private: System::Windows::Forms::Button^  b1_2;
	private: System::Windows::Forms::Button^  b1_3;
	private: System::Windows::Forms::Button^  b1_4;
	private: System::Windows::Forms::Button^  b1_5;
	private: System::Windows::Forms::Button^  b2_1;
	private: System::Windows::Forms::Button^  b2_2;
	private: System::Windows::Forms::Button^  b2_3;
	private: System::Windows::Forms::Button^  b2_4;
	private: System::Windows::Forms::Button^  b2_5;
	private: System::Windows::Forms::Button^  b3_1;
	private: System::Windows::Forms::Button^  b3_2;
	private: System::Windows::Forms::Button^  b3_3;
	private: System::Windows::Forms::Button^  b3_4;
	private: System::Windows::Forms::Button^  b3_5;
	private: System::Windows::Forms::Button^  b4_1;
	private: System::Windows::Forms::Button^  b4_2;
	private: System::Windows::Forms::Button^  b4_3;
	private: System::Windows::Forms::Button^  b4_4;
	private: System::Windows::Forms::Button^  b4_5;
	private: System::Windows::Forms::Button^  b5_1;
	private: System::Windows::Forms::Button^  b5_2;
	private: System::Windows::Forms::Button^  b5_3;
	private: System::Windows::Forms::Button^  b5_4;
	private: System::Windows::Forms::Button^  b5_5;
	protected:

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
			this->b1_1 = (gcnew System::Windows::Forms::Button());
			this->b1_2 = (gcnew System::Windows::Forms::Button());
			this->b1_3 = (gcnew System::Windows::Forms::Button());
			this->b1_4 = (gcnew System::Windows::Forms::Button());
			this->b1_5 = (gcnew System::Windows::Forms::Button());
			this->b2_1 = (gcnew System::Windows::Forms::Button());
			this->b2_2 = (gcnew System::Windows::Forms::Button());
			this->b2_3 = (gcnew System::Windows::Forms::Button());
			this->b2_4 = (gcnew System::Windows::Forms::Button());
			this->b2_5 = (gcnew System::Windows::Forms::Button());
			this->b3_1 = (gcnew System::Windows::Forms::Button());
			this->b3_2 = (gcnew System::Windows::Forms::Button());
			this->b3_3 = (gcnew System::Windows::Forms::Button());
			this->b3_4 = (gcnew System::Windows::Forms::Button());
			this->b3_5 = (gcnew System::Windows::Forms::Button());
			this->b4_1 = (gcnew System::Windows::Forms::Button());
			this->b4_2 = (gcnew System::Windows::Forms::Button());
			this->b4_3 = (gcnew System::Windows::Forms::Button());
			this->b4_4 = (gcnew System::Windows::Forms::Button());
			this->b4_5 = (gcnew System::Windows::Forms::Button());
			this->b5_1 = (gcnew System::Windows::Forms::Button());
			this->b5_2 = (gcnew System::Windows::Forms::Button());
			this->b5_3 = (gcnew System::Windows::Forms::Button());
			this->b5_4 = (gcnew System::Windows::Forms::Button());
			this->b5_5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// b1_1
			// 
			this->b1_1->AccessibleName = L"";
			this->b1_1->Location = System::Drawing::Point(381, 63);
			this->b1_1->Name = L"b1_1";
			this->b1_1->Size = System::Drawing::Size(45, 42);
			this->b1_1->TabIndex = 0;
			this->b1_1->UseVisualStyleBackColor = true;
			this->b1_1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b1_2
			// 
			this->b1_2->AccessibleName = L"";
			this->b1_2->Location = System::Drawing::Point(432, 63);
			this->b1_2->Name = L"b1_2";
			this->b1_2->Size = System::Drawing::Size(45, 42);
			this->b1_2->TabIndex = 0;
			this->b1_2->UseVisualStyleBackColor = true;
			this->b1_2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b1_3
			// 
			this->b1_3->AccessibleName = L"";
			this->b1_3->Location = System::Drawing::Point(483, 63);
			this->b1_3->Name = L"b1_3";
			this->b1_3->Size = System::Drawing::Size(45, 42);
			this->b1_3->TabIndex = 0;
			this->b1_3->UseVisualStyleBackColor = true;
			this->b1_3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b1_4
			// 
			this->b1_4->AccessibleName = L"";
			this->b1_4->Location = System::Drawing::Point(534, 63);
			this->b1_4->Name = L"b1_4";
			this->b1_4->Size = System::Drawing::Size(45, 42);
			this->b1_4->TabIndex = 0;
			this->b1_4->UseVisualStyleBackColor = true;
			this->b1_4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b1_5
			// 
			this->b1_5->AccessibleName = L"";
			this->b1_5->Location = System::Drawing::Point(585, 63);
			this->b1_5->Name = L"b1_5";
			this->b1_5->Size = System::Drawing::Size(45, 42);
			this->b1_5->TabIndex = 0;
			this->b1_5->UseVisualStyleBackColor = true;
			this->b1_5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b2_1
			// 
			this->b2_1->AccessibleName = L"";
			this->b2_1->Location = System::Drawing::Point(381, 111);
			this->b2_1->Name = L"b2_1";
			this->b2_1->Size = System::Drawing::Size(45, 42);
			this->b2_1->TabIndex = 0;
			this->b2_1->UseVisualStyleBackColor = true;
			this->b2_1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b2_2
			// 
			this->b2_2->AccessibleName = L"";
			this->b2_2->Location = System::Drawing::Point(432, 111);
			this->b2_2->Name = L"b2_2";
			this->b2_2->Size = System::Drawing::Size(45, 42);
			this->b2_2->TabIndex = 0;
			this->b2_2->UseVisualStyleBackColor = true;
			this->b2_2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b2_3
			// 
			this->b2_3->AccessibleName = L"";
			this->b2_3->Location = System::Drawing::Point(483, 111);
			this->b2_3->Name = L"b2_3";
			this->b2_3->Size = System::Drawing::Size(45, 42);
			this->b2_3->TabIndex = 0;
			this->b2_3->UseVisualStyleBackColor = true;
			this->b2_3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b2_4
			// 
			this->b2_4->AccessibleName = L"";
			this->b2_4->Location = System::Drawing::Point(534, 111);
			this->b2_4->Name = L"b2_4";
			this->b2_4->Size = System::Drawing::Size(45, 42);
			this->b2_4->TabIndex = 0;
			this->b2_4->UseVisualStyleBackColor = true;
			this->b2_4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b2_5
			// 
			this->b2_5->AccessibleName = L"";
			this->b2_5->Location = System::Drawing::Point(585, 111);
			this->b2_5->Name = L"b2_5";
			this->b2_5->Size = System::Drawing::Size(45, 42);
			this->b2_5->TabIndex = 0;
			this->b2_5->UseVisualStyleBackColor = true;
			this->b2_5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b3_1
			// 
			this->b3_1->AccessibleName = L"";
			this->b3_1->Location = System::Drawing::Point(381, 159);
			this->b3_1->Name = L"b3_1";
			this->b3_1->Size = System::Drawing::Size(45, 42);
			this->b3_1->TabIndex = 0;
			this->b3_1->UseVisualStyleBackColor = true;
			this->b3_1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b3_2
			// 
			this->b3_2->AccessibleName = L"";
			this->b3_2->Location = System::Drawing::Point(432, 159);
			this->b3_2->Name = L"b3_2";
			this->b3_2->Size = System::Drawing::Size(45, 42);
			this->b3_2->TabIndex = 0;
			this->b3_2->UseVisualStyleBackColor = true;
			this->b3_2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b3_3
			// 
			this->b3_3->AccessibleName = L"";
			this->b3_3->Location = System::Drawing::Point(483, 159);
			this->b3_3->Name = L"b3_3";
			this->b3_3->Size = System::Drawing::Size(45, 42);
			this->b3_3->TabIndex = 0;
			this->b3_3->UseVisualStyleBackColor = true;
			this->b3_3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b3_4
			// 
			this->b3_4->AccessibleName = L"";
			this->b3_4->Location = System::Drawing::Point(534, 159);
			this->b3_4->Name = L"b3_4";
			this->b3_4->Size = System::Drawing::Size(45, 42);
			this->b3_4->TabIndex = 0;
			this->b3_4->UseVisualStyleBackColor = true;
			this->b3_4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b3_5
			// 
			this->b3_5->AccessibleName = L"";
			this->b3_5->Location = System::Drawing::Point(585, 159);
			this->b3_5->Name = L"b3_5";
			this->b3_5->Size = System::Drawing::Size(45, 42);
			this->b3_5->TabIndex = 0;
			this->b3_5->UseVisualStyleBackColor = true;
			this->b3_5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b4_1
			// 
			this->b4_1->AccessibleName = L"";
			this->b4_1->Location = System::Drawing::Point(381, 207);
			this->b4_1->Name = L"b4_1";
			this->b4_1->Size = System::Drawing::Size(45, 42);
			this->b4_1->TabIndex = 0;
			this->b4_1->UseVisualStyleBackColor = true;
			this->b4_1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b4_2
			// 
			this->b4_2->AccessibleName = L"";
			this->b4_2->Location = System::Drawing::Point(432, 207);
			this->b4_2->Name = L"b4_2";
			this->b4_2->Size = System::Drawing::Size(45, 42);
			this->b4_2->TabIndex = 0;
			this->b4_2->UseVisualStyleBackColor = true;
			this->b4_2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b4_3
			// 
			this->b4_3->AccessibleName = L"";
			this->b4_3->Location = System::Drawing::Point(483, 207);
			this->b4_3->Name = L"b4_3";
			this->b4_3->Size = System::Drawing::Size(45, 42);
			this->b4_3->TabIndex = 0;
			this->b4_3->UseVisualStyleBackColor = true;
			this->b4_3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b4_4
			// 
			this->b4_4->AccessibleName = L"";
			this->b4_4->Location = System::Drawing::Point(534, 207);
			this->b4_4->Name = L"b4_4";
			this->b4_4->Size = System::Drawing::Size(45, 42);
			this->b4_4->TabIndex = 0;
			this->b4_4->UseVisualStyleBackColor = true;
			this->b4_4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b4_5
			// 
			this->b4_5->AccessibleName = L"";
			this->b4_5->Location = System::Drawing::Point(585, 207);
			this->b4_5->Name = L"b4_5";
			this->b4_5->Size = System::Drawing::Size(45, 42);
			this->b4_5->TabIndex = 0;
			this->b4_5->UseVisualStyleBackColor = true;
			this->b4_5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b5_1
			// 
			this->b5_1->AccessibleName = L"";
			this->b5_1->Location = System::Drawing::Point(381, 255);
			this->b5_1->Name = L"b5_1";
			this->b5_1->Size = System::Drawing::Size(45, 42);
			this->b5_1->TabIndex = 0;
			this->b5_1->UseVisualStyleBackColor = true;
			this->b5_1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b5_2
			// 
			this->b5_2->AccessibleName = L"";
			this->b5_2->Location = System::Drawing::Point(432, 255);
			this->b5_2->Name = L"b5_2";
			this->b5_2->Size = System::Drawing::Size(45, 42);
			this->b5_2->TabIndex = 0;
			this->b5_2->UseVisualStyleBackColor = true;
			this->b5_2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b5_3
			// 
			this->b5_3->AccessibleName = L"";
			this->b5_3->Location = System::Drawing::Point(483, 255);
			this->b5_3->Name = L"b5_3";
			this->b5_3->Size = System::Drawing::Size(45, 42);
			this->b5_3->TabIndex = 0;
			this->b5_3->UseVisualStyleBackColor = true;
			this->b5_3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b5_4
			// 
			this->b5_4->AccessibleName = L"";
			this->b5_4->Location = System::Drawing::Point(534, 255);
			this->b5_4->Name = L"b5_4";
			this->b5_4->Size = System::Drawing::Size(45, 42);
			this->b5_4->TabIndex = 0;
			this->b5_4->UseVisualStyleBackColor = true;
			this->b5_4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// b5_5
			// 
			this->b5_5->AccessibleName = L"";
			this->b5_5->Location = System::Drawing::Point(585, 255);
			this->b5_5->Name = L"b5_5";
			this->b5_5->Size = System::Drawing::Size(45, 42);
			this->b5_5->TabIndex = 0;
			this->b5_5->UseVisualStyleBackColor = true;
			this->b5_5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 418);
			this->Controls->Add(this->b5_5);
			this->Controls->Add(this->b4_5);
			this->Controls->Add(this->b3_5);
			this->Controls->Add(this->b2_5);
			this->Controls->Add(this->b1_5);
			this->Controls->Add(this->b5_4);
			this->Controls->Add(this->b4_4);
			this->Controls->Add(this->b3_4);
			this->Controls->Add(this->b2_4);
			this->Controls->Add(this->b1_4);
			this->Controls->Add(this->b5_3);
			this->Controls->Add(this->b4_3);
			this->Controls->Add(this->b3_3);
			this->Controls->Add(this->b2_3);
			this->Controls->Add(this->b1_3);
			this->Controls->Add(this->b5_2);
			this->Controls->Add(this->b4_2);
			this->Controls->Add(this->b3_2);
			this->Controls->Add(this->b2_2);
			this->Controls->Add(this->b1_2);
			this->Controls->Add(this->b5_1);
			this->Controls->Add(this->b4_1);
			this->Controls->Add(this->b3_1);
			this->Controls->Add(this->b2_1);
			this->Controls->Add(this->b1_1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			Button^ currentButton = safe_cast<Button^>(sender);
			gameController->doSomething();
		}

	public: void asd()
	{
		b1_1->Text = "asdasd";
	}
	};
}
