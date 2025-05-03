#include "StockHistoryController.h"
#include "../Database/DBConnection.h"
#include "../Models/StockHistoryModel.h"

namespace PMST {

    void StockHistoryController::Validate(StockHistoryModel^ m, bool requireId) {
        if (requireId && m->Id <= 0) throw gcnew ArgumentException("Invalid StockHistory Id.");
        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Invalid Pharmacy_Id.");
        if (m->Product_Id <= 0 || !ProductExists(m->Product_Id))
            throw gcnew ArgumentException("Invalid Product_Id.");
        if (String::IsNullOrWhiteSpace(m->Change_Type))
            throw gcnew ArgumentException("Change_Type required.");
    }

    bool StockHistoryController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Pharmacies WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    bool StockHistoryController::ProductExists(int productId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Products WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", productId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    StockHistoryModel^ StockHistoryController::Create(StockHistoryModel^ m) {
        Validate(m, false);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO StockHistory (Pharmacy_Id,Product_Id,Change_Type,Quantity_Changed,Note,Created_At,Updated_At) "
            "VALUES (@p,@pr,@ct,@qc,@n,@cA,@uA);", conn);
        cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@pr", m->Product_Id);
        cmd->Parameters->AddWithValue("@ct", m->Change_Type);
        cmd->Parameters->AddWithValue("@qc", m->Quantity_Changed);
        cmd->Parameters->AddWithValue("@n", m->Note);
        cmd->Parameters->AddWithValue("@cA", m->Created_At);
        cmd->Parameters->AddWithValue("@uA", m->Updated_At);
        cmd->ExecuteNonQuery();
        conn->Close();
        return m;
    }

    List<StockHistoryModel^>^ StockHistoryController::GetByPharmacy(int pharmacyId) {
        auto list = gcnew List<StockHistoryModel^>();
        if (pharmacyId <= 0) return list;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Product_Id,Change_Type,Quantity_Changed,Note,Created_At,Updated_At "
            "FROM StockHistory WHERE Pharmacy_Id=@p;", conn);
        cmd->Parameters->AddWithValue("@p", pharmacyId);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew StockHistoryModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Product_Id = rd->GetInt32(2);
            m->Change_Type = rd->GetString(3);
            m->Quantity_Changed = rd->GetInt32(4);
            m->Note = rd->GetString(5);
            m->Created_At = rd->GetDateTime(6);
            m->Updated_At = rd->GetDateTime(7);
            list->Add(m);
        }
        conn->Close(); return list;
    }

    List<StockHistoryModel^>^ StockHistoryController::GetByProduct(int productId) {
        auto list = gcnew List<StockHistoryModel^>();
        if (productId <= 0) return list;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id,Pharmacy_Id,Product_Id,Change_Type,Quantity_Changed,Note,Created_At,Updated_At "
            "FROM StockHistory WHERE Product_Id=@pr;", conn);
        cmd->Parameters->AddWithValue("@pr", productId);
        auto rd = cmd->ExecuteReader();
        while (rd->Read()) {
            auto m = gcnew StockHistoryModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Product_Id = rd->GetInt32(2);
            m->Change_Type = rd->GetString(3);
            m->Quantity_Changed = rd->GetInt32(4);
            m->Note = rd->GetString(5);
            m->Created_At = rd->GetDateTime(6);
            m->Updated_At = rd->GetDateTime(7);
            list->Add(m);
        }
        conn->Close(); return list;
    }
}
