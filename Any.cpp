#include <iostream>
#include <string>
#include <string_view>
#include <memory>

using namespace std;

class StorageBase{
    public:
    virtual ~StorageBase(){

    }

    virtual void Print(ostream& out) const =0;
};


template<typename T_VALUE>
class Storage:public StorageBase{
    public:
    template<typename S>
    Storage(S&& val):data_(std::forward<S>(val)){}

    void Print(ostream& out) const override{
        out<<data_;
    }

    private:
    T_VALUE data_;
};

class Any{
    public:

    template<typename T>
    Any(T&& val){
        using Initial = std::remove_reference_t<T>;
        value = std::make_unique<Storage<Initial>>(std::forward<T>(val));
    }

    void Print(ostream& out) const {
        return value->Print(out);
    }

    private:
    std::unique_ptr<StorageBase> value;
};

class Dumper {
public:
    Dumper() {
        std::cout << "construct"sv << std::endl;
    }
    ~Dumper() {
        std::cout << "destruct"sv << std::endl;
    }
    Dumper(const Dumper&) {
        std::cout << "copy"sv << std::endl;
    }
    Dumper(Dumper&&) {
        std::cout << "move"sv << std::endl;
    }
    Dumper& operator=(const Dumper&) {
        std::cout << "= copy"sv << std::endl;
        return *this;
    }
    Dumper& operator=(Dumper&&) {
        std::cout << "= move"sv << std::endl;
        return *this;
    }
};

ostream& operator<<(ostream& out, const Any& arg) {
    arg.Print(out);
    return out;
}

ostream& operator<<(ostream& out, const Dumper&) {
    return out;
}

int main() {
    Any any_int(42);
    Any any_string("abc"s);

    // операция вывода Any в поток определена чуть выше в примере
    cout << any_int << endl << any_string << endl;

    Any any_dumper_temp{Dumper{}};

    Dumper auto_dumper;
    Any any_dumper_auto(auto_dumper);
}