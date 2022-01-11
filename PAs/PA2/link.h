#ifndef BRASS_LINK_H_
#define BRASS_LINK_H_

#include "game-common.h"
#include "location.h"
#include "infrastructure.h"

#include "player.h"
#include "util-common.h"

#include <set>
#include <map>
#include <string>

const int kNumEnds = 2;

class Location;
class Infrastructure;

// This class justs models a pair of locations. To a link, this gives the meaning
// of which pairs of locations may be connected to each other through a link.
class Adjacency {
 public:
  Adjacency(Location* location_1, Location* location_2);
  ~Adjacency() = default;

  bool operator<(const Adjacency& other); 
  bool operator==(const Adjacency& other);

  // Returns true if the location is one of the ends of this adjacency.
  bool IsAdjacentTo(const Location* location) const;

  // Returns a name for the adjacency, e.g. "A<->B".
  std::string name() const;

  // Returns the other end of the adjacency, if the given `location` is one legit end.
  Location* another_end(const Location* location) const;

  // Returns the two ends of the adjacency.
  Location* const * ends() const;

  // Returns the VP for the link which connects the locations defined by this adjacency.
  // This is useful for Link::vp(). The value this function returns assume the pair of
  // locations are connected to each other. Remember, what defines the connection between
  // two locations is the resposibility of the Link class, but not this class.
  int vp_for_link() const;

 private:
  Location* locations_[kNumEnds];  // this stores the pointers of the pair of location
};

class Location;
class LinkObserver;

class Link : public Infrastructure {
 public:
  // For a link proxy, as it's a fixed slot on the map, `adj` cannot be a nullptr, but
  // is pointing to a valid Adjacency object. For a link tile, `adj` is a nullptr when
  // it's created because it's not attached to a slot on the map.
  Link(LinkType link_type, Adjacency* adj = nullptr);
  virtual ~Link() = default;

  // Returns true if the location belongs to one of the ends of `this->adj_`.
  bool IsAdjacentTo(const Location* location) const;

  // Returns true if the link is built, and `location` is one of the ends of the adjacency.
  bool IsConnectedTo(const Location* location) const;

  // Returns true if the link is built.
  virtual bool IsBuilt() const = 0;

  // Returns true if over-building the provided `link` is successful.
  virtual bool Build(Link* link) = 0;

  // Returns true if it is possible to overbuild `link`.
  // It's not possible to build on an already built link, just returns false.
  // However, if `link` represents an open slot, we can build on it, just returns true.
  virtual bool CanOverbuild(Link* link) const = 0;

  // Reacts to being overbuilt by another `link`.
  // For a proxy, its `impl_` should point to the `link` parameter's impl after it's
  // being overbuilt.
  virtual void BeOverbuilt(Link* link);

  // This is not going to be used by you.
  bool operator<(const Link& other) const;

  // Returns another end of the adjacency, if the given location is an end of the adjacency
  // that this link is associated to.
  // Otherwise, returns a nullptr.
  Location* another_end(const Location* location) const;

  // Returns the VP, which is the sum of "VP for adjacent links" from adjacent industries.
  virtual int vp() const = 0;

  // Sets the adjacency of this link.
  void set_adjacency(Adjacency* adj);

  // Returns the link type.
  LinkType link_type() const;

  // Returns the adjacency.
  Adjacency* adjacency() const;

  // Returns the properties (a data class) of the link.
  virtual LinkProperties properties() const = 0;

  // Returns the player associated to this link.
  virtual Player* player() const = 0;
  virtual std::string player_name() const = 0;

  // Associates a player to this link.
  virtual void set_player(Player* player) = 0;

  // Sets the observer for this link.
  virtual void set_observer(LinkObserver* observer) = 0;

 protected:
  LinkType link_type_;
  Adjacency* adj_;
};

class LinkImpl : public Link {
 public:
  LinkImpl(LinkType link_type, LinkProperties properties);
  ~LinkImpl() = default;

  virtual bool IsBuilt() const override;
  virtual bool Build(Link* link) override;
  virtual bool CanOverbuild(Link* link) const override;

  virtual int vp() const override;

  virtual LinkProperties properties() const override;

  virtual Player* player() const override;
  virtual std::string player_name() const override;

  virtual void set_player(Player* player) override;

  // As a LinkImpl has only the attribute of `player_` and it has
  // no other attributes that can be changed after it is built,
  // we do not let the LinkImpl class remember about any observer,
  // because there's is just simply nothing that we can inform
  // the observer about.
  virtual void set_observer(LinkObserver* observer) override;

 protected:
  Player* player_ = nullptr;
  const LinkProperties properties_;
};

class LinkProxy : public Link {
 public:
  LinkProxy(LinkType link_type, Adjacency* adj);
  ~LinkProxy() = default;

  virtual bool IsBuilt() const override final;
  virtual bool Build(Link* link) override;
  virtual bool CanOverbuild(Link* link) const override final;
  virtual void BeOverbuilt(Link* link) override final;

  virtual int vp() const override final;

  virtual LinkProperties properties() const override;

  virtual Player* player() const override;
  virtual std::string player_name() const override;  // returns kEmptyPlayerName if not available

  // As a slot on the map is not associated to a player. This function
  // literally does nothing.
  virtual void set_player(Player* player) override;
  virtual void set_observer(LinkObserver* observer) override;

 private:
  LinkObserver* observer_ = nullptr;
  LinkImpl* impl_ = nullptr;
};


class LinkSubscriber {
  friend LinkObserver;
 
 public:
  virtual ~LinkSubscriber();

 protected:
  virtual void UpdateLinkInfo(std::vector<LinkInfo> link_info) = 0;
};

class LinkObserver : public Observer {
 public:
  LinkObserver();
  ~LinkObserver();

  // This function accepts an `link` pointer which has its underlying object
  // recently changed. This updates the information that this object previously knows
  // about the `link`. If the `link` has not been seen by this observer before,
  // just insert an entry about it to cache the `link`'s information.
  void UpdateLink(Link* link);

  // Removes the link entry stored inside this object. This means let
  // the link observer forgets about the `link`, and not provide the information
  // of the `link` to its subscribers anymore.
  void RegisterSubscriber(LinkSubscriber* subscriber);

  // Removes the entry of the subscriber so that when there is any change to this observer's
  // state, we no longer informs this specific `subscriber`.
  void Unsubscribe(LinkSubscriber* subscriber);

  // Inform the subscribers of the changes to the links that are known by this observer.
  virtual void Notify() override;

 private:
  using LinkInfoMap = std::map<Link*, LinkInfo, ptr_less<Link> >;
  LinkInfoMap link_info_;  // the cache which stores the information about the previously seen Links
  std::set<LinkSubscriber*> subscribers_;
  std::map<const Location*, bool> connected_to_merchant_;
};

inline Adjacency* Link::adjacency() const {
  return adj_;
}


inline bool Adjacency::operator<(const Adjacency& other) {
  if (*locations_[0] < *other.locations_[0]) {
    return true;
  }
  if (*other.locations_[0] < *locations_[0]) {
    return false;
  }
  return *locations_[1] < *other.locations_[1];
}

inline bool Adjacency::IsAdjacentTo(const Location* location) const {
  return (locations_[0] == location) || (locations_[1] == location);
}

inline bool Link::operator<(const Link& other) const {
  if (link_type_ < other.link_type_) {
    return true;
  }
  if (link_type_ > other.link_type_) {
    return false;
  }
  return *adj_ < *other.adj_;
}

#endif  // BRASS_LINK_H_
