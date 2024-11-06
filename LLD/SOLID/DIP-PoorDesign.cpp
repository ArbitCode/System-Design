#include <iostream>

class DatabaseService
{
  public:
    void saveOrder(int orderId)
    {
      std::cout << "Order '" << orderId << "' saved to database." << std::endl;
    }
};


class OrderService
{
  private:
    DatabaseService *dbServer;
  public:
    void placeOrder(int orderId)
    {
      std::cout << "Processing order: " << orderId << std::endl;
      dbServer->saveOrder(orderId); // dependecy inversion voilate
    }
};

int main()
{
  OrderService *order = new OrderService(); 
  order->placeOrder(123); // want to save in database, filesystem : dependecy inversion voilate
  delete order;
}
