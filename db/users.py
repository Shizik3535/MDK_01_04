class Role:
    id: int
    name: str

    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class Position:
    id: int
    name: str

    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class User:
    id: int
    username: str
    hashed_password: str
    first_name: str
    last_name: str
    patronymic: str
    role: Role
    position: Position | None

    def __init__(self, id: int, username: str, hashed_password: str, first_name: str, last_name: str,
                 patronymic: str | None, role: Role, position: Position | None):
        self.id = id
        self.username = username
        self.hashed_password = hashed_password
        self.first_name = first_name
        self.last_name = last_name
        self.patronymic = patronymic
        self.role = role
        self.position = position
