#pragma once
using namespace System;

namespace PMST {
    public ref class SaleModel {
    public:
        property int Id;
        property int Pharmacy_Id;
        property int Product_Id;
        property Nullable<int> User_Id;
        property int Quantity;
        property Decimal Total_Price;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}