#pragma once
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"


using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class ProductController
    {
    private:
        static void Validate(ProductModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);
        static bool CategoryExists(int categoryId);
        static bool SupplierExists(int supplierId);

    public:
        static ProductModel^ Create(ProductModel^ m);
        static ProductModel^ GetById(int id);
        static List<ProductModel^>^ GetAll();
        static List<ProductModel^>^ GetByPharmacy(int pharmacyId);
        static bool Update(ProductModel^ m);
        static bool Delete(int id);
    };
}
