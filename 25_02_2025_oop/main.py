from parking import CarPark

if __name__ == "__main__":
    park1 = CarPark()
    # park1.add_car("A123BC", "Toyota", 2.0, 180, 5)
    # park1.add_car("B456DE", "BMW", 3.0, 220, 4)
    # park1.add_car("C789FG", "Mercedes", 4.0, 250, 4)

    # print("\nСписок автомобилей:")
    # park1.print_cars()

    print("\nОтсортировано по максимальной скорости:")
    park1.sort_cars(True)
    park1.print_cars()

    park2 = CarPark("cars2.json")
    # park2.add_car("D321HG", "Audi", 2.5, 200, 5)

    print("\nСравнение парков:")
    print(park1 == park2)
