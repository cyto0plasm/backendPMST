#include "SuppliersController.h"
#include "../Database/DBConnection.h"
#include "../Models/SupplierModel.h"


namespace PMST {

    void SupplierController::Validate(SupplierModel^ m, bool requireId) {
        if (requireId && m->Id <= 0) throw gcnew ArgumentException("Invalid Supplier Id.");
        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Pharmacy_Id must refer to an existing pharmacy.");
        if (String::IsNullOrWhiteSpace(m->Name))
            throw gcnew ArgumentException("Supplier name required.");
    }

    bool SupplierController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Pharmacies WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    SupplierModel^ SupplierController::Create(SupplierModel^ m) {
        Validate(m, false);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO Suppliers (Pharmacy_Id, Name, Contact_Info, Created_At, Updated_At) "
            "VALUES (@p,@n,@c,@cA,@uA); SELECT last_insert_rowid();", conn);
        cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@n", m->Name);
        cmd->Parameters->AddWithValue("@c", m->Contact_Info);
        cmd->Parameters->AddWithValue("@cA", m->Created_At);
        cmd->Parameters->AddWithValue("@uA", m->Updated_At);
        m->Id = safe_cast<int>((Int64)cmd->ExecuteScalar());
        conn->Close();
        return m;
    }

    SupplierModel^ SupplierController::GetById(int id) {
        if (id <= 0) return nullptr;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Name,Contact_Info,Created_At,Updated_At FROM Suppliers WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", id);
        auto rd = cmd->ExecuteReader();
        if (!rd->Read()) { conn->Close(); return nullptr; }
        auto m = gcnew SupplierModel();
        m->Id = rd->GetInt32(0);
        m->Pharmacy_Id = rd->GetInt32(1);
        m->Name = rd->GetString(2);
        m->Contact_Info = rd->GetString(3);
        m->Created_At = rd->GetDateTime(4);
        m->Updated_At = rd->GetDateTime(5);
        conn->Close(); return m;
    }

    List<SupplierModel^>^ SupplierController::GetAll() {
        auto list = gcnew List<SupplierModel^>();
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT Id,Pharmacy_Id,Name,Contact_Info,Created_At,Updated_At FROM Suppliers;", conn);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew SupplierModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Name = rd->GetString(2);
            m->Contact_Info = rd->GetString(3);
            m->Created_At = rd->GetDateTime(4);
            m->Updated_At = rd->GetDateTime(5);
            list->Add(m);
        }
        conn->Close(); return list;
    }

    List<SupplierModel^>^ SupplierController::GetByPharmacy(int pharmacyId) {
        auto list = gcnew List<SupplierModel^>();
        if (pharmacyId <= 0) return list;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Name,Contact_Info,Created_At,Updated_At FROM Suppliers WHERE Pharmacy_Id=@p;", conn);
        cmd->Parameters->AddWithValue("@p", pharmacyId);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew SupplierModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Name = rd->GetString(2);
            m->Contact_Info = rd->GetString(3);
            m->Created_At = rd->GetDateTime(4);
            m->Updated_At = rd->GetDateTime(5);
            list->Add(m);
        }
        conn->Close(); return list;
    }

    bool SupplierController::Update(SupplierModel^ m) {
        Validate(m, true);
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "UPDATE Suppliers SET Name=@n,Contact_Info=@c,Updated_At=@u WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@n", m->Name);
        cmd->Parameters->AddWithValue("@c", m->Contact_Info);
        cmd->Parameters->AddWithValue("@u", m->Updated_At);
        cmd->Parameters->AddWithValue("@id", m->Id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close(); return rows > 0;
    }

    bool SupplierController::Delete(int id) {
        if (id <= 0) return false;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("DELETE FROM Suppliers WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close(); return rows > 0;
    }
}
