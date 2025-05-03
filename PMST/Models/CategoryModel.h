#pragma once

using namespace System;

namespace PMST {
	public ref class CategoryModel {
	private:
		int id;
		int pharmacy_id;
		System::String^ name;
		System::String^ description;
		DateTime created_at;
		DateTime updated_at;

	public:
		CategoryModel(); // Constructor declaration

		property int Id {
			int get() { return id; }
			void set(int value) { id = value; }
		}

		property System::String^ Name {
			System::String^ get() { return name; }
			void set(System::String^ value) { name = value; }
		}

		property System::String^ Description {
			System::String^ get() { return description; }
			void set(System::String^ value) { description = value; }
		}
		property int Pharmacy_Id {
			int get() { return pharmacy_id; }
			void set(int value) { pharmacy_id = value; }
		}
		property DateTime Created_At {
			DateTime get() { return created_at; }
			void set(DateTime value) { created_at = value; }
		}
		property DateTime Updated_At {
			DateTime get() { return updated_at; }
			void set(DateTime value) { updated_at = value; }
		}
	};
}
