# SPBU-Homework-2
Here you can find conditions and solutions to problems for the second semester

## Navigation menu
* [Semester №1](https://github.com/GirZ0n/SPBU-Homework-1) 
* Semester №2 :arrow_left: **You are here**
* [Semester №3](https://github.com/GirZ0n/SPBU-Homework-3)
* Semester №4

## Homework

### Homework №1
1. Дан массив целых чисел `x[1]...x[m+n]`, рассматриваемый как соединение двух его отрезков: начала `x[1]...x[m]` длины `m` и конца `x[m+1]...x[m+n]` длины `n`. Не используя дополнительных массивов, переставить начало и конец. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework1/task1/main.kt)

2. Реализовать подсчет факториала (рекурсивно и итеративно). [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework1/task2/main.kt)

3. Заданы две строки: `s1` и `s2`. Найти количество вхождений `s2` в `s1` как подстроки. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework1/task3/main.kt)

4. Реализовать программу, проверяющую, является ли строка палинромом. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework1/task4/main.kt)

5. Написать программу, которая считает количество непустых строк в исходном файле. Строка считается пустой, если состоит только из пробелов и табуляций (символ `\t`), или в ней нет символов вообще. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework1/task5/main.kt)

### Homework №2
1. Определите минимальное количество символов, которые нужно удалить из строки так, чтобы она не содержала `«xxx»` в качестве подстроки. Выведите `0`, если строка изначально не содержит запрещенной подстроки `«xxx»`. Удалять символы можно в произвольных позициях (не обязательно подряд). [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework2/task1/main.kt)

2. Удалите из массива все повторяющиеся элементы. Необходимо оставить только правое вхождение, относительный порядок оставшихся элементов не должен быть изменён. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework2/task2/main.kt)

### Homework №3
1. Реализуйте класс AVL дерева, который реализует интерфейс Map. В каждой вершине хранится ключ – по нему строится дерево и значение – некий хранимый тип. Ключ и значение должны задаваться через generic. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework3/task1)

### Homework №4 
1. Реализовать класс для работы с хеш-таблицей (на списках). Общение с пользователем должно происходит в интерактивном режиме: добавить значение в хеш-таблицу, удалить значение из хеш-таблицы, поиск значения в хеш-таблице, показать статистику по хеш-таблице (общее число ячеек, load factor, число конфликтов, максимальная длина списка в конфликтных ячейках и т.п.), заполнить хеш-таблицу содержимым файла, выбрать хеш-функцию для подсчета хеша (из заранее заданных в коде). Смена хэш-функции должна происходить во время работы программы, в класс используемая хеш-функция должна передаваться из клиентского кода. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework4/task1)

2. Разработать и реализовать иерархию классов, описывающих дерево разбора арифметического выражения. Используя их, реализовать класс, вычисляющий значение выражения по дереву. Классы, представляющие операнды и операторы, должны сами уметь себя вычислять и печатать. Дерево разбора хранится в файле в виде (`<операция> <операнд1> <операнд2>`), где `<операнд1>` и `<операнд2>` сами могут быть деревьями, либо числами. Например, выражение `(1 + 1) * 2` представляется в виде `(* (+ 1 1) 2)`. Должны поддерживаться операции `{+, -, , /}` и целые числа в качестве аргументов. Требуется построить дерево в явном виде, распечатать его (не обязательно так же, как во входном файле) и посчитать значение выражения обходом дерева. Можно считать, что входной файл корректен. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework4/task2)

### Homework №5 
1. Реализовать бор (http://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D0%BE%D1%80) <br/> <br/>
Должны быть поддержаны следующие методы: <br/>
`boolean add(String element)` (возвращает true, если такой строки ещё не было, работает за O(|element|)) <br/>
`boolean contains(String element)` (работает за O(|element|)) <br/>
`boolean remove(String element)` (возвращает true, если элемент реально был в дереве, работает за O(|element|)) <br/>
`int size()` (работает за O(1)) <br/>
`int howManyStartWithPrefix(String prefix)` (работает за O(|prefix|)) <br/> <br/>
Также бор должен реализовывать интерфейс с методами: <br/>
`void serialize(OutputStream out) throws IOException` <br/>
`void deserialize(InputStream in) throws IOException` (заменяет старое дерево данными из стрима) <br/>
Стандартный сериализатор использовать нельзя. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework5/task1/Trie.kt)

### Homework №6 
1. Реализуйте асинхронную быструю сортировки с помощью сопрограмм. Проведите замеры времени, сравните с обычной реализацией. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework6/task1)

### Homework №7
1. Крестики-нолики для игры с самим собой (inclass задание) [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework7/task1)

2. Добавить в крестики-нолики меню и бота. В меню должна быть кнопка со стартом игры, а так же выбором сложности и играющей стороны. Бот с разными уровнями сложности и для игры за разные стороны. По окончанию игры, пишется победитель и по кнопке возврат в меню. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework7/task2)

### Homework №8 
1. Добавить поддержку мультиплеера в крестики-нолики [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/homeworks/homework8/task1)

### Homework №9
1. Необходимо выбрать в таблице тему и записать себя. Каждый доклад должен быть на 10-15 минут, вместе с презентацией.
Необходимо включить, как теоритическую информацию, так и практическую с примером использования. [[Сериализация]](https://github.com/GirZ0n/SPBU-Homework-2/tree/master/src/main/kotlin/homeworks/homework9)

### Test №1
1. Реализовать очередь с приоритетами в виде шаблонного класса. <br/> <br/>
Очередь должна иметь методы: <br/>
`enqueue()` -- принимающий на вход значение и численный приоритет <br/>
`dequeue()` -- возвращающий значение с наивысшим приоритетом и удаляющий его из очереди. <br/> <br/>
Если очередь пуста, `dequeue()` должен бросать исключение. Юнит-тесты обязательны. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/tests/test1)

### Test №2
2. Реализовать игру "Найди пару". При запуске отображается поле с кнопками размера `N` x `N`, где `N` чётное, кнопки без надписей. `N` принимается как параметр командной строки. Каждой кнопке ставится в соответствие число от `0` до `N2 / 2`, каждое число из этого диапазона должно встречаться на поле ровно дважды. Игрок нажимает на две произвольные (разные) кнопки, на них показывается соответствующие им числа. Если числа совпали, кнопки делаются неактивными. Если числа не совпали, кнопки возвращаются в изначальное положение. Игра заканчивается, когда игрок открыл все пары чисел. [[Solution]](https://github.com/GirZ0n/SPBU-Homework-2/blob/master/src/main/kotlin/tests/test2)
