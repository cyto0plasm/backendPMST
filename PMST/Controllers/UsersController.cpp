#include "UsersController.h"
#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"


namespace PMST {

    // ---- Helpers ----

    String^ UserController::HashPassword(String^ plain) {
        auto sha = SHA256::Create();
        array<Byte>^ bytes = Encoding::UTF8->GetBytes(plain);
        array<Byte>^ hash = sha->ComputeHash(bytes);

        // Convert to hex string
        StringBuilder^ sb = gcnew StringBuilder();
        for each (Byte b in hash)
            sb->Append(b.ToString("x2"));

        return sb->ToString();
    }

    void UserController::ValidateUserModel(UserModel^ user, bool requireId) {
        if (requireId && user->Id <= 0)
            throw gcnew ArgumentException("Invalid user Id.");

        if (String::IsNullOrWhiteSpace(user->Username))
            throw gcnew ArgumentException("Username cannot be empty.");

        if (String::IsNullOrWhiteSpace(user->Email) || !user->Email->Contains("@"))
            throw gcnew ArgumentException("Invalid email address.");
    }

    // ---- Register & Login ----

    UserModel^ UserController::Register(String^ username, String^ password, String^ email) {
        if (password->Length < 6)
            throw gcnew ArgumentException("Password must be at least 6 characters.");

        // Check for existing user
        if (Login(username, password) != nullptr)
            throw gcnew InvalidOperationException("User already exists.");

        UserModel^ newUser = gcnew UserModel();
        newUser->Username = username;
        newUser->Password = HashPassword(password);
        newUser->Email = email;
        newUser->Created_At = DateTime::Now;
        newUser->Updated_At = DateTime::Now;

        return Create(newUser);
    }

    UserModel^ UserController::Login(String^ usernameOrEmail, String^ password) {
        String^ hashed = HashPassword(password);

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "SELECT id, username, Password, email, created_at, updated_at "
            "FROM users WHERE (username = @u OR email = @u) AND Password = @p;",
            conn);

        cmd->Parameters->AddWithValue("@u", usernameOrEmail);
        cmd->Parameters->AddWithValue("@p", hashed);

        auto reader = cmd->ExecuteReader();
        if (reader->Read()) {
            UserModel^ u = gcnew UserModel();
            u->Id = reader->GetInt32(0);
            u->Username = reader->GetString(1);
            u->Password = reader->GetString(2);
            u->Email = reader->GetString(3);
            u->Created_At = reader->GetDateTime(4);
            u->Updated_At = reader->GetDateTime(5);

            conn->Close();
            return u;
        }

        conn->Close();
        return nullptr;
    }

    // ---- CRUD operations ----

    UserModel^ UserController::Create(UserModel^ user) {
        ValidateUserModel(user, false);

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO users (username, Password, email, created_at, updated_at) "
            "VALUES (@u, @p, @e, @c, @uT); "
            "SELECT last_insert_rowid();",
            conn);

        cmd->Parameters->AddWithValue("@u", user->Username);
        cmd->Parameters->AddWithValue("@p", user->Password);
        cmd->Parameters->AddWithValue("@e", user->Email);
        cmd->Parameters->AddWithValue("@c", user->Created_At);
        cmd->Parameters->AddWithValue("@uT", user->Updated_At);

        Int64 id = (Int64)cmd->ExecuteScalar();
        conn->Close();

        user->Id = safe_cast<int>(id);
        return user;
    }

    UserModel^ UserController::GetById(int id) {
        if (id <= 0) return nullptr;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "SELECT id, username, Password, email, created_at, updated_at "
            "FROM users WHERE id = @id;", conn);

        cmd->Parameters->AddWithValue("@id", id);
        auto reader = cmd->ExecuteReader();

        if (reader->Read()) {
            UserModel^ u = gcnew UserModel();
            u->Id = reader->GetInt32(0);
            u->Username = reader->GetString(1);
            u->Password = reader->GetString(2);
            u->Email = reader->GetString(3);
            u->Created_At = reader->GetDateTime(4);
            u->Updated_At = reader->GetDateTime(5);
            conn->Close();
            return u;
        }

        conn->Close();
        return nullptr;
    }

    List<UserModel^>^ UserController::GetAll() {
        auto list = gcnew List<UserModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "SELECT id, username, Password, email, created_at, updated_at FROM users;",
            conn);

        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            UserModel^ u = gcnew UserModel();
            u->Id = reader->GetInt32(0);
            u->Username = reader->GetString(1);
            u->Password = reader->GetString(2);
            u->Email = reader->GetString(3);
            u->Created_At = reader->GetDateTime(4);
            u->Updated_At = reader->GetDateTime(5);
            list->Add(u);
        }

        conn->Close();
        return list;
    }

    bool UserController::Update(UserModel^ user) {
        ValidateUserModel(user, true);
        user->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "UPDATE users SET username=@u, email=@e, Password=@p, updated_at=@uT WHERE id=@id;",
            conn);

        cmd->Parameters->AddWithValue("@u", user->Username);
        cmd->Parameters->AddWithValue("@e", user->Email);
        cmd->Parameters->AddWithValue("@p", user->Password);
        cmd->Parameters->AddWithValue("@uT", user->Updated_At);
        cmd->Parameters->AddWithValue("@id", user->Id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool UserController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand("DELETE FROM users WHERE id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }
}
