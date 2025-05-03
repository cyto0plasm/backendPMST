#pragma once
using namespace System;

namespace PMST {
    public ref class ProductModel {
    public:
        property int Id;
        property int Pharmacy_Id;
        property int Category_Id;
        property int Supplier_Id;
        property String^ Name;
        property Decimal Price;
        property int Quantity;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}