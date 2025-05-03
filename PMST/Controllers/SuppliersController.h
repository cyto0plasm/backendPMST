
#pragma once
#include "../Database/DBConnection.h"
#include "../Models/SupplierModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class SupplierController
    {
    private:
        static void Validate(SupplierModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);

    public:
        static SupplierModel^ Create(SupplierModel^ m);
        static SupplierModel^ GetById(int id);
        static List<SupplierModel^>^ GetAll();
        static List<SupplierModel^>^ GetByPharmacy(int pharmacyId);
        static bool Update(SupplierModel^ m);
        static bool Delete(int id);
    };
}
