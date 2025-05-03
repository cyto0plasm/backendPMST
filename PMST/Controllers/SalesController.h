#pragma once
#include "../Database/DBConnection.h"
#include "../Models/SaleModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class SaleController
    {
    private:
        static void Validate(SaleModel^ m);
        static bool PharmacyExists(int pharmacyId);
        static bool ProductExists(int productId);
        static bool UserExists(int userId);

    public:
        static SaleModel^ Create(SaleModel^ m);
        static List<SaleModel^>^ GetByPharmacy(int pharmacyId);
        static List<SaleModel^>^ GetByUser(int userId);
    };
}
