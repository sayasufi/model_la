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

/*идентификатор типа данных соответствует значениям,  описанным в дефайнах с суффиксами _ADR в файле arinc_par_defines.h*/
/* Идентификаторы источника/назначения  - ноль*/
/* Основные данные  - значение переменной, приведённое к множителю значения младшего разряда*/
/* Матрица состояния  - пока задавал значение "3"*/
/* Бит чётности  - высчитывается в следующей функции:*/
// Контроль чётности
UInt32 parity(uint32_t value)
{
  unsigned int parity = 0;

  for (int x = 0; x < 31; x++)
  {
   parity += (value & 0x0001); value = value >> 1;
  }
  if (parity & 0x1)
   return 1;
  else return 0;

}