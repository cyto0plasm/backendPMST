#pragma once
using namespace System;

namespace PMST {
    public ref class SupplierModel {
    public:
        property int Id;
        property int Pharmacy_Id;
        property String^ Name;
        property String^ Contact_Info;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}