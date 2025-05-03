#pragma once

#include "../Database/DBConnection.h"
#include "../Models/PharmacyModel.h"
#include "../Models/UserModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class PharmacyController
    {
    private:
        // Validate basic fields (owner must exist, name/location nonempty)
        static void ValidatePharmacyModel(PharmacyModel^ pharmacy, bool requireId);

        // Check that a user exists
        static bool UserExists(int userId);

    public:
        // Create/register a new pharmacy (assigns Owner_Id)
        static PharmacyModel^ Create(PharmacyModel^ pharmacy);

        // Read
        static PharmacyModel^ GetById(int id);
        static List<PharmacyModel^>^ GetAll();
        static List<PharmacyModel^>^ GetByOwner(int ownerId);

        // Update (only name/location; owner cannot change)
        static bool Update(PharmacyModel^ pharmacy);

        // Delete
        static bool Delete(int id);
    };
}





//#pragma once
//#include "../Database/DBConnection.h"
//#include "../Models/PharmacyModel.h"
//using namespace System;
//using namespace System::Collections::Generic;
//using namespace MySql::Data::MySqlClient;
//
//namespace PMST {
//    public ref class PharmaciesController
//    {
//    public:
//        bool CreatePharmacy(PharmacyModel^ pharmacy);
//        List<PharmacyModel^>^ GetAllPharmacies();
//        void UpdatePharmacy(PharmacyModel^ pharmacy);
//        void DeletePharmacy(int id);
//    };
//}