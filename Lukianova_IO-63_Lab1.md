Національний технічний університет України «Київський політехнічний інститут імені Ігоря Сікорського» Факультет інформатики та обчислювальної техніки 

Кафедра обчислювальної техніки 

Структури даних і алгоритми Лабораторна робота №1 Розгалужені алгоритми 

Виконала: 

студентка групи ІО-63 Лук`янова С.С Номер у списку групи: 12 Перевірив: Русінов В.В 

Київ-2026 

# 1.Мета лабораторної роботи 

Метою лабораторної роботи «Розгалужені алгоритми» є засвоєння теоретичного матеріалу та набуття практичних навичок використання керуючих конструкцій розгалуження та булевих (логічних) операцій. 

## 2. Постановка завдання 

Задано дійсне число x. Визначити значення заданої за варіантом кусковонеперервної функції y(x), якщо воно існує, або вивести на екран повідомлення про неіснування функції для заданого x. 

Необхідно розв'язати задачу двома способами: 

1. У програмі дозволяється використовувати тільки одиничні операції порівняння (=, <>, <, <=, >, >=) і не дозволяється використовувати булеві (логічні) операції (not, and, or тощо). 

2. У програмі необхідно обов'язково використати булеві (логічні) операції (not, and, or тощо). Використання булевих операцій не повинно бути надлишковим. 

3.Завдання за варіантом: 



4. Алгоритм 1: 

Блок-схема алгоритму 1 (12 варіант) 



<!-- Start of picture text -->
ca<br>Sbdrddid<br><!-- End of picture text -->

Алгоритм 2: 

Блок-схема алгоритму 2 (12 варіант) 



<!-- Start of picture text -->
a Bapianr<br>C Begin (2 6ynesnmn12, onepauintn)nporpana2<br>1 °<br>Cm ><br>We<br><!-- End of picture text -->

5. Код програми 1 

#include <stdio.h> 

int main(void) 

{ double x = 0; double y = 0; 

printf("Enter x: "); scanf("%lf", &x); 

if (x <= 0) { 

if (x < -20) { if (x < -32) { 

printf("The function is undefined for x = %g\n", x); } else { y = x * x - 3; printf("y(%g) = %.4f\n", x, y); } } else { 

printf("The function is undefined for x = %g\n", x); } } else { if (x <= 5) { y = x * x * x - 5 * x * x; 

printf("y(%g) = %.4f\n", x, y); } else { if (x <= 10) { 

printf("The function is undefined for x = %g\n", x); } else { y = x * x - 3; printf("y(%g) = %.4f\n", x, y); } } } 

return 0; } Тест 1.1 



<!-- Start of picture text -->
"C:\Users\Lukan\CLionProjects\Task 1_Lab1\cmake-build-debug\Task_1_Lab1.exe<br>Enter x<br>The function is undefined for x 4<br>Process finished with exit code 0<br><!-- End of picture text -->

Тест1.2 



Тест1.3 



<!-- Start of picture text -->
P fini ith exit<br><!-- End of picture text -->

Тест1.4 



<!-- Start of picture text -->
"C:\Users\Lukan\CLionProjects\Task 1_Lab1\cmake-build-debug\Task_1_Lab1.exe<br>Enter x<br>(3 8.0000<br>Process finished with exit code 0<br><!-- End of picture text -->

Тест1.5 



<!-- Start of picture text -->
The function is efined for x<br><!-- End of picture text -->

Тест1.6 



<!-- Start of picture text -->
Enter x<br>Process finished with exit je<br><!-- End of picture text -->

Код програми 2 

#include <stdio.h> 

int main(void) { double x = 0; double y = 0; 

printf("Enter x: "); scanf("%lf", &x); 

if (x > 0 && x <= 5) { y = x * x * x - 5 * x * x; printf("y(%g) = %.4f\n", x, y); } else if ((x >= -32 && x < -20) || x > 10) { y = x * x - 3; printf("y(%g) = %.4f\n", x, y); } else { printf("The function is undefined for x = %g\n", x); } 

return 0; 

} 

Тест2.1 



<!-- Start of picture text -->
a ' ject va. 6 } ask ukianova_I0-63. at ask exe<br><!-- End of picture text -->

Тест2.2 ee Тест2.3 



<!-- Start of picture text -->
seers Lukan\CLionProjects\Lukianova_I0-63_Lab1_Taski\Lukianova_I0-63_Lab1_Task2.exe<br><!-- End of picture text -->

Тест2.4 



<!-- Start of picture text -->
ple Lukan\CLionProjects\Lukianova_I0-63_Lab1_Task1\Lukianova_I0-63_Lab1_Task2.exe<br><!-- End of picture text -->

Тест2.5 



### 6.Висновки 

У ході виконання лабораторної роботи я набула практичних навичок роботи з конструкціями розгалуження та логічними операторами в мові С. Для розв’язання задачі я написала дві програми, які знаходять значення функції для 

різних проміжків х. Проведені тести на різних вхідних даних підтвердили, що обидва алгоритми працюють коректно. 

