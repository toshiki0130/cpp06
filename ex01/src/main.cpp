#include <iostream>
#include <typeinfo>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // Dataオブジェクトの作成
    Data originalData;
    originalData.id = 1;
    originalData.name = "Test";
    originalData.value = 42.0f;

    // Dataオブジェクトのアドレスをシリアライズ
    uintptr_t raw = Serializer::serialize(&originalData);

    // シリアライズされた値をデシリアライズ
    Data* deserializedData = Serializer::deserialize(raw);

    // 元のポインタとデシリアライズされたポインタが等しいことを確認
    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization work as expected." << std::endl;
    } else {
        std::cout << "There is an issue with serialization/deserialization." << std::endl;
    }

    // デシリアライズされたデータの内容を表示
    std::cout << "ID: " << deserializedData->id << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Value: " << deserializedData->value << std::endl;

    return 0;
}
