#include <iostream>
#include <cstring>

class Data;
void Free(Data *);

class Data
{
protected:
    int id;
    float salary;
    std::string name;
    std::string status;

public:
    Data(std::string &&name, std::string &&status, int id) : status(std::move(status)), name(std::move(name)), id(id) {}
    virtual void calcSalary() = 0;
    virtual void display()
    {
        std::cout << "id : " << id << std::endl
                  << "Name : " << name << std::endl
                  << "Status : " << status << std::endl
                  << "Salary : " << salary << std::endl
                  << std::endl;
    }
};

class FullTimeEmployee : public Data
{
private:
    float da, hra, basic_salary;

public:
    FullTimeEmployee(std::string &&name, std::string &&status, int id, float da, float hra, float basic_salary) : Data((std::string &&) name, (std::string &&) status, id), da(da), hra(hra), basic_salary(basic_salary) {}
    void calcSalary() override
    {
        Data::salary = da * hra * basic_salary;
    }
};

class PartTimeEmployee : public Data
{
private:
    float hrs, payperhrs;

public:
    PartTimeEmployee(std::string &&name, std::string &&status, int id, float hrs, float payperhrs) : Data((std::string &&) name, (std::string &&) status, id), hrs(hrs), payperhrs(payperhrs) {}
    void calcSalary() override
    {
        Data::salary = hrs * payperhrs;
    }
};

void func(Data *s)
{
    s->calcSalary();
    s->display();
    Free(s);
}

void Free(Data *s)
{
    Data *t = s;
    free(t);
    s = nullptr;
}

int main()
{
    Data *d = new FullTimeEmployee("Kazuma", "Full Time", 1, 80, 100, 1900000);
    func(d);

    d = new PartTimeEmployee("Aqua", "Part Time", 1, 6, 1000);
    func(d);

    return 0;
}