#include "qperson.h"

Qperson::Qperson()
{

}
Qperson::Qperson(QString fname,QObject *parent):QObject(parent)
{
    m_name = fname;
}
int Qperson::age()
{
    return m_age;
}
void Qperson::setAge(int value)
{
    m_age = value;
    emit ageChanged(m_age);
}
void Qperson::incAge()
{
    m_age++;
    emit ageChanged(m_age);
}
