Задание Z12.7 :

функция bool isKPeriodic(string& str, int K)

проверяет, является ли строка кратной числу К. 
Кратность — повторяемость строки каждые К символов ( К должно быть больше 0 ). 
Например, abcabcabcabc имеет кратность- 3,  так как она состоит из подстрок abc, имеющих длину - 3.

Для решения задачи функция была разбита на 3 основных алгоритма:
1. для сокращения времени обработки первый алгоритм проверяет строку на кратность от 1 до 10.
  
2. обрабатывает на кратность оставшиеся варианты длины строки.  

3. обрабатывает случаи подстроки состоящей из одного символа.

В рузультате функция может возвращать:

0   - отсутствие кратности

1   - подстрока из одного символа

> 1 - кратность подстроки из более чем одного символа.