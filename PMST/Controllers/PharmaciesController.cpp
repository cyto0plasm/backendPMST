#include "../Controllers/PharmaciesController.h"
#include "../Database/DBConnection.h"

namespace PMST {

    void PharmacyController::ValidatePharmacyModel(PharmacyModel^ pharmacy, bool requireId) {
        if (requireId && pharmacy->Id <= 0)
            throw gcnew ArgumentException("Invalid pharmacy Id.");

        if (pharmacy->Owner_Id <= 0 || !UserExists(pharmacy->Owner_Id))
            throw gcnew ArgumentException("Owner_Id must refer to an existing user.");

        if (String::IsNullOrWhiteSpace(pharmacy->Name))
            throw gcnew ArgumentException("Pharmacy name cannot be empty.");

        if (String::IsNullOrWhiteSpace(pharmacy->Location))
            throw gcnew ArgumentException("Pharmacy location cannot be empty.");
    }

    bool PharmacyController::UserExists(int userId) {
        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT COUNT(1) FROM Users WHERE Id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", userId);
        Int64 count = (Int64)cmd->ExecuteScalar();
        conn->Close();
        return count > 0;
    }

    PharmacyModel^ PharmacyController::Create(PharmacyModel^ pharmacy) {
        ValidatePharmacyModel(pharmacy, false);
        pharmacy->Created_At = DateTime::Now;
        pharmacy->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO Pharmacies (Owner_Id, Name, Location, Created_At, Updated_At) "
            "VALUES (@o, @n, @l, @c, @u); "
            "SELECT last_insert_rowid();",
            conn);
        cmd->Parameters->AddWithValue("@o", pharmacy->Owner_Id);
        cmd->Parameters->AddWithValue("@n", pharmacy->Name);
        cmd->Parameters->AddWithValue("@l", pharmacy->Location);
        cmd->Parameters->AddWithValue("@c", pharmacy->Created_At);
        cmd->Parameters->AddWithValue("@u", pharmacy->Updated_At);

        Int64 id = (Int64)cmd->ExecuteScalar();
        conn->Close();

        pharmacy->Id = safe_cast<int>(id);
        return pharmacy;
    }

    PharmacyModel^ PharmacyController::GetById(int id) {
        if (id <= 0) return nullptr;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id, Owner_Id, Name, Location, Created_At, Updated_At "
            "FROM Pharmacies WHERE Id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);
        auto reader = cmd->ExecuteReader();

        if (reader->Read()) {
            auto p = gcnew PharmacyModel(
                reader->GetInt32(0),
                reader->GetInt32(1),
                reader->GetString(2),
                reader->GetString(3),
                reader->GetDateTime(4),
                reader->GetDateTime(5)
            );
            conn->Close();
            return p;
        }

        conn->Close();
        return nullptr;
    }

    List<PharmacyModel^>^ PharmacyController::GetAll() {
        auto list = gcnew List<PharmacyModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id, Owner_Id, Name, Location, Created_At, Updated_At FROM Pharmacies;",
            conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            list->Add(gcnew PharmacyModel(
                reader->GetInt32(0),
                reader->GetInt32(1),
                reader->GetString(2),
                reader->GetString(3),
                reader->GetDateTime(4),
                reader->GetDateTime(5)
            ));
        }
        conn->Close();
        return list;
    }

    List<PharmacyModel^>^ PharmacyController::GetByOwner(int ownerId) {
        if (ownerId <= 0) return gcnew List<PharmacyModel^>();

        auto list = gcnew List<PharmacyModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT Id, Owner_Id, Name, Location, Created_At, Updated_At "
            "FROM Pharmacies WHERE Owner_Id = @o;",
            conn);
        cmd->Parameters->AddWithValue("@o", ownerId);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            list->Add(gcnew PharmacyModel(
                reader->GetInt32(0),
                reader->GetInt32(1),
                reader->GetString(2),
                reader->GetString(3),
                reader->GetDateTime(4),
                reader->GetDateTime(5)
            ));
        }
        conn->Close();
        return list;
    }

    bool PharmacyController::Update(PharmacyModel^ pharmacy) {
        ValidatePharmacyModel(pharmacy, true);
        pharmacy->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "UPDATE Pharmacies "
            "SET Name = @n, Location = @l, Updated_At = @u "
            "WHERE Id = @id;",
            conn);
        cmd->Parameters->AddWithValue("@n", pharmacy->Name);
        cmd->Parameters->AddWithValue("@l", pharmacy->Location);
        cmd->Parameters->AddWithValue("@u", pharmacy->Updated_At);
        cmd->Parameters->AddWithValue("@id", pharmacy->Id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool PharmacyController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "DELETE FROM Pharmacies WHERE Id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }
}
