#pragma once
#include "../Database/DBConnection.h"
#include "../Models/StockHistoryModel.h"
#pragma once


using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class StockHistoryController
    {
    private:
        static void Validate(StockHistoryModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);
        static bool ProductExists(int productId);

    public:
        static StockHistoryModel^ Create(StockHistoryModel^ m);
        static List<StockHistoryModel^>^ GetByPharmacy(int pharmacyId);
        static List<StockHistoryModel^>^ GetByProduct(int productId);
    };
}
