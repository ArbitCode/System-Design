#include <iostream>

class OrderRepo
{
  public:
    virtual void saveOrder(int orderId) = 0;
    virtual ~OrderRepo() = default;
};

class DatabaseService : public OrderRepo
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
    OrderRepo *orderRepo;
  public:
    OrderService(OrderRepo* repo) : orderRepo(repo){}
    void placeOrder(int orderId)
    {
      std::cout << "Processing order: " << orderId << std::endl;
      orderRepo->saveOrder(orderId);
    }
};

int main()
{
  OrderRepo *orderRepo = new DatabaseService();
  OrderService *order = new OrderService(orderRepo);
  order->placeOrder(123);
  delete order;
  delete orderRepo;
}
