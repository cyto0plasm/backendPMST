#pragma once

#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class UserController
    {
    private:
        // Hash a plain text password with SHA256
        static String^ HashPassword(String^ plain);

        // Validate basic fields
        static void ValidateUserModel(UserModel^ user, bool requireId);

    public:
        // Register a new user (returns created user with Id)
        static UserModel^ Register(String^ username, String^ password, String^ email);

        // Login by username/email + password (returns user or nullptr)
        static UserModel^ Login(String^ usernameOrEmail, String^ password);

        // CRUD
        static UserModel^ Create(UserModel^ user);
        static UserModel^ GetById(int id);
        static List<UserModel^>^ GetAll();
        static bool Update(UserModel^ user);
        static bool Delete(int id);
    };
}





//#pragma once
//#include "../Database/DBConnection.h"
//#include "../Models/UserModel.h"
//using namespace System;
//using namespace System::Collections::Generic;
//using namespace MySql::Data::MySqlClient;
//
//namespace PMST {
//    public ref class UsersController
//    {
//    public:
//        bool CreateUser(UserModel^ user);
//        List<UserModel^>^ GetAllUsers();
//        void UpdateUser(UserModel^ user);
//        void DeleteUser(int id);
//    };
//}