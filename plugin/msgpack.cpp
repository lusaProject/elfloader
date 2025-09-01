#include <iostream>
#include <sstream>
#include <msgpack.hpp>

struct MyData
{
    int id;
    std::string name;
    double value;

    MSGPACK_DEFINE(id, name, value);
};

#ifdef __cplusplus
extern "C"
{
#endif

    void main1(void)
    {
        MyData data;
        data.id = 42;
        data.name = "John";
        data.value = 3.14;

        std::stringstream buffer;
        msgpack::pack(buffer, data);

        std::string packedData = buffer.str();
        std::cout << "Packed data: " << packedData << std::endl;

        msgpack::object_handle oh = msgpack::unpack(packedData.data(), packedData.size());
        msgpack::object obj = oh.get();
        MyData unpackedData;
        obj.convert(unpackedData);

        std::cout << "Unpacked data: id=" << unpackedData.id << ", name=" << unpackedData.name << ", value=" << unpackedData.value << std::endl;

    }

#ifdef __cplusplus
}
#endif
