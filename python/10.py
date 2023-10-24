class fsm:
    state = 'A'

    def fill(self):
        if self.state == 'A':
            self.state = 'B'
            return 0
        if self.state == 'B':
            self.state = 'C'
            return 1
        if self.state == 'D':
            self.state = 'H'
            return 4
        if self.state == 'F':
            self.state = 'G'
            return 9
        if self.state == 'E':
            self.state = 'A'
            return 7
        if self.state == 'G':
            self.state = 'H'
            return 10
        raise MealyError('fill')

    def color(self):
        if self.state == 'C':
            self.state = 'D'
            return 2
        if self.state == 'D':
            self.state = 'D'
            return 5
        if self.state == 'E':
            self.state = 'H'
            return 8
        if self.state == 'H':
            self.state = 'F'
            return 11
        raise MealyError('color')

    def pose(self):
        if self.state == 'E':
            self.state = 'F'
            return 6
        if self.state == 'D':
            self.state = 'E'
            return 3
        raise MealyError('pose')


class MealyError(Exception):
    pass


def raises(func, exception):
    try:
        func()
    except Exception as e:
        assert type(e) == exception


def test():
    obj = main()
    assert obj.state == 'A'
    assert obj.fill() == 0
    assert obj.fill() == 1
    assert obj.color() == 2
    assert obj.color() == 5
    assert obj.fill() == 4
    assert obj.color() == 11
    assert obj.fill() == 9
    assert obj.fill() == 10
    obj.state = 'D'
    assert obj.pose() == 3
    assert obj.pose() == 6
    obj.state = 'E'
    assert obj.color() == 8
    obj.state = 'E'
    assert obj.fill() == 7

    obj.state = 'A'
    raises(obj.color, MealyError)
    raises(obj.pose, MealyError)

    obj.state = 'B'
    raises(obj.color, MealyError)
    raises(obj.pose, MealyError)

    obj.state = 'C'
    raises(obj.fill, MealyError)
    raises(obj.pose, MealyError)

    obj.state = 'H'
    raises(obj.fill, MealyError)
    raises(obj.pose, MealyError)

    obj.state = 'G'
    raises(obj.color, MealyError)
    raises(obj.pose, MealyError)

    obj.state = 'F'
    raises(obj.color, MealyError)
    raises(obj.pose, MealyError)


def main():
    return fsm()
