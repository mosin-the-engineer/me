#ifndef IDELESSDEBUGGER_H
#define IDELESSDEBUGGER_H
/*!
    \file
    \brief Содержит реализацию примитивного дебаггера.
    \author Мосин С.А.
    \version 1.0
    \date 2020-12-22
*/
//Qt:
#include <QFile>
#include <QTextStream>
#include <QDir>

//TODO: Добавить создание каталога и файла, если их нету

/// \brief IdeLessDebugger Класс для отладки в релизе.
/// Записывает интересующие значения в текстовый файл
/// IdeLessDebugger.txt в папке Temp.
/// Для быстрых операций есть возможность писать в кэш
/// и скидывать его на диск в конце работы.
class IdeLessDebugger
{
public:
    static IdeLessDebugger& Instance()
    {
        static IdeLessDebugger s;
        return s;
    }
    /// \brief d_out Функция печати текстовой информации
    /// \param string Текст сообщения
    void d_out(QString string)
    {
        QFile f(QDir::currentPath() + "/" + "Temp/IdeLessDebugger.txt");
        if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
            f.seek(f.size());
            QTextStream out(&f);
            out << string << "\r\n";
            f.close();
        }
    }
    /// \brief d_out Функция печати цифровой информации
    /// \param line Интовое значение для вывода
    void d_line(int line)
    {
        QFile f(QDir::currentPath() + "/" + "Temp/IdeLessDebugger.txt");
        if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
            f.seek(f.size());
            QTextStream out(&f);
            out << QString::number(line) << "\r\n";
            f.close();
        }
    }
    void d_line_cache(QString str)
    {
        m_cache_list.append(str);
    }
    void flush_cache()
    {
        QFile f(QDir::currentPath() + "/" + "Temp/IdeLessDebugger.txt");
        if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
            f.seek(f.size());
            QTextStream out(&f);
            for (const auto & i : m_cache_list)
            {
                out << i << "\r\n";
            }
            f.close();
            m_cache_list.clear();
        }
    }
private:
    QStringList m_cache_list;

    IdeLessDebugger(){}
    ~IdeLessDebugger() {}
    IdeLessDebugger(IdeLessDebugger const&) = delete;
    IdeLessDebugger& operator= (IdeLessDebugger const&) = delete;
};

#endif // IDELESSDEBUGGER_H
