//submit this file only
#include "decimal.h"
using namespace std;
//add your code below
//see FAQ for what you can/cannot do 

Decimal::Decimal()
{
    size = 1;
    content = new char[size];
    content[0] = '0';
}
Decimal::Decimal(int input){

    if(input == 0){
        size = 1;
        content = new char[size];
        content[0] = '0';
    }else{

        int TemInput = input;
        int TemSize = 0;
        int mod;

        if(input <0)
            TemInput*= -1;

        while(true){
            //mod = TemInput%10;
            TemInput/=10;
            TemSize++;
            if (TemInput == 0)
                break;
        }

        if(input < 0){
            TemInput = input *-1;
            TemSize++;
            size = TemSize;
            content = new char[size];
            content[0] = '-';
            
            for(TemSize = size-1; TemSize > 0;TemSize--){
            mod = TemInput%10;
            TemInput/=10;
            content[TemSize] = (mod+48);
            }
        }else{
            TemInput = input;
            size = TemSize;
            content = new char[size];

            for(TemSize = size-1; TemSize >= 0;TemSize--){
            mod = TemInput%10;
            TemInput/=10;
            content[TemSize] = (mod+48);
            }
        }

    }
     
}
Decimal::Decimal(const char* input){
    int TemSize = 0;

        while(true){
            if(input[TemSize] == '\0')
                break;
            TemSize++;   
        }

        size = TemSize;
        content = new char[size];
        TemSize = 0;

        while(true){
            if(input[TemSize] == '\0')
                break;
            content[TemSize] = input[TemSize];
            TemSize++;   
        }
}
Decimal::Decimal(const Decimal& another){
    this->size = another.size;
        this->content = new char[size];
        for(int i=0; i<this->size ; i++){
            content[i] = another.content[i];
        }
}
Decimal::~Decimal(){
    delete[] content;
    content = nullptr;
    //cout << "\nestructor  !!!! " << endl;
}
bool Decimal::isNegative() const{
if(content[0] =='-'){
            return true;
        }
        return false;
} 
Decimal Decimal::flipSign() const{
        Decimal flipSign;
        delete[] flipSign.content;
        if(this->isNegative()){
            flipSign.size = size-1;
            flipSign.content = new  char [flipSign.size];
            //char tem[flipSign.size];
            for(int i=0; i<flipSign.size;i++){
              //  tem[i] = this->content[i+1];
                flipSign.content[i] = this->content[i+1];
            }
            return flipSign;
        }else if(content[0] == '0'&& size==1){
            return *this;
        }else{
            flipSign.size = size+1;
            flipSign.content =  new char [flipSign.size];
            flipSign.content[0] = '-';
            //char tem[flipSign.size];
            for(int i=1; i<flipSign.size;i++){
                //tem[i] = this->content[i-1];
                flipSign.content[i] = this->content[i-1];
            }   
            return flipSign;
        }
        
       
}
bool Decimal::isLargerThan(const Decimal& another) const{
    if(size == another.size && size == 1 && content[0] == '0' && content[0]== another.content[0]){
            return false;
        } //identify 0-0
        
        bool isThisNegative = this->isNegative();
        bool isAnotherNegative = another.isNegative();
        if(isThisNegative == true && isAnotherNegative != true)
            return false;
        if(isThisNegative != true && isAnotherNegative == true)
            return true;

        if(isThisNegative== false && isAnotherNegative == false){ // both positive numbers
        
            if(this->countDigitsBeforeDP() > another.countDigitsBeforeDP())
                return true;
            if(this->countDigitsBeforeDP() < another.countDigitsBeforeDP())
                return false;
            if((this->countDigitsBeforeDP() == another.countDigitsBeforeDP())){
                for(int i=0 ; i< this->countDigitsBeforeDP();i++){
                    //cout << " \n"<<content[i] <<"  " << another.content[i] << endl;
                    if(content[i] > another.content[i])
                        return true;
                    if(content[i] < another.content[i])
                        return false;
                }
                int j=this->countDigitsBeforeDP()+1;
                if(this->countDigitsAfterDP() > another.countDigitsAfterDP()){
                    for(j;j<another.size;j++){
                        if(this->content[j]<another.content[j])
                            return false;
                    }
                    return true;
                }   
                if(this->countDigitsAfterDP() < another.countDigitsAfterDP()){
                    for(j;j<this->size;j++){
                        if(this->content[j]>another.content[j])
                            return true;
                    }
                    return false;
                }
                    
                if(this->countDigitsAfterDP() == another.countDigitsAfterDP()){
                    for(int i = this->countDigitsBeforeDP()+1; i< size;i++){
                       // cout << " \n"<<content[i] <<"  " << another.content[i] << endl;
                        if(content[i] > another.content[i]){
                            return true;
                        } 
                    }
                    return false;
                }
                
            }
        }

        if(isThisNegative== true && isAnotherNegative == true){ // both negative numbers
        
            if(this->countDigitsBeforeDP() > another.countDigitsBeforeDP())
                return false;
            if(this->countDigitsBeforeDP() < another.countDigitsBeforeDP())
                return true;//
            if((this->countDigitsBeforeDP() == another.countDigitsBeforeDP())){
                for(int i=1 ; i< this->countDigitsBeforeDP();i++){
                    //cout << " \n"<<content[i] <<"  " << another.content[i] << endl;
                    if(content[i] > another.content[i])
                        return false;
                    if(content[i] < another.content[i])
                        return true;
                }
                int j=this->countDigitsBeforeDP()+2;
                if(this->countDigitsAfterDP() > another.countDigitsAfterDP()){
                     
                    for(j; j < another.size; j++){
                    if(content[j] < another.content[j])
                        return true;
                    }
                return false;
                }
                if(this->countDigitsAfterDP() < another.countDigitsAfterDP()){
                    
                     for(j; j< this->size;j++){
                       // cout << " \n"<<content[j] <<"  " << another.content[j] << endl;
                        if(content[j] > another.content[j])
                        return false;
                     }
                return true;
                }
                if(this->countDigitsAfterDP() == another.countDigitsAfterDP()){
                    for(j; j< this->size;j++){
                        //cout << " \n"<<content[j] <<"  " << another.content[j] << endl;
                        if(content[j] < another.content[j])
                        return true;
                     }
                return false;
                }
                
            }
        }
        
       return false;
}

int Decimal::countDigitsBeforeDP() const{
        if(size == 1 && content[0] == '0')
            return 0;
        int index = 0;
        int i = 0;
        if (this->isNegative() == true)
            i = 1;
        
        for(i; i<size;i++){
            if(content[i] == '.'){
                break;
            }
            index++;
        }
        return index;
    }

int Decimal::countDigitsAfterDP() const{
    if(size == 1 && content[0] == '0')
            return 0;

    bool isThisDecimal = false;

    int i = size -1;
    int index = 0;
    for(i; i>=0; i--){
        if(content[i] == '.'){
            isThisDecimal = true;
            break;
        }
        index++;
    }
    if(isThisDecimal == false)
        return 0;
    return index;
    
}

Decimal Decimal:: add(const Decimal& another) const{
    bool flagSM = false; // Indicate if the object is flipped
    bool flagLG = false;
    Decimal LG;
    delete [] LG.content;
    LG.content = nullptr;
    Decimal SM;
    delete [] SM.content;
    SM.content = nullptr;
    Decimal temp;
    delete [] temp.content;
    temp.content = nullptr;
    //cout << 1 << endl; // 1
    Decimal idc = this->isNegative()?this->flipSign():*this;
    Decimal idk = another.isNegative()?another.flipSign():another;
    if (idc.isLargerThan(idk)){ //if another < this // 2.1
        //cout << 2.1 << endl;
        if(another.isNegative()){ //3.1
            //cout << 3.1 << endl;
            Decimal temp4 = another.flipSign();
            SM.size = temp4.size;
            SM.content = new char [SM.size];
            for (int i=0; i<SM.size;i++){
                SM.content[i] = temp4.content[i];
            }
            flagSM = true;
        }
        else{ // 3.2
            //cout << 3.2 << endl;
            SM.size = another.size;
            SM.content = new char [SM.size];
            for (int i=0; i<SM.size;i++){
                SM.content[i] = another.content[i];
            }
        }
        if(SM.countDigitsAfterDP()>this->countDigitsAfterDP()){ // 4.1
            //cout << 4.1 << endl;
            if (this->isNegative()){ // 5.1
                //cout << 5.1 << endl;
                Decimal temp3 = this->flipSign();
                temp.size = temp3.size;
                temp.content = new char [temp.size];
                for (int i=0; i<temp.size; i++){
                    temp.content[i] = temp3.content[i];
                }
                delete [] temp3.content;
                temp3.content = nullptr;
                flagLG = true;
            }
            else{ // 5.2
                //cout << 5.2 << endl;
                temp.size = this->size;
                temp.content = new char[temp.size];
                for (int i=0; i<temp.size; i++){
                    temp.content[i] = this->content[i];
                }
            }
            if(temp.countDigitsBeforeDP()==temp.size){ // 6.1
                //cout << 6.1 << endl;
                Decimal temp2(temp.multiplyByPowerOfTen(SM.countDigitsAfterDP()+1));
                temp2.content[temp.countDigitsBeforeDP()] = '.';
                LG.size = temp2.size;
                LG.content = new char[LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = temp2.content[i];
                }
                delete [] temp.content;
                temp.content = nullptr;
                delete [] temp2.content;
                temp2.content = nullptr;
            }
            else{ // 6.2
                //cout << 6.2 << endl;
                LG.size = temp.size + SM.countDigitsAfterDP()-temp.countDigitsAfterDP();
                LG.content = new char[LG.size];
                for (int i=0; i<temp.size; i++){ 
                    LG.content[i] = temp.content[i];
                }
                for (int i=temp.size; i<LG.size; i++){ 
                    LG.content[i] = '0';
                }
                delete [] temp.content;
                temp.content = nullptr;
            }
        }
        else{ //4.2
            //cout << 4.2 << endl;
            if (this->isNegative()){ // 5.1
                //cout << 5.1 << endl;
                Decimal temp2 = this->flipSign();
                LG.size = temp2.size;
                LG.content = new char [LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = temp2.content[i];
                }
                delete [] temp2.content;
                temp2.content = nullptr;
                flagLG = true;
            }
            else{ // 5.2
                //cout << 5.2 << endl;
                LG.size = this->size;
                LG.content = new char[LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = this->content[i];
                }
            }
        }
    }
    else{ // if another > this    //2.2
        //cout << 2.2 << endl;
        if(this->isNegative()){ //3.1
            //cout << 3.1 << endl;
            SM = this->flipSign();
            flagSM = true;
        }
        else{ //3.2
            //cout << 3.2 << endl;
            SM.size = this->size;
            SM.content = new char[SM.size];
            for (int i=0; i<SM.size; i++){
                SM.content[i] = this->content[i];
            }
        }
        if(SM.countDigitsAfterDP()>another.countDigitsAfterDP()){ //4.1
            //cout << 4.1 << endl;
            if (another.isNegative()){ //5.1
                //cout << 5.1 << endl;
                Decimal temp3 = another.flipSign(); 
                temp.size = temp3.size;
                temp.content = new char [temp.size];
                for (int i=0; i<temp.size; i++){
                    temp.content[i] = temp3.content[i];
                }
                delete [] temp3.content;
                temp3.content = nullptr;
                flagLG = true;
            }
            else{ //5.2
                //cout << 5.2 << endl;
                temp.size = another.size;
                temp.content = new char[temp.size];
                for (int i=0; i<temp.size; i++){
                    temp.content[i] = another.content[i];
                }
            }
            if(temp.countDigitsBeforeDP()==temp.size){ //6.1
                //cout << 6.1 << endl;
                Decimal temp2(temp.multiplyByPowerOfTen(SM.countDigitsAfterDP()+1));
                temp2.content[temp.countDigitsBeforeDP()] = '.';
                LG.size = temp2.size;
                LG.content = new char[LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = temp2.content[i];
                }
                delete [] temp.content;
                temp.content = nullptr;
                delete [] temp2.content;
                temp2.content = nullptr;
            }
            else{  //6.2
                //cout << 6.2 << endl;
                LG.size = temp.size + SM.countDigitsAfterDP()-temp.countDigitsAfterDP();
                LG.content = new char[LG.size];
                for (int i=0; i<temp.size; i++){
                    LG.content[i] = temp.content[i];
                }
                for (int i=temp.size; i<LG.size; i++){
                    LG.content[i] = '0';
                }
                delete [] temp.content;
                temp.content = nullptr;
            }
        }
        else{ // 4.2
            //cout << 4.2 << endl;
            if (another.isNegative()){ // 5.1
                //cout << 5.1 << endl;
                Decimal temp2 = another.flipSign();
                LG.size = temp2.size;
                LG.content = new char [LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = temp2.content[i];
                }
                delete [] temp2.content;
                temp2.content = nullptr;
                flagLG = true;
            }
            else{ // 5.2
                //cout << 5.2 << endl;
                LG.size = another.size;
                LG.content = new char[LG.size];
                for (int i=0; i<LG.size; i++){
                    LG.content[i] = another.content[i];
                }
            }
        }
    }
    delete [] idc.content;
    idc.content = nullptr;
    delete [] idk.content;
    idk.content = nullptr;
    Decimal sum; // initialise return object
    delete [] sum.content; 
    sum.content = nullptr;
    sum.size = LG.size+1;
    sum.content = new char[sum.size]; 
    sum.content[0] = '0';
    for (int i=0; i<LG.size; i++){
        sum.content[i+1] = LG.content[i];
    }
    

    //cout << 7 << endl; // 7
    int digit_difference = LG.countDigitsBeforeDP() - SM.countDigitsBeforeDP();
    int operation;
    bool flag = false;
    //cout << "flagSM =" << flagSM << endl;
    //cout << "flagLG =" << flagLG << endl; 
    
    
    if ((flagSM && flagLG)||((!flagSM) && (!flagLG))){
        //cout << 8.1 << endl; // 8.1
        operation = 1;
        if (flagSM && flagLG){
            flag = true;
        }
    }
    else if ((!flagSM && flagLG)||(flagSM && !flagLG)){
        //cout << 8.2 << endl; // 8.2
        operation = 2;
        if (!flagSM && flagLG){ // return negative value
            flag = true;
        }
    }

    switch(operation){
        case 1:{
            //cout << "flag=" << flag << endl; 
            //cout << 9.1 << endl; // 9.1
            for (int i = SM.size-1; i>=0; i--){ //addition with condition
                if(SM.content[i]=='.'){ //not '.' on either add or added element
                    continue;
                }
                if (sum.content[i+digit_difference+1]+SM.content[i]-48>'9'){ // if less than 0, perform plus 1 to left digit
                    int j = i;
                    while (sum.content[j+digit_difference]=='9'||sum.content[j+digit_difference]=='.'){ //if j-1 is smaller than 0
                        if (sum.content[j+digit_difference]=='.'){
                            j--;
                            //cout<<"if "<<i<<endl;
                            continue;
                            
                        }
                        //cout<<"out of if "<<i<<endl;
                        sum.content[j+digit_difference] -= 9;
                        j--;
                    }
                    //cout<<" Out of while"<<i<<endl;
                    sum.content[j+digit_difference] += 1;
                    sum.content[i+digit_difference+1] = sum.content[i+digit_difference+1] + SM.content[i] - 58;
                }
                else {
                    //cout<<"else "<<i<<endl;
                    sum.content[i+digit_difference+1] = sum.content[i+digit_difference+1] + SM.content[i] - 48;
                }
                //cout << sum.content[i+digit_difference+1];
            }
            //cout << endl;
            delete [] SM.content;
            SM.content = nullptr;
            delete [] LG.content;
            LG.content = nullptr;
            Decimal obj;
            delete [] obj.content;
            obj.content = nullptr;
            obj.size = sum.size;
            int difference = 0;
            if (sum.content[0]=='0'&&sum.content[1]!='.'){
                obj.size--;
                difference = 1;
            }
            obj.content = new char [obj.size];
            for (int i=0; i<obj.size; i++){
                obj.content[i] = sum.content[i+difference];
            }
            delete [] sum.content;
            sum.content = nullptr;
            //cout << sum.content[sum.size-1]endl;
            if (flag){ // 10.1
                //cout << 10.1 << endl;
                return obj.flipSign();
            }
            else{ // 10.2
                /*cout << 10.2 << endl;
                for (int i=0; i< obj.size; i++){
                    cout << obj.content[i];
                }
                cout << endl;*/
                return obj;
            }
        }
        case 2:{
            //cout << 9.2 << endl;
            /*cout << digit_difference << endl;
            cout << sum.size << " = " << sizeof(sum.content)/sizeof(sum.content[0]) << endl;
            for (int i=0; i<10; i++){
                cout << sum.content[i];
            }*/
            for (int i = SM.size-1; i>=0; i--){ //addition with condition
                if(SM.content[i]=='.'){ //not '.' on either add or added element
                    continue;
                }
                if (sum.content[i+digit_difference+1]-SM.content[i]<0){ // if less than 0, perform plus 1 to left digit
                    int j = i;
                    while (sum.content[j+digit_difference]=='0'||sum.content[j+digit_difference]=='.'){ //if j-1 is smaller than 0
                        if (sum.content[j+digit_difference]=='.'){
                            j--;
                            continue;
                        }
                        sum.content[j-1] += 9;
                        j--;
                    }
                    sum.content[i+digit_difference] -= 1;
                    sum.content[i+digit_difference+1] += 58 - SM.content[i] ;
                }
                else{
                    sum.content[i+digit_difference+1] = sum.content[i+digit_difference+1] - SM.content[i]  + '0';
                }
            }
            Decimal obj;
            delete [] obj.content;
            obj.content = nullptr;
            obj.size = sum.size;
            int count = 0;
            while(sum.content[count]=='0'&&sum.content[count+1]!='.'){
                obj.size--;
                count++;
            }
            obj.content = new char[obj.size];
            for (int i=0; i<obj.size; i++){
                obj.content[i] = sum.content[i+count];
            }
            delete [] LG.content;
            LG.content = nullptr;
            delete [] SM.content;
            SM.content = nullptr;
            delete [] sum.content;
            sum.content = nullptr;
            if (flag){ // 10.1
                //cout << 10.1 << endl;
                return obj.flipSign();
            }
            else { //10.2
                //cout << 10.2 << endl;
                return obj;
            }
        }
    }
    return *this;
}

void Decimal::addToSelf(const Decimal& another){
    Decimal tem{(this->add(another))};

   delete[] this->content;

    this->content = nullptr;
     this->size = tem.size;
     this->content = new char[this->size];
    
    for(int i=0; i<this->size;i++ ){
        this->content[i] = tem.content[i];
    }
    
}

Decimal Decimal::multiplyByPowerOfTen(int power) const{
    
    if(this->size == 1 && this->content[0] == '0'){
         return *this;
    }

    if(power == 0)
        return *this;
    Decimal tem;
    delete[] tem.content;
    if(this->countDigitsAfterDP() == 0){
        tem.size = this->size + power;
        tem.content = new char[tem.size];
        for(int i=0; i< this->size;i++){
            tem.content[i] = this->content[i];
        }
        for(int i= this->size; i < tem.size;i++){
            tem.content[i] = '0';
        }
        return tem;
    }

    if(this->countDigitsAfterDP() != 0){
        if(this->countDigitsAfterDP() == power){
           
            tem.size = this->size -1;
            tem.content = new char[tem.size];
            

            for(int i=0; i<((this->size) - (power+1)) ; i++){
                tem.content[i] = this->content[i];
            }
            
            for(int i= (this->size-power)-1; i<tem.size ; i++){
                tem.content[i] = this->content[i+1];
            }
            return tem;
        }

        if(this->countDigitsAfterDP() < power){
            // cout << this->countDigitsAfterDP()<< endl;
            tem.size = this->size + (power - this->countDigitsAfterDP());

            tem.content = new char [tem.size];

            for(int i = 0; i< (this->size - this->countDigitsAfterDP()-1);i++){
                tem.content[i] = this->content[i];
            }
            // cout << endl;
            // tem.print();
            // cout << endl;
            for(int i= (this->size - this->countDigitsAfterDP()) ; i < this->size; i++){
                tem.content[i] = this->content[i];
            }
            // tem.print();
            // cout << endl;

            for(int i= this->size; i< tem.size;i++){
                tem.content[i] = '0';
            }
            return tem;
        }

        if(this->countDigitsAfterDP() > power){

            tem.size = this->size;
        
            tem.content = new char [tem.size];
            for(int i = 0; i< (this->size - (this->countDigitsAfterDP()+1));i++){
                tem.content[i] = this->content[i];
            }
            // cout << endl;
            // tem.print();
            for(int i = (this->size - this->countDigitsAfterDP()-1); i<((this->size - this->countDigitsAfterDP()-1)+power);i++){
                tem.content[i] = this->content[i+1];
            }
            // cout << endl;
            // tem.print();
            //cout << endl;
              tem.content[((this->size - this->countDigitsAfterDP()-1)+power)] = '.';
            //    cout << endl;
            //   tem.print();
             for(int i = ((this->size - this->countDigitsAfterDP()-1)+power)+1  ; i < this->size ; i++){
                tem.content[i] = this->content[i];
            }
             // cout << endl;
            //  tem.print();
            return tem;
        }
    } 
}

Decimal Decimal::multiplyBySingleDigit(int multiplier) const{
    if(multiplier >= 0 && multiplier <= 9){
        if(multiplier == 1){
            return *this;
        }else if(multiplier == 0){
            Decimal temZero;
            return temZero;
        }
    }
    return this->add(this->multiplyBySingleDigit(multiplier-1));
}

Decimal Decimal::multiply(const Decimal& another) const{
    
    if((this->content[0]=='0' && this->size==1)||(another.content[0]=='0' &&another.size==1)){
        Decimal tem0;
        return tem0;
    }

    if(this->isNegative() == true && another.isNegative() == true){
        return this->flipSign().multiply(another.flipSign());
    }
    if(this->isNegative() == false && another.isNegative() == true){
        return this->multiply(another.flipSign()).flipSign();
    }
    if(this->isNegative()==true && another.isNegative()==false){
        return another.multiply(this->flipSign()).flipSign();
    }



    Decimal returnDecimal;
    delete[] returnDecimal.content;
    returnDecimal.content = nullptr;

    Decimal thisInt;
   delete[] thisInt.content;
   thisInt.content = nullptr;
    Decimal thisDecimal;
    delete[] thisDecimal.content;
    thisDecimal.content= nullptr;
    Decimal anotherInt;
    delete[] anotherInt.content;
    anotherInt.content = nullptr;
    Decimal anotherDecimal;
    delete[] anotherDecimal.content;
    anotherDecimal.content= nullptr;

    Decimal combineThis;
    delete[] combineThis.content;
    combineThis.content= nullptr;
    Decimal combineAnother;
    delete[] combineAnother.content;
    combineAnother.content =nullptr;

    //Decimal mulptiplyC3
    
    if(this->isNegative()==false && another.isNegative()==false){  // positive big - small
         //cout << endl;
        if(this->countDigitsBeforeDP() > another.countDigitsBeforeDP()){
            thisInt.size =this->countDigitsBeforeDP();
            anotherInt.size = this->countDigitsBeforeDP();
            thisInt.content = new char[thisInt.size];
            anotherInt.content = new char[anotherInt.size];
            for(int i = 0; i< this->countDigitsBeforeDP() -another.countDigitsBeforeDP() ;i++){
                thisInt.content[i] = this->content[i];
                anotherInt.content[i] = '0';
            }
            for(int i= this->countDigitsBeforeDP() -another.countDigitsBeforeDP() ; i< this->countDigitsBeforeDP();i++){
                thisInt.content[i] = this->content[i];
                anotherInt.content[i] = another.content[i-(this->countDigitsBeforeDP() -another.countDigitsBeforeDP())];
            }
            
        //     thisInt.print();
        //    anotherInt.print();
        //     cout << endl;
        }else if(this->countDigitsBeforeDP() <= another.countDigitsBeforeDP()){
            thisInt.size =another.countDigitsBeforeDP();
            anotherInt.size = another.countDigitsBeforeDP();
            thisInt.content = new char[thisInt.size];
            anotherInt.content = new char[anotherInt.size];

            for(int i = 0; i<  another.countDigitsBeforeDP()-this->countDigitsBeforeDP() ;i++){
                anotherInt.content[i] = another.content[i];
                thisInt.content[i] = '0';
            }
            for(int i= another.countDigitsBeforeDP() -this->countDigitsBeforeDP() ; i< another.countDigitsBeforeDP();i++){
                anotherInt.content[i] = another.content[i];
                thisInt.content[i] = this->content[i-(another.countDigitsBeforeDP() -this->countDigitsBeforeDP())];
            }
        //     thisInt.print();
        //    anotherInt.print();
        //     cout << endl;
        }
        // thisInt.content[thisInt.size-1] = '.';
        // anotherInt.content[anotherInt.size-1] = '.';

        if(this->countDigitsAfterDP() > another.countDigitsAfterDP()){
            thisDecimal.size = this->countDigitsAfterDP();
            anotherDecimal.size = this->countDigitsAfterDP();
            thisDecimal.content = new char [thisDecimal.size];
            anotherDecimal.content = new char[anotherDecimal.size];
            
            for(int i=0; i< another.countDigitsAfterDP() ;i++){
                 thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
                 anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
            }
            for(int i =another.countDigitsAfterDP(); i<thisDecimal.size;i++){
                thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
                 anotherDecimal.content[i] = '0'; 
            }
            
        //     thisDecimal.print();
        //    anotherDecimal.print();
        //     cout << endl;
        }else if(this->countDigitsAfterDP() <= another.countDigitsAfterDP()){
            thisDecimal.size = another.countDigitsAfterDP();
            anotherDecimal.size = another.countDigitsAfterDP();
            thisDecimal.content = new char [thisDecimal.size];
            anotherDecimal.content = new char[anotherDecimal.size];
            
            for(int i=0; i< this->countDigitsAfterDP() ;i++){
                 
                 anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
                 thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
            }
            for(int i =this->countDigitsAfterDP(); i<thisDecimal.size;i++){
                anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
                 thisDecimal.content[i] = '0'; 
            }

        //     thisDecimal.print();
        //    anotherDecimal.print();
           
        //     cout << endl;

        }

        combineThis.size=thisInt.size+thisDecimal.size;
        combineAnother.size = thisInt.size+thisDecimal.size;
        combineThis.content = new char[combineThis.size];
        combineAnother.content = new char[combineAnother.size];
        for(int i = 0; i<thisInt.size;i++){
            combineThis.content[i] = thisInt.content[i];
            combineAnother.content[i] = anotherInt.content[i];
        }
        for(int i= 0 ; i<thisDecimal.size;i++){
            combineThis.content[i+thisInt.size] = thisDecimal.content[i];
            combineAnother.content[i+thisInt.size] = anotherDecimal.content[i];
        }
        // combineThis.print();
        // combineAnother.print();
        // cout << endl;

        
       //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        


         int mulSize = combineThis.size+combineAnother.size;

         int temMuptiple[mulSize+1]={}; // NEW 
         int la=combineThis.size,lb=combineAnother.size;
        // int index =0;
        for (int i =0; i< combineThis.size;i++){
            for(int j =0; j < combineAnother.size;j++){
                temMuptiple[i+j] += ((combineThis.content[la-1-i]-'0'))*((combineAnother.content[lb-j-1]-'0'));
            }
        }
          
        for(int i =0; i< mulSize; i++){
                temMuptiple[i+1] += temMuptiple[i]/10;
                temMuptiple[i] %= 10;
        }

        // cout << endl;
        // for(int i  =0 ; i<mulSize ;i++ ){
        //     cout <<  temMuptiple[i];
        // }
    //    cout << "\n temMuptiple size : "  << sizeof(temMuptiple)/sizeof(temMuptiple[0]) << endl;
        
        int temMuptiple2[mulSize]={};
        for(int i=0 ; i<mulSize;i++ ){
            temMuptiple2[i] = temMuptiple[i];
            //cout << temMuptiple2[i] ;
        }

        // cout << "\n temMuptiple2 size : "  << sizeof(temMuptiple2)/sizeof(temMuptiple2[0]) << endl;
        
        char tem1[mulSize]={};
        for(int i= 0; i< mulSize ;i++){
            tem1[i] =  temMuptiple2[mulSize-1-i]+'0' ;
            // cout << tem1[i] ;
        }

        // cout <<  "\ntem1 : size:  "  << sizeof(tem1)/sizeof(tem1[0]) << endl; 
        // cout << endl;

        char tem2[mulSize+1]={};
        bool isDecimal = false;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~```````
        if(this->countDigitsAfterDP() >0 || another.countDigitsAfterDP() >0){
            isDecimal == true;
            int tmp2=max(this->countDigitsAfterDP(),another.countDigitsAfterDP());
            for(int i =0;i< tmp2*2;i++){
                tem2[mulSize-i] = tem1[mulSize-i-1];
            }
            tem2[mulSize-(tmp2*2)] ='.';
            for(int i=0 ; i <max(this->countDigitsBeforeDP(),another.countDigitsBeforeDP())*2;i++){
                tem2[i] = tem1[i];
            }
        }else{
            for(int i =0 ; i<mulSize ;i++ ){
                tem2[i] = tem1[i];
            }
            tem2[mulSize] ='.';
        }

        // for(int i =0; i<sizeof(tem2)/sizeof(tem2[0]);i++){
        //     cout << tem2[i] ;
        // }
        // cout <<  "tem2 size : " << sizeof(tem2)/sizeof(tem2[0]) << endl;
        int indexAfter = 0;
        int indexBefor = 0;

            for(int i = mulSize; i >=0 ; i--){
                if(tem2[i] == '0' || tem2[i]=='.'){
                    indexAfter++;
                }else break;
            }

            // cout << "\nthis before Dp :  " << this->countDigitsBeforeDP() << endl;
            // cout << "Anotehr before Dp :  " << another.countDigitsBeforeDP() << endl;

            for(int i = 0; i< max(this->countDigitsBeforeDP(),another.countDigitsBeforeDP())*2 ;i++){
                if(tem2[i] == '0' || tem2[i] == '.'){
                    indexBefor ++;
                }else break;
            }
            // cout << "\n right now before dp : " << indexBefor << endl;
            if(indexBefor == this->countDigitsBeforeDP()+another.countDigitsBeforeDP() && indexBefor >0 && tem2[this->countDigitsBeforeDP()+another.countDigitsBeforeDP()]=='.'){
                indexBefor = this->countDigitsBeforeDP()+another.countDigitsBeforeDP()-1;
            }
            // cout << "\n right now before dp2 : " << indexBefor << endl;
        
        
       
        // for(int i= 0; i< mulSize+1 ;i++){
           
        //     if(tem1[mulSize-i] =='0' && !(i >this->countDigitsAfterDP()+another.countDigitsAfterDP())){
        //         cout << "Found" << endl;
        //         indexAfter++;
        //     }
        // }

    //    cout << "\n indexBefor : " << indexBefor << endl;
    //     cout << "\n indexAfter : " << indexAfter << endl;
        
        returnDecimal.size = mulSize+1-indexBefor-indexAfter;
        returnDecimal.content = new char [returnDecimal.size];

        
        
       // cout << "\nreturnDecimal.size : " << returnDecimal.size << endl;
        
        for(int i = 0; i <returnDecimal.size ;i++ ){
            returnDecimal.content[i] = tem2[i+indexBefor];
        }
        // for(int i= 0; i< mulSize+1 ;i++){
           
        //     cout << tem1[i] ;
        // }
      

       // cout<< endl;
        
    // delete[] thisInt.content;
    // delete[] thisDecimal.content;
    // delete[] anotherInt.content;
    // delete[] anotherDecimal.content;
    // delete[] combineThis.content;
    // delete[] combineAnother.content;
    
    }
    delete[] thisInt.content;
        thisInt.content =nullptr;
        delete[] thisDecimal.content;
        thisDecimal.content =nullptr;
        delete[] anotherInt.content;
        anotherInt.content =nullptr;
        delete[] anotherDecimal.content;
        anotherDecimal.content = nullptr;

    delete[] combineThis.content;
    combineThis.content =nullptr;
    delete[] combineAnother.content;
    combineAnother.content = nullptr;
    
    return returnDecimal;
    
}
Decimal Decimal::subtract(const Decimal& another) const{
    
   if((this->size == 1 && this->content[0]=='0') &&(another.size == 1 && another.content[0]=='0')){ // both = 0
        return  *this;
    }
   
     if(this->isNegative()==false && another.isNegative()==false){
         if(this->isLargerThan(another) == false){ // positive small - big
             return another.subtract(*this).flipSign();
         }
     }

     if(this->isNegative() == true && another.isNegative() == true){
         if(this->flipSign().isLargerThan(another.flipSign()) == true){
             return this->flipSign().subtract(another.flipSign()).flipSign();
         }else return another.flipSign().subtract(this->flipSign());

     }

     if(this->isNegative()==false && another.isNegative() == true){
            if(this->isLargerThan(another.flipSign())){
                return this->add(another.flipSign());
            }else return another.flipSign().add(*this);
            
     }

     if(this->isNegative()== true && another.isNegative()==false){
         if(this->flipSign().isLargerThan(another) == true){
             return this->flipSign().add(another).flipSign();
         }else return this->flipSign().add(another).flipSign();
     }

    int carry = 0;
    

    Decimal returnDecimal;
    delete[] returnDecimal.content;

    Decimal thisInt;
    delete[] thisInt.content;
    Decimal thisDecimal;
    delete[] thisDecimal.content;
    Decimal anotherInt;
    delete[] anotherInt.content;
    Decimal anotherDecimal;
    delete[] anotherDecimal.content;

    Decimal combineThis;
    delete[] combineThis.content;
    Decimal combineAnother;
    delete[] combineAnother.content;

    if(this->isNegative()==false && another.isNegative()==false){  // positive big - small
         //cout << endl;
        if(this->countDigitsBeforeDP() > another.countDigitsBeforeDP()){
            thisInt.size =this->countDigitsBeforeDP()+1;
            anotherInt.size = this->countDigitsBeforeDP()+1;
            thisInt.content = new char[thisInt.size];
            anotherInt.content = new char[anotherInt.size];
            for(int i = 0; i< this->countDigitsBeforeDP() -another.countDigitsBeforeDP() ;i++){
                thisInt.content[i] = this->content[i];
                anotherInt.content[i] = '0';
            }
            for(int i= this->countDigitsBeforeDP() -another.countDigitsBeforeDP() ; i< this->countDigitsBeforeDP();i++){
                thisInt.content[i] = this->content[i];
                anotherInt.content[i] = another.content[i-(this->countDigitsBeforeDP() -another.countDigitsBeforeDP())];
            }
            
        //     thisInt.print();
        //    anotherInt.print();
        //     cout << endl;
        }else if(this->countDigitsBeforeDP() <= another.countDigitsBeforeDP()){
            thisInt.size =another.countDigitsBeforeDP()+1;
            anotherInt.size = another.countDigitsBeforeDP()+1;
            thisInt.content = new char[thisInt.size];
            anotherInt.content = new char[anotherInt.size];

            for(int i = 0; i<  another.countDigitsBeforeDP()-this->countDigitsBeforeDP() ;i++){
                anotherInt.content[i] = another.content[i];
                thisInt.content[i] = '0';
            }
            for(int i= another.countDigitsBeforeDP() -this->countDigitsBeforeDP() ; i< another.countDigitsBeforeDP();i++){
                anotherInt.content[i] = another.content[i];
                thisInt.content[i] = this->content[i-(another.countDigitsBeforeDP() -this->countDigitsBeforeDP())];
            }
        //     thisInt.print();
        //    anotherInt.print();
        //     cout << endl;
        }
        thisInt.content[thisInt.size-1] = '.';
        anotherInt.content[anotherInt.size-1] = '.';

        if(this->countDigitsAfterDP() > another.countDigitsAfterDP()){
            thisDecimal.size = this->countDigitsAfterDP();
            anotherDecimal.size = this->countDigitsAfterDP();
            thisDecimal.content = new char [thisDecimal.size];
            anotherDecimal.content = new char[anotherDecimal.size];
            
            for(int i=0; i< another.countDigitsAfterDP() ;i++){
                 thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
                 anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
            }
            for(int i =another.countDigitsAfterDP(); i<thisDecimal.size;i++){
                thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
                 anotherDecimal.content[i] = '0'; 
            }
            
        //     thisDecimal.print();
        //    anotherDecimal.print();
        //     cout << endl;
        }else if(this->countDigitsAfterDP() <= another.countDigitsAfterDP()){
            thisDecimal.size = another.countDigitsAfterDP();
            anotherDecimal.size = another.countDigitsAfterDP();
            thisDecimal.content = new char [thisDecimal.size];
            anotherDecimal.content = new char[anotherDecimal.size];
            
            for(int i=0; i< this->countDigitsAfterDP() ;i++){
                 
                 anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
                 thisDecimal.content[i] = this->content[this->size-this->countDigitsAfterDP()+i];
            }
            for(int i =this->countDigitsAfterDP(); i<thisDecimal.size;i++){
                anotherDecimal.content[i] = another.content[another.size-another.countDigitsAfterDP()+i];
                 thisDecimal.content[i] = '0'; 
            }

        //     thisDecimal.print();
        //    anotherDecimal.print();
           
        //     cout << endl;

        }



        combineThis.size=thisInt.size+thisDecimal.size;
        combineAnother.size = thisInt.size+thisDecimal.size;
        combineThis.content = new char[combineThis.size];
        combineAnother.content = new char[combineAnother.size];
        for(int i = 0; i<thisInt.size;i++){
            combineThis.content[i] = thisInt. content[i];
            combineAnother.content[i] = anotherInt.content[i];
        }
        for(int i= 0 ; i<thisDecimal.size;i++){
            combineThis.content[i+thisInt.size] = thisDecimal.content[i];
            combineAnother.content[i+thisInt.size] = anotherDecimal.content[i];
        }
        // combineThis.print();
        // combineAnother.print();
        //cout << endl;
        delete[] thisInt.content;
        thisInt.content =nullptr;
        delete[] thisDecimal.content;
        thisDecimal.content =nullptr;
        delete[] anotherInt.content;
        anotherInt.content =nullptr;
        delete[] anotherDecimal.content;
        anotherDecimal.content = nullptr;

        char temSub[combineThis.size];
       

        for(int i= combineThis.size-1; i >=0 ;i--){
            if(combineThis.content[i] != '.'){
                if (combineThis.content[i]-48 >= combineAnother.content[i]-48+ carry ){
                     temSub[i] = ((combineThis.content[i]-48) - (combineAnother.content[i]+carry-48))+48;
                     carry = 0;
                }
                if(combineThis.content[i]-48 < combineAnother.content[i]-48+carry){
                    //cout << "\n"  << combineThis.content[i] << "  " <<  combineAnother.content[i] << "  " ;
                    
                    temSub[i] = (10-(combineAnother.content[i]-48+carry)+(combineThis.content[i]-48))+48;
                   // cout << temSub[i] << endl;
                    carry =1;
                    // if( combineThis.content[i-1] == '0'){
                    //     combineThis.content[i-1] = '9';
                    // }else combineThis.content[i-1] = (combineThis.content[i-1]-48-1)+48;
                    

                }
                    
                }
            else temSub[i] = '.';
            
        }

        int numAfterPoint = 0;
        // 
        for(int i=combineThis.size-1 ; i>=combineThis.countDigitsBeforeDP() ;i--){
            if(temSub[i] == '0' || temSub[i] == '.'){
                numAfterPoint++;
            }else{
                break;
            }
        }
        // cout << endl;
        // for(int i; i< combineThis.size-numAfterPoint ;i++){
        //     cout << temSub[i];
        // }
        // cout << endl;
        if(temSub[0] == '0'){
                    returnDecimal.size = combineThis.size-numAfterPoint-1;
                    returnDecimal.content = new char [returnDecimal.size];
                   
                    for(int i=0 ; i<returnDecimal.size ;i++){
                        returnDecimal.content[i] = temSub[i+1] ;
                    }
                }else{
                    returnDecimal.size = combineThis.size-numAfterPoint;
                    returnDecimal.content = new char [returnDecimal.size];
                    for(int i=0 ; i<returnDecimal.size ;i++){
                        returnDecimal.content[i] = temSub[i];
                    }
                }
         
    
    }
    delete[] combineThis.content;
    combineThis.content =nullptr;
    delete[] combineAnother.content;
    combineAnother.content = nullptr;
    return returnDecimal;
}