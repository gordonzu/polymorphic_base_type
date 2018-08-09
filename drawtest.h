// drawtest.h

#ifndef DRAWTEST_OBJECT_T_H
#define DRAWTEST_OBJECT_T_H

#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <ostream>
#include <string>
#include <assert.h>

template<typename T>
std::string print_string(const T& x)
{
    std::stringstream out;
 
    out << x;
    std::string str_ = out.str();
    return str_;
}

class object_t
{
public:
    template<typename T>
    object_t(T x) : self_(std::make_shared<model<T>>(std::move(x)))
    {
    }

    friend std::string print_string(const object_t& x)
    {
        return x.self_->print_string_();      
    }

    friend std::ostream& operator<<(std::ostream& out, const object_t& x)
    {
        out << x.self_->print_string_();
        return out;
    }   

private:
    struct concept_t
    {
        virtual ~concept_t() = default;        
        virtual std::string print_string_() const = 0;
    }; 

    template<typename T>
    struct model final : concept_t
    {
        model(T x) : data_(std::move(x))
        {
        }

        std::string print_string_() const override
        {
            return print_string(data_);
        }

        T data_;
    };

    std::shared_ptr<const concept_t> self_;
}; 

using attributes_t = std::unordered_map<object_t, object_t>;

namespace std 
{
    template<>
    struct hash<object_t>
    {
        size_t operator()(const object_t& x) const
        {
            std::string str = print_string(x);
            return hash<std::string>()(str);
        }
    };
};


void print_vector(const attributes_t& x)
{
    std::stringstream out;
    out << "<vector>" << std::endl;

    for (const auto& e: x) {
        print_string(e);
    }

    out << "</vector>" << std::endl; 
}

class my_class_t
{
    friend std::ostream& operator<<(std::ostream& out, const my_class_t& x)
    {
        out << "my_class_t";
        return out;
    }
};

#endif

