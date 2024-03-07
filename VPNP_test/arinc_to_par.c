#include "arinc_to_par.h"
#include "const_sys.h"

#include <stdint.h>

void arinc_dk_to_par(struct ARINC_PAR *par);

float LimUpDn(IN const float x,      /* входной сигнал      */            /* # LimUpDn_ # */
                 IN const float max,    /* верхнее ограничение */            /* # LimUpDn_ # */
                 IN const float min)    /* нижнее ограничение  */            /* # LimUpDn_ # */
{                                                                               /* # LimUpDn_begin # */
    // float out = 0.0f;    /* выходной ограниченный сигнал */                  /* # LimUpDn_ # */
    // if (x < min)  /* входной сигнал меньше нижнего ограничения ? */           /* # LimUpDn_ # */
    // {               /* да */                                                    /* # LimUpDn_ # */
    //     out = min;      /* ограничение выходного сигнала снизу */               /* # LimUpDn_ # */
    // }                                                                           /* # LimUpDn_ # */
    // else            /* нет */                                                   /* # LimUpDn_ # */
    // {                                                                           /* # LimUpDn_ # */
    //     if (x > max)  /* входной сигнал больше верхнего ограничения ? */      /* # LimUpDn_ # */
    //     {               /* да */                                                /* # LimUpDn_ # */
    //         out = max;      /* ограничение выходного сигнала сверху */          /* # LimUpDn_ # */
    //     }                                                                       /* # LimUpDn_ # */
    //     else            /* нет */                                               /* # LimUpDn_ # */
    //     {                   /* входной сигнал внутри ограничения */             /* # LimUpDn_ # */
    //         out = x;        /* на выход сам сигнал */                           /* # LimUpDn_ # */
    //     }                                                                       /* # LimUpDn_ # */
    // }                                                                           /* # LimUpDn_ # */
    // return out;     /* на выход ограниченное значение */                        /* # LimUpDn_ # */
	return x;
}  

//--------------------------------------------------------
void arinc_dk_to_par(struct ARINC_PAR *par)
{// программа ввода параметра из зон ARINC по адресу параметра

  uint32_t  i, mask_low, mask_typ, matr,otkaz, j0, cnt, sum;
  float out;

  matr = par->out & (bit_29|bit_30) ;//выделим матрицу в 30 и 31-м разрядах

  otkaz = 0;
  sum = 0;



//---------------проверяем по биту четности--------------
    // Посчитаем биты  слова
    j0 = par->out;
    for (cnt = 0; cnt < 31; cnt++)
    {
	    sum += (j0 & 0x0001); j0 = j0>>1;
    }

  	if ((sum & 0x1) == (1&&(par->out&bit_31)) )
	{
		 otkaz |= bit_1;	  // Отказ по биту четности
	}

//---------------проверяем по адресу--------------
// Проверка по адресу
  	uint16_t out_adr = 0;
  	out_adr = par->out&0xff;
	if (out_adr != par->adr)
	{
		otkaz |= bit_2;	  //отказ параметра по адресу
	}


   	//if ((par->out&0xff) != par->adr)
	//{
	//	 otkaz |= bit_2;	  //отказ параметра по адресу
	//}
//---------------проверяем по матрице если нет отказов--------------
// //формируем отказы по матрице
//   switch (matr)
//   {
//   	  case 0://матрица 00
//   	  	  	if (par->ar_type == 3)
//   	  		{//для изм3 параметр неисправен
// 				otkaz |= bit_0;	  //отказ параметра по матрице
// 			}
// 	  break;
//   	  case bit_29://матрица 01: 0-в 31, 1 в 30
//   	  	  	if (par->ar_type == 3)
//   	  		{//для изм3 данные недостоверны
// 				otkaz |= bit_4; //нет вычисленных данных по матрице
// 			}
// 			else
// 			{//для изм2
// //				if (!(FlgRzmNTK == 1))
// //				{//если НК нет - отказ параметра
// //					otkaz |= bit_0;	  //отказ параметра по матрице
// //				}
// 			}
// 	  break;
//   	  case bit_30://матрица 10: 1 в 31, 0 в 30
//   	  	if (par->ar_type == 3)
//   	  	{//для изм3
// //				    if (!(FlgRzmNTK == 1 ))
// //				    {//если НК нет - отказ параметра
// //				    	otkaz |= bit_0;	  //отказ параметра по матрице
// //				    }

// 			  }
// 			else
// 			{//для изм2 данные недостоверны
// 				otkaz |= bit_4; //нет вычисленных данных по матрице
// 			}
// 	  break;
//   }//end switch

 //if (otkaz != 0)
  if (1 == 2)
 {//есть отказная ситуация
 	// par->sboi += 1.0f;
 //	if (par->cnt >= par->Col)
//	{//отказ в течении контрольного времени
		par->otkaz = otkaz;
	//}
//	else
//	{
	//	par->cnt = par->cnt + 1;
//	}
 }
 else
 {//нет отказной ситуации формируем целочисленный параметр и физический - снимаем отказ сразу
	//определим маску для очистки битов матрицы по типу изм2 или изм3
	if (par->ar_type==3) mask_typ = 0x1fffff00; else mask_typ = 0x3fffff00;//у изм2 младший бит матрицы оставляем как знак
	//определим маску для очистки битов, которые меньше младшего до адреса
    mask_low =0;
    i = 8;
	while (i < par->low_bit) {mask_low = (mask_low<<1) + bit_8; i++;}

	// par->ipar = ((par->out&mask_typ)&(~mask_low))<<(31-par->hi_bit); // формируем 32 разрядное знаковое слово - очищаем бит четности, матрицу, адрес, незназащие биты до младшего значащего - и все это сдвигаем в 31 разряд (считая от нуля),
  	  																								//при этом беззнаковое положительное число по протоколу (ст бит = 29) станет псевдо знаковым, просто всегда положительным
  	  																								// и масштаб тогда для всех будет равен {(цена ст. бита)*2 / 2^^31}
	par->ipar = ((int)((par->out&mask_typ)<<(3)) >> (3+par->low_bit));

	out = (float)par->ipar * par->mas;
	par->par = LimUpDn(out, par->max, par->min);
 	par->otkaz = 0;
 	// par->cnt = 0;
 }
 
	return;
}
