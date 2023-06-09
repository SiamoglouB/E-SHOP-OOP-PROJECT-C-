#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

/**
 * \class Item
 * \brief Base class for all other items.
 *
 * Base abstract class to subclassed by the Pen, Pencil, Paper and Notebook
 * specialized classes. Implements the common functions of setting
 * the common characteristics of items, namely the Name, Stock, Descritpion.
 * Implements getters for common characteristics of items as well as virtual
 * functions that should be re-implemented in each item category.
 */
class Item
{
public:
    /**
     * \brief Constructor for Item, called by the derivative classes
     *
     * @param stock <int>.The stock the item should be created with
     * @param price <double> The price of the item
     * @param name <string> The name of the item, doesn't need to be unique
     * @param desc <string> The description of the item
     */
    Item(int stock, double price, string name, string desc);
    /**
     * \brief Virtual destructor to force the reimplementation in the derivatives
     */
    virtual ~Item();

    /**
     * \brief Get the ID of the item
     *
     * The ID of an item is a 4 digit hash generated by the defining
     * characteristics of each item. The hash is computed by each derivative class
     *
     * @return <size_t> The item's hash
     */
    size_t getId();

    /**
     * \brief Set the stock of an item
     *
     * @param stock <int> The stock to set
     */
    void setStock(int stock);
    /**
     * \brief Get the Item's stock
     *
     * @return <int>
     */
    int  getStock();

    /**
     * \brief Set the price of an item
     *
     * @param price <double> The price to set
     */
    void   setPrice(double price);
    /**
     * \brief Get the Item's price
     *
     * @return <double>
     */
    double getPrice();

    /**
     * \brief Set the stock of an item
     *
     * @param name <string> The name to set
     */
    void   setName(string name);
    /**
     * \brief Get the Item's name
     *
     * @return <string>
     */
    string getName();

    /**
     * \brief Set the stock of an item
     *
     * @param desc <string> The description to set
     */
    void   setDescription(string desc);
    /**
     * \brief Get the Item's description
     *
     * @return <string>
     */
    string getDescription();

    /**
     * \brief Get the Item's category (Pen, Pencil, Paper, Notebook)
     *
     * @return <string>
     */
    string getCategory();
    /**
     * \brief Get the Item's basic getBasicInfo
     *
     * Returns the common information between items as a commaspace-separated
     * string. The order of the returned inforation is
     * "id, name, price, stock, description"
     *
     * @return <string>
     */
    string getBasicInfo();

    /**
     * \brief Set the Item's ID based on the hash
     *
     * Provides the common functionality to the derivatives of truncating the
     * hash to a 4 least significant digits. Hopefully they are unique enough to
     * be used as IDs
     */
    void setId(size_t);
    /**
     * \brief Set the Item's category
     *
     * Set the item's category by removing the first character of the string
     * returned by typeid (In the case of gcc 10 on my machine it is the name
     * of the class prefix by the length of the string (according to the
     * reference it is implementation specific))
     */
    void setCategory(string);

    /**
     * \brief Set the Item's ID.
     *
     * Pure abstract function that every derivative should implement.
     * All implementations of this function work in the same way. They create 2
     * or 3 hashes based on the unique identifiers of each item
     * which are then XOR'd together. The first identifier is the name of each
     * class as returned by typeid. The second and third (if applicable) are
     * specific to each specialization and documented there.
     */
    virtual void setId() = 0;
    /**
     * \brief Get the Item's specialization specific details
     *
     * Pure abstract function that every derivative should implement.
     * Returns a string of specialization specific details of each Item.
     */
    virtual string getDetails() = 0;

    /**
     * \brief Override the cast to std::string operator
     *
     * Override the cast to string operator to use it to return details about
     * each item. Works by calling the getBasicInfo() and getDetails() functions
     */
    operator std::string ();
    /**
     * \brief Override for the outstream operator
     *
     * Used to throw information to the cout garbage can
     */
    friend ostream& operator<<(ostream&, Item&);

    /**
     * \brief Override for the comparison operator
     *
     * Compares two Item objects by comparing their IDs
     */
    bool operator==(const Item&);

private:
    size_t _id = 0;
    int    _stock;
    double _price;
    string _name;
    string _desc;
    string _category;
};

#endif // ITEM_H
