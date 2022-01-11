#include "industry.h"

#include "player.h"

//// TODO: Complete primary and secondary industries

//primary==============================================================================================================================
PrimaryIndustry::PrimaryIndustry(IndustryType industry_type, IndustryProperties properties,
                  ResourceType resource_type):IndustryImpl(industry_type,properties,resource_type){}

  // This can overbuild the `other` industry if this is more technologically advanced,
  // and they are of the same industry type. Usually the owner of this industry must
  // also own the industry that he overbuilds on. However, if the game board has
  // exhausted all the resources, or the `other` industry is not yet built
  // (i.e. representing an empty slot), any player can overbuild the given industry
  // but is subject to the same constraints.
  // Hint: As we alway overbuild through an industry proxy, an an industry proxy always
  //       has a resource observer attached, we can assume `other` is assoicated
  //       to a valid resource observer.
bool PrimaryIndustry::CanOverbuild(Industry* other) const{
    if(other == nullptr) return true;
    if(other->IsBuilt()==false){
        return true;
    }
    if(this->properties().tech_level > other->properties().tech_level  &&  
        this->industry_type()==other->industry_type()){
        if(this->player()==other->player()){
            return true;
        }
        else{
            if(this->resource_observer_->HasResource(resource_type())==false){
                return true;
            }
        }
    }
    return false;
}

  // Returns true if all of its resource units are consumed.
bool PrimaryIndustry::IsEligibleForVp() const{
    if(IsDemolished()==false){
        if(available_units()==0){
            return true;
        }
    }
    return false;
}

  // Produces the number of output units specified by its properties,
  // and notifies the resource and industry observers of the change.
void PrimaryIndustry::ProduceResources(){
    available_units_+=properties().output_units;
    resource_observer_->UpdateResourceCount(resource_type(),properties().output_units);
    industry_observer_->UpdateIndustry(this);
}

  // Removes all the resource units available and notifies the
  // resource and industry observers of the change.
void PrimaryIndustry::RemoveResources(){
    resource_observer_->UpdateResourceCount(resource_type(),-available_units_);
    available_units_=0;
    industry_observer_->UpdateIndustry(this);
}

  // Provides the given nubmer of resource units if possible.
  // Notifies the resource and industry observes of the change.
bool PrimaryIndustry::ProvideResources(int units){
    if(available_units()<units){
        return false;
    }
    available_units_-=units;
    resource_observer_->UpdateResourceCount(resource_type(),-units);
    industry_observer_->UpdateIndustry(this);
    return true;
}

  // Returns the inventory of the industry.
int PrimaryIndustry::available_units() const{
    return available_units_;
}

  // Sets the resource observer of the industry.
void PrimaryIndustry::set_resource_observer(ResourceObserver* rsrc_observer){
    resource_observer_=rsrc_observer;
}

//Secondary=======================================================================================================================

SecondaryIndustry::SecondaryIndustry(IndustryType industry_type, IndustryProperties properties):IndustryImpl(industry_type,properties){}

  // This is similar to the function you solved for PrimaryIndustry.
  // Just that we do not allow other players who do not own the `other`
  // industry to build on it, if it is already built.
bool SecondaryIndustry::CanOverbuild(Industry* other) const{
     if(other == nullptr) return true;
    if(other->IsBuilt()==false){
        return true;
    }
    if(this->properties().tech_level > other->properties().tech_level  &&  
        this->industry_type()==other->industry_type()){
        if(this->player()==other->player()){
            return true;
        }
    }
    return false;
}

  // Returns true if the industry is sold.
bool SecondaryIndustry::IsEligibleForVp() const{
    if(sold()){
        return true;
    }
    return false;
}

  // Sells the industry, and increase the player's EXP by a number
  // specified in the industry's properties.
bool SecondaryIndustry::Sell(){
    if(!sold()){
        sold_=true;
        player_->IncreaseExp(properties().exp_increase);
        return true;
    }
    return false;
}

  // Returns true if the industry is already sold.
bool SecondaryIndustry::sold() const{
     return sold_;
}

  // Ignores the resource observer as a secondary industry does not produce
  // consumerable resources for players.
void SecondaryIndustry::set_resource_observer(ResourceObserver* rsrc_observer){
    static_cast<void>(rsrc_observer);
    resource_observer_=nullptr;
}


//// TODO ends
