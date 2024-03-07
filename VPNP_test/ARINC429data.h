#pragma once
#include "stdint.h"
#pragma pack(push, 1)

namespace VPNPtest {

    union t429Word {
        struct {
            uint32_t ucLabel : 8;          /* Идентификатор типа данных */
            uint32_t ucSdi : 2;          /* Идентификаторы источника/назначения */
            uint32_t ulData : 19;         /* Основные данные */
            uint32_t ucStatus : 2;          /* Матрица состояния */
            uint32_t ucParity : 1;          /* Бит чётности */
        } Fields;
        uint32_t ul429Data; // must be exact size of tFields struct above
     };
    struct ARINC429values
    {
        t429Word t_pitch;
        t429Word t_roll;
        t429Word t_course_mag;
        t429Word t_course_track_mag;
        t429Word t_course_true;
        t429Word t_course_gyro;
        t429Word t_w_x;
        t429Word t_w_y;
        t429Word t_w_z;
        t429Word t_n_x;
        t429Word t_n_y;
        t429Word t_n_z;
        t429Word t_H_cmplx;
        t429Word t_H_otn;
        t429Word t_a_vert;
        t429Word t_speed_vert;
        t429Word t_speed_vert_pot;
        t429Word t_v_north;
        t429Word t_v_east;
        t429Word t_speed_track;
        t429Word t_a_course;
        t429Word t_traj_slope;
        t429Word t_drift_angle;
        t429Word t_wind_speed;
        t429Word t_H_abs;
        t429Word t_H_qnh;
        t429Word t_H_qfe;
        t429Word t_airspeed_true;
        t429Word t_airspeed_prib;
        t429Word t_speed_vert_svs;
    };

}
#pragma pack(pop)

