#ifndef NODATE_H
#define NODATE_H

#include <QDate>
#include <QString>
#include <QObject>
#include <QDebug>

const QMap<QString,QString> mLunarFestival = {
                            {QString::fromLocal8Bit("正月初一"),QString::fromLocal8Bit("春节")},
                            {QString::fromLocal8Bit("正月十五"),QString::fromLocal8Bit("元宵节")},
                            {QString::fromLocal8Bit("三月初三"),QString::fromLocal8Bit("上巳节")},
                            {QString::fromLocal8Bit("五月初五"),QString::fromLocal8Bit("端午节")},
                            {QString::fromLocal8Bit("七月初七"),QString::fromLocal8Bit("七夕节")},
                            {QString::fromLocal8Bit("七月十五"),QString::fromLocal8Bit("中元节")},
                            {QString::fromLocal8Bit("八月十五"),QString::fromLocal8Bit("中秋节")},
                            {QString::fromLocal8Bit("九月初九"),QString::fromLocal8Bit("重阳节")},
                            {QString::fromLocal8Bit("十月初一"),QString::fromLocal8Bit("寒衣节")},
                            {QString::fromLocal8Bit("十月十五"),QString::fromLocal8Bit("下元节")},
                            {QString::fromLocal8Bit("腊月初八"),QString::fromLocal8Bit("腊八节")},
                            {QString::fromLocal8Bit("腊月廿三"),QString::fromLocal8Bit("祭灶节")},
                            };

const QStringList sTermTxt ={
                             QString::fromLocal8Bit("小寒"),QString::fromLocal8Bit("大寒"),
                             QString::fromLocal8Bit("立春"),QString::fromLocal8Bit("雨水"),
                             QString::fromLocal8Bit("惊蛰"),QString::fromLocal8Bit("春分"),
                             QString::fromLocal8Bit("清明"),QString::fromLocal8Bit("谷雨"),
                             QString::fromLocal8Bit("立夏"),QString::fromLocal8Bit("小满"),
                             QString::fromLocal8Bit("芒种"),QString::fromLocal8Bit("夏至"),
                             QString::fromLocal8Bit("小暑"),QString::fromLocal8Bit("大暑"),
                             QString::fromLocal8Bit("立秋"),QString::fromLocal8Bit("处暑"),
                             QString::fromLocal8Bit("白露"),QString::fromLocal8Bit("秋分"),
                             QString::fromLocal8Bit("寒露"),QString::fromLocal8Bit("霜降"),
                             QString::fromLocal8Bit("立冬"),QString::fromLocal8Bit("小雪"),
                             QString::fromLocal8Bit("大雪"),QString::fromLocal8Bit("冬至")
                            };
//1900-2100年节气表
const QStringList sTermInfo = {
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf97c3598082c95f8c965cc920f"),
                     QString::fromLocal8Bit("97bd0b06bdb0722c965ce1cfcc920f"),QString::fromLocal8Bit("b027097bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),
                     QString::fromLocal8Bit("97bcf97c359801ec95f8c965cc920f"),QString::fromLocal8Bit("97bd0b06bdb0722c965ce1cfcc920f"),QString::fromLocal8Bit("b027097bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf97c359801ec95f8c965cc920f"), QString::fromLocal8Bit("97bd0b06bdb0722c965ce1cfcc920f"),
                     QString::fromLocal8Bit("b027097bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("9778397bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97b6b97bd19801ec95f8c965cc920f"),
                     QString::fromLocal8Bit("97bd09801d98082c95f8e1cfcc920f"),QString::fromLocal8Bit("97bd097bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd197c36c9210c9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec95f8c965cc920e"),QString::fromLocal8Bit("97bd09801d98082c95f8e1cfcc920f"), QString::fromLocal8Bit("97bd097bd097c36b0b6fc9210c8dc2"),
                     QString::fromLocal8Bit("9778397bd097c36c9210c9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec95f8c965cc920e"),QString::fromLocal8Bit("97bcf97c3598082c95f8e1cfcc920f"),
                     QString::fromLocal8Bit("97bd097bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd097c36c9210c9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),
                     QString::fromLocal8Bit("97bcf97c3598082c95f8c965cc920f"),QString::fromLocal8Bit("97bd097bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf97c3598082c95f8c965cc920f"), QString::fromLocal8Bit("97bd097bd097c35b0b6fc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf97c359801ec95f8c965cc920f"),
                     QString::fromLocal8Bit("97bd097bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),
                     QString::fromLocal8Bit("97bcf97c359801ec95f8c965cc920f"),QString::fromLocal8Bit("97bd097bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf97c359801ec95f8c965cc920f"), QString::fromLocal8Bit("97bd097bd07f595b0b6fc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd19801ec9210c9274c920e"),QString::fromLocal8Bit("97b6b97bd19801ec95f8c965cc920f"),
                     QString::fromLocal8Bit("97bd07f5307f595b0b0bc920fb0722"),QString::fromLocal8Bit("7f0e397bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd097c36c9210c9274c920e"),
                     QString::fromLocal8Bit("97b6b97bd19801ec95f8c965cc920f"),QString::fromLocal8Bit("97bd07f5307f595b0b0bc920fb0722"),QString::fromLocal8Bit("7f0e397bd097c36b0b6fc9210c8dc2"),
                     QString::fromLocal8Bit("9778397bd097c36c9210c9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bd07f1487f595b0b0bc920fb0722"),
                     QString::fromLocal8Bit("7f0e397bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),
                     QString::fromLocal8Bit("97bcf7f1487f595b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"), QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf7f1487f595b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),QString::fromLocal8Bit("97bcf7f1487f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b97bd19801ec9210c965cc920e"),
                     QString::fromLocal8Bit("97bcf7f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b6fc920fb0722"), QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b97bd19801ec9210c9274c920e"),QString::fromLocal8Bit("97bcf7f0e47f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9210c91aa"),QString::fromLocal8Bit("97b6b97bd197c36c9210c9274c920e"),QString::fromLocal8Bit("97bcf7f0e47f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd097c36c9210c9274c920e"),
                     QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e37f5307f595b0b0bc920fb0722"), QString::fromLocal8Bit("7f0e397bd097c36b0b6fc9210c8dc2"),
                     QString::fromLocal8Bit("9778397bd097c36b0b70c9274c91aa"),QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e37f1487f595b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd097c35b0b6fc9210c8dc2"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e27f1487f595b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"), QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),QString::fromLocal8Bit("97b6b7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"), QString::fromLocal8Bit("9778397bd097c36b0b6fc9274c91aa"),
                     QString::fromLocal8Bit("97b6b7f0e47f531b0723b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),
                     QString::fromLocal8Bit("9778397bd097c36b0b6fc9210c91aa"),QString::fromLocal8Bit("97b6b7f0e47f149b0723b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0723b0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),QString::fromLocal8Bit("9778397bd097c36b0b6fc9210c8dc2"),QString::fromLocal8Bit("977837f0e37f149b0723b0787b0721"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e37f5307f595b0b0bc920fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc9210c8dc2"),
                     QString::fromLocal8Bit("977837f0e37f14998082b0787b0721"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e37f1487f595b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd097c35b0b6fc9210c8dc2"),QString::fromLocal8Bit("977837f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),QString::fromLocal8Bit("977837f0e37f14998082b0787b06bd"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd097c35b0b6fc920fb0722"),
                     QString::fromLocal8Bit("977837f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),QString::fromLocal8Bit("977837f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"), QString::fromLocal8Bit("977837f0e37f14998082b0787b06bd"),
                     QString::fromLocal8Bit("7f07e7f0e47f149b0723b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),
                     QString::fromLocal8Bit("977837f0e37f14998082b0723b06bd"),QString::fromLocal8Bit("7f07e7f0e37f149b0723b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0723b0b6fb0722"),
                     QString::fromLocal8Bit("7f0e397bd07f595b0b0bc920fb0722"),QString::fromLocal8Bit("977837f0e37f14898082b0723b02d5"),QString::fromLocal8Bit("7ec967f0e37f14998082b0787b0721"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e37f1487f595b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e37f0e37f14898082b0723b02d5"),
                     QString::fromLocal8Bit("7ec967f0e37f14998082b0787b0721"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e37f1487f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e37f0e37f14898082b0723b02d5"),QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e37f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e37f0e37f14898082b072297c35"),QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e37f0e37f14898082b072297c35"),
                     QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"), QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),
                     QString::fromLocal8Bit("7f0e37f0e366aa89801eb072297c35"),QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f149b0723b0787b0721"),
                     QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),QString::fromLocal8Bit("7f0e37f0e366aa89801eb072297c35"),QString::fromLocal8Bit("7ec967f0e37f14998082b0723b06bd"),
                     QString::fromLocal8Bit("7f07e7f0e47f149b0723b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e37f0e366aa89801eb072297c35"),
                     QString::fromLocal8Bit("7ec967f0e37f14998082b0723b06bd"),QString::fromLocal8Bit("7f07e7f0e37f14998083b0787b0721"),QString::fromLocal8Bit("7f0e27f0e47f531b0723b0b6fb0722"),
                     QString::fromLocal8Bit("7f0e37f0e366aa89801eb072297c35"),QString::fromLocal8Bit("7ec967f0e37f14898082b0723b02d5"),QString::fromLocal8Bit("7f07e7f0e37f14998082b0787b0721"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0722"),QString::fromLocal8Bit("7f0e36665b66aa89801e9808297c35"), QString::fromLocal8Bit("665f67f0e37f14898082b0723b02d5"),
                     QString::fromLocal8Bit("7ec967f0e37f14998082b0787b0721"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0722"), QString::fromLocal8Bit("7f0e36665b66a449801e9808297c35"),
                     QString::fromLocal8Bit("665f67f0e37f14898082b0723b02d5"),QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),
                     QString::fromLocal8Bit("7f0e36665b66a449801e9808297c35"),QString::fromLocal8Bit("665f67f0e37f14898082b072297c35"), QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),
                     QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"),QString::fromLocal8Bit("7f0e26665b66a449801e9808297c35"), QString::fromLocal8Bit("665f67f0e37f1489801eb072297c35"),
                     QString::fromLocal8Bit("7ec967f0e37f14998082b0787b06bd"),QString::fromLocal8Bit("7f07e7f0e47f531b0723b0b6fb0721"), QString::fromLocal8Bit("7f0e27f1487f531b0b0bb0b6fb0722"),
                            };


const QDate maxDate(2099,12,31);

const QDate minDate(1901,1,1);

const QStringList ChDay = {QString::fromLocal8Bit("*"),
                           QString::fromLocal8Bit("初一"),
                           QString::fromLocal8Bit("初二"),
                           QString::fromLocal8Bit("初三"),
                           QString::fromLocal8Bit("初四"),
                           QString::fromLocal8Bit("初五"),
                           QString::fromLocal8Bit("初六"),
                           QString::fromLocal8Bit("初七"),
                           QString::fromLocal8Bit("初八"),
                           QString::fromLocal8Bit("初九"),
                           QString::fromLocal8Bit("初十"),
                           QString::fromLocal8Bit("十一"),
                           QString::fromLocal8Bit("十二"),
                           QString::fromLocal8Bit("十三"),
                           QString::fromLocal8Bit("十四"),
                           QString::fromLocal8Bit("十五"),
                           QString::fromLocal8Bit("十六"),
                           QString::fromLocal8Bit("十七"),
                           QString::fromLocal8Bit("十八"),
                           QString::fromLocal8Bit("十九"),
                           QString::fromLocal8Bit("二十"),
                           QString::fromLocal8Bit("廿一"),
                           QString::fromLocal8Bit("廿二"),
                           QString::fromLocal8Bit("廿三"),
                           QString::fromLocal8Bit("廿四"),
                           QString::fromLocal8Bit("廿五"),
                           QString::fromLocal8Bit("廿六"),
                           QString::fromLocal8Bit("廿七"),
                           QString::fromLocal8Bit("廿八"),
                           QString::fromLocal8Bit("廿九"),
                           QString::fromLocal8Bit("三十")
                          };

const QStringList ChMonth = {QString::fromLocal8Bit("*"),
                             QString::fromLocal8Bit("正"),
                             QString::fromLocal8Bit("二"),
                             QString::fromLocal8Bit("三"),
                             QString::fromLocal8Bit("四"),
                             QString::fromLocal8Bit("五"),
                             QString::fromLocal8Bit("六"),
                             QString::fromLocal8Bit("七"),
                             QString::fromLocal8Bit("八"),
                             QString::fromLocal8Bit("九"),
                             QString::fromLocal8Bit("十"),
                             QString::fromLocal8Bit("十一"),
                             QString::fromLocal8Bit("腊")
                            };

const QStringList m_TianGan = {
                                QString::fromLocal8Bit("甲"),
                                QString::fromLocal8Bit("乙"),
                                QString::fromLocal8Bit("丙"),
                                QString::fromLocal8Bit("丁"),
                                QString::fromLocal8Bit("戊"),
                                QString::fromLocal8Bit("己"),
                                QString::fromLocal8Bit("庚"),
                                QString::fromLocal8Bit("辛"),
                                QString::fromLocal8Bit("壬"),
                                QString::fromLocal8Bit("癸")
                              };

const QStringList m_DiZhi = {
                                QString::fromLocal8Bit("子"),QString::fromLocal8Bit("丑"),
                                QString::fromLocal8Bit("寅"),QString::fromLocal8Bit("卯"),
                                QString::fromLocal8Bit("辰"),QString::fromLocal8Bit("巳"),
                                QString::fromLocal8Bit("午"),QString::fromLocal8Bit("未"),
                                QString::fromLocal8Bit("申"),QString::fromLocal8Bit("酉"),
                                QString::fromLocal8Bit("戌"),QString::fromLocal8Bit("亥")
                              };

const QStringList m_ShuXiang = {
                                QString::fromLocal8Bit("鼠"),QString::fromLocal8Bit("牛"),
                                QString::fromLocal8Bit("虎"),QString::fromLocal8Bit("兔"),
                                QString::fromLocal8Bit("龙"),QString::fromLocal8Bit("蛇"),
                                QString::fromLocal8Bit("马"),QString::fromLocal8Bit("羊"),
                                QString::fromLocal8Bit("猴"),QString::fromLocal8Bit("鸡"),
                                QString::fromLocal8Bit("狗"),QString::fromLocal8Bit("猪")
                               };

const unsigned int mLunarCalendarTable[199] = {
    0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A,/*1901-1910*/
    0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754,/*1911-1920*/
    0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E,/*1921-1930*/
    0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48,/*1931-1940*/
    0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51,/*1941-1950*/
    0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x6AD53C,/*1951-1960*/
    0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46,/*1961-1970*/
    0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50,/*1971-1980*/
    0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x095746,0x5497BB,/*1981-1990*/
    0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645,/*1991-2000*/
    0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E,/*2001-2010*/
    0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9,/*2011-2020*/
    0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43,/*2021-2030*/
    0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C,/*2031-2040*/
    0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37,/*2041-2050*/
    0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42,/*2051-2060*/
    0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B,/*2061-2070*/
    0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6,/*2071-2080*/
    0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E,/*2081-2090*/
    0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5          /*2091-2099*/
};

QString holiday(int month, int day)
{
    int temp = (month << 8) | day;
    QString strHoliday = "";
    switch (temp) {
    case 0x0101: strHoliday = QString::fromLocal8Bit("元旦");  break;
    case 0x020E: strHoliday = QString::fromLocal8Bit("情人节"); break;
    case 0x0308: strHoliday = QString::fromLocal8Bit("妇女节"); break;
    case 0x0401: strHoliday = QString::fromLocal8Bit("愚人节"); break;
    case 0x0501: strHoliday = QString::fromLocal8Bit("劳动节"); break;
    case 0x0504: strHoliday = QString::fromLocal8Bit("青年节"); break;
    case 0x0601: strHoliday = QString::fromLocal8Bit("儿童节"); break;
    case 0x0701: strHoliday = QString::fromLocal8Bit("建党节"); break;
    case 0x0801: strHoliday = QString::fromLocal8Bit("建军节"); break;
    case 0x090A: strHoliday = QString::fromLocal8Bit("教师节"); break;
    case 0x0A01: strHoliday = QString::fromLocal8Bit("国庆节"); break;
    case 0x0C18: strHoliday = QString::fromLocal8Bit("圣诞节"); break;
    default: break;
    }

    return strHoliday;
}

const int mMonthAdd[12] = {0,31,59,90,120,151,181,212,243,273,304,334};

bool GetSolarTerms(QDate date, unsigned int & a1, unsigned int & a2)
{
    if((!date.isValid())||(date<minDate)||(date>maxDate)) return false;
    int year  = date.year();
    int month = date.month();

    QString Info = sTermInfo[year - 1900];
    bool ok = false;
    QString Info1 = Info.mid(((month - 1) / 2) * 5, 5);
    unsigned int t = Info1.toInt(&ok, 16);
    if(!ok) return ok;
    QString m2;
    m2.setNum(t);
    m2 = m2.mid(((month % 2 ) ? 0 : 1 ) * 3, 3);
    a1 = m2.mid(0, 1).toInt(&ok);
    if(!ok) return ok;
    a2 = m2.mid(1, 2).toInt(&ok);
    return  ok;
}

bool GetLunarDay(QDate date,
                 QString &outLunarMD,
                 QString &outLunarYear,
                 QString &outLunarMonth,
                 QString &outLunarDay,
                 QString &outLunarTerms,
                 QString &outLunarFestival,
                 QString &outSolarFestival)
{

    if((!date.isValid())||(date<minDate)||(date>maxDate)) return false;

    unsigned int mLunarCalendarDay = 0;

    int year  = date.year();

    int month = date.month();

    int day = date.day();

    int Spring_NY = 0;

    int Sun_NY = 0;

    int StaticDayCount = 0;

    int index = 0;

    int flag = 0;

    int MonthCount = 1;
    unsigned int sa1,sa2;
    int nTheMonth;
    GetSolarTerms(date, sa1, sa2);
    if(day >= (int)sa1)
        nTheMonth = (year - 1901) * 12 - 2 + month;
    else
        nTheMonth = (year - 1901) * 12 - 2 + month -1;
    outLunarMonth = m_TianGan[(nTheMonth + 6) % 10] + m_DiZhi[(nTheMonth + 2) % 12] + QString::fromLocal8Bit("月");
    int nTheDate = abs(date.daysTo(QDate(1900,1,30)));
    outLunarDay = m_TianGan[(nTheDate + 9) % 10] + m_DiZhi[(nTheDate + 3) % 12]+ QString::fromLocal8Bit("日");

    if( ((mLunarCalendarTable[year-1901] & 0x0060) >> 5) == 1)
        Spring_NY = (mLunarCalendarTable[year-1901] & 0x001F) - 1;
    else
        Spring_NY = (mLunarCalendarTable[year-1901] & 0x001F) - 1 + 31;

    Sun_NY = mMonthAdd[month-1] + day - 1;

    if( (!(year % 4)) && (month > 2))
        Sun_NY++;

    if (Sun_NY >= Spring_NY)
    {
        Sun_NY -= Spring_NY;
        month = 1;
        index = 1;
        flag = 0;
        if( ( mLunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while(Sun_NY >= StaticDayCount)
        {
            Sun_NY -= StaticDayCount;
            index++;
            if(month == (int)((mLunarCalendarTable[year - 1901] & 0xF00000) >> 20))
            {
                flag = ~flag;
                if(flag == 0)
                    month++;
            }
            else
                month++;
            if( ( mLunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
                StaticDayCount=29;
            else
                StaticDayCount=30;
            MonthCount++;
        }
        day = Sun_NY + 1;
    }
    else
    {
        Spring_NY -= Sun_NY;
        year--;
        month = 12;
        if(year>=1901){
            if ( ((mLunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
                index = 12;
            else
                index = 13;
            flag = 0;
            if( ( mLunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }else{
            index = 12;
            StaticDayCount = 30;
        }
        while(Spring_NY > StaticDayCount)
        {
            Spring_NY -= StaticDayCount;
            index--;
            if(flag == 0)
                month--;
            if(month == (int)((mLunarCalendarTable[year - 1901] & 0xF00000) >> 20))
                flag = ~flag;
            if( ( mLunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
            MonthCount++;
         }
         day = StaticDayCount - Spring_NY + 1;
    }

    outLunarYear = m_TianGan[((year - 4) % 60) % 10] +\
                    m_DiZhi[((year - 4) % 60) % 12] +\
                    QString::fromLocal8Bit("年");

    mLunarCalendarDay |= day;
    mLunarCalendarDay |= (month << 6);

    if((month == (int)((mLunarCalendarTable[year - 1901] & 0xF00000) >> 20))&&(month!=MonthCount)){
        outLunarMD = QString::fromLocal8Bit("闰");
        outLunarMD.append(ChMonth[(mLunarCalendarDay & 0x3C0) >> 6]);
    }else{
        outLunarMD = ChMonth[(mLunarCalendarDay & 0x3C0) >> 6];
    }
    outLunarMD.append(QString::fromLocal8Bit("月"));
    outLunarMD.append(ChDay[mLunarCalendarDay & 0x3F]);
    outLunarTerms.clear();
    outLunarFestival.clear();
    if( date.day()==(int)sa1){
        outLunarTerms.append(sTermTxt[(date.month()-1)*2]);
    }
    if( date.day()==(int)sa2){
        outLunarTerms.append(sTermTxt[(date.month()-1)*2 + 1]);
    }
    if((StaticDayCount==29)&&(outLunarMD==QString::fromLocal8Bit("腊月廿九"))){
        outLunarFestival.append(QString::fromLocal8Bit("除夕"));
    }
    if((StaticDayCount==30)&&(outLunarMD==QString::fromLocal8Bit("腊月三十"))){
        outLunarFestival.append(QString::fromLocal8Bit("除夕"));
    }
    if((date.day()==(int)(sa1-1))&&(date.month()==4)){
        outLunarFestival.append(QString::fromLocal8Bit("寒食节"));
    }
    outLunarFestival.append(mLunarFestival[outLunarMD]);
    outSolarFestival = holiday(date.month(), date.day());
    return true;
}


#endif // NODATE_H
