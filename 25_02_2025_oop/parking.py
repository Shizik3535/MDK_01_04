from cars import Car
import json
import os


class CarPark:
    def __init__(self, filename="cars.json"):
        self.filename = filename
        self.cars: list[Car] = self.load_from_file()

    def __eq__(self, other):
        if len(self.cars) != len(other.cars):
            return False
        return True

    def __gt__(self, other):
        return len(self.cars) > len(other.cars)

    def add_car(
            self,
            plate: str,
            brand: str,
            engine_volume: float,
            max_speed: float,
            seats: int,
    ):
        car_id = len(self.cars) + 1
        new_car = Car(
            id=car_id,
            plate=plate,
            brand=brand,
            engine_volume=engine_volume,
            max_speed=max_speed,
            seats=seats,
        )
        self.cars.append(new_car)
        self.save_to_file()

    def sort_cars(self, flag=False):
        if flag:
            self.cars.sort(key=lambda x: x.max_speed, reverse=True)
        else:
            self.cars.sort(key=lambda x: x.car_id)

    def print_cars(self):
        for car in self.cars:
            print(car)

    def save_to_file(self):
        with open(self.filename, "w") as file:
            file.write(json.dumps([car.__dict__ for car in self.cars]))

    def load_from_file(self) -> list[Car]:
        try:
            with open(self.filename, "r") as file:
                data = json.load(file)
                return [Car(**car) for car in data]
        except (FileNotFoundError, json.JSONDecodeError):
            return []