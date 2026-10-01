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
<img width="671" height="43" alt="Знімок екрана 2026-10-01 134555" src="https://github.com/user-attachments/assets/1beec9bf-6ee8-4841-b4a3-f0c84b837acc" />

4. Алгоритм 1: 

Блок-схема алгоритму 1 (12 варіант) 
<img width="1190" height="900" alt="1" src="https://github.com/user-attachments/assets/a9762794-efb7-4546-8855-ef64e5f58f03" />

Алгоритм 2: 

Блок-схема алгоритму 2 (12 варіант) 
<img width="1150" height="850" alt="2" src="https://github.com/user-attachments/assets/2ea0cf52-e7c1-4451-8ee7-7472c9125d0a" />

5. Код програми 1

```c
#include <stdio.h>

int main(void)
{
    double x = 0;
    double y = 0;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        if (x < -20) {
            if (x < -32) {
                printf("The function is undefined for x = %g\n", x);
            } else {
                y = x * x - 3;
                printf("y(%g) = %.4f\n", x, y);
            }
        } else {
            printf("The function is undefined for x = %g\n", x);
        }
    } else {
        if (x <= 5) {
            y = x * x * x - 5 * x * x;
            printf("y(%g) = %.4f\n", x, y);
        } else {
            if (x <= 10) {
                printf("The function is undefined for x = %g\n", x);
            } else {
                y = x * x - 3;
                printf("y(%g) = %.4f\n", x, y);
            }
        }
    }

    return 0;
}

```

Тест 1.1 

<img width="671" height="162" alt="test1_1" src="https://github.com/user-attachments/assets/656f6c0f-6d0c-4b88-b537-645b4ca2b722" />

Тест1.2 

<img width="746" height="182" alt="test1_2" src="https://github.com/user-attachments/assets/31101843-7407-4929-9c2a-813b651fb4e4" />

Тест1.3 

<img width="843" height="157" alt="test1_3" src="https://github.com/user-attachments/assets/cd5eb22f-c7f1-4d01-b9eb-9540204b01f7" />

Тест1.4 

<img width="667" height="156" alt="test1_4" src="https://github.com/user-attachments/assets/b8b060e2-52ca-41de-9e0a-72b470850f63" />

Тест1.5 

<img width="682" height="133" alt="test1_5" src="https://github.com/user-attachments/assets/8705fbc9-6099-4947-a5cc-45593feaacb9" />

Тест1.6 

<img width="633" height="157" alt="test1_6" src="https://github.com/user-attachments/assets/97a93975-1b62-4764-957d-cc96a22c5ec3" />

Код програми 2 

Код програми 2

```c
#include <stdio.h>

int main(void)
{
    double x = 0;
    double y = 0;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x > 0 && x <= 5) {
        y = x * x * x - 5 * x * x;
        printf("y(%g) = %.4f\n", x, y);
    } else if ((x >= -32 && x < -20) || x > 10) {
        y = x * x - 3;
        printf("y(%g) = %.4f\n", x, y);
    } else {
        printf("The function is undefined for x = %g\n", x);
    }

    return 0;
}

```

Тест2.1 

<img width="770" height="138" alt="test2_1" src="https://github.com/user-attachments/assets/43ed922e-1eb6-4973-b919-305871387a03" />

Тест2.2

<img width="788" height="171" alt="Test2_2" src="https://github.com/user-attachments/assets/f5c9ff10-4430-4870-a542-d3462e756350" />

Тест2.3 

<img width="747" height="182" alt="test2_3" src="https://github.com/user-attachments/assets/6716cf65-c2b9-420c-aff6-4e9237705c09" />

Тест2.4 

<img width="727" height="135" alt="test2_4" src="https://github.com/user-attachments/assets/d95b90f9-2aac-4a29-aa58-acebbd5fb64b" />

Тест2.5 

<img width="776" height="183" alt="test2_5" src="https://github.com/user-attachments/assets/3cf88ba5-a812-4fa3-8b76-8b0728e9f3d4" />

### 6.Висновки 

У ході виконання лабораторної роботи я набула практичних навичок роботи з конструкціями розгалуження та логічними операторами в мові С. Для розв’язання задачі я написала дві програми, які знаходять значення функції для різних проміжків х. Проведені тести на різних вхідних даних підтвердили, що обидва алгоритми працюють коректно. 

