[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7369712&assignment_repo_type=AssignmentRepo)
# Упрощённая модель банковской системы

В этом домашнем задании вам предстоит разработать упрощённую 
объектно-ориентированную модель функционирования банка.
Данная модель будет иметь множество допущений, отличий от реальной работы банков,
выдуманных ограничений и т.п. Помните, что задание - учебное,
а цель его - изучить методы и приёмы ООП.

Задание можно выполнить с использованием одном из предложенных 
языков программирования:

- C++
- Java
- Kotlin
- Scala
- C#

Также можно, но не рекомендуется использовать Python.
Другие языки использовать можно только с согласия преподавателя.

## Основные модели упрощённой банковской системы

- **Клиент**. Клиент может быть физическим или юридическим лицом.
Банку известна вся необходимая информация о клиенте. ИП и самозанятый является
физическим лицом. 
- **Счёт**. Клиент может открыть счёт. В рамках задания, будем считать что
можно открыть только дебетовый счёт. Счёт может быть в одной из следующих валют: 
российский рубль, доллар США, евро. Также может быть установлен лимит на операции 
снятия денег со счёта.
- **Карта**. Карта может быть дебетовой или кредитной. Карта привязана к соответствующему
счёту (дебетовому или кредитному). Карта может быть одной из трёх платёжных систем:
Lisa, MasterBart, HoMiR. У карты есть срок действия. Также может быть установлен
лимит на операции перевода с карты, отличающийся от лимита счёта. Если для карты
лимит не установлен, то лимитом карты считается лимит счёта.
- **Транзакция**. Транзакцией будем считать операцию перевода денежных средств
с одного счёта на другой. Пользователь может совершать перевод с карты на карту,
при этом подразумевается взаимодействие с соответствующими счетами. Для каждой
транзакции должен быть известен счёт списания, счёт зачисления, сумма, 
валюта операции, дата и время совершения, статус (к обработке, обрабатывается, 
выполнено, отклонено).
- **Операция с наличных**. Клиент может снять или положить наличные в отделении
банка или банкомате. Для каждого пользователя установлен лимит на однократное 
снятие наличных (не более X денег за раз). Если лимит превышен, наличные 
не выдаются. Для каждой операции снятия известно: тип (снятие, пополнение), счёт, 
сумма, дата и время, статус (выполнено, отклонено), место снятия 
(отделение или банкомат), номер отделения или банкомата. 

## Сценарии

Необходимо реализовать следующие сценарии использования:

- Регистрация клиента
- Изменение информации о клиенте
- Открытие счёта
- Закрытие счёта:
  - с переводом денежных средств на другой счёт с помощью транзакции
  - со снятием наличных (лимит на снятие в таком случае не действует)
- Установка лимита снятия для счёта
- Выпуск карты к счёту
- Перепривязка карты к другому счёту
- Закрытие карты (без перевода денежных средств)
- Установка лимита снятия для карты
- Совершение транзакции
- Снятие наличных
- Пополнение счёта наличными

Привести примеры использования для каждого сценария.

## Уточнения
- В этом задании считаем что одной карте соответствует один счёт, и наоборот,
одному счёту соответствует одна карта.
- Также, в этом задании считаем, что транзакция возможна только тогда, когда 
валюты счетов совпадают. Если валюты не совпадают, то транзакция отклоняется.
- Транзакция отклоняется, если недостаточно денег на счёте.
- Считаем, что в банкоматах или отделениях бесконечно много денег.
- Считаем, что деньги снимаются в валюте счёта.
- При перепривязке карты текущий счёт заменяется другим. Не забывайте проверять,
что к счёту не привязана другая карта.
- Нельзя, чтобы карта не была привязана к счёту. Если так получилось, карта 
считается закрытой.
