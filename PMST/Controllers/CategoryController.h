#pragma once

#include "../Models/CategoryModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class CategoryController
    {
    private:
        static void Validate(CategoryModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);

    public:
        static CategoryModel^ Create(CategoryModel^ m);
        static CategoryModel^ GetById(int id);
        static List<CategoryModel^>^ GetAll();
        static List<CategoryModel^>^ GetByPharmacy(int pharmacyId);
        static bool Update(CategoryModel^ m);
        static bool Delete(int id);
    };
}