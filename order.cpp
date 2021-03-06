#include "order.h"

Order::Order(std::string email) { 
    this->_email = email;
}
Order::Order(std::istream& ist) {
    ist >> _email; ist.ignore();
    int numoforder;
    ist >> numoforder;
    for (int i = 0; i < numoforder; i++)
        _product_orders.add_a(Product_order(ist)); 
}
std::string Order::email() const {return _email;}
double Order::cost() {
    double sum;
    for (auto& po : _product_orders.list()) sum += po.cost();
    return sum;
}
void Order::add_product_order(Product_order po) {
    _product_orders.add_a(po);
}

int Order::num_product_orders() {return _product_orders.size();}

Product_order Order::product_order(int index) {
    //if (0 > index || index > (_product_orders.size()-1)) 
    //    throw std::out_of_range{"Order: Product index " + std::to_string(index) 
    //        + " with only " + std::to_string(_product_orders.size()-1) + " products"};
    return _product_orders.at(index);
}
std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "\tEmail: " << order.email() << std::endl;
    ost << "\tPurchased Items:\n" << std::endl;
    if (order._product_orders.size() == 0){
        ost << "\t\t(empty)" << std::endl;
        return ost;
    }
    for (auto& po : order._product_orders.list()) 
        ost << "\t\t" << po.name() << '\n';
    return ost;
}

void Order::save(std::ostream& ost){
    ost << _email <<'\n';
    ost << _product_orders.size() << '\n';
    for (int i = 0; i < _product_orders.size(); i++){
        _product_orders.at(i).save(ost);
    }  
}
