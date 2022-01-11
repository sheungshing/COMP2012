#include "GymStudent.h"
#include <iostream>

using namespace std;

// TODO: complete the constructor of GymStudent
GymStudent::GymStudent(const string& name, const string& gender):GymPerson(name,gender),num_of_session(0){
    session_list = new const GymSession *[MAX_NUM_OF_SESS-1];
    
}

// TODO: complete GymStudent::join_session
void GymStudent::join_session(const GymSession* sess) {
    if(num_of_session < MAX_NUM_OF_SESS){
        session_list[num_of_session] = sess;
        num_of_session++;
    }else{
     cout << "Failed to join " << sess->get_area()<< " at "<<sess->get_period() << ". Reached the maximum number of sessions allowed. "<< endl;}
    return;
}
void GymStudent::print() const {
    cout << "GymStudent " << get_name() << ", Gender: " << get_gender() <<endl;
    cout<< "Joined sessions: " <<endl;
    for(int i = 0 ; i < num_of_session ; i ++ ) {
        cout << "Period: " << session_list[i]->get_period() << ", Area: " << session_list[i]->get_area() << endl;
    }
    cout<<endl; 
}