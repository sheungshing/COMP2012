#include "link.h"

//// TODO: complete the member function defintions of LinkImpl and LinkProxy

//LinkImpl======================================================================================================================
  LinkImpl::LinkImpl(LinkType link_type, LinkProperties properties):Link(link_type),properties_(properties){}

  bool LinkImpl::IsBuilt() const{
    if(adj_!=nullptr){
      return true;
    }
    return false;
  }

  bool LinkImpl::Build(Link* link){
    if(adj_!=nullptr){
      if(CanOverbuild(link)){
        /*link_type_=link->link_type();
        adj_=link->adjacency();*/
        link->BeOverbuilt(this);
        return true;
      }
    }
    return false;
  }
  
  bool LinkImpl::CanOverbuild(Link* link) const{
      if(link==nullptr){
        return true;
      }
      return false;
  }

  int LinkImpl::vp() const {
      if(adj_!=nullptr){
        return adj_->vp_for_link();
      }
      else{return 0;}
  }

  LinkProperties LinkImpl::properties() const {
      return properties_;
  }

  Player* LinkImpl::player() const {
      return player_;
  }

  std::string LinkImpl::player_name() const{
      if(player_!=nullptr){
        return player_->name();
      }
      return kEmptyPlayerName;
  }

  void LinkImpl::set_player(Player* player) {
      player_=player;
  }

  void LinkImpl::set_observer(LinkObserver* observer){
      static_cast<void>(observer);
      return;
  }


//LinkProxy=====================================================================================================
  LinkProxy::LinkProxy(LinkType link_type, Adjacency* adj):Link(link_type,adj){}
  
  bool LinkProxy::IsBuilt() const{
    if(impl_!=nullptr){
      return impl_->IsBuilt();
    }
    return false;
  }

  bool LinkProxy::Build(Link* link){
    if(impl_!=nullptr){
      if(CanOverbuild(link)){
        impl_->Build(link);
        return true;
      }
    }
    return false;
  }
  
  bool LinkProxy::CanOverbuild(Link* link) const{
      if(impl_!=nullptr){
        return impl_->CanOverbuild(link);
      }
      return false;
  }

  void LinkProxy::BeOverbuilt(Link* link){
      delete adj_;
      impl_=static_cast<LinkImpl*>(link);
      observer_->UpdateLink(this);
      observer_->Notify();
  }

  int LinkProxy::vp() const {
      return (impl_ == nullptr)? 0 : impl_->vp();
  }

  LinkProperties LinkProxy::properties() const {
      if(impl_!=nullptr){
        return impl_->properties();
      }
      return {};
  }

  Player* LinkProxy::player() const {
      return (impl_==nullptr)?nullptr:impl_->player();
  }

  std::string LinkProxy::player_name() const{
    if(impl_!=nullptr){
      return impl_->player_name();
    }
    return kEmptyPlayerName;
  }

  void LinkProxy::set_player(Player* player) {
    if(impl_!=nullptr){
      impl_->set_player(player);
    }
    else{
      static_cast<void>(player);
    }
  }
  
  void LinkProxy::set_observer(LinkObserver* observer){
      observer_=observer;
  }


//// TODO ends
