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