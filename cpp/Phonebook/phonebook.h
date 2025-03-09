#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <map>
#include <iostream>
#include <algorithm>  // implements sort
#include <vector>  // to add at the end of a vector
//#include <cctype>

class PhoneBookEntry {
    public:
        PhoneBookEntry() {}
        PhoneBookEntry(const std::string &name, const std::string &num, const std::string &email):
            _name(name), _phoneNumber(num), _email(email) {}

        // addictional phone number with its type (work, home...)
        void addPhoneNumber(const std::string &type, std::string &number) {
            addictionalNumbers[type] = number;
        }

        // print data
        void print() const {
            std::cout << "Name:" << _name << std::endl;
            std::cout << "Main number:" << _phoneNumber << std::endl;
            std::cout << "Email:" << _email << std::endl;
            
            // extend to multiple phone numbers
            for(const auto &[type, number] : addictionalNumbers) {
                std::cout << type << ": " << number << std::endl;
            }
            std::cout << "==========================\n";
        }

        // sort by name
        bool operator<(const PhoneBookEntry &other) const {
            return _name < other._name;
        }

        // find by name
        bool findByName(const std::string &name, PhoneBookEntry &foundEntry) const{
            if (_name == name) {
                foundEntry = *this;
                return true;
            }
            return false;
        }

        // add international prefix +39
        void addInternationalPrefix() {
            auto addPrefixIfNeeded = [](std::string &number) {
                if(number[0] != '+') {
                    number = "+39" + number;
                }
            };

            addPrefixIfNeeded(_phoneNumber);  // lambda function

            for (auto &entry : addictionalNumbers) {
                addPrefixIfNeeded(entry.second);
            }
        }

        // no data hiding
        std::string _name;
        std::string _phoneNumber;
        std::string _email;
        std::map<std::string, std::string> addictionalNumbers;
};

class PhoneBook {
    public:
        PhoneBook() {}

        void addEntry(const PhoneBookEntry &entry) {
            entries.push_back(entry);  // adds new element at the end of the vector
        }
        
        void printAll() {
            for(const auto &entry : entries) {
                entry.print();
            }
        }

        void sortEntries() {
            std::sort(entries.begin(), entries.end());
        }

        bool findByName(const std::string &name, PhoneBookEntry foundEntry) const {
            for (const auto &entry : entries) {
                if (entry.findByName(name, foundEntry)) {
                    return true;
                }
            }
            return false;
        }

        void addPrefix() {
            for (auto &entry : entries) {
                entry.addInternationalPrefix();
            }
        }

    private:
        std::vector<PhoneBookEntry> entries;
};



#endif