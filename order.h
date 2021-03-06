#ifndef __ORDER_H
#define __ORDER_H

#include "product_order.h"
#include "product_order_list.h"
#include <vector>
#include <fstream>

class Order{
  public:
    Order(std::string email);
    Order(std::istream& ist);
    std::string email() const;
    double cost();
    void add_product_order(Product_order po);
    int num_product_orders();
    Product_order product_order(int index);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  private:
    std::string _email;
    Product_order_list _product_orders;
};
#endif
