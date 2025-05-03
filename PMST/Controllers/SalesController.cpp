#include "SalesController.h"
#include "../Database/DBConnection.h"
#include "../Models/SaleModel.h"

namespace PMST {

    void SaleController::Validate(SaleModel^ m) {
        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Invalid Pharmacy_Id.");
        if (m->Product_Id <= 0 || !ProductExists(m->Product_Id))
            throw gcnew ArgumentException("Invalid Product_Id.");
        if (m->User_Id.HasValue && m->User_Id.Value <= 0)
            throw gcnew ArgumentException("Invalid User_Id.");
    }

    bool SaleController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Pharmacies WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    bool SaleController::ProductExists(int productId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Products WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", productId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    bool SaleController::UserExists(int userId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Users WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", userId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    SaleModel^ SaleController::Create(SaleModel^ m) {
        Validate(m);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO Sales (Pharmacy_Id,Product_Id,User_Id,Quantity,Total_Price,Created_At,Updated_At) "
            "VALUES (@p,@pr,@u,@q,@t,@cA,@uA);", conn);
        cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@pr", m->Product_Id);
        cmd->Parameters->AddWithValue("@u", m->User_Id.HasValue ? (Object^)m->User_Id.Value : DBNull::Value);
        cmd->Parameters->AddWithValue("@q", m->Quantity);
        cmd->Parameters->AddWithValue("@t", m->Total_Price);
        cmd->Parameters->AddWithValue("@cA", m->Created_At);
        cmd->Parameters->AddWithValue("@uA", m->Updated_At);
        cmd->ExecuteNonQuery();
        conn->Close(); return m;
    }

    List<SaleModel^>^ SaleController::GetByPharmacy(int pharmacyId) {
        auto list = gcnew List<SaleModel^>();
        if (pharmacyId <= 0) return list;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Product_Id,User_Id,Quantity,Total_Price,Created_At,Updated_At "
            "FROM Sales WHERE Pharmacy_Id=@p;", conn);
        cmd->Parameters->AddWithValue("@p", pharmacyId);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew SaleModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Product_Id = rd->GetInt32(2);
            m->User_Id = rd->IsDBNull(3) ? Nullable<int>() : Nullable<int>(rd->GetInt32(3));
            m->Quantity = rd->GetInt32(4);
            m->Total_Price = rd->GetDecimal(5);
            m->Created_At = rd->GetDateTime(6);
            m->Updated_At = rd->GetDateTime(7);
            list->Add(m);
        }
        conn->Close(); return list;
    }

    List<SaleModel^>^ SaleController::GetByUser(int userId) {
        auto list = gcnew List<SaleModel^>();
        if (userId <= 0) return list;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Product_Id,User_Id,Quantity,Total_Price,Created_At,Updated_At "
            "FROM Sales WHERE User_Id=@u;", conn);
        cmd->Parameters->AddWithValue("@u", userId);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew SaleModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Product_Id = rd->GetInt32(2);
            m->User_Id = rd->IsDBNull(3) ? Nullable<int>() : Nullable<int>(rd->GetInt32(3));
            m->Quantity = rd->GetInt32(4);
            m->Total_Price = rd->GetDecimal(5);
            m->Created_At = rd->GetDateTime(6);
            m->Updated_At = rd->GetDateTime(7);
            list->Add(m);
        }
        conn->Close(); return list;
    }
}
