#pragma once
using namespace System;

namespace PMST {
    public ref class StockHistoryModel {
    public:
        property int Id;
        property int Pharmacy_Id;
        property int Product_Id;
        property String^ Change_Type;
        property int Quantity_Changed;
        property String^ Note;
        property DateTime Created_At;
        property DateTime Updated_At;
    };

}