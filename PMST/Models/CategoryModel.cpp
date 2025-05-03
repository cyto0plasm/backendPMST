#include "CategoryModel.h"

using namespace PMST;

CategoryModel::CategoryModel() {
    this->id = 0;
    this->pharmacy_id = 1;
    this->name = "";
    this->description = "";
    this->created_at = DateTime::Now;
    this->updated_at = DateTime::Now;
}