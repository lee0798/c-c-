#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Person
{
	private:
		long identity;
	public: 
		void setId(long identity);
		long getId() const;
};
void Person::setId(long id){
	identity = id;
	assert(identity >= 100000000 && identity <= 999999999); //에러 검출을 위해
}
long Person::getId() const{
	return identity;
}
class Student : public Person{
	private:
		double gpa;
	public: 
		void setGPA(double gpa);
		double getGPA() const;
};
void Student :: setGPA(double gp){
	gpa = gp;
	assert(gpa >= 0 && gpa <= 4.0);
}
double Student::getGPA() const{
	return gpa;
}
int main(){
	Person person;
	person.setId(111111111L);
	cout << "Person 객체 정보" << endl;
	cout << "사람의 구분 번호" << person.getId();
	cout <<endl <<endl;
	Student student;
	student.setId(222222222L);
	student.setGPA(3.9);
	cout << "Student 객체 정보"<< endl;
	cout << "학생의 구분 번호"<<student.getId()<<endl;
	cout << "학생의 학점" <<  student.getGPA();
}
