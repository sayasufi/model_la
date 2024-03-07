
#ifndef ARINC_PAR_DEFINES_H_
#define ARINC_PAR_DEFINES_H_



#include "stdint.h"







/*******************************************************************/
/*                              INPUT                              */
/*******************************************************************/


/*******************************************************************/
/*                              OUTPUT                             */
/*******************************************************************/



/*
№ разряда	32	31, 30	29…11	10, 9	8…1
Состав слова	Признак четности кода	Матрица состояния	Данные	Данные или идентиф. источника	Адрес
мл..ст
*/

/*Счетчик посылок P1*/
#define AR_OUT_CNT_P1               0155
#define AR_OUT_CNT_P1_LOW_BIT       32-3-16 
#define AR_OUT_CNT_P1_MASS          1
#define AR_OUT_CNT_P1_MIN           0
#define AR_OUT_CNT_P1_MAX           32767
#define AR_OUT_CNT_P1_TEST_VALUE    32767 
#define AR_OUT_CNT_P1_AR_TYPE       0

/*Слово состояния 1*/
#define AR_OUT_SDS_1_P1_ADR            0277
#define AR_OUT_SDS_1_P1_LOW_BIT        32-3-19 
#define AR_OUT_SDS_1_P1_TEST_VALUE     0x9999
#define AR_OUT_SDS_1_P1_AR_TYPE        0

/*Слово состояния 2*/
#define AR_OUT_SDS_2_P1_ADR            0270
#define AR_OUT_SDS_2_P1_LOW_BIT        32-3-19
#define AR_OUT_SDS_2_P1_TEST_VALUE     0x9999
#define AR_OUT_SDS_2_P1_AR_TYPE        0

/*Слово состояния 3*/
#define AR_OUT_SDS_3_P1_ADR            0271
#define AR_OUT_SDS_3_P1_LOW_BIT        32-3-19  
#define AR_OUT_SDS_3_P1_TEST_VALUE     0x9999
#define AR_OUT_SDS_3_P1_AR_TYPE        0

/*Слово состояния 4*/
#define AR_OUT_SDS_4_P1_ADR            0272
#define AR_OUT_SDS_4_P1_LOW_BIT        32-3-19 
#define AR_OUT_SDS_4_P1_TEST_VALUE     0x9999
#define AR_OUT_SDS_4_P1_AR_TYPE        0

/*Слово состояния 5*/
#define AR_OUT_SDS_5_P1_ADR            0273
#define AR_OUT_SDS_5_P1_LOW_BIT        32-3-19
#define AR_OUT_SDS_5_P1_TEST_VALUE     0x9999 
#define AR_OUT_SDS_5_P1_AR_TYPE        0

/*Угол тангажа*/
#define AR_OUT_PITCH_ADR            0324
#define AR_OUT_PITCH_LOW_BIT        32-3-1-14
#define AR_OUT_PITCH_MASS           0.011f
#define AR_OUT_PITCH_MIN            -90
#define AR_OUT_PITCH_MAX            90
#define AR_OUT_PITCH_TEST_VALUE     5.0f
#define AR_OUT_PITCH_AR_TYPE        0

/*  Угол крена */
#define AR_OUT_ROLL_ADR             0325
#define AR_OUT_ROLL_LOW_BIT         32-3-1-14
#define AR_OUT_ROLL_MASS            0.011f
#define AR_OUT_ROLL_MIN             -180
#define AR_OUT_ROLL_MAX             180
#define AR_OUT_ROLL_TEST_VALUE      45.0f
#define AR_OUT_ROLL_AR_TYPE         0

/*Магнитный курс*/
#define AR_OUT_COURSE_MAG_ADR           0320
#define AR_OUT_COURSE_MAG_LOW_BIT       32-3-1-15  
#define AR_OUT_COURSE_MAG_MASS          0.0055f
#define AR_OUT_COURSE_MAG_MIN           0
#define AR_OUT_COURSE_MAG_MAX           360
#define AR_OUT_COURSE_MAG_TEST_VALUE    15.0f
#define AR_OUT_COURSE_MAG_AR_TYPE       0

/* Магнитный путевой угол*/
#define AR_OUT_COURSE_TRACK_MAG_ADR         0317
#define AR_OUT_COURSE_TRACK_MAG_LOW_BIT     32-3-1-15  
#define AR_OUT_COURSE_TRACK_MAG_MASS        0.0055f
#define AR_OUT_COURSE_TRACK_MAG_MIN         0
#define AR_OUT_COURSE_TRACK_MAG_MAX         360
#define AR_OUT_COURSE_TRACK_MAG_TEST_VALUE  5.0f
#define AR_OUT_COURSE_TRACK_MAG_AR_TYPE     0

/* Истинный курс 314*/
#define AR_OUT_COURSE_TRUE_ADR           0314
#define AR_OUT_COURSE_TRUE_LOW_BIT       32-3-1-15  
#define AR_OUT_COURSE_TRUE_MASS          0.0055f
#define AR_OUT_COURSE_TRUE_MIN           0
#define AR_OUT_COURSE_TRUE_MAX           360
#define AR_OUT_COURSE_TRUE_TEST_VALUE    10.0f
#define AR_OUT_COURSE_TRUE_AR_TYPE       0

/*Гироскопический курс 	334; */
#define AR_OUT_COURSE_GYRO_ADR           0334
#define AR_OUT_COURSE_GYRO_LOW_BIT       32-3-1-11  
#define AR_OUT_COURSE_GYRO_MASS          0.09f
#define AR_OUT_COURSE_GYRO_MIN           0
#define AR_OUT_COURSE_GYRO_MAX           360
#define AR_OUT_COURSE_GYRO_TEST_VALUE    22.5f
#define AR_OUT_COURSE_GYRO_AR_TYPE       0

/*  Угловая скорость тангажа */
#define AR_OUT_W_X_ADR             0336
#define AR_OUT_W_X_LOW_BIT         32-3-1-16  
#define AR_OUT_W_X_MASS            0.015f
#define AR_OUT_W_X_MIN             -512
#define AR_OUT_W_X_MAX             512
#define AR_OUT_W_X_TEST_VALUE      10
#define AR_OUT_W_X_AR_TYPE         0

/*  Угловая скорость крена */
#define AR_OUT_W_Y_ADR             0337
#define AR_OUT_W_Y_LOW_BIT         32-3-1-16  
#define AR_OUT_W_Y_MASS            0.015f
#define AR_OUT_W_Y_MIN             -512
#define AR_OUT_W_Y_MAX             512
#define AR_OUT_W_Y_TEST_VALUE      10
#define AR_OUT_W_Y_AR_TYPE         0

/*  Угловая скорость рысканья */
#define AR_OUT_W_Z_ADR             0330
#define AR_OUT_W_Z_LOW_BIT         32-3-1-16  
#define AR_OUT_W_Z_MASS            0.015f
#define AR_OUT_W_Z_MIN             -512
#define AR_OUT_W_Z_MAX             512
#define AR_OUT_W_Z_TEST_VALUE      10
#define AR_OUT_W_Z_AR_TYPE         0

/*Продольное ускорение*/
#define AR_OUT_N_X_ADR             0331
#define AR_OUT_N_X_LOW_BIT         32-3-1-14  
#define AR_OUT_N_X_MASS            0.001f
#define AR_OUT_N_X_MIN             -8
#define AR_OUT_N_X_MAX             8
#define AR_OUT_N_X_TEST_VALUE      0.02f
#define AR_OUT_N_X_AR_TYPE         0

 /* Боковое ускорение*/
#define AR_OUT_N_Y_ADR             0332
#define AR_OUT_N_Y_LOW_BIT         32-3-1-14  
#define AR_OUT_N_Y_MASS            0.001
#define AR_OUT_N_Y_MIN             -8
#define AR_OUT_N_Y_MAX             8
#define AR_OUT_N_Y_TEST_VALUE      0.01f
#define AR_OUT_N_Y_AR_TYPE         0

/*Нормальное ускорение*/ 
#define AR_OUT_N_Z_ADR             0333
#define AR_OUT_N_Z_LOW_BIT         32-3-1-14  
#define AR_OUT_N_Z_MASS            0.001f
#define AR_OUT_N_Z_MIN             -8
#define AR_OUT_N_Z_MAX             8
#define AR_OUT_N_Z_TEST_VALUE      0.01f
#define AR_OUT_N_Z_AR_TYPE         0

/*Географические координаты широта старшая часть	010 */
#define AR_OUT_B_CLX_HEAD_ADR             010
#define AR_OUT_B_CLX_HEAD_LOW_BIT         32-3-1-20  
#define AR_OUT_B_CLX_HEAD_MASS            0.000172f
#define AR_OUT_B_CLX_HEAD_MIN             -90
#define AR_OUT_B_CLX_HEAD_MAX             90
#define AR_OUT_B_CLX_HEAD_TEST_VALUE      22.5f
#define AR_OUT_B_CLX_HEAD_AR_TYPE         0

/*Географические координаты долгота старшая часть 	011 */
#define AR_OUT_L_CLX_HEAD_ADR             011
#define AR_OUT_L_CLX_HEAD_LOW_BIT         32-3-1-20  
#define AR_OUT_L_CLX_HEAD_MASS            0.000172f
#define AR_OUT_L_CLX_HEAD_MIN             -180
#define AR_OUT_L_CLX_HEAD_MAX             180
#define AR_OUT_L_CLX_HEAD_TEST_VALUE      22.5f
#define AR_OUT_L_CLX_HEAD_AR_TYPE         0

/*Географические координаты широта младшая часть */
#define AR_OUT_B_CLX_TAIL_ADR       0310
#define AR_OUT_B_CLX_TAIL_LOW_BIT   32-3-1-11 
#define AR_OUT_B_CLX_TAIL_MASS      0.0000000838
#define AR_OUT_B_CLX_TAIL_MIN       0
#define AR_OUT_B_CLX_TAIL_MAX       0.000172
#define AR_OUT_B_CLX_TAIL_TEST_VALUE     0
#define AR_OUT_B_CLX_TAIL_AR_TYPE   0

/*Географические координаты долгота младшая часть */
#define AR_OUT_L_CLX_TAIL_ADR           0311
#define AR_OUT_L_CLX_TAIL_LOW_BIT       32-3-1-11 
#define AR_OUT_L_CLX_TAIL_MASS          0.0000000838
#define AR_OUT_L_CLX_TAIL_MIN           0
#define AR_OUT_L_CLX_TAIL_MAX           0.000172
#define AR_OUT_L_CLX_TAIL_TEST_VALUE    0
#define AR_OUT_L_CLX_TAIL_AR_TYPE       0


/*Комплексная высота полета(362 !!!) */
#define AR_OUT_H_CMPLX_ADR           0362
#define AR_OUT_H_CMPLX_LOW_BIT       32-3-1-18 
#define AR_OUT_H_CMPLX_MASS          0.1524f
#define AR_OUT_H_CMPLX_MIN           -39951
#define AR_OUT_H_CMPLX_MAX           39951
#define AR_OUT_H_CMPLX_TEST_VALUE    3048
#define AR_OUT_H_CMPLX_AR_TYPE       0


/*Инерциальная высота полета(361) */
#define AR_OUT_H_OTN_ADR           0363
#define AR_OUT_H_OTN_LOW_BIT       32-3-1-18 
#define AR_OUT_H_OTN_MASS          0.1524f
#define AR_OUT_H_OTN_MIN           -39951
#define AR_OUT_H_OTN_MAX           39951
#define AR_OUT_H_OTN_TEST_VALUE    3048
#define AR_OUT_H_OTN_AR_TYPE       0

/*Инерциальная высота полета(361) */
/*
#define AR_OUT_H_INER_ADR           0361
#define AR_OUT_H_INER_LOW_BIT       32-3-1-18 
#define AR_OUT_H_INER_MASS          0.1524f
#define AR_OUT_H_INER_MIN           -39951
#define AR_OUT_H_INER_MAX           39951
#define AR_OUT_H_INER_TEST_VALUE    3048
#define AR_OUT_H_INER_AR_TYPE       0
*/

/* Вертикальное ускорение; 364;*/
#define AR_OUT_A_VERT_ADR           0364
#define AR_OUT_A_VERT_LOW_BIT       32-3-1-14
#define AR_OUT_A_VERT_MASS          0.001f
#define AR_OUT_A_VERT_MIN           -8
#define AR_OUT_A_VERT_MAX           8
#define AR_OUT_A_VERT_TEST_VALUE    0.1
#define AR_OUT_A_VERT_AR_TYPE       0


/* Вертикальная скорость 360*/
#define AR_OUT_SPEED_VERT_ADR           0365
#define AR_OUT_SPEED_VERT_LOW_BIT       32-3-1-15
#define AR_OUT_SPEED_VERT_MASS          0.00508f
#define AR_OUT_SPEED_VERT_MIN           -168
#define AR_OUT_SPEED_VERT_MAX           168
#define AR_OUT_SPEED_VERT_TEST_VALUE    -3
#define AR_OUT_SPEED_VERT_AR_TYPE       0

/* Инерциальная вертикальная скорость(365)*/
/*
#define AR_OUT_SPEED_VERT_INER_ADR           0365
#define AR_OUT_SPEED_VERT_INER_LOW_BIT       32-3-1-15
#define AR_OUT_SPEED_VERT_INER_MASS          0.00508f
#define AR_OUT_SPEED_VERT_INER_MIN           -168
#define AR_OUT_SPEED_VERT_INER_MAX           168
#define AR_OUT_SPEED_VERT_INER_TEST_VALUE    -3
#define AR_OUT_SPEED_VERT_INER_AR_TYPE       0
*/
/*Потенциальная вертикальная скорость 360*/
#define AR_OUT_SPEED_VERT_POT_ADR           0360
#define AR_OUT_SPEED_VERT_POT_LOW_BIT       32-3-1-15
#define AR_OUT_SPEED_VERT_POT_MASS          0.00508f
#define AR_OUT_SPEED_VERT_POT_MIN           -168
#define AR_OUT_SPEED_VERT_POT_MAX           168
#define AR_OUT_SPEED_VERT_POT_TEST_VALUE    -3
#define AR_OUT_SPEED_VERT_POT_AR_TYPE       0

/*Путевая скорость N/S  373*/
#define AR_OUT_V_NORTH_ADR           0373
#define AR_OUT_V_NORTH_LOW_BIT       32-3-1-14
#define AR_OUT_V_NORTH_MASS          0.2315f
#define AR_OUT_V_NORTH_MIN           -1800
#define AR_OUT_V_NORTH_MAX           1800
#define AR_OUT_V_NORTH_TEST_VALUE    102
#define AR_OUT_V_NORTH_AR_TYPE       0

/*Путевая скорость E/W  374*/ 
#define AR_OUT_V_EAST_ADR           0374
#define AR_OUT_V_EAST_LOW_BIT       32-3-1-14
#define AR_OUT_V_EAST_MASS          0.2315f
#define AR_OUT_V_EAST_MIN           -1800
#define AR_OUT_V_EAST_MAX           1800
#define AR_OUT_V_EAST_TEST_VALUE    102
#define AR_OUT_V_EAST_AR_TYPE       0

/*Путевая скорость 312*/
#define AR_OUT_SPEED_TRACK_ADR           0312
#define AR_OUT_SPEED_TRACK_LOW_BIT       32-3-1-14
#define AR_OUT_SPEED_TRACK_MASS          0.2315f
#define AR_OUT_SPEED_TRACK_MIN           0
#define AR_OUT_SPEED_TRACK_MAX           1800
#define AR_OUT_SPEED_TRACK_TEST_VALUE    102
#define AR_OUT_SPEED_TRACK_AR_TYPE       0

/*Ускорение вдоль траектории полета (323) */
#define AR_OUT_A_COURSE_ADR           0323
#define AR_OUT_A_COURSE_LOW_BIT       32-3-1-14
#define AR_OUT_A_COURSE_MASS          0.001f
#define AR_OUT_A_COURSE_MIN           -8
#define AR_OUT_A_COURSE_MAX           8
#define AR_OUT_A_COURSE_TEST_VALUE    0.1f
#define AR_OUT_A_COURSE_AR_TYPE       0

/*Угол наклона траектории(322)*/
#define AR_OUT_TRAJ_SLOPE_ADR           0322
#define AR_OUT_TRAJ_SLOPE_LOW_BIT       32-3-1-11  
#define AR_OUT_TRAJ_SLOPE_MASS          0.09f
#define AR_OUT_TRAJ_SLOPE_MIN           -180
#define AR_OUT_TRAJ_SLOPE_MAX           180
#define AR_OUT_TRAJ_SLOPE_TEST_VALUE    -5
#define AR_OUT_TRAJ_SLOPE_AR_TYPE       0

/*Угол сноса(321)*/
#define AR_OUT_DRIFT_ANGLE_ADR           0321
#define AR_OUT_DRIFT_ANGLE_LOW_BIT       32-3-1-11  
#define AR_OUT_DRIFT_ANGLE_MASS          0.09f
#define AR_OUT_DRIFT_ANGLE_MIN           -180
#define AR_OUT_DRIFT_ANGLE_MAX           180
#define AR_OUT_DRIFT_ANGLE_TEST_VALUE    -10
#define AR_OUT_DRIFT_ANGLE_AR_TYPE       0

/*Скорость ветра (315)*/
#define AR_OUT_WIND_SPEED_ADR           0315
#define AR_OUT_WIND_SPEED_LOW_BIT       32-3-1-14 
#define AR_OUT_WIND_SPEED_MASS          0.2315f
#define AR_OUT_WIND_SPEED_MIN           0
#define AR_OUT_WIND_SPEED_MAX           1800
#define AR_OUT_WIND_SPEED_TEST_VALUE    51
#define AR_OUT_WIND_SPEED_AR_TYPE       0


/*Магнитное направление ветра(372)*/
/*
#define AR_OUT_WIND_ANGLE_MAG_ADR           0372
#define AR_OUT_WIND_ANGLE_MAG_LOW_BIT       32-3-1-8 
#define AR_OUT_WIND_ANGLE_MAG_MASS          0.7f
#define AR_OUT_WIND_ANGLE_MAG_MIN           -180
#define AR_OUT_WIND_ANGLE_MAG_MAX           180
#define AR_OUT_WIND_ANGLE_MAG_TEST_VALUE    30
#define AR_OUT_WIND_ANGLE_MAG_AR_TYPE       0
*/
/*Мультиплексор СНС_1	 	301*/
/*
#define AR_OUT_MULT_SNS_1_ADR            0301
#define AR_OUT_MULT_SNS_1_LOW_BIT        32-3-19
#define AR_OUT_MULT_SNS_1_TEST_VALUE     0x9999
#define AR_OUT_MULT_SNS_1_AR_TYPE        0
*/
/*Мультиплексор СНС_2 		302*/
/*
#define AR_OUT_MULT_SNS_2_ADR            0302
#define AR_OUT_MULT_SNS_2_LOW_BIT        32-3-19
#define AR_OUT_MULT_SNS_2_TEST_VALUE     0x9999
#define AR_OUT_MULT_SNS_2_AR_TYPE        0
*/

/*Мультиплексор ТЕХН 		303*/
#define AR_OUT_MULT_TXT_ADR            0303
#define AR_OUT_MULT_TXT_LOW_BIT        32-3-19
#define AR_OUT_MULT_TXT_TEST_VALUE     0x9999
#define AR_OUT_MULT_TXT_AR_TYPE        0

/*Время от включения 		005	*/
#define AR_OUT_TIME_ON_ADR           0005
#define AR_OUT_TIME_ON_LOW_BIT       32-3-1-17
#define AR_OUT_TIME_ON_MASS          1    
#define AR_OUT_TIME_ON_AR_TYPE       0


/*Время от начала навигации 006 */
#define AR_OUT_TIME_NAV_ADR           0006
#define AR_OUT_TIME_NAV_LOW_BIT       32-3-1-17
#define AR_OUT_TIME_NAV_MASS          1 
#define AR_OUT_TIME_NAV_AR_TYPE       0


/*Счетчик посылок P2*/
#define AR_OUT_CNT_P2_ADR               0155
#define AR_OUT_CNT_P2_LOW_BIT       32-3-16 
#define AR_OUT_CNT_P2_MASS          1
#define AR_OUT_CNT_P2_MIN           0
#define AR_OUT_CNT_P2_MAX           32767
#define AR_OUT_CNT_P2_TEST_VALUE    32767 
#define AR_OUT_CNT_P2_AR_TYPE       0



/*Слово состояния 1 p2*/
#define AR_OUT_SDS_1_P2_ADR            0001//0273
#define AR_OUT_SDS_1_P2_LOW_BIT        32-3-19 
#define AR_OUT_SDS_1_P2_TEST_VALUE     0x9999
#define AR_OUT_SDS_1_P2_AR_TYPE        0

/*Слово состояния 2 p2*/
#define AR_OUT_SDS_2_P2_ADR            0002//0274
#define AR_OUT_SDS_2_P2_LOW_BIT        32-3-19
#define AR_OUT_SDS_2_P2_TEST_VALUE     0x9999
#define AR_OUT_SDS_2_P2_AR_TYPE        0


/*абсолютная барометрическая высота    (362 !!!) */
#define AR_OUT_H_ABS_ADR           0362
#define AR_OUT_H_ABS_LOW_BIT       32-3-1-18 
#define AR_OUT_H_ABS_MASS          0.1524f
#define AR_OUT_H_ABS_MIN           -39951
#define AR_OUT_H_ABS_MAX           39951
#define AR_OUT_H_ABS_TEST_VALUE    3048
#define AR_OUT_H_ABS_AR_TYPE       0

/*относительная баровысота (коррекция по QNH) (362 !!!) */
#define AR_OUT_H_QNH_ADR           0362
#define AR_OUT_H_QNH_LOW_BIT       32-3-1-18 
#define AR_OUT_H_QNH_MASS          0.1524f
#define AR_OUT_H_QNH_MIN           -39951
#define AR_OUT_H_QNH_MAX           39951
#define AR_OUT_H_QNH_TEST_VALUE    3048
#define AR_OUT_H_QNH_AR_TYPE       0

/*относительная баровысота (коррекция по QFE) (362 !!!) */
#define AR_OUT_H_QFE_ADR           0362
#define AR_OUT_H_QFE_LOW_BIT       32-3-1-18 
#define AR_OUT_H_QFE_MASS          0.1524f
#define AR_OUT_H_QFE_MIN           -39951
#define AR_OUT_H_QFE_MAX           39951
#define AR_OUT_H_QFE_TEST_VALUE    3048
#define AR_OUT_H_QFE_AR_TYPE       0

/* истинная (воздушная) скорость свс */
#define AR_OUT_AIR_SPEED_TRUE_SVS_ADR           0315
#define AR_OUT_AIR_SPEED_TRUE_SVS_LOW_BIT       32-3-1-14 
#define AR_OUT_AIR_SPEED_TRUE_SVS_MASS          0.2315f
#define AR_OUT_AIR_SPEED_TRUE_SVS_MIN           0
#define AR_OUT_AIR_SPEED_TRUE_SVS_MAX           1800
#define AR_OUT_AIR_SPEED_TRUE_SVS_TEST_VALUE    51
#define AR_OUT_AIR_SPEED_TRUE_SVS_AR_TYPE       0

/* приборная скорость  свс    */
#define AR_OUT_AIR_SPEED_PRIB_SVS_ADR           0315
#define AR_OUT_AIR_SPEED_PRIB_SVS_LOW_BIT       32-3-1-14 
#define AR_OUT_AIR_SPEED_PRIB_SVS_MASS          0.2315f
#define AR_OUT_AIR_SPEED_PRIB_SVS_MIN           0
#define AR_OUT_AIR_SPEED_PRIB_SVS_MAX           1800
#define AR_OUT_AIR_SPEED_PRIB_SVS_TEST_VALUE    51
#define AR_OUT_AIR_SPEED_PRIB_SVS_AR_TYPE       0

/* вертикальная скорость свс  360*/
#define AR_OUT_SPEED_VERT_SVS_ADR           0360
#define AR_OUT_SPEED_VERT_SVS_LOW_BIT       32-3-1-15
#define AR_OUT_SPEED_VERT_SVS_MASS          0.00508f
#define AR_OUT_SPEED_VERT_SVS_MIN           -168
#define AR_OUT_SPEED_VERT_SVS_MAX           168
#define AR_OUT_SPEED_VERT_SVS_TEST_VALUE    -3
#define AR_OUT_SPEED_VERT_SVS_AR_TYPE       0


/* число Маха полета    364;*/
#define AR_OUT_M_SVS_ADR           0364
#define AR_OUT_M_SVS_LOW_BIT       32-3-1-14
#define AR_OUT_M_SVS_MASS          0.001f
#define AR_OUT_M_SVS_MIN           -8
#define AR_OUT_M_SVS_MAX           8
#define AR_OUT_M_SVS_TEST_VALUE    0.1
#define AR_OUT_M_SVS_AR_TYPE       0


/* температура наружного воздуха              [°С] */
#define AR_OUT_TEMP_H_ADR           0360
#define AR_OUT_TEMP_H_LOW_BIT       32-3-1-15
#define AR_OUT_TEMP_H_MASS          0.00508f
#define AR_OUT_TEMP_H_MIN           -168
#define AR_OUT_TEMP_H_MAX           168
#define AR_OUT_TEMP_H_TEST_VALUE    -3
#define AR_OUT_TEMP_H_AR_TYPE       0


/* температура торможения                     [°С] */
#define AR_OUT_TEMP_R_ADR           0360
#define AR_OUT_TEMP_R_LOW_BIT       32-3-1-15
#define AR_OUT_TEMP_R_MASS          0.00508f
#define AR_OUT_TEMP_R_MIN           -168
#define AR_OUT_TEMP_R_MAX           168
#define AR_OUT_TEMP_R_TEST_VALUE    -3
#define AR_OUT_TEMP_R_AR_TYPE       0


/* скоростной напор                 [°С] */
#define AR_OUT_Q_ADR           0360
#define AR_OUT_Q_LOW_BIT       32-3-1-15
#define AR_OUT_Q_MASS          0.00508f
#define AR_OUT_Q_MIN           -168
#define AR_OUT_Q_MAX           168
#define AR_OUT_Q_TEST_VALUE    -3
#define AR_OUT_Q_AR_TYPE       0


/* Полное давление  (362 !!!) */
#define AR_OUT_P_F_ADR           0362
#define AR_OUT_P_F_LOW_BIT       32-3-1-18 
#define AR_OUT_P_F_MASS          0.1524f
#define AR_OUT_P_F_MIN           -39951
#define AR_OUT_P_F_MAX           39951
#define AR_OUT_P_F_TEST_VALUE    3048
#define AR_OUT_P_F_AR_TYPE       0

/* статическое давление воздуха         [мм.рт.ст] */
#define AR_OUT_P_H_STAT_ADR           0362
#define AR_OUT_P_H_STAT_LOW_BIT       32-3-1-18 
#define AR_OUT_P_H_STAT_MASS          0.1524f
#define AR_OUT_P_H_STAT_MIN           -39951
#define AR_OUT_P_H_STAT_MAX           39951
#define AR_OUT_P_H_STAT_TEST_VALUE    3048
#define AR_OUT_P_H_STAT_AR_TYPE       0

/* температура датчика давления воздуха Д1     [°С] */
#define AR_OUT_TD1_ADR           0360
#define AR_OUT_TD1_LOW_BIT       32-3-1-15
#define AR_OUT_TD1_MASS          0.00508f
#define AR_OUT_TD1_MIN           -168
#define AR_OUT_TD1_MAX           168
#define AR_OUT_TD1_TEST_VALUE    -3
#define AR_OUT_TD1_AR_TYPE       0

/* температура датчика давления воздуха Д2            [°С] */
#define AR_OUT_TD2_ADR           0360
#define AR_OUT_TD2_LOW_BIT       32-3-1-15
#define AR_OUT_TD2_MASS          0.00508f
#define AR_OUT_TD2_MIN           -168
#define AR_OUT_TD2_MAX           168
#define AR_OUT_TD2_TEST_VALUE    -3
#define AR_OUT_TD2_AR_TYPE       0


/*Счетчик посылок P3*/
#define AR_OUT_CNT_P3_ADR           0155
#define AR_OUT_CNT_P3_LOW_BIT       32-3-16
#define AR_OUT_CNT_P3_MASS          1 
#define AR_OUT_CNT_P3_MIN           0
#define AR_OUT_CNT_P3_MAX           32767
#define AR_OUT_CNT_P3_TEST_VALUE    32767 
#define AR_OUT_CNT_P3_AR_TYPE       0


/*Слово состояния 1*/
#define AR_OUT_SDS_1_P3_ADR            0277
#define AR_OUT_SDS_1_P3_LOW_BIT        32-3-19 
#define AR_OUT_SDS_1_P3_TEST_VALUE     0x9999
#define AR_OUT_SDS_1_P3_AR_TYPE        0

/*Слово состояния 2*/
#define AR_OUT_SDS_2_P3_ADR            0270
#define AR_OUT_SDS_2_P3_LOW_BIT        32-3-19
#define AR_OUT_SDS_2_P3_TEST_VALUE     0x9999
#define AR_OUT_SDS_2_P3_AR_TYPE        0

/*Слово состояния 3*/
#define AR_OUT_SDS_3_P3_ADR            0271
#define AR_OUT_SDS_3_P3_LOW_BIT        32-3-19  
#define AR_OUT_SDS_3_P3_TEST_VALUE     0x9999
#define AR_OUT_SDS_3_P3_AR_TYPE        0


/*Показатель ухудшения горизонтальной точности HDOP*/
#define AR_OUT_HDOP_ADR             0101
#define AR_OUT_HDOP_DIGITS          15  
#define AR_OUT_HDOP_HIGH_BIT        29
#define AR_OUT_HDOP_LOW_BIT         32-3-1-15  
#define AR_OUT_HDOP_MASS            0.03125
#define AR_OUT_HDOP_MIN             0
#define AR_OUT_HDOP_MAX             1024
#define AR_OUT_HDOP_TEST_VALUE      10
#define AR_OUT_HDOP_AR_TYPE         0

/*Показатель ухудшения вертикальной точности VDOP*/
#define AR_OUT_VDOP_ADR             0102
#define AR_OUT_VDOP_DIGITS          15  
#define AR_OUT_VDOP_HIGH_BIT        29
#define AR_OUT_VDOP_LOW_BIT         32-3-1-15  
#define AR_OUT_VDOP_MASS            0.03125
#define AR_OUT_VDOP_MIN             0
#define AR_OUT_VDOP_MAX             1024
#define AR_OUT_VDOP_TEST_VALUE      20
#define AR_OUT_VDOP_AR_TYPE         0

/*Показатель ухудшения вертикальной точности PDOP*/
#define AR_OUT_PDOP_ADR             0102
#define AR_OUT_PDOP_DIGITS          15  
#define AR_OUT_PDOP_HIGH_BIT        29
#define AR_OUT_PDOP_LOW_BIT         32-3-1-15  
#define AR_OUT_PDOP_MASS            0.03125
#define AR_OUT_PDOP_MIN             0
#define AR_OUT_PDOP_MAX             1024
#define AR_OUT_PDOP_TEST_VALUE      20
#define AR_OUT_PDOP_AR_TYPE         0


/* Вертикальная скорость sns */
#define AR_OUT_SPEED_VERT_SNS_ADR           0365
#define AR_OUT_SPEED_VERT_SNS_LOW_BIT       32-3-1-15
#define AR_OUT_SPEED_VERT_SNS_MASS          0.00508f
#define AR_OUT_SPEED_VERT_SNS_MIN           -168
#define AR_OUT_SPEED_VERT_SNS_MAX           168
#define AR_OUT_SPEED_VERT_SNS_TEST_VALUE    -3
#define AR_OUT_SPEED_VERT_SNS_AR_TYPE       0




/*Путевая скорость 312*/
#define AR_OUT_SPEED_TRACK_SNS_ADR           0312
#define AR_OUT_SPEED_TRACK_SNS_LOW_BIT       32-3-1-14
#define AR_OUT_SPEED_TRACK_SNS_MASS          0.2315f
#define AR_OUT_SPEED_TRACK_SNS_MIN           0
#define AR_OUT_SPEED_TRACK_SNS_MAX           1800
#define AR_OUT_SPEED_TRACK_SNS_TEST_VALUE    102
#define AR_OUT_SPEED_TRACK_SNS_AR_TYPE       0


/*Путевая скорость N/S  373*/
#define AR_OUT_V_NORTH_SNS_ADR           0373
#define AR_OUT_V_NORTH_SNS_LOW_BIT       32-3-1-14
#define AR_OUT_V_NORTH_SNS_MASS          0.2315f
#define AR_OUT_V_NORTH_SNS_MIN           -1800
#define AR_OUT_V_NORTH_SNS_MAX           1800
#define AR_OUT_V_NORTH_SNS_TEST_VALUE    102
#define AR_OUT_V_NORTH_SNS_AR_TYPE       0

/*Путевая скорость E/W  374*/ 
#define AR_OUT_V_EAST_SNS_ADR           0374
#define AR_OUT_V_EAST_SNS_LOW_BIT       32-3-1-14
#define AR_OUT_V_EAST_SNS_MASS          0.2315f
#define AR_OUT_V_EAST_SNS_MIN           -1800
#define AR_OUT_V_EAST_SNS_MAX           1800
#define AR_OUT_V_EAST_SNS_TEST_VALUE    102
#define AR_OUT_V_EAST_SNS_AR_TYPE       0



/* путевой угол*/
#define AR_OUT_COURSE_TRACK_SNS_ADR         0317
#define AR_OUT_COURSE_TRACK_SNS_LOW_BIT     32-3-1-15  
#define AR_OUT_COURSE_TRACK_SNS_MASS        0.0055f
#define AR_OUT_COURSE_TRACK_SNS_MIN         0
#define AR_OUT_COURSE_TRACK_SNS_MAX         360
#define AR_OUT_COURSE_TRACK_SNS_TEST_VALUE  5.0f
#define AR_OUT_COURSE_TRACK_SNS_AR_TYPE     0

/*высота СНС [м] */
#define AR_OUT_H_SNS_ADR           0362
#define AR_OUT_H_SNS_LOW_BIT       32-3-1-18 
#define AR_OUT_H_SNS_MASS          0.1524f
#define AR_OUT_H_SNS_MIN           -39951
#define AR_OUT_H_SNS_MAX           39951
#define AR_OUT_H_SNS_TEST_VALUE    3048
#define AR_OUT_H_SNS_AR_TYPE       0



/*Географические координаты широта старшая часть	010 */
#define AR_OUT_B_CLX_SNS_HEAD_ADR             010
#define AR_OUT_B_CLX_SNS_HEAD_LOW_BIT         32-3-1-20  
#define AR_OUT_B_CLX_SNS_HEAD_MASS            0.000172f
#define AR_OUT_B_CLX_SNS_HEAD_MIN             -90
#define AR_OUT_B_CLX_SNS_HEAD_MAX             90
#define AR_OUT_B_CLX_SNS_HEAD_TEST_VALUE      22.5f
#define AR_OUT_B_CLX_SNS_HEAD_AR_TYPE         0

/*Географические координаты долгота старшая часть 	011 */
#define AR_OUT_L_CLX_SNS_HEAD_ADR             011
#define AR_OUT_L_CLX_SNS_HEAD_LOW_BIT         32-3-1-20  
#define AR_OUT_L_CLX_SNS_HEAD_MASS            0.000172f
#define AR_OUT_L_CLX_SNS_HEAD_MIN             -180
#define AR_OUT_L_CLX_SNS_HEAD_MAX             180
#define AR_OUT_L_CLX_SNS_HEAD_TEST_VALUE      22.5f
#define AR_OUT_L_CLX_SNS_HEAD_AR_TYPE         0

/*Географические координаты широта младшая часть */
#define AR_OUT_B_CLX_SNS_TAIL_ADR       0310
#define AR_OUT_B_CLX_SNS_TAIL_LOW_BIT   32-3-1-11 
#define AR_OUT_B_CLX_SNS_TAIL_MASS      0.0000000838
#define AR_OUT_B_CLX_SNS_TAIL_MIN       0
#define AR_OUT_B_CLX_SNS_TAIL_MAX       0.000172
#define AR_OUT_B_CLX_SNS_TAIL_TEST_VALUE     0
#define AR_OUT_B_CLX_SNS_TAIL_AR_TYPE   0

/*Географические координаты долгота младшая часть */
#define AR_OUT_L_CLX_SNS_TAIL_ADR           0311
#define AR_OUT_L_CLX_SNS_TAIL_LOW_BIT       32-3-1-11 
#define AR_OUT_L_CLX_SNS_TAIL_MASS          0.0000000838
#define AR_OUT_L_CLX_SNS_TAIL_MIN           0
#define AR_OUT_L_CLX_SNS_TAIL_MAX           0.000172
#define AR_OUT_L_CLX_SNS_TAIL_TEST_VALUE    0
#define AR_OUT_L_CLX_SNS_TAIL_AR_TYPE       0



/*Текущее время*/
#define AR_OUT_ALT_CUR_UTC_TIME_ADR         0150
#define AR_OUT_ALT_CUR_UTC_TIME_DIGITS      17 
#define AR_OUT_ALT_CUR_UTC_TIME_MASS        1
#define AR_OUT_ALT_CUR_UTC_TIME_HIGH_BIT    29
#define AR_OUT_ALT_CUR_UTC_TIME_LOW_BIT     32-3-17
#define AR_OUT_ALT_CUR_UTC_TIME_MIN         0
#define AR_OUT_ALT_CUR_UTC_TIME_MAX         235959
#define AR_OUT_ALT_CUR_UTC_TIME_TEST_VALUE  0
#define AR_OUT_ALT_CUR_UTC_TIME_AR_TYPE     2

/*Текущая дата	ДДК [dd.mm.yy]*/
#define AR_OUT_CUR_DATE_ADR         0260
#define AR_OUT_CUR_DATE_LOW_BIT     32-3-18 
#define AR_OUT_CUR_DATE_AR_TYPE     0



#endif
