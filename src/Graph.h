#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <exception>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Asset;
struct Contact;

struct Asset {
    std::string message_id;
    int index;
    std::set<int> connected_contacts;

    Asset(const std::string& message_id, const int index)
        : message_id(message_id), index(index)
    {}
};

struct Contact {
    std::string email_address;
    int index;
    std::set<int> connected_assets;

    Contact(const std::string& email_address, const int index)
        : email_address(email_address), index(index)
    {}
};

class Graph {
    int next_asset,next_contact;

    std::vector<Asset> assets;
    std::vector<Contact> contacts;
    std::map<std::string, int> contact_list;
    std::map<std::string, int> asset_list;

  public:
    Graph()
        : next_asset(0), next_contact(0)
    {}

    ~Graph()
    {}

    int FindOrInsertContact(const std::string& email_address)
    {
        std::map<std::string,int>::const_iterator iter=contact_list.find(email_address);
        if(iter == contact_list.end()) {
            contact_list.insert(std::pair<const std::string,int>(email_address, next_contact));
            contacts.push_back(Contact(email_address, next_contact));
            return next_contact++;
        } else return iter->second;
    }

    int FindOrInsertAsset(const std::string& email_id)
    {
        std::map<std::string,int>::const_iterator iter=asset_list.find(email_id);
        if(iter == asset_list.end()) {
            asset_list.insert(std::pair<const std::string,int>(email_id, next_asset));
            assets.push_back(Asset(email_id, next_asset));
            return next_asset++;
        } else return iter->second;
    }

    void AttachAsset(const int asset_id, const int contact_id)
    {
        if(asset_id < 0 || contact_id < 0 || asset_id >= (int)assets.size() || contact_id >= (int)contacts.size())
            throw std::exception();
        else {
            assets[asset_id].connected_contacts.insert(contact_id);
            contacts[contact_id].connected_assets.insert(asset_id);
        }
    }

    const Asset& FetchAsset(const int index)
    {
        if(index < 0 || index >= (int)assets.size()) throw std::exception();
        else return assets[index];
    }

    const Contact& FetchContact(const int index)
    {
        if(index < 0 || index >= (int)contacts.size()) throw std::exception();
        else return contacts[index];
    }

};

#endif
