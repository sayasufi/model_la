
#ifndef UDP_ARINC_DATA_H
#define UDP_ARINC_DATA_H

#include "stdint.h"
#pragma pack(push, 1)


    struct S_UDP_PACK_ODS_DATA
    {
        /* HEADER*/
        /* P1 */
        uint16_t preface_1;	      /* Преамбула	0xCDEFFA01   */
        uint16_t preface_2;	      /* Преамбула	             */
        uint16_t preface_3;	      /* Преамбула	             */
        uint16_t preface_4;	      /* Преамбула	             */
        uint16_t reciever_addr;    /* Адресат пакета	 0x0001  */
        uint16_t sender_addr;      /* Источник пакета 0x0002  */
        uint16_t id;               /* № пакета	0x0003              */
        uint16_t reserv_1;         /* Зарезервировано	0x0000      */
        uint16_t reserv_2;         /* Зарезервировано	0x0000      */
        uint16_t reserv_3;         /* Зарезервировано	0x0000      */
        uint16_t size;             /* Длина всего пакета	0x03A2      */

        // 1
        union  {
            uint16_t w;
            struct {
                uint16_t vpnp_valid : 1;                    // Исправность ВПНП
                uint16_t vpnp_fail : 1;                     // Отказ ВПНП
                uint16_t data_failure : 1;                  // Отказ данных от ВС
                uint16_t data_link : 1;                     // Нет данных от ВС
                uint16_t built_in_test : 1;                 // Тест начального включения
                uint16_t ground_test : 1;                   // Наземный контроль
                uint16_t wait : 1;                          // Ожидание
                uint16_t nav : 1;                           // Навигация
                uint16_t bit9 : 1;
                uint16_t bit10 : 1;
                uint16_t bit11 : 1;
                uint16_t bit12 : 1;
                uint16_t mfi10_link_fail : 1;               // Нет данных от МФИ-10
                uint16_t mfi12l_link_fail : 1;              // Нет данных от МФИ-12 левый
                uint16_t mfi12r_link_fail : 1;              // Нет данных от МФИ-12 правый
                uint16_t prep_done : 1;                     // Подготовка завершена
            } bit;
        } sds1;

        uint16_t _reserve0;

        // 2
        union {
            uint16_t w;
            struct {
                uint16_t cdmk_valid : 1;                    // Исправность ЦДМК
                uint16_t cdmk_failure : 1;                  // Отказ ЦДМК
                uint16_t cdmk_link : 1;                     // Наличие связи с ЦДМК по CAN
                uint16_t bit4 : 1;
                uint16_t ufos1_valid : 1;                   // Исправность УФОС-01 №1
                uint16_t ufos1_failure : 1;                 // Отказ УФОС-01 №1
                uint16_t ufos1_link : 1;                    // Наличие связи с УФОС-01 по CAN №1
                uint16_t ufos1_work : 1;                    // УФОС-01 №1 в режиме "Работа"
                uint16_t ufos2_valid : 1;                   // Исправность УФОС-01 №2
                uint16_t ufos2_failure : 1;                 // Отказ УФОС-01 №2
                uint16_t ufos2_link : 1;                    // Наличие связи с УФОС-01 по CAN №2
                uint16_t ufos2_work : 1;                    // УФОС-01 №2 в режиме "Работа"
                uint16_t bit13 : 1;
                uint16_t bit14 : 1;
                uint16_t bit15 : 1;
                uint16_t bit16 : 1;
            } bit;
        } sds2;

        // 3
        union {
            uint16_t w;
            struct {
                uint16_t setup : 1;                 // Выставка

                uint16_t bit_2 : 1;
                uint16_t bit_3 : 1;
                uint16_t adjust : 1;                // Режим Юстировка

                uint16_t adjust_auto : 1;           // Ведется автоматическая юстировка
                uint16_t adjust_heading : 1;        // Ведется ручная юстировка курса
                uint16_t adjust_pitch : 1;          // Ведется ручная юстировка тангажа
                uint16_t adjust_roll : 1;           // Ведется ручная юстировка крена

                uint16_t adjust_reset : 1;          // Сброс юстировочных значений
                uint16_t adjust_reset_heading : 1;  // Сброс юстировочных значений курса
                uint16_t adjust_reset_pitch : 1;    // Сброс юстировочных значений тангажа
                uint16_t adjust_reset_roll : 1;     // Сброс юстировочных значений крена

                uint16_t bit_13 : 1;
                uint16_t bit_14 : 1;
                uint16_t bit_15 : 1;
                uint16_t bit_16 : 1;
            } bit;
        } sds3;

        uint16_t resrv[12];

        uint32_t preface_ar_1;      /*Преамбула канала ARINC-429 №1(Данные ИНС) ВПНП-1М */

        uint32_t cnt_p1;            /*Счетчик посылок*/

        union {
            uint32_t w;
            struct {
                uint32_t arinc : 8;        // Восьмеричный код 277
                uint32_t id : 2;        // Идентификатор

                uint32_t vpnp_valid : 1;        // Признак «Исправность ВПНП»
                uint32_t vpnp_fail : 1;        // Признак «Отказ ВПНП»

                uint32_t data_miss_ch1 : 1;        // Признак «Нет данных от ВС» КЛС 1
                uint32_t data_fail_ch1 : 1;        // Признак «Отказ данных от ВС» КЛС 1
                uint32_t data_miss_ch2 : 1;        // Признак «Нет данных от ВС» КЛС 2
                uint32_t data_fail_ch2 : 1;        // Признак «Отказ данных от ВС» КЛС 2

                uint32_t _res0 : 1;        // Резерв
                uint32_t _res1 : 1;        // Резерв
                uint32_t _res2 : 1;        // Резерв
                uint32_t _res3 : 1;        // Резерв

                uint32_t start_test : 1;        // Признак «Тест начального включения»
                uint32_t ground : 1;        // Признак «Наземный контроль»
                uint32_t setup : 1;        // Признак «Выставка»
                uint32_t nav : 1;        // Признак «Навигация»

                uint32_t wait : 1;        // Признак «Ожидание»
                uint32_t bche_ins : 1;        // Признак «Подогрев БЧЭ ИНС»
                uint32_t vpnp_type : 2;        // Тип «ВПНП»
                uint32_t _res5 : 1;        // Резерв

                uint32_t matrix : 2;        // Матрица состояния СДС (см. табл. 4)
                uint32_t parity : 1;        // Дополнение до четности
            } bit;
        } sds_01_p1;

        union {
            uint32_t w;
            struct {
                unsigned arinc : 8;        // Восьмеричный код 277

                unsigned id : 2;        // Идентификатор
                unsigned sns : 1;        // Признак «Коррекция по СНС»
                unsigned svs : 1;        // Признак «Коррекция по СВС»

                unsigned dmk : 1;        // Признак «Коррекция по ДМК»
                unsigned low_accuracy : 1;        // Признак «Пониженная точность»
                unsigned _res0 : 1;        // Резерв
                unsigned _res1 : 1;        // Резерв

                unsigned _res2 : 1;        // Резерв
                unsigned _res3 : 1;        // Резерв

                unsigned _res4 : 1;        // Резерв

                unsigned adjust_mode : 1;        // Признак «Режим юстировка»

                unsigned auto_adjust : 1;        // Признак «Ведется автоматическая юстировка»
                unsigned course_manual : 1;        // Признак «Ведется ручная юстировка курса»
                unsigned pitch_manual : 1;        // Признак «Ведется ручная юстировка тангажа»
                unsigned roll_manual2 : 1;        // Признак «Ведется ручная юстировка крена» ?????

                unsigned roll_manual : 1;        // Признак «Ведется ручная юстировка крена» ?????
                unsigned adjust_reset : 1;        // Признак «Сброс юстировочных значений»
                unsigned course_reset : 1;        // Признак «Сброс юстировочных значений курса»
                unsigned pitch_reset : 1;        // Признак «Сброс юстировочных значений тангажа»

                unsigned roll_reset : 1;        // Признак «Сброс юстировочных значений крена»
                unsigned matrix : 2;        // Матрица состояния СДС (см. табл. 4)
                unsigned parity : 1;        // Дополнение до четности
            } bit;
        } sds_02_p1;

        union {
            uint32_t w;
            struct {
                unsigned code : 8;        // Восьмеричный код 271

                unsigned id : 2;        // Идентификатор
                unsigned sns_valid : 1;        // Признак «Исправность СНС»
                unsigned sns_fail : 1;        // Признак «Отказ СНС»

                unsigned data_fail : 1;        // Признак «Недостоверность данных СНС»
                unsigned data_update : 1;        // Признак «Признак выдачи обновленных параметров»
                unsigned sns_type : 2;        // Тип выбранной СНС

                unsigned elipsoid : 2;        // Тип используемого эллипсоида

                unsigned _res0 : 11;       // Резерв
                unsigned matrix : 2;        // Матрица состояния СДС (см. табл. 4)
                unsigned parity : 1;        // Дополнение до четности
            } bit;
        } sds_03_p1;

        // uint32_t sds_01_p1;            /* СДС 1 */
        // uint32_t sds_02_p1;            /* СДС 2 */
        // uint32_t sds_03_p1;            /* СДС 3 */
        uint32_t sds_04_p1;            /* СДС 4 */
        uint32_t sds_05_p1;            /* СДС 5 */

        int32_t pitch;             /* Угол тангажа*/
        int32_t roll;              /* Угол крена */
        int32_t course_mag;        /* Курс магнитный */
        int32_t course_track_mag;  /* Магнитный путевой угол */
        int32_t course_true;	    /* Истинный курс */
        int32_t course_gyro;       /* Гироскопический курс  */

        int32_t w_x;               /* Угловая скорость тангажа;		 */
        int32_t w_y;               /* Угловая скорость крена;  		 */
        int32_t w_z;               /* Угловая скорость рысканья; 	 */
        int32_t n_x;               /* Продольное ускорение;  */
        int32_t n_y;               /* Боковое ускорение;    	 */
        int32_t n_z;               /* Нормальное ускорение;   */
        uint32_t L_clx_head;		/*Географические координаты долгота старшая часть 	 */
        uint32_t L_clx_tail;		/*Географические координаты долгота младшая часть 	 */
        uint32_t B_clx_head;		/*Географические координаты широта старшая часть	 */
        uint32_t B_clx_tail;		/*Географические координаты широта младшая часть 	 */
        int32_t H_cmplx;           /*Комплексная высота полета*/
        int32_t H_otn; 		    /* Относительная барометрическая высота */
        int32_t a_vert;			/* Вертикальное ускорение; */
        int32_t speed_vert;        /*Вертикальная скорость*/
        int32_t speed_vert_pot;    /*Потенциальная вертикальная скорость */
        int32_t v_north; 		    /*Путевая скорость N/S  */
        int32_t v_east; 		    /*Путевая скорость E/W  */
        int32_t speed_track;	    /*Путевая скорость */
        int32_t a_course; 		    /*Ускорение вдоль траектории полета  */
        int32_t traj_slope;		/*Угол наклона траектории */
        int32_t drift_angle;       /*Угол сноса*/
        int32_t wind_speed;		/*Скорость ветра */
        int32_t wind_angle_mag;    /*Магнитное направление ветра*/
        int32_t mult_txt;          /*Мультиплексор ТЕХН 		*/
        int32_t time_on;		    /*Время от включения 		005	*/
        int32_t time_nav;		    /*Время от начала навигации 006 */

        uint32_t reserv_4;
        uint32_t reserv_5;
        uint32_t reserv_6;
        uint32_t reserv_7;
        uint32_t reserv_8;
        uint32_t reserv_9;
        uint32_t reserv_10;
        uint32_t reserv_11;

        uint32_t p1_end_sig; /*Индентификатор окончания пакета №1*/

        uint32_t reserv_12; /* !!!*/

        /******/
        /* P2 */
        /******/

        uint32_t preface_ar_2;  /*Преамбула канала ARINC-429 №2(Данные СВС) ВПНП-1М*/

        uint32_t cnt_p2;        /*Счетчик посылок*/

        uint32_t sds_01_p2;     /* СДС 1 */
        uint32_t sds_02_p2;     /* СДС 2 */
        int32_t H_abs;         /* абсолютная барометрическая высота           [м] */
        int32_t H_qnh;         /* относительная баровысота (коррекция по QNH) [м] */
        int32_t H_qfe;         /* относительная баровысота (коррекция по QFE) [м] */
        int32_t airspeed_true; /* истинная (воздушная) скорость            [км/ч] */
        int32_t airspeed_prib; /* приборная скорость                       [км/ч] */
        int32_t speed_vert_svs;/* вертикальная скорость                     [м/с] */
        int32_t M;             /* число Маха полета                        [ед.М] */
        int32_t temp_h;        /* температура наружного воздуха              [°С] */
        int32_t temp_r;        /* температура торможения                     [°С] */
        int32_t Q;             /* скоростной напор                           [Па] */
        int32_t P_f;           /*Полное давление                       [мм.рт.ст] */
        int32_t P_h_stat;      /* статическое давление воздуха         [мм.рт.ст] */
        int32_t Td1;            /* температура датчика давления воздуха Д1    [°С] */
        int32_t Td2;            /* температура датчика давления воздуха Д2    [°С] */

        uint32_t reserv_13;
        uint32_t reserv_14;
        uint32_t reserv_15;
        uint32_t reserv_16;
        int32_t altitude_danger;   // опасная высота

        int32_t radio_altitude;     // Высота от Радиовысотомера.
        int32_t altitude_trend;     // Тренд высоты Habs 
        int32_t speed_trend;        // Тренд скорости приборной 
        // uint32_t reserv_18;
        // uint32_t reserv_19;
        // uint32_t reserv_20;

        uint32_t p2_end_sig; /*Индентификатор окончания пакета №2*/

        /******/
        /* P3 */
        /******/
        uint32_t preface_ar_3;  /*Преамбула канала ARINC-429 №3(Данные СНС) ВПНП-1М*/

        uint32_t cnt_p3;        /*Счетчик посылок*/

        // uint32_t sds_01_p3;     /* СДС 1 */
        union {
            uint32_t w;
            struct {
                unsigned parity : 1;
                unsigned matrix : 2;
                unsigned reserve : 11;
                unsigned elipsoid : 2;
                unsigned sns_type : 2;
                unsigned data_update : 1;
                unsigned data_fail : 1;
                unsigned sns_fail : 1;
                unsigned sns_valid : 1;
                unsigned id : 2;
                unsigned code : 8;
            }bit;
        }sds_01_p3;     /* СДС 1 */

        uint32_t sds_02_p3;     /* СДС 2 */
        uint32_t sds_03_p3;     /* СДС 3 */

        uint32_t hdop; /*Геометрический фактор HDOP  умноженный на 10*/
        uint32_t vdop; /*Геометрический фактор VDOP  умноженный на 10*/
        uint32_t pdop; /*Геометрический фактор PDOP  умноженный на 10*/

        int32_t vertical_speed_sns;    /* вертикальная скорость                     [м/с] */
        int32_t speed_track_sns;	    /*Путевая скорость */
        int32_t v_north_sns; 		    /*Путевая скорость N/S  */
        int32_t v_east_sns; 		    /*Путевая скорость E/W  */
        int32_t track_angle_sns;       /* путевой угол*/

        int32_t H_sns;         /*высота СНС [м] */

        uint32_t L_clx_head_sns;		/*Географические координаты долгота старшая часть 	 */
        uint32_t L_clx_tail_sns;		/*Географические координаты долгота младшая часть 	 */
        uint32_t B_clx_head_sns;		/*Географические координаты широта старшая часть	 */
        uint32_t B_clx_tail_sns;		/*Географические координаты широта младшая часть 	 */

        uint32_t time_cur;              /*Текущее время*/
        uint32_t date_cur;              /*Текущая дата*/


        uint32_t reserv_21;
        uint32_t reserv_22;
        uint32_t reserv_23;
        uint32_t reserv_24;
        uint32_t reserv_25;
        uint32_t reserv_26;
        uint32_t reserv_27;
        uint32_t reserv_28;

        uint32_t p3_end_sig; /*Индентификатор окончания пакета №3*/

        uint16_t sds1X; // TODO....
        // 2
        union {
            uint16_t w;
            struct {
                uint16_t baro0 : 1;                         // Текущая коррекция баровысоты[0]
                uint16_t baro1 : 1;                         // Текущая коррекция баровысоты[1]
                uint16_t baro_update : 1;                   // Признак "Данные коррекции баровысоты обновлены"
                uint16_t bit4 : 1;
                uint16_t ufos1_valid : 1;
                uint16_t ufos1_failure : 1;
                uint16_t ufos1_link : 1;
                uint16_t ufos1_work : 1;
                uint16_t ufos2_valid : 1;
                uint16_t ufos2_failure : 1;
                uint16_t ufos2_link : 1;
                uint16_t ufos2_work : 1;
                uint16_t bit13 : 1;
                uint16_t bit14 : 1;
                uint16_t bit15 : 1;
                uint16_t bit16 : 1;
            } bit;
        } sds2X;

        union sds3X {
            uint16_t w;
            struct {
                uint16_t ailerons_trim_n : 1;       // Нейтральное положение триммера элеронов
                uint16_t elevator_trim_n : 1;       // Нейтральное положение триммера РВ
                uint16_t rudder_trim_n : 1;          // Нейтральное положение триммера РН
                uint16_t engine_start : 1;          // Запуск двигателя
                uint16_t manual_mode : 1;           // Ручной режим 
                uint16_t wow : 1;                   // Шасси обжато
                uint16_t apu_start : 1;             // ВСУ Запуск
                uint16_t apu_work : 1;              // ВСУ Работа
                uint16_t engine_fire : 1;           // Пожар двигатель
                uint16_t apu_fire : 1;              // ВСУ Пожар
                uint16_t engine_failure : 1;        // Отказ двигателя
                uint16_t generator_fail : 1;        // Отказ генератора
                uint16_t bit13 : 1;
                uint16_t bit14 : 1;
                uint16_t bit15 : 1;
                uint16_t bit16 : 1;
            }bit;
        } sds3X;

        uint16_t sds4X;

        uint16_t pressure;                      // Давление(коррекция)

        uint16_t flash_page;                    // Номер используемой страницы FLASH
        uint16_t flash_block;                   // Номер используемогог блока FLASH

        uint16_t _reserve1;

        int16_t rudder_trim_pos;
        int16_t ailerons_trim_pos;
        int16_t elevator_trim_pos;

        uint16_t battery_current;               // Ток аккумулятора
        uint16_t battery_voltage;               // Напряжение аккумулятора
        uint16_t generator_current;             // Ток генератора
        uint16_t generator_voltage;             // Напряжение генератора

        uint16_t oil_pressure;                  // Давление масла
        uint16_t fuel_pressure;                 // Давление топлива
        uint16_t fuel_consumption;              // Расход топлива
        int16_t oil_temperature;                // Температура масла
        uint16_t fuel_rem_l;                    // Остаток топлива в левом баке
        uint16_t fuel_rem_r;                    // Остаток топлива в правом баке
        uint16_t engine_torque;                 // Значение крутящего момента/шага винта
        uint16_t engine_rate;                   // Значение оборотов двигателя
        uint16_t engine_exhaust_temperature;    // Температура выходящих газов двигателя
        uint16_t flaps_position;                // Положение закрылков
        uint16_t oil_radiator_position;         // Положение створки маслорадиатора

        int16_t alpha;                          // Расчетный угол атаки
        int16_t alpha_min;                      // Угол атаки минимально допустимый
        int16_t alpha_max;                      // Угол атаки максимально допустимый
        int16_t ny_min;                         // Перегрузка минимально допустимая
        int16_t ny_max;                         // Перегрузка максимально допустимая
        uint16_t speed_min;                     // Скорость минимально допустимая
        uint16_t speed_max;                     // Скорость максимально допустимая
        uint16_t fuel_rem;                      // Общий остаток топлива
        int16_t rudder_position;                // Положение руля направления
        int16_t ailerons_position;              // Положение элеронов
        int16_t elevator_position;              // Положение руля высоты
        int16_t slide_position;                 // Положение шарика скольжения(боковая перегрузка)

        int16_t adjust_course_value;
        int16_t adjust_pitch_value;
        int16_t adjust_roll_value;

        int16_t Nz_filter;
        int16_t Ny_filter;
        int16_t Vy_filter;
        int16_t Alpha_filter;
        int16_t air_temperature;

        uint32_t _reserve3;

        uint32_t cnt_ispr;      /*Счетчик исправности*/
        uint32_t crc_pack;      /*Контрольная сумма пакета*/
    };

#pragma pack(pop)
#endif
