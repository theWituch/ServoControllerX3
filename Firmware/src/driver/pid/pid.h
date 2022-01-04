#ifndef PID_H_
#define PID_H_

#include "pid/port.h

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/
/*! \ingroup pid
 * \brief Errorcodes used in PID module
 */
typedef enum
{
    PID_ENOERR,         /*!< no error */
    PID_DISABLED,       /*!< PID are disabled */
    PID_ERROREXCEED,    /*!< command error exceeded */
    PID_INERROR         /*!< PID has an error */
} ePIDErrorCode;

/*! \ingroup pid
 * \brief PID configuration
 */
typedef struct
__attribute__((packed))
{
    /*!< proportional gain
     */
    float32_t   fPGain;
    /*!< integral gain
     *
     * Value: Ki =  1/Ti
     */
    float32_t   fIGain;
    /* !<  derivative gain
     */
    float32_t   fDGain;

    float32_t   fFF0Gain;           /*!< feedforward proportional gain */
    float32_t   fFF1Gain;           /*!< feedforward derivative gain */

    float32_t   fDeadband;          /*!< max allowed command error */
    float32_t   fBias;              /*!< steady state offset */
    float32_t   fOutputLimit;       /*!< output limit */

    float32_t   fErrorLimit;        /*!< command error limit */
    float32_t   fPErrorLimit;       /*!< proportional command error limit */
    float32_t   fIErrorLimit;       /*!< integrated command error limit */
    float32_t   fDErrorLimit;       /*!< differentiated command error limit */

    uint32_t    ulCRC;              /*!< configuration checksum */
}
PIDConfig_t;

/*! \ingroup pid
 * \brief PID status
 */
typedef struct
__attribute__((packed))
{
    uint32_t Enabled :      1;      /*!< enable bit 1=will be processed*/
    uint32_t CycleState :   1;      /*!< cycle bit 1=should be processed */
    uint32_t LimitState :   1;      /*!< limit state when output is 100% */
    uint32_t ucErrorCode :  8;      /*!< error code for error tracking */
    uint32_t :21;
}
PIDStatus_t;

/*! \ingroup pid
 * \brief PID object
 */
typedef struct
__attribute__((packed))
{
    PIDConfig_t xConfig;            /*!< configuration */

    PIDStatus_t xStatus;            /*!< status */

    float32_t   lCommand;           /*!< commanded value */
    float32_t   lCommandPrevious;   /*!< previous command for differentiator */

    float32_t   lFeedback;          /*!< feedback value */
    float32_t   lFeedbackPrevious;  /*!< previous feedback value */

    float32_t   fError;             /*!< regulation error (command - feedback) */
    float32_t   fErrorPrevious;     /*!< previous error for differentiator */

    float32_t   fErrorIntegral;     /*!< integral value of error */
    float32_t   fErrorDerivative;   /*!< derivative value of error */

    float32_t   fOutput;            /*!< the output value */
    float32_t   fPOutput;           /*!< the proportional output value */
    float32_t   fIOutput;           /*!< the integral output value */
    float32_t   fDOutput;           /*!< the derivative output value */
    float32_t   fFF0Output;         /*!< the feed firward 0 output value */
    float32_t   fFF1Output;         /*!< the feed firward 1 output value */
}
PID_t;

/* ----------------------- Constant variables -------------------------------*/
const PIDConfig_t xPIDCleanConfig __attribute__(( weak ));

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

ePIDErrorCode ePIDInit(PID_t *xPIDObject, PIDConfig_t xPIDConfig);

inline ePIDErrorCode ePIDEnable(PID_t *xPIDObject);

inline ePIDErrorCode ePIDDisable(PID_t *xPIDObject);

ePIDErrorCode ePIDProcess(PID_t *xPIDObject);

#endif