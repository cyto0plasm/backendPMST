#pragma once
using namespace System;

namespace PMST {
    public ref class PharmacyModel {
    public:
        property int Id;
        property int Owner_Id;
        property String^ Name;
        property String^ Location;
        property DateTime Created_At;
        property DateTime Updated_At;

    public:
		PharmacyModel() {
			this->Id = 0;
			this->Owner_Id = 0;
			this->Name = "";
			this->Location = "";
			this->Created_At = DateTime::Now;
			this->Updated_At = DateTime::Now;
		}
        PharmacyModel(int id, int owner_id, String^ name, String^ location, DateTime created_at, DateTime updated_at) {
			this->Id = id;
			this->Owner_Id = owner_id;
			this->Name = name;
			this->Location = location;
			this->Created_At = created_at;
			this->Updated_At = updated_at;
        }

    };
}