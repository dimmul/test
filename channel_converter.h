#ifndef CHANNEL_CONVERTER_H_
#define CHANNEL_CONVERTER_H_


/**\
 * @brief Тип структуры {Номер платы, Номер места}
 */
typedef struct
{
  uint16_t BrdNum;    /// Номер платы
  uint16_t BrdChNum;  /// Номер канала на плате
} ChConvBrdData_t;


ChConvBrdData_t ChConv_LogicToBrd(uint16_t LogicNum);
uint16_t ChConv_BrdToLogic(uint16_t BrdNum, uint16_t BrdChNum);


#endif
