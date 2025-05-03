#pragma once
using namespace System;

namespace PMST {
    public ref class UserModel {
    public:
        property int Id;
        property String^ Username;
        property String^ Password;
        property String^ Email;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}