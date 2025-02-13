import datetime


class Staff:
    id: int
    first_name: str

    def __init__(self, id: int, first_name: str):
        self.id = id
        self.first_name = first_name


class Check:
    staff_id: int
    date: datetime.date
    summ: float

    def __init__(self, staff_id: int, date: datetime.date, summ: float):
        self.staff_id = staff_id
        self.date = date
        self.summ = summ


def read_staff(filename: str) -> list[Staff]:
    with open(filename, "r", encoding="utf-8") as file:
        lines = file.readlines()
        staffs = []
        for line in lines:
            staff_id, first_name = line.split()
            staffs.append(Staff(int(staff_id), first_name))
    return staffs


def read_check(filename: str) -> list[Check]:
    with open(filename, "r", encoding="utf-8") as file:
        lines = file.readlines()
        checks = []
        for line in lines:
            staff_id, date, summ = line.strip().split()
            checks.append(Check(int(staff_id), datetime.date.fromisoformat(date), float(summ)))
    return checks


def create_order(staff_filename, check_filename):
    staff = read_staff(staff_filename)
    checks = read_check(check_filename)

    sorted_staff = sorted(staff, key=lambda x: x.first_name)
    order = []
    for number, staff in enumerate(sorted_staff):
        summa = 0
        for check in checks:
            if check.staff_id == staff.id:
                summa += check.summ
        order.append((number, staff.first_name, summa))

    with open("order.txt", "w", encoding="utf-8") as file:
        file.write("№  ФИО     Сумма\n")
        for i, staff, summa in order:
            file.write(f"{i + 1}. {staff}: {summa}\n")


create_order("staff.txt", "orders.txt")
