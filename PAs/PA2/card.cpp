#include "card.h"

#include "util-common.h"

//// TODO: Complete the member function defintion of the cardd classes

//Card====================================================================================================================
Card::Card(const std::string& name):name_(name){}
Card::~Card(){}
/*bool Card::BuildIndustry(Industry* to_build, Industry* to_be_overbuilt) const{}*/
bool Card::IsWildCard() const{
    if(name_ == "Wild Industry" || name_ =="Wild Location"){
        return true;
    }
    return false;
}
std::string Card::name() const{
    return name_;
}


//LocationCard===========================================================================================================
LocationCard::LocationCard(Location* location):Card(location->name()),location_(location){}

// bool LocationCard::IsWildCard() const {
//     return false;
// }

/*bool LocationCard::CanBuildIndustry(const PlayerNetwork* network,
                        Industry* to_build,
                        Industry* to_be_overbuilt) const {}*/

bool LocationCard::CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const{
    static_cast<void>(network);
    if(to_be_overbuilt->location()==location_){
        return true;
    }
    return false;
}

CardType LocationCard::card_type() const{
    return CardType::kLocationCard;
}

//WildLocationCard==============================================================================================
WildLocationCard::WildLocationCard():Card("Wild Location"){}

// bool WildLocationCard::IsWildCard() const {
//     return true;
// }

/*bool WildLocationCard::CanBuildIndustry(const PlayerNetwork* network,
                        Industry* to_build,
                        Industry* to_be_overbuilt) const {}*/

bool WildLocationCard::CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const{
    static_cast<void>(network);
    return true;
}

CardType WildLocationCard::card_type() const{
    return CardType::kWildLocationCard;
}

//IndustryCard====================================================================================================
IndustryCard::IndustryCard(IndustryType industry_type):Card(ToString(industry_type)),industry_type_(industry_type){}

// bool IndustryCard::IsWildCard() const {
//     return false;
// }

/*bool IndustryCard::CanBuildIndustry(const PlayerNetwork* network,
                        Industry* to_build,
                        Industry* to_be_overbuilt) const {}*/

bool IndustryCard::CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const{
    if(network->HasEstablished()==false){
        if(to_be_overbuilt->industry_type()==industry_type_){
            return true;
        }
    }
    else{
        if((to_be_overbuilt->industry_type()==industry_type_) && (network->IsCovering(to_be_overbuilt->location()))){
            return true;
        }
    }
    return false;
}

CardType IndustryCard::card_type() const{
    return CardType::kIndustryCard;
}

//WildIndustryCard==============================================================================================
WildIndustryCard::WildIndustryCard():Card("Wild Industry"){}

// bool WildIndustryCard::IsWildCard() const {
//     return true;
// }

/*bool WildIndustryCard::CanBuildIndustry(const PlayerNetwork* network,
                        Industry* to_build,
                        Industry* to_be_overbuilt) const {}*/

bool WildIndustryCard::CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const{
    if(network->IsCovering(to_be_overbuilt->location())){
        return true;
    } 
    return false;
}

CardType WildIndustryCard::card_type() const{
    return CardType::kWildIndustryCard;
}


//// TODO ends
