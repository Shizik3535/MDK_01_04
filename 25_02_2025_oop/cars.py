class Car:
    def __init__(self, id: int, plate: str, brand: str, engine_volume: float, max_speed: int, seats: int):
        self.id = id
        self.plate = plate
        self.brand = brand
        self.engine_volume = engine_volume
        self.max_speed = max_speed
        self.seats = seats

    def __repr__(self):
        return f"Car(id={self.id}, plate='{self.plate}', brand='{self.brand}', engine_volume={self.engine_volume}, max_speed={self.max_speed}, seats={self.seats})"
