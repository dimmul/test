#include "std_types.h"
#include "channel_converter.h"


/**
 * @brief Тип таблицы соответствия
 */
typedef struct
{
  uint16_t LogicChNum;  /// Логический номер канала (из ПИВа)
  uint16_t BrdNum;      /// Номер места платы
  uint16_t BrdChNum;    /// Номер канала на плате
} ChConvTable_t;


/**
 * @brief Таблица соответствия
 */
static const ChConvTable_t Table[] =
{
  {.LogicChNum = 1,   .BrdNum = 1,  .BrdChNum = 2},
  {.LogicChNum = 2,   .BrdNum = 2,  .BrdChNum = 2},
  {.LogicChNum = 3,   .BrdNum = 3,  .BrdChNum = 2},
  {.LogicChNum = 4,   .BrdNum = 5,  .BrdChNum = 2},
  {.LogicChNum = 5,   .BrdNum = 6,  .BrdChNum = 2},
  {.LogicChNum = 6,   .BrdNum = 7,  .BrdChNum = 2},
  {.LogicChNum = 7,   .BrdNum = 9,  .BrdChNum = 2},
  {.LogicChNum = 8,   .BrdNum = 10, .BrdChNum = 2},
  {.LogicChNum = 9,   .BrdNum = 11, .BrdChNum = 2},
  {.LogicChNum = 10,  .BrdNum = 4,  .BrdChNum = 2},
  {.LogicChNum = 11,  .BrdNum = 8,  .BrdChNum = 2},
  {.LogicChNum = 12,  .BrdNum = 12, .BrdChNum = 2},
  {.LogicChNum = 13,  .BrdNum = 1,  .BrdChNum = 1},
  {.LogicChNum = 14,  .BrdNum = 2,  .BrdChNum = 1},
  {.LogicChNum = 15,  .BrdNum = 3,  .BrdChNum = 1},
  {.LogicChNum = 16,  .BrdNum = 5,  .BrdChNum = 1},
  {.LogicChNum = 17,  .BrdNum = 6,  .BrdChNum = 1},
  {.LogicChNum = 18,  .BrdNum = 7,  .BrdChNum = 1},
  {.LogicChNum = 19,  .BrdNum = 9,  .BrdChNum = 1},
  {.LogicChNum = 20,  .BrdNum = 10, .BrdChNum = 1},
  {.LogicChNum = 21,  .BrdNum = 11, .BrdChNum = 1},
  {.LogicChNum = 22,  .BrdNum = 4,  .BrdChNum = 1},
  {.LogicChNum = 23,  .BrdNum = 8,  .BrdChNum = 1},
  {.LogicChNum = 24,  .BrdNum = 12, .BrdChNum = 1}
};

/**
 * @brief Размер таблицы соответствия
 */
static const uint16_t TableSize = sizeof(Table)/sizeof(Table[0]);


/**
 * @brief Функция преобразования логического номера канала в структуру {Номер платы, Номер канала на плате}
 *
 * @param LogicNum - Логический номер канала (из ПИВа)
 * @return Структура {Номер платы, Номер канала на плате}
 *          Если логический канал не найден, то в структуре будут нули
 */
ChConvBrdData_t ChConv_LogicToBrd(uint16_t LogicNum)
{
  ChConvBrdData_t result = {0,0};
  uint16_t idx = 0;

  // Поиск логического номера в таблице
  for (idx = 0; idx < TableSize; idx++)
  {
    // Если найден
    if (Table[idx].LogicChNum == LogicNum)
    {
      // Сохраняем результат
      result.BrdNum = Table[idx].BrdNum;
      result.BrdChNum = Table[idx].BrdChNum;

      // Прерываем цикл
      break;
    }
  }

  return result;
}

/**
 * @brief Функция преобразования комбинации {Номер платы, Номер канала на плате} в логический номер канала
 *
 * @param BrdNum - Номер платы
 * @param BrdChNum - Номер канала на плате
 * @return Логический номер канала
 *          Если комбинация не найдена, то будет ноль
 */
uint16_t ChConv_BrdToLogic(uint16_t BrdNum, uint16_t BrdChNum)
{
  uint16_t result = 0;
  uint16_t idx = 0;

  // Поиск комбинации в таблице
  for (idx = 0; idx < TableSize; idx++)
  {
    // Если найдена комбинация
    if ((Table[idx].BrdNum == BrdNum) && (Table[idx].BrdChNum == BrdChNum))
    {
      // Сохраняем результат
      result = Table[idx].LogicChNum;

      // Прерываем цикл
      break;
    }
  }

  return result;
}
