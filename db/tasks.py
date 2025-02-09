from datetime import date
from db.users import User


class TaskPriority:
    id: int
    name: str

    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class TaskStatus:
    id: int
    name: str

    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class Task:
    id: int
    title: str
    description: str
    creation_date: date
    due_date: date
    priority: TaskPriority
    status: TaskStatus

    assigned_users: list[User] = []

    def __init__(self, id: int, title: str, description: str, creation_date: date, due_date: date, priority: int,
                 status: int):
        self.id = id
        self.title = title
        self.description = description
        self.creation_date = creation_date
        self.due_date = due_date
        self.priority = priority
        self.status = status

    def assign_user(self, user: User):
        self.assigned_users.append(user)
